//////////////////////////////////////////////////////////////////////////////
// Filename    : GCMonsterKillQuestStatus.h 
// Written By  : elca@ewestsoft.com
// Description : 
// ����� ���������� ������ ��Ŷ�� ���� Ŭ���� ����
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_MONSTER_KILL_QUEST_STATUS_H__
#define __GC_MONSTER_KILL_QUEST_STATUS_H__

#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class GCMonsterKillQuestStatus;
// ���Ӽ������� Ŭ���̾�Ʈ�� �ڽ��� ����� ������ �˷��ֱ� ���� Ŭ����
//////////////////////////////////////////////////////////////////////////////

class GCMonsterKillQuestStatus : public Packet 
{
public:
	GCMonsterKillQuestStatus() ;
	~GCMonsterKillQuestStatus() ;
	
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_GC_MONSTER_KILL_QUEST_STATUS; }
	PacketSize_t getPacketSize() const  { return szWORD + szWORD + szDWORD; }
	string getPacketName() const  { return "GCMonsterKillQuestStatus"; }
	string toString() const ;

public:
	WORD getQuestID() const  { return m_QuestID; }
	void setQuestID(WORD e)  { m_QuestID = e; }
	
	WORD getCurrentNum() const  { return m_CurrentNum; }
	void setCurrentNum(WORD n)  { m_CurrentNum = n; }

	DWORD getRemainTime() const  { return m_Time; }
	void setRemainTime(DWORD d)  { m_Time = d; }
	
private :
	WORD m_QuestID;
	WORD m_CurrentNum;
	DWORD m_Time;
};


//////////////////////////////////////////////////////////////////////////////
// class GCMonsterKillQuestStatusFactory;
//////////////////////////////////////////////////////////////////////////////

class GCMonsterKillQuestStatusFactory : public PacketFactory 
{
public :
	GCMonsterKillQuestStatusFactory()  {}
	virtual ~GCMonsterKillQuestStatusFactory()  {}
	
public:
	Packet* createPacket()  { return new GCMonsterKillQuestStatus(); }
	string getPacketName() const  { return "GCMonsterKillQuestStatus"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_MONSTER_KILL_QUEST_STATUS; }
	PacketSize_t getPacketMaxSize() const  { return szWORD + szWORD + szDWORD; }
};

//////////////////////////////////////////////////////////////////////////////
// class GCMonsterKillQuestStatusHandler;
//////////////////////////////////////////////////////////////////////////////

class GCMonsterKillQuestStatusHandler 
{
public:
	static void execute(GCMonsterKillQuestStatus* pGCMonsterKillQuestStatus, Player* pPlayer) ;

};

#endif
