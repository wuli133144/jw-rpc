/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_I_SERVER_H_
#define _BGCC2_I_SERVER_H_

#include "bgcc_stdint.h"
#include "shareable.h"

namespace bgcc {

    /**
     * @brief �������ӿ���
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��15�� 14ʱ54��02��
     */
    class IServer : public Shareable {
    public:
        /**
         * @brief ~IServer ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��15�� 14ʱ54��11��
         */
        virtual ~IServer() { }

        /**
         * @brief init ��ʼ������
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��15�� 14ʱ54��20��
         */
        virtual int32_t init() {
            return 0;
        }

        /**
         * @brief serve ��������
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��15�� 14ʱ54��30��
         */
        virtual int32_t serve() = 0;

        /**
         * @brief stop ֹͣ����
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��15�� 14ʱ54��45��
         */
        virtual int32_t stop() = 0;
    };
}

#endif // _BGCC2_I_SERVER_H_

