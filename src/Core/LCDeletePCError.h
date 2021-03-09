//////////////////////////////////////////////////////////////////////
// 
// Filename    : LCDeletePCError.h 
// Written By  : Reiot
// Description :
// 
//////////////////////////////////////////////////////////////////////

#ifndef __LC_DELETE_PC_ERROR_H__
#define __LC_DELETE_PC_ERROR_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class LCDeletePCError;
//
//////////////////////////////////////////////////////////////////////

class LCDeletePCError : public Packet {

public:
	LCDeletePCError() {};
    ~LCDeletePCError() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_LC_DELETE_PC_ERROR; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szBYTE; }
	
	// get packet's name
	string getPacketName() const  { return "LCDeletePCError"; }
	
	// get packet's debug string
	string toString() const ;
	
	// get/set error message
//	string getMessage() const  { return m_Message; }
//	void setMessage(string message)  { m_Message = message; }
	// get /set ErrorID
	BYTE getErrorID() const  { return m_ErrorID; }
	void setErrorID(BYTE ErrorID)  { m_ErrorID = ErrorID; }

private : 

	// ���� �޽���
	BYTE m_ErrorID;

};


//////////////////////////////////////////////////////////////////////
//
// class LCDeletePCErrorFactory;
//
// Factory for LCDeletePCError
//
//////////////////////////////////////////////////////////////////////

class LCDeletePCErrorFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new LCDeletePCError(); }

	// get packet name
	string getPacketName() const  { return "LCDeletePCError"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_LC_DELETE_PC_ERROR; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const  { return szBYTE; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class LCDeletePCErrorHandler;
//
//////////////////////////////////////////////////////////////////////

class LCDeletePCErrorHandler {

public:

	// execute packet's handler
	static void execute(LCDeletePCError* pPacket, Player* pPlayer) ;

};

#endif
