/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONF_UNIT_H_
#define _BGCC2_CONF_UNIT_H_

#include <string>
#include <map>
#include <vector>
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief ���õ�Ԫ
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��11�� 14ʱ04��23��
     */
    class ConfUnit {
    public:
        typedef std::vector<ConfUnit*>::const_iterator const_iterator;
        typedef std::vector<ConfUnit*>::iterator iterator;

        /**
         * @brief ���õ�Ԫ�����ͱ�ʶ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ04��12��
         */
        enum unit_type_t {
            UT_BOOL,
            UT_INT32,
            UT_INT64,
            UT_DOUBLE,
            UT_STRING,
            UT_ARRAY,
            UT_GROUP
        };

        /**
         * @brief ConfUnit ���캯����ͨ�����ͱ�ʶ����
         *
         * @param type
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ06��20��
         */
        explicit ConfUnit(unit_type_t type);

        /**
         * @brief ConfUnit ���캯��������bool�������õ�Ԫ
         *
         * @param b ��ʼֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ06��42��
         */
        explicit ConfUnit(bool b);

        /**
         * @brief ConfUnit ���캯��������int32_t�������õ�Ԫ
         *
         * @param i ��ʼֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ07��00��
         */
        explicit ConfUnit(int32_t i);

        /**
         * @brief ConfUnit ���캯��������int64_t�������õ�Ԫ
         *
         * @param l ��ʼֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ07��28��
         */
        explicit ConfUnit(int64_t l);

        /**
         * @brief ConfUnit ���캯��������double�������õ�Ԫ
         *
         * @param d ��ʼֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ07��47��
         */
        explicit ConfUnit(double d);

        /**
         * @brief ConfUnit ���캯��������string�������õ�Ԫ
         *
         * @param str C����ַ���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 15ʱ37��00��
         */
        explicit ConfUnit(const char* str);

        /**
         * @brief ConfUnit ���캯��������string�������õ�Ԫ
         *
         * @param str ��ʼֵ
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ08��00��
         */
        explicit ConfUnit(const std::string& str);

        /**
         * @brief ~ConfUnit ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ08��39��
         */
        ~ConfUnit();

        /**
         * @brief get_type ��ȡ���õ�Ԫ����
         *
         * @return ���õ�Ԫ����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ10��18��
         */
        int32_t get_type() const;

        /**
         * @brief is_bool �ж����õ�Ԫ�Ƿ�Ϊbool����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ10��46��
         */
        bool is_bool() const;

        /**
         * @brief is_int32 �ж����õ�Ԫ�Ƿ�Ϊint32����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ11��24��
         */
        bool is_int32() const;

        /**
         * @brief is_int64 �ж����õ�Ԫ�Ƿ�Ϊint64����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ11��47��
         */
        bool is_int64() const;

        /**
         * @brief is_double �ж����õ�Ԫ�Ƿ�Ϊdobule����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ12��06��
         */
        bool is_double() const;

        /**
         * @brief is_string �ж����õ�Ԫ�Ƿ�Ϊstring����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ12��25��
         */
        bool is_string() const;

        /**
         * @brief is_array �ж����õ�Ԫ�Ƿ�Ϊarray����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ12��41��
         */
        bool is_array() const;

        /**
         * @brief is_group �ж����õ�Ԫ�Ƿ�Ϊgroup����
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ12��56��
         */
        bool is_group() const;

        /**
         * @brief to_bool ȡ�����õ�Ԫ�е�boolֵ
         *
         * @return boolֵ
         * @see
         * @note �����õ�Ԫ����bool���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ13��24��
         */
        bool to_bool() const;

        /**
         * @brief to_int32 ȡ�����õ�Ԫ�е�int32ֵ
         *
         * @return int32ֵ
         * @see
         * @note �����õ�Ԫ����int32���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ15��47��
         */
        int32_t to_int32() const;

        /**
         * @brief to_int64 ȡ�����õ�Ԫ�е�int64ֵ
         *
         * @return int64ֵ
         * @see
         * @note �����õ�Ԫ����int32����int64���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ19��22��
         */
        int64_t to_int64() const;

        /**
         * @brief to_double ȡ�����õ�Ԫ�е�doubleֵ
         *
         * @return doubleֵ
         * @see
         * @note �����õ�Ԫ����double��int32��int64���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ21��35��
         */
        double to_double() const;

        /**
         * @brief to_string ȡ�����õ�Ԫ�е�stringֵ
         *
         * @return stringֵ
         * @see
         * @note �����õ�Ԫ����string���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ22��38��
         */
        std::string to_string() const;

        /**
         * @brief set_bool ����bool�������õ�boolֵ
         *
         * @param b ֵ
         * @see
         * @note �����õ�Ԫ����bool���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 15ʱ07��39��
         */
        void set_bool(bool b);

        /**
         * @brief set_int32 ����int32�������õ�int32ֵ
         *
         * @param i ֵ
         * @see
         * @note �����õ�Ԫ����int32���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 15ʱ08��23��
         */
        void set_int32(int32_t i);

        /**
         * @brief set_int64 ����int64�������õ�int64ֵ
         *
         * @param l ֵ
         * @see
         * @note �����õ�Ԫ����int64���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 15ʱ08��52��
         */
        void set_int64(int64_t l);

        /**
         * @brief set_double ����double�������õ�Ԫ��doubleֵ
         *
         * @param d ֵ
         * @see
         * @note �����õ�Ԫ����double���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 15ʱ09��32��
         */
        void set_double(double d);

        /**
         * @brief set_string ����string�������õ�Ԫ��stringֵ
         *
         * @param str ֵ
         * @see
         * @note �����õ�Ԫ����string���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 15ʱ10��07��
         */
        void set_string(const std::string& str);

        /**
         * @brief begin ȡ��array���͵��׵�����
         *
         * @return �׵�����
         * @see
         * @note �����õ�Ԫ����array���ͣ����׳�std::explicit�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ23��53��
         */
        const_iterator begin() const;

        /**
         * @brief end ȡ��array���͵�β������
         *
         * @return β������
         * @see
         * @note �����õ�Ԫ����array���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ24��53��
         */
        const_iterator end() const;

        /**
         * @brief operator[] ȡ����Ӧ�±��ϵ����õ�Ԫָ��
         *
         * @param index �±�
         *
         * @return ���õ�Ԫָ�룬���Ҳ����򷵻�NULL
         * @see
         * @note �����õ�Ԫ����group���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ26��08��
         */
        ConfUnit* operator[](const std::string& index);

        /**
         * @brief push_back ����Ԫ�ز���array��
         *
         * @param punit ��Ԫ��
         *
         * @return ��Ԫ��
         * @see
         * @note �����õ�Ԫ����array���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ27��52��
         */
        ConfUnit* push_back(ConfUnit* punit);

        /**
         * @brief pop_back ��array�е���Ԫ��
         * @see
         * @note �����õ�Ԫ����array���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ29��43��
         */
        void pop_back();

        /**
         * @brief insert ����Ԫ����Ϊ����key����group��
         *
         * @param key ������
         * @param punit ��Ԫ��
         * @see
         * @note �����õ�Ԫ����group���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ30��55��
         */
        void insert(const std::string& key, ConfUnit* punit);

        /**
         * @brief erase ��group��ɾ��������key��Ӧ�����õ�Ԫ
         *
         * @param key ������
         * @see
         * @note �����õ�Ԫ����group���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ32��07��
         */
        void erase(const std::string& key);

        /**
         * @brief clear ���array��group
         * @see
         * @note �����õ�Ԫ����array��group���ͣ����׳�std::exception�쳣
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 14ʱ33��02��
         */
        void clear();

        /**
         * @brief size �������õ�ԪԪ�ظ���
         *
         * @return Ԫ�ظ���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��11�� 19ʱ54��56��
         */
        int32_t size() const;

    private:
        unit_type_t _type;
        union {
            bool b;
            int32_t i;
            int64_t l;
            double d;
        }_union;
        std::string _string;
        std::vector<ConfUnit*> _vector;
        std::map<std::string, ConfUnit*> _map;
    }; // end of class ConfUnit
}

#endif // _BGCC2_CONF_UNIT_H_

