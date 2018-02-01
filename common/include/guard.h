/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_GUARD_H_
#define _BGCC2_GUARD_H_

#include <stdlib.h>

namespace bgcc {

    /**
     * @brief 
     *
     * @tparam LockType
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��05��30�� 19ʱ19��33��
     */
    template <typename LockType>
        class Guard {
        public:
            /**
             * @brief Guard ���캯������Mutex����
             *
             * @param lock ������ָ��
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��05��30�� 19ʱ26��09��
             */
            Guard(LockType* lock) : _locked(false), _lock(lock) {
                if (NULL != _lock) {
                    if (0 == _lock->lock()) {
                        _locked = true;
                    }
                }
            }

            /**
             * @brief is_locked �������Ƿ�ɹ�
             *
             * @return �����ɹ�����true�����򷵻�false
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��05��30�� 19ʱ26��33��
             */
            bool is_locked() const {
                return _locked;
            }

            /**
             * @brief ~Guard ������������Mutex����
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012��05��30�� 19ʱ27��12��
             */
            ~Guard() {
                if (NULL != _lock) {
                    if (0 == _lock->unlock()) {
                        _locked = false;
                    }
                }
            }
        private:
            mutable bool _locked;
            LockType* _lock;
        };
}

#endif // _BGCC2_GUARD_H_

