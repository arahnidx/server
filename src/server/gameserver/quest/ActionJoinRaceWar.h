//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionJoinRaceWar.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_JOIN_RACE_WAR_H__
#define __ACTION_JOIN_RACE_WAR_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionJoinRaceWar
//////////////////////////////////////////////////////////////////////////////

class ActionJoinRaceWar : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_JOIN_RACE_WAR; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2) ;
	virtual string toString() const ;

private:
};


//////////////////////////////////////////////////////////////////////////////
// class ActionJoinRaceWarFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionJoinRaceWarFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_JOIN_RACE_WAR; }
	virtual string getActionName() const  { return "JoinRaceWar"; }
	virtual Action* createAction() const  { return new ActionJoinRaceWar(); }
};

#endif
