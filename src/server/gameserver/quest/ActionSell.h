//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionSell.h
// Written By  : 
// Description : 
// NPC�� �������� �÷��̾�� �Ĵ� �׼��̴�. �����δ� �ŷ���
// �����ϰ� ����� �׼��̸�, �ϴ� ���� �÷��̾�� ���� NPC��
// ���� ������ ��Ŷ���� �����ִ� �� ���̴�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_SELL_H__
#define __ACTION_SELL_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionSell
//////////////////////////////////////////////////////////////////////////////

class ActionSell : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_SELL; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;
};

//////////////////////////////////////////////////////////////////////////////
// class AskFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionSellFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_SELL; }
	virtual string getActionName() const  { return "Sell"; }
	virtual Action* createAction() const  { return new ActionSell(); }
};

#endif
