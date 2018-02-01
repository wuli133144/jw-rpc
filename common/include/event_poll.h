/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_EVENT_POLL_H_
#define _BGCC2_EVENT_POLL_H_

#ifndef _WIN32

#include <sys/epoll.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXNFD 10000

namespace bgcc {

    /**
     * @brief �¼����ͱ�ʶ
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��14�� 20ʱ02��50��
     */
    enum {
        EVENT_NONE  = 0x0,  /** ���¼�*/
        EVENT_READ  = 0x1,  /** ���¼�*/
        EVENT_WRITE = 0x2,  /** д�¼�*/
        EVENT_ERROR = 0x4   /** �����¼�*/
    };

    class EventLoop;    /** ǰ������*/

    /**
     * @brief  �¼�����ص���������
     *
     * @param el �¼�ѭ������
     * @param fd �ļ�������
     * @param arg ����
     *
     * @return 
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��14�� 20ʱ01��17��
     */
    typedef void (*callback_func_t)(EventLoop* el, int32_t fd, void* arg);

    /**
     * @brief ��װ�¼����¼�������
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��14�� 20ʱ00��59��
     */
    struct Event {
        /**
         * @brief Event �¼���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��14�� 20ʱ04��59��
         */
        Event() :
            fd(-1),
            mask(EVENT_NONE),
            read_cb(NULL),
            write_cb(NULL),
            error_cb(NULL),
            read_cb_arg(NULL),
            write_cb_arg(NULL),
            error_cb_arg(NULL) {
            }

        int32_t fd; /** �¼���Ӧ��fd*/
        uint32_t mask;  /** �¼���ʶλ*/
        callback_func_t read_cb;    /** ���ص�*/
        callback_func_t write_cb;   /** д�ص�*/
        callback_func_t error_cb;   /** ����ص�*/
        void* read_cb_arg;
        void* write_cb_arg;
        void* error_cb_arg;
    };

    /**
     * @brief �¼�ѭ��
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��06��14�� 20ʱ05��36��
     */
    class EventLoop {
    public:
        /**
         * @brief EventLoop ���캯��
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��14�� 20ʱ19��50��
         */
        EventLoop();

        /**
         * @brief create �����ڲ�epoll
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��14�� 20ʱ19��59��
         */
        int32_t create();
        int32_t destroy();

        int32_t add_event(Event* event);
        int32_t del_event(Event* event);

        int32_t loop();
        int32_t unloop();
        bool is_stopped() const;
    private:
        enum state_t {
            S_UNINIT,
            S_INIT,
            S_LOOP,
            S_STOP,
            S_DESTROYED
        };
    private:
        state_t _state;
        mutable bool _stopped;
        int32_t _epfd;
        struct epoll_event _ep_events[MAXNFD];
        Event _events[MAXNFD];
    };
}

#endif

#endif // _BGCC2_EVENT_POLL_H_

