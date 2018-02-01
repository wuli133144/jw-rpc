/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_MUTEX_H_
#define _BGCC_MUTEX_H_

#ifdef _WIN32
#include <Windows.h>
#else
#include <pthread.h>
#include <limits.h>
#endif

#include "bgcc_stdint.h"

#ifdef _WIN32
#define BGCC_MUTEX_WAIT_INFINITE INFINITE
#define bgcc_mutex_t HANDLE
#else
#define BGCC_MUTEX_WAIT_INFINITE UINT_MAX
#define bgcc_mutex_t pthread_mutex_t
#endif

namespace bgcc {

    /**
     * @brief ʵ���̼߳�Ļ������
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��05��30�� 17ʱ23��40��
     */
    class Mutex {
    public:
        /**
         * @brief Mutex ���캯��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ24��08��
         */
        Mutex();

        /**
         * @brief ~Mutex ���캯��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ24��14��
         */
        ~Mutex();

        /**
         * @brief lock ��������
         *
         * @param millisecond ��ʱʱ�������룩
         *
         * @return �����ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ24��23��
         */
        int32_t lock(uint32_t millisecond = BGCC_MUTEX_WAIT_INFINITE);

        /**
         * @brief try_lock ���Լ�������
         *
         * @return �����ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ24��57��
         */
        int32_t try_lock();

        /**
         * @brief unlock ��������
         *
         * @return �����ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ25��44��
         */
        int32_t unlock();

    protected:
        /**
         * @brief Mutex ���ÿ������캯��
         *
         * @param Mutex
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ28��45��
         */
        Mutex(const Mutex&);

        /**
         * @brief operator= ���ø�ֵ�����
         *
         * @param Mutex
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 17ʱ29��08��
         */
        Mutex& operator=(const Mutex&);

    private:
        bgcc_mutex_t _mutex;

    }; // end of class Mutex

}

#endif // _BGCC_MUTEX_H_

