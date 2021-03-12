//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCSkillToObjectOK6.h 
// Written By  : elca@ewestsoft.com
// Description : ����� ���������� ������ ��Ŷ�� ���� Ŭ���� ����
// 				����� ���� �е��� ������ ��Ŷ
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_SKILL_TO_OBJECT_OK_6_H__
#define __GC_SKILL_TO_OBJECT_OK_6_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "ModifyInfo.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCSkillToObjectOK6;
//
// ���Ӽ������� Ŭ���̾�Ʈ�� �ڽ��� ����� ������ �˷��ֱ� ���� Ŭ����
//
//////////////////////////////////////////////////////////////////////

class GCSkillToObjectOK6 : public ModifyInfo {

public :
	
	// constructor
	GCSkillToObjectOK6() ;
	
	// destructor
	~GCSkillToObjectOK6() ;

	
public :
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GC_SKILL_TO_OBJECT_OK_6; }
	
	// get packet's body size
	// ����ȭ��, �̸� ���� ������ ����Ѵ�.
	PacketSize_t getPacketSize() const  { return szCoord*2 + szSkillType + szDuration + szBYTE + ModifyInfo::getPacketSize(); }

	// get packet's name
	string getPacketName() const  { return "GCSkillToObjectOK6"; }
	
	// get packet's debug string
	string toString() const ;

	// get / set ObjectID
	Coord_t getX() const  { return m_X;}
	Coord_t getY() const  { return m_Y;}
	void setXY(Coord_t X, Coord_t Y)  { m_X = X; m_Y = Y;}
		

	// get / set SkillType
	SkillType_t getSkillType() const  { return m_SkillType; }
	void setSkillType(SkillType_t SkillType)  { m_SkillType = SkillType; }

	// get / set Duration
	Duration_t getDuration() const  { return m_Duration; }
	void setDuration(Duration_t Duration)  { m_Duration = Duration; }
	
	// get / set CEffectID 
//	CEffectID_t getCEffectID() const  { return m_CEffectID; }
//	void setCEffectID(CEffectID_t e)  { m_CEffectID = e; }

	BYTE getGrade() const  { return m_Grade; } 
	void setGrade( BYTE grade )  { m_Grade = grade; }

private :

	// origin X, Y	
	Coord_t m_X, m_Y;

	// SkillType
	SkillType_t m_SkillType;

	// Duration
	Duration_t m_Duration;

	// CEffectID
//	CEffectID_t m_CEffectID;

	BYTE m_Grade;
};


//////////////////////////////////////////////////////////////////////
//
// class GCSkillToObjectOK6Factory;
//
// Factory for GCSkillToObjectOK6
//
//////////////////////////////////////////////////////////////////////

class GCSkillToObjectOK6Factory : public PacketFactory {

public :
	
	// constructor
	GCSkillToObjectOK6Factory()  {}
	
	// destructor
	virtual ~GCSkillToObjectOK6Factory()  {}

	
public :
	
	// create packet
	Packet* createPacket()  { return new GCSkillToObjectOK6(); }

	// get packet name
	string getPacketName() const  { return "GCSkillToObjectOK6"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_SKILL_TO_OBJECT_OK_6; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szCoord*2+ szSkillType + szDuration + szBYTE + ModifyInfo::getPacketMaxSize(); }

};


//////////////////////////////////////////////////////////////////////
//
// class GCSkillToObjectOK6Handler;
//
//////////////////////////////////////////////////////////////////////

class GCSkillToObjectOK6Handler {

public :

	// execute packet's handler
	static void execute(GCSkillToObjectOK6* pGCSkillToObjectOK6, Player* pPlayer) ;

};

#endif
