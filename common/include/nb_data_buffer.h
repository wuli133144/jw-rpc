/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_NB_DATA_H_
#define _BGCC2_NB_DATA_H_

#include <string>
#include "shareable.h"
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief �����ֽ������ݻ�����
     * @see
     * @note ���̰߳�ȫ
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��05��30�� 20ʱ01��30��
     */
    class NBDataBuffer : public Shareable {
    public:
        /**
         * @brief NBDataBuffer ���캯��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ02��12��
         */
        NBDataBuffer();

        /**
         * @brief ~NBDataBuffer ��������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ02��18��
         */
        ~NBDataBuffer();

        /**
         * @brief append_bool �򻺳�����׷�Ӳ���ֵ��
         * ��bΪtrueʱ��׷��һ���ֽڵ�1��Ϊfalseʱ��׷��һ���ֽڵ�0
         *
         * @param value ��׷�ӵĲ���ֵ
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ02��46��
         */
        int32_t append_bool(bool b);

        /**
         * @brief append_int8 �򻺳�����׷��8λ������
         *
         * @param i8 ��׷�ӵ�8λ����
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ04��19��
         */
        int32_t append_int8(int8_t i8);

        /**
         * @brief append_int16 �򻺳�����׷��16λ������
         *
         * @param i16 ��׷�ӵ�16λ����
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ05��35��
         */
        int32_t append_int16(int16_t i16);

        /**
         * @brief append_int32 �򻺳�����׷��32λ������
         *
         * @param i32 ��׷�ӵ�32λ����
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ06��09��
         */
        int32_t append_int32(int32_t i32);

        /**
         * @brief append_int64 �򻺳�����׷��64λ������
         *
         * @param i64 ��׷�ӵ�64λ����
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ06��46��
         */
        int32_t append_int64(int64_t i64);

        /**
         * @brief append_float �򻺳�����׷�Ӹ�����
         *
         * @param f ��׷�ӵĸ�����
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ07��22��
         */
        int32_t append_float(float f);

        /**
         * @brief append_string �򻺳�����׷��4���ֽڵ��ַ������ȼ��ַ���
         *
         * @param str ��׷�ӵ��ַ���
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ08��08��
         */
        int32_t append_string(const std::string& str);

        /**
         * @brief append_binary �򻺳�����׷�Ӷ��������ݳ��ȼ�����������
         *
         * @param buffer ��׷�ӵĶ����������׵�ַ
         * @param buflen ��׷�ӵĶ��������ݳ���
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ09��13��
         */
        int32_t append_binary(const void* buffer, int32_t buflen);

        /**
         * @brief append �򻺳�����׷�����ݣ���׷�����ݵĳ��ȣ�
         *
         * @param buffer ��׷�ӵĶ����������׵�ַ
         * @param buflen ��׷�ӵĶ��������ݳ���
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ10��11��
         */
        int32_t append(const void* buffer, int32_t buflen);

        /**
         * @brief get_data �����������ݸ��Ƶ���ʱ����
         *
         * @param ppdata ���ݵ��׵�ַ
         * @param size ���ڽ������ݵ��ֽ���
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note ����������free���ص�����
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ11��23��
         */
        int32_t get_data(void** ppdata, int32_t& size);

        /**
         * @brief get_data_copy 
         *
         * @param ppdata ���ڴ�����ݵ��׵�ַ�������߸����ͷſռ�
         * @param size ���ڴ����ʱ�����ֽ���
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ15��00��
         */
        int32_t get_data_copy(void** ppdata, int32_t& size);

        /**
         * @brief clear ��ջ���������
         *
         * @param keep_allocted_mem �������ڴ汣����־��Ĭ�ϲ�����
         *
         * @return �ɹ�����0�����򷵻ش�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ17��37��
         */
        int32_t clear(bool keep_allocted_mem = false);

    protected:
        /**
         * @brief NBDataBuffer ���ÿ������캯��
         *
         * @param NBDataBuffer
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ22��04��
         */
        NBDataBuffer(const NBDataBuffer&);

        /**
         * @brief operator= ���ø��������
         *
         * @param NBDataBuffer
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 20ʱ22��18��
         */
        NBDataBuffer& operator=(const NBDataBuffer&);

    private:
        int32_t _size;
        int32_t _maxsize;
        void* _data;
    }; // end of class NBDataBuffer

}

#endif // _BGCC2_NB_DATA_H_

