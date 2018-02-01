/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_THREADGROUP_H_
#define _BGCC_THREADGROUP_H_

#include <vector>
#include "thread.h"
#include "shared_pointer.h"

namespace bgcc {

    /**
     * @class ThreadGroup
     * @brief ThreadGroup��Thread�ļ��ϣ��������һ������߳�
     */
    class ThreadGroup {
	public:
        ThreadGroup();
        ~ThreadGroup();

        /**
         * @brief   ������߳�
         * @param   thread ����ӵ����߳�
         * @return  �ɹ�����true
         */
		bool addThread(SharedPointer<Thread> thread);

        /**
         * @brief   �ȴ��߳����е������߳�ִ�н���
         * @param   
         * @return  �ɹ�����true
         */
		bool join();

        /**
         * @brief   ��ȡ�߳����е��̸߳���
         * @param   
         * @return  �߳����е��̸߳���
         */
		size_t size();

        /**
         * @brief   ��ֹ�߳����е������̵߳�ִ��
         * @param   
         * @return  �ɹ�����true
         */
		bool terminateAll();
	private:
        ThreadGroup(const ThreadGroup&);
        ThreadGroup& operator=(const ThreadGroup&);

		std::vector<SharedPointer<Thread> > _threads;
        typedef std::vector<SharedPointer<Thread> >::const_iterator citr_type;
	};
}

#endif // _BGCC_THREADGROUP_H_

