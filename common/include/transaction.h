/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_TRANSACTION_H_
#define _BGCC_TRANSACTION_H_

#include <time.h>
#include <string>               // for std::string
#include <map>                  // for std::map

#include "bgcc_stdint.h"
#include "shareable.h"          // for super class
#include "shared_pointer.h"      // for member _data
#include "mutex.h"              // for member Mutex
#include "thread.h"
#include "protocol.h"
#include "nb_data_buffer.h"

namespace bgcc {

    typedef int32_t TicketIdType;
    typedef int32_t ThreadIdType;
    typedef int32_t PortType;

    /**
     * @class TicketMapKeyType
     * @brief ����map������
     */
    struct TicketMapKeyType {
        /** �ͻ���ip */
        std::string ip;
        /** �ͻ���port */
        PortType port;
        /** �ͻ��˳����߳�id */
        ThreadIdType threadId;
        /** �ͻ��˳�����ú����� */
        std::string funcName;
    };

    typedef SharedPointer<IProtocol> ProtocolSharedPointer;

    /**
     * @brief   ����map�����ͱȽϺ���
     * @param   lhs ��Ƚ���
     * @param   rhs �ұȽ���
     * @return  ��lhs<rhsʱ������true;���򷵻�false��
     */
    bool operator<(const TicketMapKeyType& lhs, const TicketMapKeyType& rhs);

    /**
     * @class TicketMapValueType
     * @brief ����mapֵ����
     */
    struct TicketMapValueType {
        /** ����� */
        TicketIdType ticketId;
        /** ֵ���ʱ��� */
        time_t storeTime;
    };


    class Transaction : public Shareable {
        private:
            friend class IntervalClearRunner;
            Transaction();
        public:
            static Transaction* get_instance();
            virtual ~Transaction();
            /**
             * @brief   ��ȡһ���µ������
             * @param   
             * @return  
             */
            TicketIdType getTicketId(ProtocolSharedPointer protocol, ThreadIdType threadId, std::string funcName);

            /**
             * @brief   ��ȡ��һ�ε������
             * @param   
             * @return  
             */
            TicketIdType getCurrentTicketId(ProtocolSharedPointer protocol, ThreadIdType threadId, std::string funcName);

            /**
             * @brief   ��������Ż�ȡ���ݡ������ڲ����������¿ռ䣬���ڴ�����ݡ�
             * @param   ticketId �����
             * @param   data [out] ����ָ�����ݴ��λ��
             * @param   size [out] ���ڽ������������С
             * @return  �����롣�ɹ�����SUCCESS��
             * @note    ���óɹ���data���ɵ������ͷš�
             */
            int32_t retrieveDataCopyByTicketId(TicketIdType ticketId, void** data, int32_t& size);

            /**
             * @brief   ��������Ŵ�ȡ���ݡ�
             * @param   ticketId �����
             * @param   data �����׵�ַ
             * @param   size �����ֽ���
             * @return  �����롣�ɹ�����SUCCESS��
             */
            int32_t saveDataByTicketId(TicketIdType ticketId, void* data, int32_t size);

        private:
            /**
             * @brief   ����protocol��ȡip��port
             * @param   
             * @return  
             */
            int32_t getIpAndPort(ProtocolSharedPointer protocol, std::string& ip, PortType& port);
#ifdef _DEBUG
        public:
#endif
            TicketIdType _getTicketId(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName);
            TicketIdType _getCurrentTicketId(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName);
        private:

            /**
             * @brief   ���ݿͻ���ip��port���ͻ��˳����߳�id����������������map�ļ�
             * @param   ip �ͻ���ip
             * @param   port �ͻ���port
             * @param   threadId �ͻ����߳�id
             * @param   funcName �ͻ��˳�����
             * @return  ����map��
             */
            TicketMapKeyType makeKey(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName);

            /**
             * @brief   ��ȡ��һ�����õ������
             * @param   
             * @return  ���õ������
             */
            TicketIdType getNextTicketId();

            /**
             * @brief   �����Ե������������
             * @param   
             * @return  
             */
            int32_t intervalClear();

        private:
            typedef std::map<TicketMapKeyType, TicketMapValueType> TicketKey2TicketValueMap;
            typedef std::map<TicketIdType, SharedPointer<NBDataBuffer> > TicketId2DataMap;

            TicketKey2TicketValueMap _tickets;
            TicketId2DataMap _data;

            TicketIdType _counter;
            Mutex _mutex;

            SharedPointer<Thread> _intervalClearThread;
    };

}
#endif
