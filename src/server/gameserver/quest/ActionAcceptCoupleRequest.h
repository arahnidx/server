
//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionAcceptCoupleRequest.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ACCEPT_COUPLE_REQUEST_H__
#define __ACTION_ACCEPT_COUPLE_REQUEST_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionAcceptCoupleRequest
//////////////////////////////////////////////////////////////////////////////

class ActionAcceptCoupleRequest : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_ACCEPT_COUPLE_REQUEST; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:

private:
};


//////////////////////////////////////////////////////////////////////////////
// class ActionAcceptCoupleRequestFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionAcceptCoupleRequestFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_ACCEPT_COUPLE_REQUEST; }
	virtual string getActionName() const  { return "AcceptCoupleRequest"; }
	virtual Action* createAction() const  { return new ActionAcceptCoupleRequest(); }
};
#endif
