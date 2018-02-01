/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_THREADPOOL_H_
#define _BGCC_THREADPOOL_H_

#include "runnable.h"
#include "sync_vector.h"
#include "thread_group.h"
#include "shareable.h"

namespace bgcc {

    /**
     * @class ThreadPool
     * @brief �̳߳�ά��һ��Ԥ�ȴ����õ��̼߳�һ��������С��߳�����ִ����������е�����
     */
    class ThreadPool : public Shareable {
    private:
        class ThreadPoolRunner;
    public:
        /**
         * @class state_t
         * @brief �̳߳�״̬
         */
        enum state_t {
            UNINITIALIZED, INITIALIZED
        };

        /**
         * @brief   ���캯��
         * @param   
         * @return  
         */
        ThreadPool();

        /**
         * @brief   ��������
         * @param   
         * @return  
         */
        ~ThreadPool();

        /** �̳߳���Ĭ���̸߳��� */
        static const int DEFAULT_THREADS_NUM = 10;

        /**
         * @brief   ��ʼ���̳߳أ������涨�������߳�
         * @param   nThreads �����̵߳ĸ���
         * @return  �ɹ�����0
         */
        int init(int nThreads = DEFAULT_THREADS_NUM);

        /**
         * @brief   ������������������
         * @param   pr ����ӵ�����
         * @return  �ɹ�����true
         */
        bool addTask(RunnableSharedPointer pr);

        /**
         * @brief  �ȴ������߳�ִ����ϡ��벻Ҫ���ô˷������̳߳��е��߳���Զ�����Զ�ִ�н���
         * @param   
         * @return  
         */
        bool join();

        /**
         * @brief   ��ȡ�̸߳���
         * @param   
         * @return  ��ǰ�̳߳����̸߳���
         */
        size_t size();

        /**
         * @brief   ��ֹ�����̵߳�ִ��
         * @param   
         * @return  
         */
        bool terminate();
    private:
        /*
        * addWorker: ���̳߳������nWorker���߳�
        */
        int addWorker(int nWorker);

        friend class ThreadPoolRunner;

        /* ��ӵ��̳߳��е����� */
        SyncVector<RunnableSharedPointer> _tasks;

        /* �߳��� */
        ThreadGroup _threadGroup;
        state_t _state;
    };
}

#endif // _BGCC_THREADPOOL_H_

