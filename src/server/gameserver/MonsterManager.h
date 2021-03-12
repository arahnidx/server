//////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterManager.h 
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __MONSTER_MANAGER_H__
#define __MONSTER_MANAGER_H__

#include "CreatureManager.h"
#include "MonsterCounter.h"
#include "Item.h"
#include "Timeval.h"
#include <unordered_map>
#include <list>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// class MonsterManager
//////////////////////////////////////////////////////////////////////////////

class Zone;
class Monster;
class MonsterCorpse;
struct SUMMON_INFO;
struct ITEM_TEMPLATE;

struct EventMonsterInfo
{
	MonsterType_t   monsterType;
	int				regenDelay;
	Timeval			regenTime;
	int				x, y;
	bool			bExist;
};

class MonsterManager : public CreatureManager 
{
public:
	MonsterManager(Zone* pZone) ;
	~MonsterManager() ;
	
public:
	// load from database
	void load() ;

	// add monster
	void addCreature(Creature* pCreature) ;

	// ���͵��� �߰��Ѵ�.
	void addMonsters(ZoneCoord_t x, ZoneCoord_t y, MonsterType_t monsterType, int num, const SUMMON_INFO& summonInfo, list<Monster*>* pSummonedMonsters=NULL);

	// delete monster
	void deleteCreature(ObjectID_t objectID) ;//NoSuchElementException, Error);

	// �Ŵ����� �Ҽӵ� ũ��ó��(NPC,Monster)�� ó���Ѵ�.
	void processCreatures() ;

	// ������ ���ڰ� �پ����� ��쿡, ���͸� �߰��Ѵ�.
	void regenerateCreatures() ;

	// ���͸� �߰��� ������ ��ġ�� �˻��Ѵ�.
	bool findPosition(MonsterType_t monsterType, ZoneCoord_t& x, ZoneCoord_t& y) const ;

	// ���� ũ��ó�� ó���Ѵ�.
	void killCreature(Creature* pDeadMonster) ;

	// ���� ���Ϳ��Լ� �������� �����Ѵ�.
	void addItem(Monster* pDeadMonster, MonsterCorpse* pMonsterCorpse) ;
	
	// �ؽ����� ���� �׼����� ��
	const unordered_map<MonsterType_t, MonsterCounter*>& getMonsters(void) { return m_Monsters;}

	// ��ü�� �������� ������ �ν��Ѵ�. pMonster�� pCreature�� ������ ��쿡..
	void addPotentialEnemy(Monster* pMonster, Creature* pCreature) ;

	// ��ü�� ������ �ν��Ѵ�. pMonster�� pCreature�� ������ ��쿡..
	void addEnemy(Monster* pMonster, Creature* pCreature) ;

	// get debug string 
	string toString() const ;

	// delete AllMonsters
	void deleteAllMonsters(bool bDeleteFromZone=true) ;//NoSuchElementException, Error);

	// kill AllMonsters
	void killAllMonsters(const unordered_map<ObjectID_t, ObjectID_t>& exceptCreatures) ;//NoSuchElementException, Error);

	int upgradeItemTypeByLuck(int luckLevel, Creature::CreatureClass ownerCreatureClass, ITEM_TEMPLATE& it) ;
	int upgradeOptionByLuck(int luckLevel, Creature::CreatureClass ownerCreatureClass, ITEM_TEMPLATE& it) ;

protected :
	void parseMonsterList(const string& text, bool bReload=false) ;
	void parseEventMonsterList(const string& text, bool bReload=false) ;

private:
	Zone* m_pZone; // ���� �Ŵ����� �Ҽӵ� ���� ���� ������
	unordered_map< SpriteType_t, MonsterCounter* > m_Monsters; // ���� ���� �����ϴ� ������ ���� ��Ȳ
	Timeval m_RegenTime; // ���� ���� ��� �ð�

	int m_RICE_CAKE_PROB_RATIO[5];
	int m_SumOfCakeRatio;

	// by sigi. 2002.10.14
	vector<EventMonsterInfo>* 	m_pEventMonsterInfo; 
	int							m_nEventMonster;

	ZoneID_t					m_CastleZoneID;
};

#endif
