/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SOCKET_BASE_H_
#define _BGCC_SOCKET_BASE_H_

#ifdef _WIN32 
#include <windows.h>
#define BGCC_EINTR  WSAEINTR
#else 
typedef int32_t SOCKET;
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define BGCC_EINTR  EINTR
#endif

#include "bgcc_stdint.h"
#include "shareable.h"
#include "transport.h"
#include "mutex.h"
#include "guard.h"

namespace bgcc {

    /**
     * @class Socket 
     * @brief Socket���ֹ����ӿ�ʵ��
     */
    class Socket :  public ITransport {
    public:

        virtual ~Socket();

        /**
         * @brief   �����ӣ��麯������client��server���о���ʵ��
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t open();

        /**
         * @brief   �ر����Ӳ���ʼ����windows����Ҫ�������⴦��
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t close();

        /**
         * @brief   ��ȡ����
         * @param   buffer ����recv���ݵĴ洢�ռ�
         * @param   length �������ݵĳ���
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t read(void * buffer, int32_t length);

        /**
         * @brief   д����
         * @param   buffer ����write���ݵĴ洢�ռ�
         * @param   length д���ݵĳ���
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t write(const void* buffer, int32_t length);

        /**
         * @brief   �ж�socket�Ƿ�򿪣��������̺Ϸ��жϣ��麯����client��server�ֱ�ʵ��
         * @return  �ɹ�����ture��ʧ�ܷ���false
         */
        virtual bool is_open() const;

        /**
         * @brief   �����鿴�Ƿ��п�������
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual bool peek() const;

        /**
         * @brief   ����socket��ʱʱ��
         * @param   seconds ��ʱʱ��
         * @param   optname ��ʾ���ͻ��ǽ���
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        int32_t set_timeout(int32_t seconds, int32_t optname);
        /**
         * @brief   ���÷��ͳ�ʱʱ��
         * @param   buffer ����recv���ݵĴ洢�ռ�
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        int32_t set_send_timeout(int32_t seconds);

        /**
         * @brief   ���ý��ճ�ʱʱ��
         * @param   buffer ����recv���ݵĴ洢�ռ�
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        int32_t set_recv_timeout(int32_t second);

        SOCKET get_socket() const {
            return _socket;
        }
    protected:
        Socket();
        /**ȫ��socket���*/
        SOCKET _socket;
        int32_t _send_timeout;
        int32_t _recv_timeout;

        /**��ʱʱ��*/
        //int32_t _send_timeout;

        /**���ճ�ʱʱ��*/
        // int32_t _recv_timeout;

    protected:
        /**
         * @brief   ��ʼ����ҪΪ����ɶ�Winsock DLL�ļ��ء�
         * @return  �ɹ����ʼ������0�����򷵻�Windows�����롣
         */
        int32_t init();

        /**
         * @brief   ���ʼ����Ҫ��ɶ�Winsock DLL��ж�ء�
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        int32_t uninit();

    private:
        static int32_t _nofSockets;
        static Mutex _mutex;
    };
}

#endif

