/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_LOG_DEVICE_H_
#define _BGCC2_LOG_DEVICE_H_

#include <stdio.h>      // for FILE
#include <vector>

#ifndef _WIN32
#include <pthread.h>    // for pthread_mutex_t
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#include "time_util.h"
#include "mutex.h"

#define MAX_DEVICE_NAME_LEN  512
#define MAX_FILE_PATH_LEN    512
#define MAX_LOG_FORMAT_LEN   512

#define BGCC_LOG_SPLIT_POLICY_BY_TIME   0x0
#define BGCC_LOG_SPLIT_POLICY_BY_SIZE   0x1

namespace bgcc {

    /**
     * @brief ���ڱ�ʾ���䵽��־�豸����־��Ϣ
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 11ʱ05��26��
     */
    struct log_message_t {
        int32_t loglevel;          /** ��־����*/
        const char* content;       /** ��־���ݣ��ڸ�ʽ������%C��ʾ*/
        const char* loglevel_name; /** ��־�������ƣ��ڸ�ʽ������%N��ʾ*/
        const char* filename;      /** ��־�����ļ����ļ������ڸ�ʽ������%F��ʾ*/
        const char* line;          /** ��־���ڵ��кţ��ڸ�ʽ������%L��ʾ*/
		struct ::timeval tv;         /** ��־����������ʱ�䣬�ڸ�ʽ������%D��ʾ*/
        long long tid;       /** �߳�ID���ڸ�ʽ������%T��ʾ*/
    };

    /**
     * @brief ��־�豸�ӿڡ�����涨����־�豸�����еĹ�������
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 11ʱ06��24��
     */
    class ILogDevice {
    public:
        /**
         * @brief ~ILogDevice ��־�豸�ӿ���������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ06��37��
         */
        virtual ~ILogDevice() {
        }

        /**
         * @brief is_opened �ж���־�豸�Ƿ��Ѵ�
         *
         * @return  ����־�豸�Ѵ��򷵻�true�����򷵻�false��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ06��53��
         */
        virtual bool is_opened() const = 0;

        /**
         * @brief open ����־�豸
         *
         * @param param ��������
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ07��09��
         */
        virtual int32_t open(void* param = NULL) = 0;

        /**
         * @brief close �ر���־�豸
         *
         * @param param ��������
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ07��49��
         */
        virtual int32_t close(void* param = NULL) = 0;

        /**
         * @brief write д��־
         *
         * @param log_message ��־��Ϣ
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ08��32��
         */
        virtual int32_t write(const struct log_message_t& log_message) = 0;

        /**
         * @brief get_name ������־�豸����
         *
         * @return ��־�豸����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ08��57��
         */
        virtual const char* get_name() const = 0;

        /**
         * @brief get_loglevel ������־�豸����
         *
         * @return ��־�豸����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ09��15��
         */
        virtual int32_t get_loglevel() const = 0;

        /**
         * @brief get_split_policy ������־�豸�ָ����
         *
         * @return ��־�豸�ָ����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ09��34��
         */
        virtual int32_t get_split_policy() const = 0;

        /**
         * @brief get_max_size ������־�豸�ļ����ֵ����λΪ�ֽڣ�
         *
         * @return  ��־�ļ�����ֽ���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ10��04��
         */
        virtual off_t get_max_size() const = 0;

        /**
         * @brief get_max_record_interval ������־�豸�ļ���¼���ʱ������λΪ�룩
         *
         * @return  ��־�ļ���¼���ʱ��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ10��20��
         */
        virtual int32_t get_max_record_interval() const = 0;

        /**
         * @brief get_log_format ��ȡ��־�豸����־��ʽ���ƴ�
         *
         * @return  ��־�豸����־��ʽ���ƴ�
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ10��39��
         */
        virtual const char* get_log_format() const = 0;
    };

    /**
     * @brief ��־�豸�ĳ����ࡣ���ඨ�����־�豸��ͨ�÷���
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 11ʱ11��09��
     */
    class AbstractLogDevice : public ILogDevice {
    public:
        /**
         * @brief AbstractLogDevice ���캯��
         *
         * @param name ��־�豸��
         * @param loglevel �豸��־����
         * @param split_policy �豸�ָ����
         * @param max_size ��־�ļ�����ֽ���
         * @param max_record_interval ��־�ļ���¼���ʱ��
         * @param log_format ��־��ʽ���ƴ�
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ12��24��
         */
        AbstractLogDevice(
                const char* name,
                int32_t loglevel,
                int32_t split_policy,
                off_t max_size,
                int32_t max_record_interval,
                const char* log_format);

        /**
         * @brief ~AbstractLogDevice ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ13��12��
         */
        virtual ~AbstractLogDevice();

        /**
         * @brief get_name ������־�豸����
         *
         * @return ��־�豸����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ08��57��
         */
        virtual const char* get_name() const;

        /**
         * @brief get_loglevel ������־�豸����
         *
         * @return ��־�豸����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ09��15��
         */
        virtual int32_t get_loglevel() const;

        /**
         * @brief get_split_policy ������־�豸�ָ����
         *
         * @return ��־�豸�ָ����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ09��34��
         */
        virtual int32_t get_split_policy() const;

        /**
         * @brief get_max_size ������־�豸�ļ����ֵ����λΪ�ֽڣ�
         *
         * @return  ��־�ļ�����ֽ���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ10��04��
         */
        virtual off_t get_max_size() const;

        /**
         * @brief get_max_record_interval ������־�豸�ļ���¼���ʱ������λΪ�룩
         *
         * @return  ��־�ļ���¼���ʱ��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ10��20��
         */
        virtual int32_t get_max_record_interval() const;

        /**
         * @brief get_log_format ��ȡ��־�豸����־��ʽ���ƴ�
         *
         * @return  ��־�豸����־��ʽ���ƴ�
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ10��39��
         */
        virtual const char* get_log_format() const;

    protected:
        char    _name[MAX_DEVICE_NAME_LEN]; /** �豸����*/
        int32_t _loglevel;                  /** �豸��־�ȼ�*/
        int32_t _split_policy;              /** �ָ����*/
        int32_t _max_size;                  /** �ļ���󳤶�(��λ�ֽ�)*/
        int32_t _max_record_interval;       /** �ļ�����¼����(��λ��)*/
        char    _log_format[MAX_LOG_FORMAT_LEN]; /** ��־�豸����־��ʽ���ƴ�*/
    };

    /**
     * @brief �ļ���־�豸��
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��12�� 11ʱ16��46��
     */
    class FileLogDevice : public AbstractLogDevice {
    public:
        /**
         * @brief FileLogDevice ���캯��
         *
         * @param file_path �ļ���־�豸�ļ�·��
         * @param name ��־�豸��
         * @param loglevel �豸��־����
         * @param split_policy �豸�ָ����
         * @param max_size ��־�ļ�����ֽ���
         * @param max_record_interval ��־�ļ���¼���ʱ��
         * @param log_format ��־��ʽ���ƴ�
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ16��56��
         */
        FileLogDevice(
                const char* file_path,
                const char* name,
                int32_t loglevel,
                int32_t split_policy,
                off_t max_size,
                int32_t max_record_interval,
                const char* log_format);

        /**
         * @brief ~FileLogDevice ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ17��43��
         */
        virtual ~FileLogDevice();

        /**
         * @brief is_opened �ж���־�豸�Ƿ��Ѵ�
         *
         * @return  ����־�豸�Ѵ��򷵻�true�����򷵻�false��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ06��53��
         */
        virtual bool is_opened() const;

        /**
         * @brief open ����־�豸
         *
         * @param param ��������
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ07��09��
         */
        virtual int32_t open(void* param = NULL);

        /**
         * @brief close �ر���־�豸
         *
         * @param param ��������
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ07��49��
         */
        virtual int32_t close(void* param = NULL);

        /**
         * @brief write д��־
         *
         * @param log_message ��־��Ϣ
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ08��32��
         */
        virtual int32_t write(const struct log_message_t& log_message);

    private:
        /**
         * @brief exec_time_split_policy ����time�ָ���ԣ���������ʱ�����µ���־�ļ�
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ18��31��
         */
        int32_t exec_time_split_policy();

        /**
         * @brief exec_size_split_policy ����size�ָ���ԣ���������ʱ�����µ���־�ļ�
         *
         * @param len ��д�����־�����ַ����ַ���
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ18��44��
         */
        int32_t exec_size_split_policy(size_t len);

        /**
         * @brief get_file_stat ��ȡ��־�ļ����ļ�״̬
         *
         * @param state �ļ�״̬
         *
         * @return  �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ19��19��
         */
        int32_t get_file_stat(struct stat& state) const;

        /**
         * @brief format_log_message ��ʽ����־��Ϣ
         *
         * @param logbuf ��־��Ϣ���ջ�����
         * @param logbufsiz ��־��Ϣ��������С
         * @param log_message ��־��Ϣ�ṹ��
         *
         * @return ���ظ�ʽ������ֽ���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 11ʱ20��34��
         */
        int32_t format_log_message(char* logbuf, int32_t logbufsiz,
                const struct log_message_t& log_message);

    private:
        std::string create_filename_suffix();

        char _file_path[MAX_FILE_PATH_LEN]; /** �ļ�ȫ·����*/
        FILE* _fp;  /** �ļ�ָ��*/
        Mutex _mutex;
		struct ::timeval _create_time;  /** �ļ��Ĵ���ʱ��, ���ڰ�time��־�ָ����, ���ô˳�Ա��ԭ����ͨ��fstat�õ���stat�����޷���ʾ�ļ�����ʱ�䣿*/
        off_t _file_size; /** ��ŵ�ǰ��־�ļ���С*/

    };
}
#endif // _BGCC2_LOG_DEVICE_H_

