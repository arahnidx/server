//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGRideMotorCycle.h 
// Written By  : elca@ewestsoft.com
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_RIDE_MOTORCYCLE_H__
#define __CG_RIDE_MOTORCYCLE_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGRideMotorCycle;
//
//////////////////////////////////////////////////////////////////////

class CGRideMotorCycle : public Packet {

public:
	
	// constructor
	CGRideMotorCycle() ;
	
	// destructor
	~CGRideMotorCycle() ;

	
public:
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CG_RIDE_MOTORCYCLE; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const  { return szObjectID + szCoord + szCoord ; }

	// get packet name
	string getPacketName() const  { return "CGRideMotorCycle"; }

	// get/set ObjectID
	ObjectID_t getObjectID() const   { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	// get/set X
	Coord_t getX() const  { return m_X; }
	void setX(Coord_t X)  { m_X = X; }

	// get/set Y
	Coord_t getY() const  { return m_Y; }
	void setY(Coord_t Y)  { m_Y = Y; }
	
	// get packet's debug string
	string toString() const ;

private :

	// ObjectID
	ObjectID_t m_ObjectID;

	// Coord X
	Coord_t m_X;

	// Coord Y
	Coord_t m_Y;
	
};


//////////////////////////////////////////////////////////////////////
//
// class CGRideMotorCycleFactory;
//
// Factory for CGRideMotorCycle
//
//////////////////////////////////////////////////////////////////////

class CGRideMotorCycleFactory : public PacketFactory {

public:
	
	// constructor
	CGRideMotorCycleFactory()  {}
	
	// destructor
	virtual ~CGRideMotorCycleFactory()  {}

	
public:
	
	// create packet
	Packet* createPacket()  { return new CGRideMotorCycle(); }

	// get packet name
	string getPacketName() const  { return "CGRideMotorCycle"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_RIDE_MOTORCYCLE; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szObjectID + szCoord + szCoord; }

};


//////////////////////////////////////////////////////////////////////
//
// class CGRideMotorCycleHandler;
//
//////////////////////////////////////////////////////////////////////

class CGRideMotorCycleHandler {

public:

	// execute packet's handler
	static void execute(CGRideMotorCycle* pCGRideMotorCycle, Player* pPlayer) ;

};

#endif
