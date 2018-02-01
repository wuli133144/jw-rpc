/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_THREAD_H_
#define _BGCC2_THREAD_H_


#include "shareable.h"
#include "runnable.h"
#include "shared_pointer.h"
#include "sema.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace bgcc {

    typedef void* (*run_func_t)(void*);
    typedef SharedPointer<Runnable> RunnableSharedPointer;
    typedef SharedPointer<Runnable> RunnableSP;
    /**
     * @brief ����ϵͳ�߳�ģ�͵ĳ��󣬸����̵߳Ĵ�����ִ�С��ȴ��������Լ�����
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��13�� 19ʱ57��32��
     */
    class Thread : public Shareable {
    private:
        enum state_t {
            INIT,
            START,
            JOINED,
            STOP
        };
    public:
        /**
         * @brief Thread ���캯��
         *
         * @param runner �߳�ִ�е�����
         * @param detached �Ƿ����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ07��35��
         */
        Thread(const RunnableSP& runner, bool detached = false);

        /**
         * @brief Thread ���캯��
         *
         * @param func �߳�ִ�е�����
         * @param detached �Ƿ����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ08��00��
         */
        Thread(run_func_t func, void* arg = NULL, bool detached = false);

        /**
         * @brief ~Thread ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ08��21��
         */
        ~Thread();

        /**
         * @brief start �����̵߳�ִ��
         *
         * @return �ɹ�����true
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ08��32��
         */
        bool start();

        /**
         * @brief join �ȴ��߳�ִ�н���
         *
         * @return �ɹ�����true
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ08��59��
         */
        bool join();

        /**
         * @brief stop ��ֹ�̵߳�ִ��
         *
         * @return �ɹ�����true
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ09��15��
         */
        bool stop();

#ifdef _WIN32
        /**
         * @brief get_thread_id �����߳�ID������Windows��ʹ��
         *
         * @return �߳�ID
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ09��49��
         */
        DWORD get_thread_id() const;

        /**
         * @brief HANDLE �����߳̾��������Windows��ʹ��
         *
         * @return �߳̾��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ10��19��
         */
        operator HANDLE();

#else
        /**
         * @brief get_thread_id �����߳�ID������Linux��ʹ��
         *
         * @return �߳�ID
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 20ʱ10��46��
         */
        pthread_t get_thread_id() const;
#endif

    private:
        bool setDetached();
#ifdef _WIN32
        static DWORD __stdcall thread_start_func(LPVOID lpParam);
#else
        static void* thread_start_func(void* arg);
#endif
    private:
        bool _use_functor;
        RunnableSP _functor;
        run_func_t _func_ptr;
        void* _func_arg;
        Semaphore _sema;
        mutable bool _detached;
        state_t _state;

#ifdef _WIN32
        HANDLE _handle;
        DWORD _thread_id;
#else
        pthread_t _thread;
#endif

    };
}
#endif // _BGCC2_THREAD_H_

