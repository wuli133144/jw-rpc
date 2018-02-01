/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_THREADMANAGER_H_
#define _BGCC_THREADMANAGER_H_

#include "thread.h"
#include "shared_pointer.h"
#include "runnable.h"

namespace bgcc {

    /**
     * @class ThreadManger
     * @brief ���ڴ����µ��߳�
     */
    class ThreadManager {
    public:
        /**
         * @brief   �����µ��߳�
         * @param   pr �߳�ִ�е�����
         * @return  
         */
        static SharedPointer<Thread> createThread(SharedPointer<Runnable> pr);
    private:
        ThreadManager(const ThreadManager&);
        ThreadManager& operator=(const ThreadManager&);
    };

}

#endif

