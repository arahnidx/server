//----------------------------------------------------------------------
// 
// Filename    : GLKickVerify.h 
// Written By  : Reiot
// Description : 
// 
//----------------------------------------------------------------------

#ifndef __GL_KICK_VERIFY_H__
#define __GL_KICK_VERIFY_H__

// include files
#include "DatagramPacket.h"
#include "PacketFactory.h"


//----------------------------------------------------------------------
//
// class GLKickVerify;
//
// '�̹� ���� ��' ������ �ذ��ϱ� ����...
// LGKickCharacter�� �����ϴ� ��� ��Ŷ�̴�.
//
//----------------------------------------------------------------------

class GLKickVerify : public DatagramPacket {

public :
	
    // Datagram ��ü�������� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(Datagram & iDatagram) ;
		    
    // Datagram ��ü�� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(Datagram & oDatagram) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GL_KICK_VERIFY; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  
	{ 
		return szBYTE + szBYTE + m_PCName.size() + szuint;
	}

	// get packet name
	string getPacketName() const  { return "GLKickVerify"; }
	
	// get packet's debug string
	string toString() const ;

public :

	// get/set playerID
	bool isKicked() const  { return m_bKicked; }
	void setKicked(bool bKicked=true)  { m_bKicked = bKicked; }

  	// get/set pcName
    string getPCName() const  { return m_PCName; }
    void setPCName(const string& pcName)  { m_PCName = pcName; }

    uint getID() const  { return m_ID; }
    void setID(uint id)  { m_ID = id; }

	
private :

	// Player ID
	bool   m_bKicked;

	string m_PCName;

	uint   m_ID;
};


//////////////////////////////////////////////////////////////////////
//
// class GLKickVerifyFactory;
//
// Factory for GLKickVerify
//
//////////////////////////////////////////////////////////////////////

class GLKickVerifyFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket()  { return new GLKickVerify(); }

	// get packet name
	string getPacketName() const  { return "GLKickVerify"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GL_KICK_VERIFY; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GLKickVerifyPacketMaxSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const  
	{ 
		return szBYTE + szBYTE + 20 + szuint;
	}

};


//////////////////////////////////////////////////////////////////////
//
// class GLKickVerifyHandler;
//
//////////////////////////////////////////////////////////////////////

class GLKickVerifyHandler {
	
public :

	// execute packet's handler
	static void execute(GLKickVerify* pPacket) ;

};

#endif
