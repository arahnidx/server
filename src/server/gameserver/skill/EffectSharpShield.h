//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectSharpShield.h
// Written by  : crazydog
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_SHARP_SHIELD__
#define __EFFECT_SHARP_SHIELD__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectSharpShield
//////////////////////////////////////////////////////////////////////////////

class EffectSharpShield : public Effect 
{
public:
	EffectSharpShield(Creature* pCreature) ;

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_SHARP_SHIELD_1; }
	EffectClass getSendEffectClass() const throw() { return m_ClientEffectClass; }

	void affect() {}
	void affect(Creature* pCreature) ;
	void affect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) ;

	void unaffect(Creature* pCreature) ;
	void unaffect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) ;
	void unaffect(Item* pItem)  {}
	void unaffect() ;

	string toString() const throw();

public:
	void setLevel(Level_t Level) throw();

	Damage_t getDamage() const throw() { return m_Damage; }
	void setDamage(Damage_t Damage) throw() { m_Damage = Damage; }

	EffectClass getClientEffectClass() const throw() { return m_ClientEffectClass; }
	void setClientEffectClass(EffectClass effectClass) throw() { m_ClientEffectClass = effectClass; }

private:
	EffectClass 	m_ClientEffectClass;	// Ŭ���̾�Ʈ�� �����ٶ� ���� ����Ʈ Ŭ���� ���̵�
	Damage_t 		m_Damage;				// ���������� �ִ� ������
};

//////////////////////////////////////////////////////////////////////////////
// class EffectSharpShieldLoader
//////////////////////////////////////////////////////////////////////////////

class EffectSharpShieldLoader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_SHARP_SHIELD_1; }
	virtual string getEffectClassName() const throw() { return "EffectSharpShield"; }

public:
	virtual void load(Creature* pCreature)  {}
};


#endif // __EFFECT_SHARP_SHIELD__
