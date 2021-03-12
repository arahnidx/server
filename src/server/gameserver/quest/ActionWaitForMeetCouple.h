//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionWaitForMeetCouple.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_WAIT_FOR_MEET_COUPLE_H__
#define __ACTION_WAIT_FOR_MEET_COUPLE_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionWaitForMeetCouple
//////////////////////////////////////////////////////////////////////////////

class ActionWaitForMeetCouple : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_WAIT_FOR_MEET_COUPLE; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:

private:
};


//////////////////////////////////////////////////////////////////////////////
// class ActionWaitForMeetCoupleFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionWaitForMeetCoupleFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_WAIT_FOR_MEET_COUPLE; }
	virtual string getActionName() const  { return "WaitForMeetCouple"; }
	virtual Action* createAction() const  { return new ActionWaitForMeetCouple(); }
};
#endif
