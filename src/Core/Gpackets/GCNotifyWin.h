//////////////////////////////////////////////////////////////////////////////
// Filename    : GCNotifyWin.h 
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_NOTIFY_WIN_H__
#define __GC_NOTIFY_WIN_H__

#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class GCNotifyWin;
// NPC �� ��縦 �ֺ��� PC �鿡�� �����Ѵ�.
//////////////////////////////////////////////////////////////////////////////

class GCNotifyWin : public Packet 
{
public:
    void read(SocketInputStream & iStream) ;
    void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_GC_NOTIFY_WIN; }
	PacketSize_t getPacketSize() const  { return szDWORD + szBYTE + m_Name.size(); }
	string getPacketName() const  { return "GCNotifyWin"; }
	string toString() const ;

	DWORD getGiftID() const  { return m_GiftID; }
	void setGiftID(DWORD gID)  { m_GiftID = gID; }

	string getName() const  { return m_Name; }
	void setName(const string & msg)  { m_Name = msg; }

private:
	DWORD		m_GiftID; // NPC's object id
	string		m_Name;  // chatting message
	
};


//////////////////////////////////////////////////////////////////////////////
// class GCNotifyWinFactory;
//////////////////////////////////////////////////////////////////////////////


class GCNotifyWinFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new GCNotifyWin(); }
	string getPacketName() const  { return "GCNotifyWin"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_NOTIFY_WIN; }
	PacketSize_t getPacketMaxSize() const  { return szDWORD + szBYTE + 2048 ; }
};


//////////////////////////////////////////////////////////////////////////////
// class GCNotifyWinHandler;
//////////////////////////////////////////////////////////////////////////////

class GCNotifyWinHandler 
{
public:
	static void execute(GCNotifyWin* pPacket, Player* pPlayer) ;

};

#endif
