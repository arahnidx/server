//////////////////////////////////////////////////////////////////////////////
// Filename    : CGUseItemFromGQuestInventory.h 
// Written By  : excel96
// Description : 
// �κ��丮 ���� �������� ����� ��, Ŭ���̾�Ʈ�� X, Y �� ObjectID��
// ������ ������ Ŭ������ ����, ������ �̿� �´� �ڵ带 ó���Ѵ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __CG_USE_ITEM_FROM_GQUEST_INVENTORY_H__
#define __CG_USE_ITEM_FROM_GQUEST_INVENTORY_H__

#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class CGUseItemFromGQuestInventory;
//////////////////////////////////////////////////////////////////////////////

class CGUseItemFromGQuestInventory : public Packet 
{
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_CG_USE_ITEM_FROM_GQUEST_INVENTORY; }
	PacketSize_t getPacketSize() const  { return szBYTE; }
	string getPacketName() const  { return "CGUseItemFromGQuestInventory"; }
	string toString() const ;
	
public:
	BYTE getIndex() const  { return m_Index; }
	void setIndex(BYTE Index)  { m_Index = Index; }

private:
	BYTE   m_Index; // �������� index
};


//////////////////////////////////////////////////////////////////////////////
// class CGUseItemFromGQuestInventoryFactory;
//////////////////////////////////////////////////////////////////////////////

class CGUseItemFromGQuestInventoryFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGUseItemFromGQuestInventory(); }
	string getPacketName() const  { return "CGUseItemFromGQuestInventory"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_USE_ITEM_FROM_GQUEST_INVENTORY; }
	PacketSize_t getPacketMaxSize() const  { return szBYTE; }
};


//////////////////////////////////////////////////////////////////////////////
// class CGUseItemFromGQuestInventoryHandler;
//////////////////////////////////////////////////////////////////////////////

class GQuestInventory;
class Item;

class CGUseItemFromGQuestInventoryHandler 
{
public:
	static void execute(CGUseItemFromGQuestInventory* pPacket, Player* pPlayer) ;
};

#endif
