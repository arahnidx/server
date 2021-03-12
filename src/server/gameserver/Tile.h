//////////////////////////////////////////////////////////////////////////////
// FileName		: Tile.h
// Written By	: reiot@ewestsoft.com
// Description	: 
//////////////////////////////////////////////////////////////////////////////

#ifndef __TILE_H__
#define __TILE_H__

#include <forward_list>
#include "Types.h"
#include "Exception.h"
#include "Object.h"
#include "Creature.h"
#include "Item.h"
#include "Obstacle.h"
#include "Effect.h"
#include "Portal.h"
#include "Sector.h"

// macro
#define FLAG_ZERO(set)       (set=0)
#define FLAG_SET(set,flag)   (set|=(1<<(flag)))
#define FLAG_CLEAR(set,flag) (set&=~(1<<(flag)))
#define FLAG_ISSET(set,flag) (set&(1<<(flag)))

// type redefinition
typedef WORD BuildingID_t;
typedef WORD TerrainID_t;

//////////////////////////////////////////////////////////////////////////////
// Tile class:
//////////////////////////////////////////////////////////////////////////////

class Packet;

class Tile 
{
public:
	enum TileFlags 
	{
		TILE_GROUND_BLOCKED = 0 ,	// Ÿ���� ������ ������ ���
		TILE_AIR_BLOCKED ,			// Ÿ���� ������ ������ ���
		TILE_UNDERGROUND_BLOCKED ,	// Ÿ���� ���ϰ� ������ ���
		TILE_WALKING_CREATURE ,		// Ÿ���� ���� ũ��ó�� ���� ��� 
		TILE_FLYING_CREATURE ,		// Ÿ���� ���߿� ũ��ó�� ���� ��� 
		TILE_BURROWING_CREATURE ,	// Ÿ���� ���Ͽ� ũ��ó�� ���� ��� 
		TILE_ITEM, 					// Ÿ�� ���� �������� ���� ���� ���
		TILE_OBSTACLE ,				// Ÿ�� ���� ���¸� ���� ��ֹ��� ���� ���� ���
		TILE_EFFECT,				// Ÿ�� ���� ���� ��ü�� ���� ��� 
		TILE_BUILDING ,				// Ÿ�� ���� �ǹ��� ���� ���
		TILE_PORTAL ,				// Ÿ�� ���� ��Ż�� ���� ���� ��� 
		TILE_TERRAIN				// ȿ���� �ִ� ��� Ÿ���� ���
	};

public:
	Tile(WORD m_Flag = 0, WORD m_Opt = 0) ;
	~Tile() ;

public:
	bool addCreature(Creature* pCreature, bool bCheckEffect=true, bool bCheckPortal=true) ;
	void deleteCreature(ObjectID_t creatureID) ;
	void deleteCreature(Creature::MoveMode mode) ;
	Creature* getCreature(ObjectID_t creatureID) ;
	Creature* getCreature(Creature::MoveMode mode) ;

	bool hasWalkingCreature() const  { return FLAG_ISSET(m_wFlags, TILE_WALKING_CREATURE) > 0; }
	bool hasFlyingCreature() const  { return FLAG_ISSET(m_wFlags, TILE_FLYING_CREATURE) > 0; }
	bool hasBurrowingCreature() const  { return FLAG_ISSET(m_wFlags, TILE_BURROWING_CREATURE) > 0; }
	bool hasCreature(Creature::MoveMode mode) const  { return FLAG_ISSET(m_wFlags, mode + TILE_WALKING_CREATURE) > 0; }
	bool hasCreature() const  { 
		return FLAG_ISSET(m_wFlags, TILE_WALKING_CREATURE) ||
			   FLAG_ISSET(m_wFlags, TILE_BURROWING_CREATURE) ||
			   FLAG_ISSET(m_wFlags, TILE_FLYING_CREATURE) ; 
	}

public:
	void addItem(Item* pItem) ;
	void deleteItem() ;
	Item* getItem() ;
	bool hasItem() const  { return FLAG_ISSET(m_wFlags, TILE_ITEM) > 0; }
	
public:
	void addObstacle(Obstacle* pObstacle) ;
	void deleteObstacle() ;
	Obstacle* getObstacle() ;
	bool hasObstacle() const  { return FLAG_ISSET(m_wFlags, TILE_OBSTACLE) > 0; }

public:
	void addEffect(Effect* pEffect) ;
	bool canAddEffect() ;
	void deleteEffect(ObjectID_t effectID) ;
	Effect* getEffect(ObjectID_t effectID) ;
	bool hasEffect() const  { return FLAG_ISSET(m_wFlags, TILE_EFFECT) > 0; }
	Effect* getEffect(Effect::EffectClass effectClass) ;

public:
	void addBuilding(BuildingID_t buildingID) ;
	void deleteBuilding() ;
	BuildingID_t getBuilding() const ;
	bool hasBuilding() const  { return FLAG_ISSET(m_wFlags, TILE_BUILDING) > 0; }

public:
	void addPortal(Portal* pPortal) ;
	void deletePortal() ;
	Portal* getPortal() const ;
	bool hasPortal() const  { return FLAG_ISSET(m_wFlags, TILE_PORTAL) > 0; }

public:
	void addTerrain(TerrainID_t terrainID) ;
	void deleteTerrain() ;
	TerrainID_t getTerrain() const ;
	bool isTerrain() const  { return FLAG_ISSET(m_wFlags, TILE_TERRAIN) > 0; }

public:
	bool isGroundBlocked() const  { return FLAG_ISSET(m_wFlags, TILE_GROUND_BLOCKED) > 0; }
	bool isAirBlocked() const  { return FLAG_ISSET(m_wFlags, TILE_AIR_BLOCKED) > 0; }
	bool isUndergroundBlocked() const  { return FLAG_ISSET(m_wFlags, TILE_UNDERGROUND_BLOCKED) > 0; }
	bool isBlocked(Creature::MoveMode mode) const  { return FLAG_ISSET(m_wFlags, TILE_GROUND_BLOCKED + mode) > 0; }
	void setBlocked(Creature::MoveMode mode)  { FLAG_SET(m_wFlags, TILE_GROUND_BLOCKED + mode); }
	void clearBlocked(Creature::MoveMode mode)  { FLAG_CLEAR(m_wFlags, TILE_GROUND_BLOCKED + mode); }

	bool isFixedGroundBlocked() const  { return isGroundBlocked() && !hasWalkingCreature(); }

public:
	void addObject(Object* pObject) ;
	void deleteObject(ObjectID_t objectID) ;
	void deleteObject(ObjectPriority tilePriority) ;
	Object* getObject(ObjectID_t objectID) const ;
	Object* getObject(ObjectPriority tilePriority) const ;

public:
	WORD getOption() const  { return m_wOption; }
	void setOption(WORD option)  { m_wOption = option; }

public:
	Sector* getSector(void) const { return m_pSector; }
	void setSector(Sector* pSector) { m_pSector = pSector; }

public:
	const forward_list<Object*> & getObjectList() const  { return m_Objects; }
	forward_list<Object*> & getObjectList()  { return m_Objects; }

	string toString() const ;

private:
	WORD           m_wFlags;  // Ÿ�� �Ӽ� �÷���
	WORD           m_wOption; // �ɼ� �÷���, Ÿ�� �Ӽ� �÷��׿� ���� �ٸ��� ���ȴ�.
	forward_list<Object*> m_Objects; // ������Ʈ �������� ����Ʈ
	Sector*        m_pSector; // �� Ÿ���� ���� ���Ϳ� ���� ������
};

#endif
