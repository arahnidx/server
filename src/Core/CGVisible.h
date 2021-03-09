//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGVisible.h 
// Written By  : crazydog
// Description : ���㳪 ���뿡�� ����������� ���ƿ��������..
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_VISIBLE_H__
#define __CG_VISIBLE_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class CGVisible;
//
//////////////////////////////////////////////////////////////////////

class CGVisible : public Packet {

public:
	CGVisible() {};
    virtual ~CGVisible() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CG_VISIBLE; }
	
	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static CGVisiblePacketSize �� �����ؼ� �����϶�.
	PacketSize_t getPacketSize() const  { return 0; }

	// get packet name
	string getPacketName() const  { return "CGVisible"; }
	
	// get packet's debug string
	string toString() const ;

};


//////////////////////////////////////////////////////////////////////
//
// class CGVisibleFactory;
//
// Factory for CGVisible
//
//////////////////////////////////////////////////////////////////////

class CGVisibleFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new CGVisible(); }

	// get packet name
	string getPacketName() const  { return "CGVisible"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_VISIBLE; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static CGVisiblePacketSize �� �����ؼ� �����϶�.
	PacketSize_t getPacketMaxSize() const  { return 0; }

};


//////////////////////////////////////////////////////////////////////
//
// class CGVisibleHandler;
//
//////////////////////////////////////////////////////////////////////

class CGVisibleHandler {
	
public:

	// execute packet's handler
	static void execute(CGVisible* pPacket, Player* player) ;
};

#endif
