//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionPrepareTeach.h
// Written By  : 
// Description : 
// ���� NPC�� ������ �� �� �ִ� ����� ������ ���ϴ� �׼��̴�.
// PrepareShop�� ����ϰ� AtFirst ������� �̿��Ͽ� ó��
// �ѹ��� �����ϰ� �ٽô� �������� �ʴ´�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_PREPARE_TEACH_H__
#define __ACTION_PREPARE_TEACH_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionPrepareTeach;
//////////////////////////////////////////////////////////////////////////////

class ActionPrepareTeach : public Action 
{
public:
	virtual ActionType_t getActionType() const  { return ACTION_PREPARE_TEACH; }
	virtual void read(PropertyBuffer & propertyBuffer) ;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) ;
	virtual string toString() const ;

public:
	SkillLevel_t getMaxLevel(void) const  { return m_MaxLevel;}
	void setMaxLevel(SkillLevel_t level)  { m_MaxLevel = level;}

private:
	SkillLevel_t m_MaxLevel; // ������ �� ��ų�� �ƽ� ����

};


//////////////////////////////////////////////////////////////////////////////
// class ActionPrepareTeachFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionPrepareTeachFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const  { return Action::ACTION_PREPARE_TEACH; }
	virtual string getActionName() const  { return "PrepareTeach"; }
	virtual Action* createAction() const  { return new ActionPrepareTeach(); }

};

#endif
