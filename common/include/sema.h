/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SEMAPHORE_H_
#define _BGCC2_SEMAPHORE_H_

#ifdef _WIN32
#include <Windows.h>
#else
#include <semaphore.h>
#include <limits.h>
#endif

#include "bgcc_stdint.h"

#ifdef _WIN32
#define BGCC_SEMA_WAIT_INFINITE INFINITE
#define bgcc_sem_t HANDLE
#else
#define BGCC_SEMA_WAIT_INFINITE UINT_MAX
#define bgcc_sem_t sem_t
#endif

namespace bgcc {

    /**
     * @brief ʵ���̼߳������ͬ��
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��05��30�� 14ʱ19��15��
     */
    class Semaphore {
    public:
        /**
         * @brief Semaphore ���캯��
         *
         * @param ninit �ź����ĳ�ʼֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 14ʱ22��46��
         */
        Semaphore(int32_t ninit = 0);

        /**
         * @brief ~Semaphore ���캯��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 14ʱ19��48��
         */
        ~Semaphore();

        /**
         * @brief wait �ȴ��ź���
         *
         * @param millisecond ��ʱʱ�������룩
         *
         * @return �ɹ�����0�����򷵻ش����롣�������ʹ��ErrorUtil::strbgccerror_rת��Ϊ�ı���Ϣ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 14ʱ20��33��
         */
        int32_t wait(uint32_t millisecond = BGCC_SEMA_WAIT_INFINITE);

        /**
         * @brief signal �����ź���
         *
         * @return �ɹ�����0�����򷵻ش����롣�������ʹ��ErrorUtil::strbgccerror_rת��Ϊ�ı���Ϣ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 14ʱ21��34��
         */
        int32_t signal();

    protected:
        /**
         * @brief Semaphore ���ÿ������캯��
         *
         * @param Semaphore
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 14ʱ20��00��
         */
        Semaphore(const Semaphore&);

        /**
         * @brief operator= ���ø�ֵ�����
         *
         * @param Semaphore
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 14ʱ20��19��
         */
        Semaphore& operator=(const Semaphore&);

    private:
        bgcc_sem_t _sem;

    }; // end of class Semaphore

}

#endif // _BGCC2_SEMAPHORE_H_

