/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_ITRANSPORT_H_
#define _BGCC_ITRANSPORT_H_

#include "bgcc_stdint.h"
#include "shareable.h"

namespace bgcc {

    /**
     * @class ITransport 
     * @brief ��������ӿ��࣬��������������ʵ��
     */
    class ITransport : public Shareable {
    public:
        virtual ~ITransport() { }

        /**
         * @brief  �����ӣ��ͻ��˳�������connect����������������bind��listen
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t open() = 0;

        /**
         * @brief   �ر�socket������windows�½���ϵͳ����
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t close() = 0;

        /**
         * @brief   ��ȡ����
         * @param   buffer ����recv���ݵĴ洢�ռ�
         * @param   length �������ݵĳ���
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t read(void* buffer, int32_t length) = 0;

        /**
         * @brief   ��socket send����
         * @param   buffer ����send���ݵĴ洢�ռ�
         * @param   length send���ݵĳ���
         * @return  �����ɹ�����0�����򷵻ش����롣
         */
        virtual int32_t write(const void* buffer, int32_t length) = 0;

        /**
         * @brief   �ж������Ƿ��
         * @return  �����ɹ�����true�����򷵻�false��
         */
        virtual bool is_open() const = 0;

        /**
         * @brief   ��⵱ǰ���ܻ������Ƿ��п�������
         * @return  �����ɹ�����true�����򷵻�false��
         */
        virtual bool peek() const = 0;

    };

}

#endif 

