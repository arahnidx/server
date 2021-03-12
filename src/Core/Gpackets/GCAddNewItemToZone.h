//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCAddNewItemToZone.h 
// Written By  : elca
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_ADD_NEW_ITEM_TO_ZONE_H__
#define __GC_ADD_NEW_ITEM_TO_ZONE_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"
#include "SubItemInfo.h"
#include "GCAddItemToZone.h"


//////////////////////////////////////////////////////////////////////
//
// class GCAddNewItemToZone;
//
////////////////////////////////////////////////////////////////////

class GCAddNewItemToZone : public GCAddItemToZone {

public :

	GCAddNewItemToZone() ;
	~GCAddNewItemToZone() ;
	
	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GC_ADD_NEW_ITEM_TO_ZONE; }
	
	// get packet's name
	string getPacketName() const  { return "GCAddNewItemToZone"; }

	// get packet's debug string
	string toString() const ;
	
};


//////////////////////////////////////////////////////////////////////
//
// class GCAddNewItemToZoneFactory;
//
// Factory for GCAddNewItemToZone
//
//////////////////////////////////////////////////////////////////////

class GCAddNewItemToZoneFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket()  { return new GCAddNewItemToZone(); }

	// get packet name
	string getPacketName() const  { return "GCAddNewItemToZone"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_ADD_NEW_ITEM_TO_ZONE; }

	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static GCAddNewItemToZonePacketSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const  { return szObjectID + szCoord + szCoord + szBYTE + szItemType + szBYTE + 255 + szDurability + szItemNum + szBYTE +(szObjectID + szBYTE + szItemType + szItemNum + szSlotID)* 12; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCAddNewItemToZoneHandler;
//
//////////////////////////////////////////////////////////////////////

class GCAddNewItemToZoneHandler {

public :

	// execute packet's handler
	static void execute(GCAddNewItemToZone* pPacket, Player* pPlayer) ;

};

#endif
