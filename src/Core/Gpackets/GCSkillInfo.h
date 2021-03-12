//--------------------------------------------------------------------------------
// 
// Filename    : GCSkillInfo.h 
// Written By  : Reiot
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __GC_SKILL_INFO_H__
#define __GC_SKILL_INFO_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"
#include "PCSkillInfo.h"
#include "SlayerSkillInfo.h"
#include "VampireSkillInfo.h"
#include "Assert.h"

//--------------------------------------------------------------------------------
//
// class GCSkillInfo;
//
// Ŭ���̾�Ʈ�� ���� ������ �����ؼ� CGConnect ��Ŷ�� ������, ���� ������ ũ��ó��
// ���� �������� �ε��ؼ� ���� �� �غ� �ϰ� �ȴ�. �״��� PC�� ������ ����,
// �׸��� �� ������ GCSkillInfo�� ��Ƽ� Ŭ���̾�Ʈ�� �����ϰ� �ȴ�.
//
//--------------------------------------------------------------------------------

class GCSkillInfo : public Packet {

public :

	// constructor
	GCSkillInfo() ;

	// destructor
	~GCSkillInfo() ;
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GC_SKILL_INFO; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const ;

	// get packet name
	string getPacketName() const  { return "GCSkillInfo"; }
	
	// get packet's debug string
	string toString() const ;

//--------------------------------------------------
// methods
//--------------------------------------------------
public :

	// get / set PCType
	BYTE getPCType() const  { return m_PCType; }
	void setPCType(BYTE PCType)  { m_PCType = PCType; }

    // add / delete / clear Skill List
	void addListElement(PCSkillInfo* pPCSkillInfo)  { m_pPCSkillInfoList.push_back(pPCSkillInfo); }
	
	// ClearList
	void clearList()  { m_pPCSkillInfoList.clear(); }
	
	// pop front Element in Status List
	PCSkillInfo* popFrontListElement() 
	{
		PCSkillInfo* TempPCSkillInfo = m_pPCSkillInfoList.front(); m_pPCSkillInfoList.pop_front(); return TempPCSkillInfo;
	}

private :

	BYTE m_PCType;

	//---------------------------------------------------------
	// PC Skill Information
	// SlayerSkillInfo �Ǵ� VampireSkillInfo �� ����Ѵ�.
	//---------------------------------------------------------
	list<PCSkillInfo *> m_pPCSkillInfoList;

};


//--------------------------------------------------------------------------------
//
// class GCSkillInfoFactory;
//
// Factory for GCSkillInfo
//
//--------------------------------------------------------------------------------

class GCSkillInfoFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket()  { return new GCSkillInfo(); }

	// get packet name
	string getPacketName() const  { return "GCSkillInfo"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_SKILL_INFO; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCSkillInfoPacketMaxSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const  
	{ 
		return SlayerSkillInfo::getMaxSize();
	}

};


//--------------------------------------------------------------------------------
//
// class GCSkillInfoHandler;
//
//--------------------------------------------------------------------------------

class GCSkillInfoHandler {

public :

	// execute packet's handler
	static void execute(GCSkillInfo* pPacket, Player* pPlayer) ;

};

#endif
