/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_PROCESSOR_H_
#define _BGCC_PROCESSOR_H_

#include "shareable.h"
#include "protocol.h"

namespace bgcc {

	/**
	 * @class IProcessor 
	 * @brief �������ӿ�
	 */
	class IProcessor : public Shareable {
		public:
			/**
			 * @brief   ����������
			 */
			virtual ~IProcessor() {}

			virtual int32_t process(char* request,
                    int32_t request_len,
                    SharedPointer<IProtocol> out) = 0;

            virtual std::string get_name() const = 0;

		protected:
			/**
			 * @brief   ���캯������ֱֹ�ӹ���IProcessor����
			 */
			IProcessor() { }
	};

}

#endif
