//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveItem.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_ITEM_H__
#define __ACTION_GIVE_ITEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"
#include "Item.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveItem
//////////////////////////////////////////////////////////////////////////////

class ActionGiveItem : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_GIVE_ITEM; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:
private:
	Item::ItemClass m_ItemClass;
	ItemType_t		m_ItemType;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveItemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveItemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_GIVE_ITEM; }
	virtual string getActionName() const  { return "GiveItem"; }
	virtual Action* createAction() const  { return new ActionGiveItem(); }
};
#endif
