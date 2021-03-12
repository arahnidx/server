////////////////////////////////////////////////////////////////////////////////
// Filename    : CGTradePrepare.h 
// Written By  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////

#ifndef __CG_TRADE_PREPARE_H__
#define __CG_TRADE_PREPARE_H__

#include "Packet.h"
#include "PacketFactory.h"

////////////////////////////////////////////////////////////////////////////////
// ��ȯ �ڵ�
////////////////////////////////////////////////////////////////////////////////

enum
{
	// ���� ó�� ��ȯ�� ���ϴ� �÷��̾ �� �ڵ�� ��Ŷ�� ������.
	CG_TRADE_PREPARE_CODE_REQUEST = 0,

	// ���� ó�� ��ȯ�� ��û�� �÷��̾ ��Ҹ� �ߴ�.
	CG_TRADE_PREPARE_CODE_CANCEL,

	// ��ȯ�� ��û���� �÷��̾ ��ȯ�� ���� ���
	CG_TRADE_PREPARE_CODE_ACCEPT,

	// ��ȯ�� ��û���� �÷��̾ ��ȯ�� ������ ���� ���
	CG_TRADE_PREPARE_CODE_REJECT,

	// ��ȯ�� ��û���� �÷��̾ ���� ��ȯ�� �� �� ���� ���
	CG_TRADE_PREPARE_CODE_BUSY,

	CG_TRADE_PREPARE_CODE_MAX
};

////////////////////////////////////////////////////////////////////////////////
//
// class CGTradePrepare;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradePrepare : public Packet 
{
public:
	void read(SocketInputStream & iStream) ;
	void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_CG_TRADE_PREPARE; }
	PacketSize_t getPacketSize() const  { return szObjectID + szBYTE; }
	string getPacketName() const  { return "CGTradePrepare"; }
	string toString() const ;
	
public:
	ObjectID_t getTargetObjectID() const  { return m_TargetObjectID; }
	void setTargetObjectID(ObjectID_t id)  { m_TargetObjectID = id; }

	BYTE getCode(void) const  { return m_Code; }
	void setCode(BYTE code)  { m_Code = code; }

private:
	ObjectID_t m_TargetObjectID; // ��ȯ�� ���ϴ� ������ OID
	BYTE       m_Code;           // ��ȯ �ڵ�

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGTradePrepareFactory;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradePrepareFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGTradePrepare(); }
	string getPacketName() const  { return "CGTradePrepare"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_TRADE_PREPARE; }
	PacketSize_t getPacketMaxSize() const  { return szObjectID + szBYTE; }
};


////////////////////////////////////////////////////////////////////////////////
//
// class CGTradePrepareHandler;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradePrepareHandler 
{
public:
	static void execute(CGTradePrepare* pPacket, Player* player) ;
	static void executeSlayer(CGTradePrepare* pPacket, Player* player) ;
	static void executeVampire(CGTradePrepare* pPacket, Player* player) ;
	static void executeOusters(CGTradePrepare* pPacket, Player* player) ;
	static void executeError(CGTradePrepare* pPacket, Player* player, BYTE ErrorCode) ;
};

#endif
