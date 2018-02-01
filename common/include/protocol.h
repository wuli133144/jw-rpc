/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_PROTOCOL_H_
#define _BGCC_PROTOCOL_H_

#include <string>
#include "shareable.h"
#include "transport.h"
#include "shared_pointer.h"
#include "bgcc_stdint.h"

namespace bgcc {

    /** 
     * @class DataTypeID
     * @brief ���ͱ�ʶ
     */
    enum DataTypeID {
        IDSTOP,
        IDVOID,
        IDBOOL,
        IDBYTE,
        IDINT16,
        IDINT32,
        IDINT64,
        IDFLOAT,
        IDSTR,
        IDBIN,
        IDSTRUCT,
        IDMAP,
        IDSET,
        IDLIST,
        IDFIELD,
        IDSERVICE,
        IDMSG
    };

    /**
     * @class MsgTypeID
     * @brief ��Ϣ���ͱ�ʶ
     */
    enum MsgTypeID {
        CALL = 1,
        REPLY,
        EXCEPTION,
        ONEWAY
    };

    typedef int32_t FieldIDType;
    typedef int32_t SequenceNOType;
    /**
     * @class IProtocol
     * @brief Э����ӿ�
     *
     * �ṩ�������л������ݷ����л��ӿڡ�
     */
    class IProtocol : public Shareable {
        public:
        typedef SharedPointer<ITransport> TransportSharedPointer;

        /**
         * @brief   ����ֵ���л�
         * @param   value �����л��Ĳ���ֵ��
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeBool(const bool value)  = 0;

        /**
         * @brief   8λ�������л�
         * @param   value �����л���8λ����ֵ��
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeByte(const int8_t value) = 0;

        /**
         * @brief   16λ�������л�
         * @param   value �����л���16λ����ֵ��
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeInt16(const int16_t value) = 0;

        /**
         * @brief   32λ�������л�
         * @param   value �����л���32λ����ֵ��
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeInt32(const int32_t value) = 0;

        /**
         * @brief   64λ�������л�
         * @param   value �����л���64λ����ֵ��
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeInt64(const int64_t value) = 0;

        /**
         * @brief   ���������л�
         * @param   value �����л��ĸ�������
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeFloat(const float value) = 0;

        /**
         * @brief   �ַ������л�
         * @param   value �����л����ַ�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeString(const std::string& value) = 0;

        /**
         * @brief   �������������л�
         * @param   value �����л��Ķ��������ݡ�
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeBinary(const void* data, const int32_t size) = 0;

        /**
         * @brief   ��Ϣ���л���ʼ
         * @param   msgName ��Ϣ����
         * @param   msgType ��Ϣ����
         * @param   seqNo   ��Ϣ���к�
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeMessageBegin(
            const std::string& processor_name,
            const std::string& function_name,
            const MsgTypeID msg_type,
            const SequenceNOType seq_no) = 0;

        /**
         * @brief   ��Ϣ���л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeMessageEnd() = 0;

        /**
         * @brief   struct���л���ʼ
         * @param   name set����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeStructBegin(const std::string& name) = 0;

        /**
         * @brief   struct���л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeStructEnd() = 0;

        /**
         * @brief   �����л���ʼ
         * @param   name       ������
         * @param   fieldType �����ͱ�ʶ
         * @param   fieldId   ������
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeFieldBegin(
                const std::string& name,
                const DataTypeID fieldtype,
                const FieldIDType fieldId) = 0;

        /**
         * @brief   �����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeFieldEnd() = 0;

        /**
         * @brief   ���������л�, ���ڱ�ʶһϵ����Ľ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeFieldStop() = 0;

        /**
         * @brief   map���л���ʼ
         * @param   keyType �����ͱ�ʶ
         * @param   valueType ֵ���ͱ�ʶ
         * @param   size Ԫ�ظ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeMapBegin(
                const DataTypeID keyType,
                const DataTypeID valueType,
                const int32_t size) = 0;

        /**
         * @brief   map���л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeMapEnd() = 0;

        /**
         * @brief   list���л���ʼ
         * @param   elemType Ԫ�����ͱ�ʶ
         * @param   size Ԫ�ظ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeListBegin(
                const DataTypeID elemType,
                const int32_t size) = 0;

        /**
         * @brief   list���л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeListEnd() = 0;

        /**
         * @brief   set���л���ʼ
         * @param   elemType Ԫ�����ͱ�ʶ
         * @param   size Ԫ�ظ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeSetBegin(
                const DataTypeID elemType,
                const int32_t size) = 0;

        /**
         * @brief   set���л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t writeSetEnd() = 0;

        /**
         * @brief   ����ֵ�����л�
         * @param   value �����л���õ��Ĳ���ֵ
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readBool(bool& value) = 0;

        /**
         * @brief   8λ���������л�
         * @param   value �����л���õ���8λ����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readByte(int8_t& value) = 0;

        /**
         * @brief   16λ���������л�
         * @param   value �����л���õ���16λ����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readInt16(int16_t& value) = 0;

        /**
         * @brief   32λ���������л�
         * @param   value �����л���õ���32λ����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readInt32(int32_t& value) = 0;

        /**
         * @brief   64λ���������л�
         * @param   value �����л���õ���64λ����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readInt64(int64_t& value) = 0;

        /**
         * @brief   �����������л�
         * @param   value �����л���õ��ĸ�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readFloat(float& value) = 0;

        /**
         * @brief   �ַ��������л�
         * @param   value �����л���õ����ַ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readString(std::string& value) = 0;

        /**
         * @brief   ���������ݷ����л�
         * @param   value �����л���õ��Ķ���������
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readBinary(std::string& value) = 0;

        /**
         * @brief   set�����л���ʼ
         * @param   elemType �����л���õ���setԪ�����ͱ�ʶ
         * @param   size �����л���õ���setԪ�ظ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readSetBegin(DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   set�����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readSetEnd() = 0;

        /**
         * @brief   list�����л���ʼ
         * @param   elemType �����л���õ���listԪ�����ͱ�ʶ
         * @param   size �����л���õ���listԪ�ظ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readListBegin(DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   list�����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readListEnd() = 0;

        /**
         * @brief   map�����л���ʼ
         * @param   keyType �����л���õ���map�����ͱ�ʶ
         * @param   valueType �����л���õ���mapֵ���ͱ�ʶ
         * @param   size �����к�õ���Ԫ�ظ���
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readMapBegin(
                DataTypeID& keyType,
                DataTypeID& valueType,
                int32_t& size) = 0;

        /**
         * @brief   map�����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readMapEnd() = 0;

        /**
         * @brief   struct�����л���ʼ
         * @param   name �����л���õ���struct����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readStructBegin(std::string& name) = 0;

        /**
         * @brief   struct�����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readStructEnd() = 0;

        /**
         * @brief   ��Ϣ�����л���ʼ
         * @param   msgName �����л���õ�����Ϣ����
         * @param   msgType �����л���õ�����Ϣ����
         * @param   seqNO �����л��õ�����Ϣ���к�
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readMessageBegin(
                std::string& msgName,
                MsgTypeID& msgType,
                SequenceNOType& seqNO) = 0;

        /**
         * @brief   ��Ϣ�����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readMessageEnd() = 0;

        /**
         * @brief   �����л���ʼ
         * @param   name �����л���õ���������
         * @param   field_type �����л���õ��������ͱ�ʶ
         * @param   field_id ������
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readFieldBegin(
                std::string& name,
                DataTypeID& fieldType,
                FieldIDType& fieldID) = 0;

        /**
         * @brief   �����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t readFieldEnd() = 0;

        /**
         * @brief   ��ȡ��Э������Ӧ�ĵײ㴫�������ָ�����
         * @return  ���������ָ�����
         */
        virtual TransportSharedPointer getTransport() = 0;

        /**
         * @brief   ���ñ�Э������Ӧ�ĵײ㴫�������ָ�����
         * @param   transport �����õĴ��������ָ�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t setTransport(TransportSharedPointer transport) = 0;

        /**
         * @brief   �Թ�ָ�����͵�����
         * @param   dataTypeID���Թ����������ͱ�ʶ
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         */
        virtual int32_t skip(DataTypeID dataTypeID) = 0;

        ///////////////////////////////////////////////////////
        /**
         * @brief   ����ֵ�����л�
         * @param   value �����л���õ��Ĳ���ֵ
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readBool(char* request, int32_t request_len, bool& value) = 0;

        /**
         * @brief   8λ���������л�
         * @param   value �����л���õ���8λ����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readByte(char* request, int32_t request_len, int8_t& value) = 0;

        /**
         * @brief   16λ���������л�
         * @param   value �����л���õ���16λ����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readInt16(char* request, int32_t request_len, int16_t& value) = 0;

        /**
         * @brief   32λ���������л�
         * @param   value �����л���õ���32λ����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readInt32(char* request, int32_t request_len, int32_t& value) = 0;

        /**
         * @brief   64λ���������л�
         * @param   value �����л���õ���64λ����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readInt64(char* request, int32_t request_len, int64_t& value) = 0;

        /**
         * @brief   �����������л�
         * @param   value �����л���õ��ĸ�����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readFloat(char* request, int32_t request_len, float& value) = 0;

        /**
         * @brief   �ַ��������л�
         * @param   value �����л���õ����ַ���
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readString(char* request, int32_t request_len, std::string& value) = 0;

        /**
         * @brief   ���������ݷ����л�
         * @param   value �����л���õ��Ķ���������
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readBinary(char* request, int32_t request_len, std::string& value) = 0;

        /**
         * @brief   set�����л���ʼ
         * @param   elemType �����л���õ���setԪ�����ͱ�ʶ
         * @param   size �����л���õ���setԪ�ظ���
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readSetBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   set�����л�����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readSetEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   list�����л���ʼ
         * @param   elemType �����л���õ���listԪ�����ͱ�ʶ
         * @param   size �����л���õ���listԪ�ظ���
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readListBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   list�����л�����
         * @return  �ɹ�ʱ����0������ʱ���ش����롣
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readListEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   map�����л���ʼ
         * @param   keyType �����л���õ���map�����ͱ�ʶ
         * @param   valueType �����л���õ���mapֵ���ͱ�ʶ
         * @param   size �����к�õ���Ԫ�ظ���
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readMapBegin(char* request, int32_t request_len, 
                DataTypeID& keyType,
                DataTypeID& valueType,
                int32_t& size) = 0;

        /**
         * @brief   map�����л�����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readMapEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   struct�����л���ʼ
         * @param   name �����л���õ���struct����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readStructBegin(char* request, int32_t request_len, std::string& name) = 0;

        /**
         * @brief   struct�����л�����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readStructEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   ��Ϣ�����л���ʼ
         * @param   msgName �����л���õ�����Ϣ����
         * @param   msgType �����л���õ�����Ϣ����
         * @param   seqNO �����л��õ�����Ϣ���к�
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readMessageBegin(char* request, int32_t request_len, 
                std::string& msgName,
                MsgTypeID& msgType,
                SequenceNOType& seqNO) = 0;

        /**
         * @brief   ��Ϣ�����л�����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readMessageEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   �����л���ʼ
         * @param   name �����л���õ���������
         * @param   field_type �����л���õ��������ͱ�ʶ
         * @param   field_id ������
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readFieldBegin(char* request, int32_t request_len, 
                std::string& name,
                DataTypeID& fieldType,
                FieldIDType& fieldID) = 0;

        /**
         * @brief   �����л�����
         * @return  �������ĵ�request���ֽ���������ʱ����-1
         */
        virtual int32_t readFieldEnd(char* request, int32_t request_len) = 0;
    };

}

#endif
