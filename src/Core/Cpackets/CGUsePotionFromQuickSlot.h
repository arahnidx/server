//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGUsePotionFromQuickSlot.h 
// Written By  : reiot@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_USE_POTION_FROM_QUICKSLOT_H__
#define __CG_USE_POTION_FROM_QUICKSLOT_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class CGUsePotionFromQuickSlot;
//
//////////////////////////////////////////////////////////////////////

class CGUsePotionFromQuickSlot : public Packet {
public:

	// constructor
	CGUsePotionFromQuickSlot() ;

	// destructor
	~CGUsePotionFromQuickSlot() ;

public:
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CG_USE_POTION_FROM_QUICKSLOT; }
	
	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static CGUsePotionFromQuickSlotPacketSize �� �����ؼ� �����϶�.
	PacketSize_t getPacketSize() const  { return szObjectID + szSlotID; }

	// get packet name
	string getPacketName() const  { return "CGUsePotionFromQuickSlot"; }
	
	// get packet's debug string
	string toString() const ;
	
public:

	// get / set ObjectID
	ObjectID_t getObjectID() const  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	// get / set QuickSlotID
	SlotID_t getSlotID() const  { return m_SlotID; }
	void setSlotID(SlotID_t SlotID)  { m_SlotID = SlotID; }


private :
	
	// ObjectID
	ObjectID_t m_ObjectID;

	// QuickSlot�� ID
	SlotID_t m_SlotID;

};


//////////////////////////////////////////////////////////////////////
//
// class CGUsePotionFromQuickSlotFactory;
//
// Factory for CGUsePotionFromQuickSlot
//
//////////////////////////////////////////////////////////////////////

class CGUsePotionFromQuickSlotFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new CGUsePotionFromQuickSlot(); }

	// get packet name
	string getPacketName() const  { return "CGUsePotionFromQuickSlot"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_USE_POTION_FROM_QUICKSLOT; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static CGUsePotionFromQuickSlotPacketSize �� �����ؼ� �����϶�.
	PacketSize_t getPacketMaxSize() const  { return szObjectID + szSlotID; }

};


//////////////////////////////////////////////////////////////////////
//
// class CGUsePotionFromQuickSlotHandler;
//
//////////////////////////////////////////////////////////////////////

class CGUsePotionFromQuickSlotHandler {
	
public:

	// execute packet's handler
	static void execute(CGUsePotionFromQuickSlot* pPacket, Player* player) ;
};

#endif
