//--------------------------------------------------------------------------------
// 
// Filename    : CLVersionCheck.h 
// Written By  : reiot@ewestsoft.com
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __CL_VERSION_CHECK_H__
#define __CL_VERSION_CHECK_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//--------------------------------------------------------------------------------
//
// class CLVersionCheck;
//
// Ŭ���̾�Ʈ�� �α��� �������� ���ʿ� �����ϴ� ��Ŷ�̴�.
// ���̵�� �н����尡 ��ȣȭ�Ǿ� �ִ�.
//
//--------------------------------------------------------------------------------

class CLVersionCheck : public Packet {

public:
	CLVersionCheck() {};
    ~CLVersionCheck() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CL_VERSION_CHECK; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szDWORD; }

	// get packet name
	string getPacketName() const  { return "CLVersionCheck"; }
	
	// get packet's debug string
	string toString() const ;

public:

	// get/set Client Version
	DWORD getVersion() const  { return m_Version; }
	void setVersion(DWORD Version)  { m_Version = Version; }

private :

	// Ŭ���̾�Ʈ ����
	DWORD m_Version;
};


//--------------------------------------------------------------------------------
//
// class CLVersionCheckFactory;
//
// Factory for CLVersionCheck
//
//--------------------------------------------------------------------------------

class CLVersionCheckFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new CLVersionCheck(); }

	// get packet name
	string getPacketName() const  { return "CLVersionCheck"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CL_VERSION_CHECK; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const  { return szDWORD; }

};


//--------------------------------------------------------------------------------
//
// class CLVersionCheckHandler;
//
//--------------------------------------------------------------------------------

class CLVersionCheckHandler {

public:

	// execute packet's handler
	static void execute(CLVersionCheck* pPacket, Player* pPlayer) ;

};

#endif
