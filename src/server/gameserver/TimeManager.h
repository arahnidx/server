//////////////////////////////////////////////////////////////////////////////
// Filename   : TimeManager.h
// Written By : Reiot
//////////////////////////////////////////////////////////////////////////////

#ifndef __TIME_MANAGER_H__
#define __TIME_MANAGER_H__

#include "Types.h"
#include "GameTime.h"


#define DAWN_START_HOUR    4
#define DAWN_END_HOUR      8

#define DAY_START_HOUR     8
#define DAY_END_HOUR      16

#define DUSK_START_HOUR   16
#define DUSK_END_HOUR     20

#define NIGHT_START_HOUR  20
#define NIGHT_END_HOUR     4

enum Timeband
{
	TIME_DAWN = 0, // ����
	TIME_DAY,      // ��
	TIME_DUSK,     // ����
	TIME_NIGHT,    // ��

	TIME_MAX
};

//////////////////////////////////////////////////////////////////////////////
// class TimeManager;
//
// ���� ���� �ð��� ������ִ� �Ŵ��� Ŭ�����̴�.(��� �Ŵ������ �� �͵� ����.
// �� �ܿ��� ���� �ٸ� ������ �� �͵� ����...
//////////////////////////////////////////////////////////////////////////////

class TimeManager 
{
public:
	void init() ;

	GameTime getGameTime() const ;	

	time_t getgametime() const ;

	time_t getBaseGameTime() const  { return m_BaseGameTime; }
	time_t getBaseRealTime() const  { return m_BaseRealTime; }

	bool isDawnTime(void) const ;
	bool isDayTime(void) const ;
	bool isDuskTime(void) const ;
	bool isNightTime(void) const ;
	uint getTimeband(void) const ;

	// get debug string
	string toString() const ;

private:
	time_t m_BaseGameTime;
	time_t m_BaseRealTime;
	
};

// global variable declaration
extern TimeManager* g_pTimeManager;

#endif
