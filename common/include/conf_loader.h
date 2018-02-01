/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONF_LOADER_H_
#define _BGCC2_CONF_LOADER_H_

#include <vector>
#include "bgcc_stdint.h"

namespace bgcc {

    class ConfUnit;

    /**
     * @brief �����ļ�������
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��01�� 10ʱ48��10��
     */
    class ConfLoader {
    public:
        /**
         * @brief ����󳤶�
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��01�� 10ʱ46��17��
         */
        static const int32_t MAX_LINE_LEN;

        /**
         * @brief load_conf ���������ļ�
         *
         * @param conf_filename �����ļ���
         *
         * @return �������ݵ�Root;�����س���ʱ����NULL
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��01�� 10ʱ46��48��
         */
        static ConfUnit* load_conf(const char* conf_filename);

    private:
        /**
         * @brief is_white_line �ж�line�Ƿ�Ϊ�հ���----�Կհ׷���ɵ���
         *
         * @param line C����ַ���
         *
         * @return true��ʾlineΪ�հ��У����򷵻�false
         * @see
         * @note ��(line == NULL)ʱ����false
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��01�� 10ʱ45��17��
         */
        static bool is_white_line(const char* line);

        /**
         * @brief is_comment_line �ж�line�Ƿ�Ϊע����----��'#'���ص���
         *
         * @param line C����ַ���
         *
         * @return true��ʾlineΪע���У����򷵻�false
         * @see
         * @note ��(line == NULL)ʱ����false
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��01�� 10ʱ43��22��
         */
        static bool is_comment_line(const char* line);

        static int32_t handle_line(const char* line, ConfUnit* root, ConfUnit*& current);

        static int32_t handle_as_section(const char* line, std::vector<std::string>& paths);

        static int32_t handle_as_item(const char* line, std::string& key, std::string& value);

        static ConfUnit* push_section(ConfUnit* root, const std::vector<std::string>& paths);

        static int32_t push_item(ConfUnit* current, const std::string& key,
                const std::string& value);

    };
}

#endif  //_BGCC2_CONF_LOADER_H_
