//////////////////////////////////////////////////////////////////////////////
// Filename    : Belt.h
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __BELT_H__
#define __BELT_H__

#include "Item.h"
#include "ConcreteItem.h"
#include "ItemPolicies.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class Belt;
//////////////////////////////////////////////////////////////////////////////

class Belt : public ConcreteItem <Item::ITEM_CLASS_BELT, NoStack, HasDurability, HasOption, GroceryGrade, NoAttacking>
{
public:
	Belt() ;
	Belt(ItemType_t itemType, const list<OptionType_t>& optionType) ;
	~Belt() ;

public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) ;
	virtual bool destroy() ;
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) ;
	void tinysave(const string & field) const 	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const ;
	virtual string toString() const ;

	static void initItemIDRegistry(void) ;

public:
//	virtual ItemClass getItemClass() const  { return Item::ITEM_CLASS_BELT; }
//	virtual string getObjectTableName() const  { return "BeltObject"; }

//	virtual ItemType_t getItemType() const  { return m_ItemType; }
//	virtual void setItemType(ItemType_t itemType)  { m_ItemType = itemType; }

/*	virtual bool hasOptionType() const  { return !m_OptionType.empty(); }
	virtual int getOptionTypeSize() const  { return m_OptionType.size(); }
	virtual int getRandomOptionType() const  { if (m_OptionType.empty()) return 0; int pos = rand()%m_OptionType.size(); list<OptionType_t>::const_iterator itr = m_OptionType.begin(); for (int i=0; i<pos; i++) itr++; return *itr; }
	virtual const list<OptionType_t>& getOptionTypeList() const  { return m_OptionType; }
	virtual OptionType_t getFirstOptionType() const  { if (m_OptionType.empty()) return 0; return m_OptionType.front(); }
	virtual void removeOptionType(OptionType_t OptionType)  { list<OptionType_t>::iterator itr = find(m_OptionType.begin(), m_OptionType.end(), OptionType); if (itr!=m_OptionType.end()) m_OptionType.erase(itr); }
	virtual void changeOptionType(OptionType_t currentOptionType, OptionType_t newOptionType)  { list<OptionType_t>::iterator itr = find(m_OptionType.begin(), m_OptionType.end(), currentOptionType); if (itr!=m_OptionType.end()) *itr=newOptionType; }
	virtual void addOptionType(OptionType_t OptionType)  { m_OptionType.push_back(OptionType); }
	virtual void setOptionType(const list<OptionType_t>& OptionType)  { m_OptionType = OptionType; }


	virtual VolumeWidth_t getVolumeWidth() const ;
	virtual VolumeHeight_t getVolumeHeight() const ;
	virtual Weight_t getWeight() const ;

	virtual Durability_t getDurability() const  { return m_Durability; }
	void setDurability(Durability_t durability)  { m_Durability = durability; }
*/
	void setInventory(Inventory* pInventory)  { m_pInventory = pInventory; }
	Inventory* getInventory() const  { return m_pInventory; }

	PocketNum_t getPocketCount(void) const ;

/*	virtual Defense_t getDefenseBonus() const ;
	virtual Protection_t getProtectionBonus() const ;*/

	void makePCItemInfo(PCItemInfo& result) const;

private:
//	ItemType_t     m_ItemType;      // ������ Ÿ��
//	list<OptionType_t>   m_OptionType;    // �ɼ� Ÿ��
//	Durability_t   m_Durability;    // ������
	Inventory*     m_pInventory;    // �κ��丮
	
	static Mutex    m_Mutex;          // ������ ID ���� ��
	static ItemID_t m_ItemIDRegistry; // Ŭ������ ���� ������ ���̵� �߱ޱ�
};


//////////////////////////////////////////////////////////////////////////////
// class BeltInfo
//////////////////////////////////////////////////////////////////////////////

class BeltInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_BELT; }

	virtual Durability_t getDurability() const  { return m_Durability; }
	virtual void setDurability(Durability_t durability)  { m_Durability = durability; }

	uint getPocketCount() const  { return m_PocketCount; }
	void setPocketCount(uint pocketCount)  { m_PocketCount = pocketCount; }

	Defense_t getDefenseBonus() const  { return m_DefenseBonus; }
	void setDefenseBonus(Defense_t acBonus)  { m_DefenseBonus = acBonus; }

	Protection_t getProtectionBonus() const  { return m_ProtectionBonus; }
	void setProtectionBonus(Protection_t acBonus)  { m_ProtectionBonus = acBonus; }

	virtual uint getItemLevel(void) const  { return m_ItemLevel; }
	virtual void setItemLevel(uint level)  { m_ItemLevel = level; }

	virtual string toString() const ;

private:
	Durability_t  m_Durability;      // ������
	uint          m_PocketCount;     // ������ ����
	Defense_t     m_DefenseBonus;    // defense bonus
	Protection_t  m_ProtectionBonus; // protection bonus
	uint          m_ItemLevel;       // �������� ����

};


//////////////////////////////////////////////////////////////////////////////
// class BeltInfoManager;
//////////////////////////////////////////////////////////////////////////////

class BeltInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_BELT; }
	virtual void load() ;
};

extern BeltInfoManager* g_pBeltInfoManager;


//////////////////////////////////////////////////////////////////////////////
// class BeltFactory
//////////////////////////////////////////////////////////////////////////////

class BeltFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_BELT; }
	virtual string getItemClassName() const  { return "Belt"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType)  { return new Belt(ItemType,OptionType); }
};


//////////////////////////////////////////////////////////////////////////////
// class BeltLoader;
//////////////////////////////////////////////////////////////////////////////

class BeltLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const  { return Item::ITEM_CLASS_BELT; }
	virtual string getItemClassName() const  { return "Belt"; }

public:
	virtual void load(Creature* pCreature) ;
	virtual void load(Zone* pZone) ;
	virtual void load(StorageID_t storageID, Inventory* pInventory) ;
};

extern BeltLoader* g_pBeltLoader;

#endif
