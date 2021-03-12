//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionAskByQuestLevel.h
// Written By  : excel96
// Description : 
// Creature�� PC���� ������ ������. �� ���� NPC ��ȭâ�� ��µȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ASK_BY_QUEST_LEVEL_H__
#define __ACTION_ASK_BY_QUEST_LEVEL_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionAskByQuestLevel
//////////////////////////////////////////////////////////////////////////////

class ActionAskByQuestLevel : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_ASK_BY_QUEST_LEVEL; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:
	ScriptID_t getScriptID( int index ) const  { return m_ScriptID[index]; }
	void setScriptID( int index, ScriptID_t scriptID )  { m_ScriptID[index] = scriptID; }

private:
	ScriptID_t m_ScriptID[5];   // ���� ��� ���̵�
};


//////////////////////////////////////////////////////////////////////////////
// class ActionAskByQuestLevelFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionAskByQuestLevelFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_ASK_BY_QUEST_LEVEL; }
	virtual string getActionName() const  { return "AskByQuestLevel"; }
	virtual Action* createAction() const  { return new ActionAskByQuestLevel(); }
};
#endif
