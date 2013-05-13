#ifndef ARG3_NET_SOCKETFACTORY_H
#define ARG3_NET_SOCKETFACTORY_H
#include <memory>

#ifndef THIN

#include "bufferedsocket.h"

namespace arg3
{
    namespace net
    {
        class BufferedSocket;

        /* factory class to control sockets in a server */
        class SocketFactory
        {
        public:
            /* creates a buffered socket from a raw socket */
            virtual std::shared_ptr<BufferedSocket> createSocket(SOCKET sock, const sockaddr_in &addr)= 0;
        };

        /* default implementation of a socket factory */
        class DefaultSocketFactory : public SocketFactory
        {
        public:
            virtual std::shared_ptr<BufferedSocket> createSocket(SOCKET sock, const sockaddr_in &addr);
        };

        /* default factory instance */
        extern DefaultSocketFactory defaultSocketFactory;
    }
}

#endif
#endif
