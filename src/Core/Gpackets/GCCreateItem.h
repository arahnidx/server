//////////////////////////////////////////////////////////////////////////////
// Filename    : GCCreateItem.h 
// Written By  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_CREATE_ITEM_H__
#define __GC_CREATE_ITEM_H__

#include "Packet.h"
#include "PacketFactory.h"
#include <list>

//////////////////////////////////////////////////////////////////////////////
// class GCCreateItem;
//////////////////////////////////////////////////////////////////////////////

class GCCreateItem : public Packet 
{
public:
	GCCreateItem() ;

public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_GC_CREATE_ITEM; }
	PacketSize_t getPacketSize() const  
	{ 
		return szObjectID +  // ������ ������Ʈ ID
			szBYTE +         // ������ Ŭ����
			szItemType +     // ������ Ÿ��
			szBYTE + m_OptionType.size() +   // ������ �ɼ�
			szDurability +   // ������ ������
			szSilver +       // ������ �� ���ݷ�
			szGrade +       // ������ ���
			szEnchantLevel + // ������ ��æƮ ����
			szItemNum +      // ������ ����
			szCoordInven +   // ������ X ��ǥ
			szCoordInven;    // ������ Y ��ǥ
	}
	string getPacketName() const  { return "GCCreateItem"; }
	string toString() const ;

public:
	ObjectID_t getObjectID() const  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	BYTE getItemClass() const  { return m_ItemClass; }
	void setItemClass(BYTE ItemClass)  { m_ItemClass = ItemClass; }

	ItemType_t getItemType() const  { return m_ItemType; }
	void setItemType(ItemType_t ItemType)  { m_ItemType = ItemType; }

	int getOptionTypeSize() const  { return m_OptionType.size(); }
	const list<OptionType_t>& getOptionType() const  { return m_OptionType; }
	OptionType_t popOptionType() 
	{
		if (m_OptionType.empty()) return 0;
		OptionType_t optionType = m_OptionType.front();
		m_OptionType.pop_front();
		return optionType;
	}
	void addOptionType(OptionType_t OptionType)  { m_OptionType.push_back( OptionType ); }
	void setOptionType(const list<OptionType_t>& OptionTypes)  { m_OptionType = OptionTypes; }

	Durability_t getDurability() const  { return m_Durability; }
	void setDurability(Durability_t Durability)  { m_Durability = Durability; }

	Silver_t getSilver() const  { return m_Silver; }
	void setSilver(Silver_t silver)  { m_Silver = silver; }

	Grade_t getGrade() const  { return m_Grade; }
	void setGrade(Grade_t silver)  { m_Grade = silver; }

	EnchantLevel_t getEnchantLevel() const  { return m_EnchantLevel; }
	void setEnchantLevel(EnchantLevel_t level)  { m_EnchantLevel = level; }

	ItemNum_t getItemNum() const  { return m_ItemNum; }
	void setItemNum(ItemNum_t num)  { m_ItemNum = num; }

	CoordInven_t getInvenX() const  { return m_InvenX; }
	void setInvenX(CoordInven_t InvenX)  { m_InvenX = InvenX; }

	CoordInven_t getInvenY() const  { return m_InvenY; }
	void setInvenY(CoordInven_t InvenY)  { m_InvenY = InvenY; }

private:
	ObjectID_t     		m_ObjectID;     // ������Ʈ ID
	BYTE           		m_ItemClass;    // ������ Ŭ����
	ItemType_t     		m_ItemType;     // ������ Ÿ��
	list<OptionType_t>  m_OptionType;   // �ɼ� Ÿ��
	Durability_t   		m_Durability;   // ������
	Silver_t       		m_Silver;       // �� ���ݷ�
	Grade_t       		m_Grade;       // ������ ���
	EnchantLevel_t 		m_EnchantLevel; // ��æƮ ����
	ItemNum_t      		m_ItemNum;      // �������� ����
	CoordInven_t   		m_InvenX;       // �κ��丮 X ��ǥ
	CoordInven_t   		m_InvenY;       // �κ��丮 Y ��ǥ
	
};


//////////////////////////////////////////////////////////////////////////////
// class GCCreateItemFactory;
//////////////////////////////////////////////////////////////////////////////

class GCCreateItemFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new GCCreateItem(); }
	string getPacketName() const  { return "GCCreateItem"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_CREATE_ITEM; }
	PacketSize_t getPacketMaxSize() const  
	{ 
		return szObjectID +  // ������ ������Ʈ ID
			szBYTE +         // ������ Ŭ����
			szItemType +     // ������ Ÿ��
			szBYTE + 255 +   // ������ �ɼ�
			szDurability +   // ������ ������
			szSilver +       // ������ �� ���ݷ�
			szGrade +       // ������ ���
			szEnchantLevel + // ������ ��æƮ ����
			szItemNum +      // ������ ����
			szCoordInven +   // ������ X ��ǥ
			szCoordInven;    // ������ Y ��ǥ
	}
};


//////////////////////////////////////////////////////////////////////////////
// class GCCreateItemHandler;
//////////////////////////////////////////////////////////////////////////////

class GCCreateItemHandler 
{
public:
	static void execute(GCCreateItem* pPacket, Player* pPlayer) ;

};

#endif
