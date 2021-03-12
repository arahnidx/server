//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGSelectPortal.h 
// Written By  : elca@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_SELECT_PORTAL_H__
#define __CG_SELECT_PORTAL_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGSelectPortal;
//
//////////////////////////////////////////////////////////////////////

class CGSelectPortal : public Packet {

public:
	
	// constructor
	CGSelectPortal() ;
	
	// destructor
	~CGSelectPortal() ;

	
public:
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CG_SELECT_PORTAL; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szZoneID; }

	// get packet name
	string getPacketName() const  { return "CGSelectPortal"; }

	// get / set ZoneID
	ObjectID_t getZoneID() const   { return m_ZoneID; }
	void setZoneID(ZoneID_t ZoneID)  { m_ZoneID = ZoneID; }

	// get packet's debug string
	string toString() const ;

private :

	ZoneID_t m_ZoneID;

};


//////////////////////////////////////////////////////////////////////
//
// class CGSelectPortalFactory;
//
// Factory for CGSelectPortal
//
//////////////////////////////////////////////////////////////////////

class CGSelectPortalFactory : public PacketFactory {

public:
	
	// constructor
	CGSelectPortalFactory()  {}
	
	// destructor
	virtual ~CGSelectPortalFactory()  {}

	
public:
	
	// create packet
	Packet* createPacket()  { return new CGSelectPortal(); }

	// get packet name
	string getPacketName() const  { return "CGSelectPortal"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_SELECT_PORTAL; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szZoneID; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGSelectPortalHandler;
//
//////////////////////////////////////////////////////////////////////

class CGSelectPortalHandler {

public:

	// execute packet's handler
	static void execute(CGSelectPortal* pCGSelectPortal, Player* pPlayer) ;

};

#endif
