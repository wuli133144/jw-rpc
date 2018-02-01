/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SHAREABLE_H_
#define _BGCC2_SHAREABLE_H_

#include "mutex.h"
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief �ṩ����ԭ��������ͨ�ü��������ܣ��ɱ��������ָ�������
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��13�� 15ʱ30��12��
     */
    class Shareable {
    public:
        /**
         * @brief ~Shareable ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ32��46��
         */
        virtual ~Shareable() { }

        /**
         * @brief inc �������ü���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ32��53��
         */
        void inc();

        /**
         * @brief dec �������ü���
         *
         * @return ���ü�����1���ֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ33��02��
         */
        int32_t dec();

        /**
         * @brief get_count ��ȡ��ǰ���ü���
         *
         * @return ��ǰ���ü���ֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ33��25��
         */
        int32_t get_count();
    protected:
        /**
         * @brief Shareable ������ʽ���죬����ͨ�����๹��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ33��46��
         */
        Shareable();
    private:
        int32_t _count;
        Mutex _mutex;
    private:
        /**
         * @brief Shareable ���ÿ������칦��
         *
         * @param Shareable
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ29��11��
         */
        Shareable(const Shareable&);

        /**
         * @brief operator= ���ø�ֵ�����
         *
         * @param Shareable
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��13�� 15ʱ29��36��
         */
        Shareable& operator=(const Shareable&);
    };
}

#endif // _BGCC2_SHAREABLE_H_

