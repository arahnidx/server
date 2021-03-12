//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionRewardEventQuest.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_REWARD_EVENT_QUEST_H__
#define __ACTION_REWARD_EVENT_QUEST_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionRewardEventQuest
//////////////////////////////////////////////////////////////////////////////

class ActionRewardEventQuest : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_REWARD_EVENT_QUEST; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:
	ScriptID_t getScriptID( int index ) const  { return m_ScriptID[index]; }
	void setScriptID( int index, ScriptID_t scriptID )  { m_ScriptID[index] = scriptID; }

private:
	ScriptID_t m_ScriptID[5];   // ���� ��� ���̵�
	ScriptID_t m_CounterScriptID;	// ����Ʈ�� �Ϸ���� �ʾ��� ��
	ScriptID_t m_CancelScriptID;	// ���� �ܰ� ����Ʈ�� ������ ���� ��
};


//////////////////////////////////////////////////////////////////////////////
// class ActionRewardEventQuestFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionRewardEventQuestFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_REWARD_EVENT_QUEST; }
	virtual string getActionName() const  { return "RewardEventQuest"; }
	virtual Action* createAction() const  { return new ActionRewardEventQuest(); }
};
#endif
