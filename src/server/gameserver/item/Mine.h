//////////////////////////////////////////////////////////////////////////////
// Filename    : Mine.h
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __MINE_H__
#define __MINE_H__

#include "Item.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class Mine;
//////////////////////////////////////////////////////////////////////////////

class Mine : public Item 
{
public:
	Mine() ;
	Mine(ItemType_t itemType, const list<OptionType_t>& optionType) ;
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) ;
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) ;
	void tinysave(const string & field) const 	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const ;
	virtual string toString() const ;

	static void initItemIDRegistry(void) ;

public:
	virtual ItemClass getItemClass() const  { return Item::ITEM_CLASS_MINE; }
	virtual string getObjectTableName() const  { return "MineObject"; }

	virtual ItemType_t getItemType() const  { return m_ItemType; }
	virtual void setItemType(ItemType_t itemType)  { m_ItemType = itemType; }

	virtual VolumeWidth_t getVolumeWidth() const ;
	virtual VolumeHeight_t getVolumeHeight() const ;
	virtual Weight_t getWeight() const ;

	Damage_t getDamage() const  { return m_Damage;}
	void setDamage(Damage_t D)  { m_Damage = D;}

	Dir_t getDir() const  { return m_Dir;}
	void setDir(Dir_t R)  { m_Dir = R;}

	string getInstallerName() const  { return m_InstallerName; }
	void setInstallerName( const string & InstallerName )  { m_InstallerName = InstallerName; }

	int getInstallerPartyID() const  { return m_InstallerPartyID; }
	void setInstallerPartyID( int InstallerPartyID )  { m_InstallerPartyID = InstallerPartyID; }

	virtual Damage_t getMinDamage() const ;
	virtual Damage_t getMaxDamage() const ;

	virtual ItemNum_t getNum() const  { return m_Num; }
	virtual void setNum(ItemNum_t Num)  { m_Num = Num; }

	bool    isStackable() const  { return true; }

private:
	ItemType_t	m_ItemType; // ������ Ÿ��
	Damage_t	m_Damage;
	ItemNum_t	m_Num;
	Dir_t		m_Dir;
	string		m_InstallerName;
	int			m_InstallerPartyID;
	
	static Mutex    m_Mutex;          // ������ ID ���� ��
	static ItemID_t m_ItemIDRegistry; // Ŭ������ ���� ������ ���̵� �߱ޱ�
};


//////////////////////////////////////////////////////////////////////////////
// class MineInfo
//////////////////////////////////////////////////////////////////////////////

class MineInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_MINE; }
	virtual string toString() const ;

	virtual Damage_t getMinDamage() const  { return m_MinDamage; }
	virtual void setMinDamage(Damage_t minDamage)  { m_MinDamage = minDamage; }

	virtual Damage_t getMaxDamage() const  { return m_MaxDamage; }
	virtual void setMaxDamage(Damage_t maxDamage)  { m_MaxDamage = maxDamage; }

private:
	Damage_t m_MinDamage;     // �ּ� ������
	Damage_t m_MaxDamage;     // �ִ� ������
};


//////////////////////////////////////////////////////////////////////////////
// class MineInfoManager;
//////////////////////////////////////////////////////////////////////////////

class MineInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_MINE; }
	virtual void load() ;
};

extern MineInfoManager* g_pMineInfoManager;


//////////////////////////////////////////////////////////////////////////////
// class MineFactory
//////////////////////////////////////////////////////////////////////////////

class MineFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_MINE; }
	virtual string getItemClassName() const  { return "Mine"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType)  { return new Mine(ItemType,OptionType); }
};


//////////////////////////////////////////////////////////////////////////////
// class MineLoader;
//////////////////////////////////////////////////////////////////////////////

class MineLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_MINE; }
	virtual string getItemClassName() const  { return "Mine"; }

public:
	virtual void load(Creature* pCreature) ;
	virtual void load(Zone* pZone) ;
	virtual void load(StorageID_t storageID, Inventory* pInventory) ;
};

extern MineLoader* g_pMineLoader;

#endif
