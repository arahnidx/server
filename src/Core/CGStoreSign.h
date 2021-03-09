//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGStoreSign.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_STORE_SIGN_H__
#define __CG_STORE_SIGN_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGStoreSign;
//
//////////////////////////////////////////////////////////////////////

class CGStoreSign : public Packet
{
public:
	CGStoreSign() {};
    virtual ~CGStoreSign() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CG_STORE_SIGN; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szBYTE + m_Sign.size(); }

	// get packet name
	string getPacketName() const  { return "CGStoreSign"; }

	// get packet's debug string
	string toString() const ;

	string	getSign() const { return m_Sign; }
	void	setSign(const string& sign) { m_Sign = sign; }

private :
	string	m_Sign;
};


//////////////////////////////////////////////////////////////////////
//
// class CGStoreSignFactory;
//
// Factory for CGStoreSign
//
//////////////////////////////////////////////////////////////////////

class CGStoreSignFactory : public PacketFactory {

public:
	
	// constructor
	CGStoreSignFactory()  {}
	
	// destructor
	virtual ~CGStoreSignFactory()  {}

	
public:
	
	// create packet
	Packet* createPacket()  { return new CGStoreSign(); }

	// get packet name
	string getPacketName() const  { return "CGStoreSign"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_STORE_SIGN; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szBYTE + 80; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGStoreSignHandler;
//
//////////////////////////////////////////////////////////////////////

class CGStoreSignHandler {

public:

	// execute packet's handler
	static void execute(CGStoreSign* pCGStoreSign, Player* pPlayer) ;

};

#endif
