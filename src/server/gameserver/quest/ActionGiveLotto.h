//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveLotto.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_LOTTO_H__
#define __ACTION_GIVE_LOTTO_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveLotto
//////////////////////////////////////////////////////////////////////////////

class ActionGiveLotto : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_GIVE_LOTTO; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:

private:
	int		m_QuestLevel;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveLottoFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveLottoFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_GIVE_LOTTO; }
	virtual string getActionName() const  { return "GiveLotto"; }
	virtual Action* createAction() const  { return new ActionGiveLotto(); }
};
#endif
