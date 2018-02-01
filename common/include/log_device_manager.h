/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_LOG_DEVICE_MANAGER_H_
#define _BGCC2_LOG_DEVICE_MANAGER_H_

#include <vector>
#include "log_device.h"
#include "bgcc_stdint.h"

//BGCC log level definition
#define BGCC_LOGLEVEL_TRACE  0x0
#define BGCC_LOGLEVEL_DEBUG  0x1
#define BGCC_LOGLEVEL_NOTICE 0x2
#define BGCC_LOGLEVEL_WARN   0x3
#define BGCC_LOGLEVEL_FATAL  0x4
#define BGCC_LOGLEVEL_NOLOG  0x10

namespace bgcc {

    /**
     * @brief log_open 1. ����BGCC�����ļ�����BGCC��־���� 2. ����BGCC������־����"bgcc"
     *
     * @param conf_filepath BGCC��־�����ļ�·��
     * @see
     * @note �������ļ������ڻ��������ļ�����ʱ������������ʾ��ֱ���˳������ִ��
     * ����main������ڴ����øú���
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 10ʱ39��56��
     */
    void log_open(const char* conf_filepath = NULL);

    /**
     * @brief log_close �ر�BGCC��־����
     *
     * @return 
     * @see
     * @note
     * ����main��������ǰ���øú���
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 10ʱ47��16��
     */
    int32_t log_close();

    /**
     * @brief ��־������
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 10ʱ50��39��
     */
    class LogDeviceManager {
    public:
        /**
         * @brief get_instance ��ȡ��־������
         *
         * @return  ��־������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ51��00��
         */
        static LogDeviceManager* get_instance();

        /**
         * @brief ~LogDeviceManager ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ51��19��
         */
        ~LogDeviceManager();

        /**
         * @brief is_device_exist �ж�ָ���豸device_name�Ƿ����
         *
         * @param device_name �豸����
         *
         * @return ���豸����ʱ����true�����򷵻�false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ51��48��
         */
        bool is_device_exist(const char* device_name);

        /**
         * @brief get_device_loglevel ��ȡָ���豸����־����
         *
         * @param device_name �豸����
         *
         * @return ��־���𡣵��豸����ָ�����豸������ʱ������BGCC_LOGLEVEL_NOLOG
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ52��34��
         */
        int32_t get_device_loglevel(const char* device_name);

        /**
         * @brief write ����־д���豸device_name��
         *
         * @param device_name �豸����
         * @param log_message ��־��Ϣ
         *
         * @return �ɹ��򷵻�0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ55��28��
         */
        int32_t write(const char* device_name, const struct log_message_t& log_message);

    private:
        /**
         * @brief add_device �����豸��ӵ��豸�б���
         *
         * @param device ���豸
         *
         * @return �����ɹ�����0�������豸�����������豸������ͬʱ������Ϊ���ʧ�ܣ����ط�0ֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ57��33��
         */
        int32_t add_device(ILogDevice* device);

        /**
         * @brief get_device �����豸���ƻ�ȡ�豸
         *
         * @param device_name �豸����
         *
         * @return �豸ָ�롣��ָ���豸������ʱ����NULL
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ58��33��
         */
        ILogDevice* get_device(const char* device_name);

        std::vector<ILogDevice*> _devices;

        /**
         * @brief LogDeviceManager ������ʾ����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ57��04��
         */
        LogDeviceManager();

        /**
         * @brief operator= ���ÿ�������
         *
         * @param LogDeviceManager
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 10ʱ57��15��
         */
        LogDeviceManager& operator=(const LogDeviceManager&);

    private:
        friend void load_default_device();
        friend void load_conf_device(const char*);
    };
}
#endif // _BGCC2_LOG_DEVICE_MANAGER_H_

