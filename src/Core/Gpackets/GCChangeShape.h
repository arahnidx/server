//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCChangeShape.h 
// Written By  : elca@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_CHANGE_SHAPE_H__
#define __GC_CHANGE_SHAPE_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"
#include <list>

#define SHAPE_FLAG_QUEST 0x01

//////////////////////////////////////////////////////////////////////
//
// class GCChangeShape;
//
// ���� �������� Ư�� ����ڰ� �������ٴ� ������ Ŭ���̾�Ʈ�� ������ 
// �� ����ϴ� ��Ŷ ��ü�̴�.(CreatureID,X,Y,DIR) �� �����Ѵ�.
//
//////////////////////////////////////////////////////////////////////

class GCChangeShape : public Packet {

public :
	
	// constructor
	GCChangeShape() ;
	
	// destructor
	~GCChangeShape() ;

	
public :
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GC_CHANGE_SHAPE; }
	
	// get packet's body size
	// ����ȭ��, �̸� ���� ������ ����Ѵ�.
	PacketSize_t getPacketSize() const  { return szObjectID + szBYTE + szItemType + szOptionType + szSpeed + szBYTE ; }

	// get packet's name
	string getPacketName() const  { return "GCChangeShape"; }
	
	// get packet's debug string
	string toString() const ;

	// get Object ID 
	ObjectID_t getObjectID() const  { return m_ObjectID; }
	void setObjectID(ObjectID_t objectID)  { m_ObjectID = objectID; }

	// get/set ItemClass
	BYTE getItemClass() const  { return m_ItemClass; }
	void setItemClass(BYTE ItemClass)  { m_ItemClass = ItemClass; }

	// get / set ItemType
	ItemType_t getItemType() const  { return m_ItemType; }
	void setItemType(ItemType_t ItemType)  { m_ItemType = ItemType ; }

	// get / set OptionType
	void setOptionType(OptionType_t optionType)  { m_OptionType = optionType; }
	OptionType_t getOptionType() const  { return m_OptionType; }

	// get / set AttackSpeed
	Speed_t getAttackSpeed() const  { return m_AttackSpeed; }
	void setAttackSpeed(Speed_t AttackSpeed)  { m_AttackSpeed = AttackSpeed; }

	BYTE getFlag() const  { return m_Flag; }
	void setFlag( BYTE flag )  { m_Flag = flag; }

private :

	// ũ��ó ���̵�
	ObjectID_t m_ObjectID;
	
	// Item Class
	BYTE m_ItemClass;

	// Item Type
	ItemType_t m_ItemType;

	// Option Type
	OptionType_t m_OptionType;

	// Attack Speed
	Speed_t m_AttackSpeed;

	BYTE m_Flag;
};


//////////////////////////////////////////////////////////////////////
//
// class GCChangeShapeFactory;
//
// Factory for GCChangeShape
//
//////////////////////////////////////////////////////////////////////

class GCChangeShapeFactory : public PacketFactory {

public :
	
	// constructor
	GCChangeShapeFactory()  {}
	
	// destructor
	virtual ~GCChangeShapeFactory()  {}

	
public :
	
	// create packet
	Packet* createPacket()  { return new GCChangeShape(); }

	// get packet name
	string getPacketName() const  { return "GCChangeShape"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_CHANGE_SHAPE; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szObjectID + szBYTE + szItemType + szOptionType + szSpeed + szBYTE; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCChangeShapeHandler;
//
//////////////////////////////////////////////////////////////////////

class GCChangeShapeHandler {

public :

	// execute packet's handler
	static void execute(GCChangeShape* pGCChangeShape, Player* pPlayer) ;

};

#endif
