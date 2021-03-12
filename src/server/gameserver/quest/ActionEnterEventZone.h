//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEnterEventZone.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ENTER_EVENT_ZONE_H__
#define __ACTION_ENTER_EVENT_ZONE_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionEnterEventZone
//////////////////////////////////////////////////////////////////////////////

class ActionEnterEventZone : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_ENTER_EVENT_ZONE; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

private:
	WORD    m_EventID;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionEnterEventZoneFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionEnterEventZoneFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_ENTER_EVENT_ZONE; }
	virtual string getActionName() const  { return "EnterEventZone"; }
	virtual Action* createAction() const  { return new ActionEnterEventZone(); }
};
#endif
