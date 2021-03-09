//--------------------------------------------------------------------------------
// 
// Filename    : GCDeleteInventoryItem.h 
// Written By  : Reiot
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __GC_DELETE_INVENTORY_ITEM_H__
#define __GC_DELETE_INVENTORY_ITEM_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//--------------------------------------------------------------------------------
//
// class GCDeleteInventoryItem;
//
//--------------------------------------------------------------------------------

class GCDeleteInventoryItem : public Packet {

public :

	// constructor
	GCDeleteInventoryItem()  {}
	GCDeleteInventoryItem(ObjectID_t objectID) : m_ObjectID(objectID) {}
    ~GCDeleteInventoryItem() {};


public :
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GC_DELETE_INVENTORY_ITEM; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  
	{ 
		return szObjectID; 
	}

	// get packet name
	string getPacketName() const  { return "GCDeleteInventoryItem"; }
	
	// get packet's debug string
	string toString() const ;

public :

	// get/set object id
	ObjectID_t getObjectID() const  { return m_ObjectID; }
	void setObjectID(ObjectID_t objectID)  { m_ObjectID = objectID; }

private :

	// object id
	ObjectID_t m_ObjectID;

};


//////////////////////////////////////////////////////////////////////
//
// class GCDeleteInventoryItemFactory;
//
// Factory for GCDeleteInventoryItem
//
//////////////////////////////////////////////////////////////////////

class GCDeleteInventoryItemFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket()  { return new GCDeleteInventoryItem(); }

	// get packet name
	string getPacketName() const  { return "GCDeleteInventoryItem"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_DELETE_INVENTORY_ITEM; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const  
	{ 
		return szObjectID; 
	}

};


//////////////////////////////////////////////////////////////////////
//
// class GCDeleteInventoryItemHandler;
//
//////////////////////////////////////////////////////////////////////

class GCDeleteInventoryItemHandler {

public :

	// execute packet's handler
	static void execute(GCDeleteInventoryItem* pPacket, Player* player) ;

};

#endif
