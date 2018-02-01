/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SERVICE_MANAGER_H_
#define _BGCC2_SERVICE_MANAGER_H_

#include <map>
#include <string>
#include "shared_pointer.h"
#include "processor.h"
#include "mutex.h"

namespace bgcc {
    /**
     * @brief ����һ�����ʵ�塣ÿ�������ɵ���processor���ṩ
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��21�� 13ʱ14��58��
     */
    class ServiceManager {
    public:
        /**
         * @brief ServiceManager ���캯��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 16ʱ22��29��
         */
        ServiceManager();

        /**
         * @brief add_service ��ӷ���
         *
         * @param processor ����ʵ��
         *
         * @return ��ӳɹ�������Ѵ����򷵻�0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 13ʱ15��51��
         */
        int32_t add_service(SharedPointer<IProcessor> processor);

        /**
         * @brief remove_service ɾ������
         *
         * @param processor ����ʵ��
         *
         * @return ɾ���ɹ�����񲻴��ڷ���0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 13ʱ18��49��
         */
        int32_t remove_service(SharedPointer<IProcessor> processor);

        /**
         * @brief remove_service ɾ������
         *
         * @param name ����ʵ������
         *
         * @return ɾ���ɹ�����񲻴��ڷ���0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 13ʱ21��49��
         */
        int32_t remove_service(const std::string& name);

        /**
         * @brief remove_all_service ɾ�����з���ʵ��
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 13ʱ22��51��
         */
        int32_t remove_all_service();

        /**
         * @brief get_service ��ȡ����ʵ��
         *
         * @param name ����ʵ������
         *
         * @return ����ʵ������ָ��
         * @see
         * @note �ڵ�����ɺ�����÷���ֵ��is_valid()��������鷵��ֵ�Ƿ����
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 13ʱ23��44��
         */
        SharedPointer<IProcessor> get_service(const std::string& name) const;

        /**
         * @brief is_service_exist ����ض�����ʵ���Ƿ����
         *
         * @param name ����ʵ������
         *
         * @return true��ʾ����ʵ�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 13ʱ26��16��
         */
        bool is_service_exist(const std::string& name) const;

        /**
         * @brief get_service_count ��ȡ����ʵ������
         *
         * @return ����ʵ������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 16ʱ19��29��
         */
        int32_t get_service_count() const;
    private:
        /**
         * @brief ServiceManager ���ÿ������캯��
         *
         * @param ServiceManager
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 16ʱ20��26��
         */
        ServiceManager(const ServiceManager&);

        /**
         * @brief operator= ���ø�ֵ�����
         *
         * @param ServiceManager
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��21�� 16ʱ20��41��
         */
        ServiceManager& operator=(const ServiceManager&);

        typedef std::map<std::string, SharedPointer<IProcessor> > name2service_map;
        name2service_map _name2service;
        mutable Mutex _mutex;
    };
}
#endif // _BGCC2_SERVICE_MANAGER_H_

