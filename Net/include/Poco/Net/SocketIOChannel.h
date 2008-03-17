//
// SocketIOChannel.h
//
// $Id: //poco/Main/Data/include/Poco/Net/SocketIOChannel.h#1 $
//
// Library: Net
// Package: IO
// Module:  SocketIOChannel
//
// Definition of the SocketIOChannel class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Net_SocketIOChannel_INCLUDED
#define Net_SocketIOChannel_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/IOChannel.h"
#include "Poco/IOChannelConfig.h"
#include "Poco/Net/Socket.h"
#include "Poco/Net/SocketImpl.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/DatagramSocket.h"


namespace Poco {
namespace Net {


class Net_API SocketIOChannel: public Poco::IOChannel
	/// Wraps a socket into IO channel interface.
	/// Both stream and datagram sockets are supported.
{
public:
	SocketIOChannel(IOChannelConfig* pConfig);
		/// Creates SocketIOChannel.

	~SocketIOChannel();
		/// Destroys SocketIOChannel.

	void open();
		/// Opens SocketIOChannel.

	void close();
		/// Closes SocketIOChannel.
	
	bool isStream();
		/// Returns true if SocketIOChannel currently wraps stream socket.

	bool isDatagram();
		/// Returns true if SocketIOChannel currently wraps datagram socket.

private:
	SocketIOChannel(const SocketIOChannel&);
	const SocketIOChannel& operator=(const SocketIOChannel&);

	void init();

	int readData(char* pReadBuf, int length);
	int readData(char*& pReadBuf);
	int writeData(const char* buffer, int length);

	Poco::Net::Socket& socket();
	Poco::Net::SocketImpl* socketImpl();

	Poco::Net::Socket* _pSocket;
};


//
// inlines
//


inline Poco::Net::Socket& SocketIOChannel::socket()
{
	if (!_pSocket) init();

	return *_pSocket;
}


inline Poco::Net::SocketImpl* SocketIOChannel::socketImpl()
{
	return socket().impl();
}


inline void SocketIOChannel::close()
{
	socketImpl()->close();
	delete _pSocket;
	_pSocket = 0;
}


inline bool SocketIOChannel::isStream()
{
	return Poco::IOChannelConfig::CONNECTION_CHANNEL == config().getType();
}


inline bool SocketIOChannel::isDatagram()
{
	return Poco::IOChannelConfig::CONNECTIONLESS_CHANNEL == config().getType();
}


} } // namespace Poco::Net


#endif // Net_SocketIOChannel_INCLUDED