//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGSelectGuild.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_SELECT_GUILD_H__
#define __CG_SELECT_GUILD_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGSelectGuild;
//
//////////////////////////////////////////////////////////////////////

class CGSelectGuild : public Packet
{
public:
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CG_SELECT_GUILD; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szGuildID; }

	// get packet name
	string getPacketName() const  { return "CGSelectGuild"; }

	// get packet's debug string
	string toString() const ;

	// get/set GuildID
	GuildID_t getGuildID() const  { return m_GuildID; }
	void setGuildID( GuildID_t GuildID )  { m_GuildID = GuildID; }


private :

	// Guild ID
	GuildID_t m_GuildID;
	
};


//////////////////////////////////////////////////////////////////////
//
// class CGSelectGuildFactory;
//
// Factory for CGSelectGuild
//
//////////////////////////////////////////////////////////////////////

class CGSelectGuildFactory : public PacketFactory {

public:
	
	// constructor
	CGSelectGuildFactory()  {}
	
	// destructor
	virtual ~CGSelectGuildFactory()  {}

	
public:
	
	// create packet
	Packet* createPacket()  { return new CGSelectGuild(); }

	// get packet name
	string getPacketName() const  { return "CGSelectGuild"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_SELECT_GUILD; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szGuildID; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGSelectGuildHandler;
//
//////////////////////////////////////////////////////////////////////

class CGSelectGuildHandler {

public:

	// execute packet's handler
	static void execute(CGSelectGuild* pCGSelectGuild, Player* pPlayer) ;

};

#endif
