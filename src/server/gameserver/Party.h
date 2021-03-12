//////////////////////////////////////////////////////////////////////////////
// Filename    : Party.h
// Written by  : excel96
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __PARTY_H__
#define __PARTY_H__

#include "Creature.h"
#include "Mutex.h"
#include "ModifyInfo.h"
#include "Mutex.h"
#include <unordered_map>
#include <list>

// ��Ƽ�� �ִ� ũ��
const int PARTY_MAX_SIZE = 6;

//////////////////////////////////////////////////////////////////////////////
// forward declaration
//////////////////////////////////////////////////////////////////////////////
class Packet;
class GCPartyJoined;
class Creature;
class MonsterCorpse;

//////////////////////////////////////////////////////////////////////////////
// class PartyInviteInfo
//////////////////////////////////////////////////////////////////////////////

class PartyInviteInfo
{
public:
	PartyInviteInfo() { m_HostName = ""; m_GuestName = ""; }
	~PartyInviteInfo() {}

public:
	string getHostName(void) const { return m_HostName; }
	void setHostName(const string& name) { m_HostName = name; }

	string getGuestName(void) const { return m_GuestName; }
	void setGuestName(const string& name) { m_GuestName = name; }

public:
	string toString(void) const ;

protected:
	string m_HostName;
	string m_GuestName;
};


//////////////////////////////////////////////////////////////////////////////
// class PartyInviteInfoManager
//////////////////////////////////////////////////////////////////////////////

class PartyInviteInfoManager
{
public:
	PartyInviteInfoManager() ;
	~PartyInviteInfoManager() ;

public:
	bool hasInviteInfo(const string& HostName) ;
	bool canInvite(Creature* pHost, Creature* pGuest) ;
	bool isInviting(Creature* pHost, Creature* pGuest) ;
	void initInviteInfo(Creature* pHost, Creature* pGuest) ;
	void cancelInvite(Creature* pHost, Creature* pGuest) ;
	void cancelInvite(Creature* pCreature) ;

public:
	bool addInviteInfo(PartyInviteInfo* pInfo) ;
	void deleteInviteInfo(const string& HostName) ;
	PartyInviteInfo* getInviteInfo(const string& HostName) ;

protected:
	unordered_map<string, PartyInviteInfo*> m_InfoMap;
	Mutex m_Mutex;
};


//////////////////////////////////////////////////////////////////////////////
// class Party
//////////////////////////////////////////////////////////////////////////////

class Party
{
public:
	Party(Creature::CreatureClass CClass) ;
	~Party() ;

public:
	int getID(void) const { return m_ID; }
	void setID(int ID) { m_ID = ID; }

	Creature::CreatureClass getCreatureClass(void) const { return m_CreatureClass; }

public:
	Creature* getMember(const string& name) const ;
	void addMember(Creature* pCreature) ;
	void deleteMember(const string& name) ;
	bool hasMember(const string& name) const ;

	// �۷ι� ��Ƽ �Ŵ��������� ����Ѵ�.
	// ��Ƽ�� ��ü�ϱ� ���� ��Ƽ ������� ��Ƽ ID�� 0���� �����,
	// ���� ��Ƽ �Ŵ������� �ش� ID�� ���� ��Ƽ�� �����Ѵ�.
	void destroyParty(void) ;

public:
	// ��Ƽ ����鿡�� ��Ŷ�� ������.
	void broadcastPacket(Packet* pPacket, Creature* pOwner=NULL) ;

	// ���ο� ��Ƽ���� �߰��Ǿ��� �� ��Ƽ���鿡�� ���ư���
	// GCPartyJoined ��Ŷ�� �����Ѵ�.
	void makeGCPartyJoined(GCPartyJoined* pGCPartyJoined) const ;

public:
	int getSize(void) const ;
	unordered_map<string, Creature*> getMemberMap(void) ;

	// ������ �Ÿ�(8Ÿ��) ���� �ִ� ������� ���ڸ� �����Ѵ�.
	int getAdjacentMemberSize(Creature* pLeader) const ;
	int getAdjacentMemberSize_LOCKED(Creature* pLeader) const ;

	// ����ġ�� ��Ǯ���� ������.
	int shareAttrExp(Creature* pLeader, int amount, int STRMultiplier, int DEXMultiplier, int INTMultiplier, ModifyInfo& LeaderModifyInfo) const ;
	int shareVampireExp(Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const ;
	int shareOustersExp(Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const ;

public:
	void shareRevealer(Creature* pCaster, int Duration) ;
	void shareDetectHidden(Creature* pCaster, int Duration) ;
	void shareDetectInvisibility(Creature* pCaster, int Duration) ;
	void shareExpansion(Creature* pCaster, int Duration, int percent) ;
	void shareActivation(Creature* pCaster, int Duration) ;
	void shareGnomesWhisper(Creature* pCaster, int Duration, int SkillLevel) ;
	void shareHolyArmor(Creature* pCaster, int DefBonus, int SkillLevel) ;
	bool shareWaterElementalHeal(Creature* pCaster, int HealPoint) ;
	void shareGDRLairEnter(Creature* pLeader) ;

	void shareRankExp(Creature* pLeader, int amount) ;
	void shareAdvancementExp(Creature* pLeader, int amount) ;

	void dissectCorpse(Creature* pDissecter, MonsterCorpse* pCorpse) ;
	void eventPartyCrash() ;

public:
	bool isFamilyPay() const { return m_bFamilyPay; }
	void refreshFamilyPay();

public:
	string toString(void) const ;

protected:
	int                          m_ID;            // ��Ƽ ID
	Creature::CreatureClass      m_CreatureClass; // ��Ƽ�� ����
	unordered_map<string, Creature*>  m_MemberMap;     // ��Ƽ ���
	mutable Mutex                m_Mutex;         // ���ο��� ���� ��
	bool						 m_bFamilyPay;	  // �йи� ����� ���� ��Ƽ�ΰ�?
};


//////////////////////////////////////////////////////////////////////////////
// class PartyManager
//////////////////////////////////////////////////////////////////////////////

class PartyManager
{
public:
	PartyManager() ;
	virtual ~PartyManager() ;

public:
	virtual bool createParty(int ID, Creature::CreatureClass) ;
	virtual bool addPartyMember(int ID, Creature* pCreature) ;
	virtual bool deletePartyMember(int ID, Creature* pCreature) ;
	virtual Party* getParty(int ID) ;

public:
	virtual string toString(void) const  = 0;

protected:
	unordered_map<int, Party*> m_PartyMap; // ��Ƽ ����
	mutable Mutex m_Mutex;
};


//////////////////////////////////////////////////////////////////////////////
// class LocalPartyManager
//////////////////////////////////////////////////////////////////////////////

class LocalPartyManager : public PartyManager
{
public:
	LocalPartyManager() ;
	virtual ~LocalPartyManager() ;

public:
	void heartbeat(void) ;
	int getAdjacentMemberSize(int PartyID, Creature* pLeader) const ;
	int shareAttrExp(int PartyID, Creature* pLeader, int amount, int STRMultiplier, int DEXMultiplier, int INTMultiplier, ModifyInfo& LeaderModifyInfo) const ;
	int shareVampireExp(int PartyID, Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const ;
	int shareOustersExp(int PartyID, Creature* pLeader, int amount, ModifyInfo& LeaderModifyInfo) const ;
	void shareRevealer(int PartyID, Creature* pCaster, int Duration) ;
	void shareDetectHidden(int PartyID, Creature* pCaster, int Duration) ;
	void shareDetectInvisibility(int PartyID, Creature* pCaster, int Duration) ;
	void shareExpansion(int PartyID, Creature* pCaster, int Duration, int Percent) ;
	void shareActivation(int PartyID, Creature* pCaster, int Duration) ;
	void shareGnomesWhisper(int PartyID, Creature* pCaster, int Duration, int SkillLevel) ;
	void shareHolyArmor(int PartyID, Creature* pCaster, int DefBonus, int SkillLevel) ;
	bool shareWaterElementalHeal(int PartyID, Creature* pCaster, int HealPoint) ;
	void shareGDRLairEnter(int PartyID, Creature* pLeader) ;
	
	int shareRankExp(int PartyID, Creature* pLeader, int amount) const ;
	int shareAdvancementExp(int PartyID, Creature* pLeader, int amount) const ;

public:
	virtual string toString(void) const ;
};


//////////////////////////////////////////////////////////////////////////////
// class GlobalPartyManager
//////////////////////////////////////////////////////////////////////////////

class GlobalPartyManager : public PartyManager
{
public:
	GlobalPartyManager() ;
	virtual ~GlobalPartyManager() ;

public:
	bool canAddMember(int ID) ;
	virtual bool addPartyMember(int ID, Creature* pCreature) ;
	virtual bool deletePartyMember(int ID, Creature* pCreature) ;
	virtual bool expelPartyMember(int ID, Creature* pExpeller, const string& ExpelleeName) ;

	int registerParty(void) ;

	void refreshFamilyPay(int ID);

public:
	virtual string toString(void) const ;

protected:
	int m_PartyIDRegistry; // ��Ƽ ID ������
};

extern GlobalPartyManager* g_pGlobalPartyManager;


//////////////////////////////////////////////////////////////////////////////
// ���Ǹ� ���� ���� �Լ���...
//////////////////////////////////////////////////////////////////////////////
void deleteAllPartyInfo(Creature* pCreature) ;


#endif
