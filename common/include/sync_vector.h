/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SYNC_VECTOR_H_
#define _BGCC_SYNC_VECTOR_H_

#include <vector>
#include "mutex.h"
#include "sema.h"
#include "guard.h"
#include "bgcc_error.h"
#include "shareable.h"

/**
 * @brief �̰߳�ȫvector
 * @see
 * @note
 * @author  liuxupeng(liuxupeng@baidu.com)
 * @date    2012��05��30�� 16ʱ42��56��
 */
namespace bgcc {

    template <typename ElemType>
        class SyncVector : public Shareable {
        public:
            SyncVector() { }
            typedef Guard<Mutex> ScopedGuard;

            /**
             * @brief put ��ͬ��vector�����Ԫ�أ������ظ�����ͬʱ�����ź���
             *
             * @param elem ��Ԫ��
             *
             * @return ��ӳɹ�����0�����򷵻ش�����
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��05��30�� 19ʱ11��24��
             */
            int32_t put(ElemType elem) {
                {
                    ScopedGuard guard(&_mutex);
                    if (guard.is_locked()) {
                        try {
                            _vector.push_back(elem);
                        }
                        catch(std::bad_alloc &) {
                            return E_BGCC_NOMEM;
                        }
                    }
                    else {
                        return E_BGCC_SYSERROR;
                    }
                }
                _sem.signal();
                return 0;
            }

            /**
             * @brief get ��ͬ��vector��ȡԪ�ء����ͬ��vectorΪ�գ�������ָ��ʱ��
             * BGCC_SEMA_WAIT_INFINITE��ʾ����������
             *
             * @param elem ȡ�õ�Ԫ��
             * @param millisecond ��ʱʱ�������룩
             *
             * @return �ɹ�����0�����򷵻ش�����: E_BGCC_TIMEOUT��ʾ��ʱ.
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��05��30�� 19ʱ12��19��
             */
            int32_t get(ElemType& elem, int millisecond) {
                int32_t ret = _sem.wait(millisecond);

                if (0 == ret) {
                    {
                        ScopedGuard guard(&_mutex);
                        if (guard.is_locked()) {
                            elem = _vector.back();
                            _vector.pop_back();
                        }
                        else {
                            return E_BGCC_SYSERROR;
                        }
                    }
                    return 0;
                }
                else {
                    return ret;
                }
            }

            int32_t size() {
                ScopedGuard guard(&_mutex);
                return (int32_t)_vector.size();
            }

        protected:
            SyncVector(const SyncVector&);
            SyncVector& operator=(const SyncVector&);

        private:
            std::vector<ElemType> _vector;
            Mutex _mutex;
            Semaphore _sem;

        }; // end of class SyncVector
}

#endif // _BGCC_SYNC_VECTOR_H_
