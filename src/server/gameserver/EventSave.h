//////////////////////////////////////////////////////////////////////////////
// Filename    : EventSave.h
// Written by  : Reiot
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __SAVE_H__
#define __SAVE_H__

#include "Event.h"

//////////////////////////////////////////////////////////////////////////////
// class EventSave;
// �� ĳ���͸� �ֱ������� �����ϵ��� ���ִ� �̺�Ʈ�̴�.
//////////////////////////////////////////////////////////////////////////////

class EventSave : public Event 
{
public:
	EventSave(GamePlayer* pGamePlayer) ;
	virtual ~EventSave() ;

public:
	virtual EventClass getEventClass() const  { return EVENT_SAVE; }

	// get event life-cycle
	// EventSave �̺�Ʈ�� �ֱ������� ��� ����Ǿ�� �ϹǷ�, �����Ǿ�� �ȵȴ�.
	virtual bool isTemporary() const  { return false; }
	virtual bool isPermanent() const  { return true; }

	virtual void activate() ;
	
	virtual string toString() const  { return "EventSave Event"; }
};

#endif
