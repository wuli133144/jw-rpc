/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SERVICE_FRAMEWORK_H_
#define _BGCC2_SERVICE_FRAMEWORK_H_

#include <stdlib.h>
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief ��ȡ״̬ö��ֵ
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��04�� 14ʱ01��03��
     */
    enum reading_state_t {
        S_SIZE_READING,
        S_DATA_READING,
        S_READING_END
    };

    /**
     * @brief ���ڱ�ʾ��ǰ�Ķ�ȡ״̬
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��04�� 14ʱ01��26��
     */
    struct reading_item_t {
        enum reading_state_t    state;  /** ��ǰ�Ķ�״̬*/
        int32_t                 nexpected;  /** �������������ֽ�*/
        int32_t                 nread;  /** �Ѿ���ȡ�˶����ֽ�*/
        char                    head_buf[20]; /** ��Ϣͷ�������� */
        char*                   data;   /** ��Ϣ��������ʹ��mempoll������ͷ�*/

        reading_item_t() {
            state = S_SIZE_READING;
            nexpected = 20;
            nread = 0;
            data = NULL;
        }

        void reset() {
            state = S_SIZE_READING;
            nexpected = 20;
            nread = 0;
            data = NULL;
        }
    };

    /**
     * @brief ���ڱ�ʾ��ǰ��д��״̬
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��04�� 14ʱ04��02��
     */
    struct writing_item_t {
        int32_t nexpected;  /** �������������ֽ�*/
        int32_t nwritten;   /** �Ѿ�д�˶����ֽ�*/
        char* data; /** ��Ϣ��������ʹ��mempoll�ͷ�*/
    };
}
#endif // _BGCC2_SERVICE_FRAMEWORK_H_

