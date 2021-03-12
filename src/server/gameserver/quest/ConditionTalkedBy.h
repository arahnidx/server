//////////////////////////////////////////////////////////////////////////////
// Filename    : ConditionTalkedBy.h
// Written By  : 
// Description :
// NPC�� PC�κ��� ��ȭ�� �޾��� ���, Ư���� �� ������� ���� �ƴ� ���ɼ��� ����.
//////////////////////////////////////////////////////////////////////////////

#ifndef __TALKED_BY_H__
#define __TALKED_BY_H__

#include "Condition.h"
#include "ConditionFactory.h"
#include "Creature.h"

//////////////////////////////////////////////////////////////////////////////
// class ConditionTalkedBy;
//////////////////////////////////////////////////////////////////////////////

class ConditionTalkedBy : public Condition 
{
public:
	virtual ConditionType_t getConditionType() const  { return CONDITION_TALKED_BY; }

	virtual bool isPassive() const  { return true; }

	virtual bool isSatisfied(Creature* pNPC, Creature* pPC = NULL, void* pParam = NULL) const  
	{ 
		return pNPC != NULL && pNPC->isNPC() && pPC != NULL && pPC->isPC(); 
	}

	virtual void read(PropertyBuffer & propertyBuffer)  { }

	virtual string toString() const  { return "ConditionTalkedBy"; }

};

//////////////////////////////////////////////////////////////////////////////
// class ConditionTalkedByFactory;
//////////////////////////////////////////////////////////////////////////////

class ConditionTalkedByFactory : public ConditionFactory 
{
public:
    virtual ConditionType_t getConditionType() const  { return Condition::CONDITION_TALKED_BY; }
    virtual Condition* createCondition() const  { return new ConditionTalkedBy(); }
    virtual string getConditionName() const  { return "TalkedBy"; }
};

#endif
