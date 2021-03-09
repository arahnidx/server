////////////////////////////////////////////////////////////////////////////////
// Filename    : CGTradeRemoveItem.h 
// Written By  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////

#ifndef __CG_TRADE_REMOVE_ITEM_H__
#define __CG_TRADE_REMOVE_ITEM_H__

#include "Packet.h"
#include "PacketFactory.h"

////////////////////////////////////////////////////////////////////////////////
//
// class CGTradeRemoveItem;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradeRemoveItem : public Packet 
{
public:
    CGTradeRemoveItem() {};
    virtual ~CGTradeRemoveItem() {};
	void read(SocketInputStream & iStream) ;
	void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_CG_TRADE_REMOVE_ITEM; }
	PacketSize_t getPacketSize() const  { return szObjectID*2; }
	string getPacketName() const  { return "CGTradeRemoveItem"; }
	string toString() const ;
	
public:
	ObjectID_t getTargetObjectID() const  { return m_TargetObjectID; }
	void setTargetObjectID(ObjectID_t id)  { m_TargetObjectID = id; }

	ObjectID_t getItemObjectID() const  { return m_ItemObjectID; }
	void setItemObjectID(ObjectID_t id)  { m_ItemObjectID = id; }

private:
	ObjectID_t m_TargetObjectID; // ��ȯ�� ���ϴ� ������ ObjectID
	ObjectID_t m_ItemObjectID;   // ��ȯ ����Ʈ�� �߰��� �������� OID

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGTradeRemoveItemFactory;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradeRemoveItemFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGTradeRemoveItem(); }
	string getPacketName() const  { return "CGTradeRemoveItem"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_TRADE_REMOVE_ITEM; }
	PacketSize_t getPacketMaxSize() const  { return szObjectID*2; }
};


////////////////////////////////////////////////////////////////////////////////
//
// class CGTradeRemoveItemHandler;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradeRemoveItemHandler 
{
public:
	static void execute(CGTradeRemoveItem* pPacket, Player* player) ;
	static void executeSlayer(CGTradeRemoveItem* pPacket, Player* player) ;
	static void executeVampire(CGTradeRemoveItem* pPacket, Player* player) ;
	static void executeOusters(CGTradeRemoveItem* pPacket, Player* player) ;
	static void executeError(CGTradeRemoveItem* pPacket, Player* player, BYTE ErrorCode) ;
};

#endif
