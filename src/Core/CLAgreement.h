//--------------------------------------------------------------------------------
// 
// Filename    : CLAgreement.h 
// Written By  : reiot@ewestsoft.com
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __CL_AGREEMENT_H__
#define __CL_AGREEMENT_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//--------------------------------------------------------------------------------
//
// class CLAgreement;
//
// Ŭ���̾�Ʈ�� �α��� �������� ���ʿ� �����ϴ� ��Ŷ�̴�.
// ���̵�� �н����尡 ��ȣȭ�Ǿ� �ִ�.
//
//--------------------------------------------------------------------------------

class CLAgreement : public Packet {

public:
	CLAgreement() {};
    virtual ~CLAgreement() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const { return PACKET_CL_AGREEMENT; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szBYTE; }

	// get packet name
	string getPacketName() const  { return "CLAgreement"; }
	
	// get packet's debug string
	string toString() const ;

public:

	// get/set agreement �ݸ��� ����� ��� ���� ����
	bool isAgree() const { return (m_Agree ? true : false); }
	void setAgree(bool agree ) { m_Agree = agree; }

private :

	// �ݸ��� ����� ��� ���� ����
	BYTE m_Agree;
};


//--------------------------------------------------------------------------------
//
// class CLAgreementFactory;
//
// Factory for CLAgreement
//
//--------------------------------------------------------------------------------

class CLAgreementFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new CLAgreement(); }

	// get packet name
	string getPacketName() const  { return "CLAgreement"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CL_AGREEMENT; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const  { return szBYTE; }

};


//--------------------------------------------------------------------------------
//
// class CLAgreementHandler;
//
//--------------------------------------------------------------------------------

class CLAgreementHandler {

public:

	// execute packet's handler
	static void execute(CLAgreement* pPacket, Player* pPlayer) ;

};

#endif
