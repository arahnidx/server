//----------------------------------------------------------------------
// 
// Filename    : SGQuitGuildOK.h 
// Written By  : Reiot
// Description : 
// 
//----------------------------------------------------------------------

#ifndef __SG_QUIT_GUILD_OK_H__
#define __SG_QUIT_GUILD_OK_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//----------------------------------------------------------------------
//
// class SGQuitGuildOK;
//
// ���� �߰� �Ǿ����� ���Ӽ����� �˸���.
//
// *CAUTION*
//
//----------------------------------------------------------------------

class SGQuitGuildOK : public Packet {

public:
	SGQuitGuildOK() {};
    ~SGQuitGuildOK() {};
    // Datagram ��ü�������� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream& iStream) ;
		    
    // Datagram ��ü�� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream& oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_SG_QUIT_GUILD_OK; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  
	{ 
		return szGuildID +			// guild ID
			   szBYTE +				// name length
			   m_Name.size();		// name size
	}

	// get packet name
	string getPacketName() const  { return "SGQuitGuildOK"; }
	
	// get packet's debug string
	string toString() const ;

public:

	// get/set guildID
	GuildID_t getGuildID() const  { return m_GuildID; }
	void setGuildID(GuildID_t guildID )  { m_GuildID = guildID; }

	// get/set guild name
	const string& getName() const  { return m_Name; }
	void setName(const string& name )  { m_Name = name; }

private :

	// GuildID
	GuildID_t m_GuildID;

	// name
	string m_Name;

};


//////////////////////////////////////////////////////////////////////
//
// class SGQuitGuildOKFactory;
//
// Factory for SGQuitGuildOK
//
//////////////////////////////////////////////////////////////////////

class SGQuitGuildOKFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new SGQuitGuildOK(); }

	// get packet name
	string getPacketName() const  { return "SGQuitGuildOK"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_SG_QUIT_GUILD_OK; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static LGIncomingConnectionPacketMaxSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const  
	{ 
		return szGuildID +				// guild ID
			   szBYTE +					// name length
			   20; 						// name max size
	}

};


//////////////////////////////////////////////////////////////////////
//
// class LGIncomingConnectionHandler;
//
//////////////////////////////////////////////////////////////////////

class SGQuitGuildOKHandler {
	
public:

	// execute packet's handler
	static void execute(SGQuitGuildOK* pPacket) ;

};

#endif
