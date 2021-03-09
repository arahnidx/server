//////////////////////////////////////////////////////////////////////
// 
// Filename    : DatagramPacket.h 
// Written By  : reiot@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __DATAGRAM_PACKET_H__
#define __DATAGRAM_PACKET_H__

// include files
#include "Packet.h"
#include "Datagram.h"
#include "SocketAPI.h"


//////////////////////////////////////////////////////////////////////
//
// class DatagramPacket;
//
// �������� UDP ��ſ� ���Ǵ� ��Ŷ�� ���̽� Ŭ�����̴�.
// �⺻������ �� ��Ŷ���� ���� ���� �ּ�(address)�� ��Ʈ(port)�� ����
// �ϰ� �־�� �ϸ�, Datagram�� �а� ���� �޽�带 override �ؾ� �ϱ�
// ������ ���ԵǾ���.
//
//////////////////////////////////////////////////////////////////////

class DatagramPacket : public Packet {
	
public :
	
	// destructor
	virtual ~DatagramPacket ()  {}

	// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
	// �����ͱ׷� ��Ŷ�� TCP �������� ���۵Ǿ� �Դٸ� �������� ������ �����Ѵ�.
	virtual void read (SocketInputStream & iStream)  
	{ 
		throw ProtocolException("datagram packet from TCP socket"); 
	}

	// Datagram ��ü���� �����͸� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
	virtual void read (Datagram & iDatagram)  = 0;
	
	// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
	// �����ͱ׷� ��Ŷ�� TCP �������� ����� �� ����.
	virtual void write (SocketOutputStream & oStream) const 
	{ 
		throw Error("cannot write datagram-packet to TCP-socket-stream"); 
	}

	// Datagram ��ü�� ��Ŷ�� ���̳ʸ� �̹����� ������.
	virtual void write (Datagram & oDatagram) const  = 0;
	
	// execute packet's handler
	virtual void execute (Player* pPlayer)  = 0;
	
	// get packet's DatagramPacketID	
	virtual PacketID_t getPacketID () const  = 0;

	// get packet's body size
	virtual PacketSize_t getPacketSize () const  = 0;

	// get packet's name
	virtual string getPacketName () const  = 0;
	
	// get packet's debug string
	virtual string toString () const  = 0;

	// get/set host
	string getHost () const  { return m_Host; }
	void setHost (const string& host)  { m_Host = host; }

	// get/set port
	uint getPort () const  { return m_Port; }
	void setPort (uint port)  { m_Port = port; }
	

protected :

	// sender's host
	string m_Host;

	// sender's port
	uint m_Port;
	
};

#endif
