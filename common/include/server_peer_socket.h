/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SERVERPEERSOCKET_H_
#define _BGCC_SERVERPEERSOCKET_H_

#ifdef _WIN32
    #include <winsock.h>
#else
    #include <sys/socket.h>
#endif

#include "socket_base.h"
#include "shared_pointer.h"
#include "peer_info.h"

namespace bgcc {
    /**
	 * @class ServerSocket 
	 * @brief server socket�࣬�̳�Socket�� 
	*/
	class ServerPeerSocket : public Socket {
    public:
        /**
		 * @brief   �Զ�socket������Ϣ����������socket
		 * @param   socket socketID
		 * @return  ��
		 */
		ServerPeerSocket(SOCKET socket);
        ~ServerPeerSocket() {
        }
        /**
		 * @brief   ��ʼ���Զ���Ϣ����󡢻�ȡ�Զ�������Ϣ
		 * @return  �ɹ�����0��ʧ�ܷ��ش�����
		 */
        int InitPeerInfo();
        /**
		 * @brief   ���ضԶ���Ϣ����
		 * @return  �Զ���Ϣ����
		 */
        SharedPointer<PeerInfo> GetPeerInfo();
    private:
        
        SharedPointer<PeerInfo>  _peerinfo;
	};

}

#endif //_BGCC_SERVERPEERSOCKET_H_

