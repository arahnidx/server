//--------------------------------------------------------------------------------
// 
// Filename    : CLRegisterPlayer.h 
// Written By  : Reiot
// 
//--------------------------------------------------------------------------------

#ifndef __CL_REGISTER_PLAYER_H__
#define __CL_REGISTER_PLAYER_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//--------------------------------------------------------------------------------
//
// class CLRegisterPlayer;
//
// Ŭ���̾�Ʈ�� �α��� �������� ���ʿ� �����ϴ� ��Ŷ�̴�.
// ���̵�� �н����尡 ��ȣȭ�Ǿ� �ִ�. ������ �ƴϴ�..
//
//--------------------------------------------------------------------------------

class CLRegisterPlayer : public Packet {

public:
	CLRegisterPlayer() {};
    virtual ~CLRegisterPlayer() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) ;
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_CL_REGISTER_PLAYER; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const 
	{
		// ����ȭ�� �̸� ���� ����� ����ϵ��� �Ѵ�.
		return    szBYTE + m_ID.size() 			// ���̵�
				+ szBYTE + m_Password.size() 	// ��ȣ
				+ szBYTE + m_Name.size() 		// �̸�
				+ szBYTE						// ����
				+ szBYTE + m_SSN.size() 		// �ֹε�Ϲ�ȣ
				+ szBYTE + m_Telephone.size() 	// ��ȭ��ȣ
				+ szBYTE + m_Cellular.size() 	// �޴�����ȣ
				+ szBYTE + m_ZipCode.size() 	// �����ȣ
				+ szBYTE + m_Address.size() 	// �ּ�
				+ szBYTE 						// �����ڵ�
				+ szBYTE + m_Email.size() 		// ���ڸ���
				+ szBYTE + m_Homepage.size() 	// Ȩ������
				+ szBYTE + m_Profile.size() 	// �ڱ�Ұ���
				+ szBYTE;						// ��������
	}

	// get packet name
	string getPacketName() const  { return "CLRegisterPlayer"; }
	
	// get packet's debug string
	string toString() const ;

public:

	//----------------------------------------------------------------------
	// *CAUTION* 
	// �� setXXX()���� �ִ� ���̸� üũ�ؼ� truncate ������, �ּұ��̴� 
	// üũ���� �ʴ´�. �ּ� ���̴� read()/write() ���� üũ�ȴ�. 
	//----------------------------------------------------------------------

    // get/set player's id
	string getID() const  { return m_ID; }
	void setID(string id)  { m_ID =(id.size() > maxIDLength) ? id.substr(0,maxIDLength) : id; }

    // get/set player's password
    string getPassword() const  { return m_Password; }
    void setPassword(string password)  { m_Password =(password.size() > maxPasswordLength) ? password.substr(0,maxPasswordLength) : password; }

    // get/set player's name
    string getName() const  { return m_Name; }
    void setName(string name)  { m_Name =(name.size() > maxNameLength) ? name.substr(0,maxNameLength) : name; }

    // get/set player's sex
    Sex getSex() const  { return m_Sex; }
    void setSex(Sex sex)  { m_Sex = sex; }

    // get/set player's ssn
    string getSSN() const  { return m_SSN; }
    void setSSN(string ssn)  { m_SSN =(ssn.size() > maxSSNLength) ? ssn.substr(0,maxSSNLength) : ssn; }

    // get/set player's telephone
    string getTelephone() const  { return m_Telephone; }
    void setTelephone(string telephone)  { m_Telephone =(telephone.size() > maxTelephoneLength) ? telephone.substr(0,maxTelephoneLength) : telephone; }

    // get/set player's cellular
    string getCellular() const  { return m_Cellular; }
    void setCellular(string cellular)  { m_Cellular =(cellular.size() > maxCellularLength) ? cellular.substr(0,maxCellularLength) : cellular; }

    // get/set player's zipcode
    string getZipCode() const  { return m_ZipCode; }
    void setZipCode(string zipcode)  { m_ZipCode =(zipcode.size() > maxZipCodeLength) ? zipcode.substr(0,maxZipCodeLength) : zipcode; }

    // get/set player's address
    string getAddress() const  { return m_Address; }
    void setAddress(string address)  { m_Address =(address.size() > maxAddressLength) ? address.substr(0,maxAddressLength) : address; }

    // get/set player's nation
    Nation getNation() const  { return m_Nation; }
    void setNation(Nation nation)  { m_Nation = nation; }

    // get/set player's email
    string getEmail() const  { return m_Email; }
    void setEmail(string email)  { m_Email =(email.size() > maxEmailLength) ? email.substr(0,maxEmailLength) : email; }

    // get/set player's homepage
    string getHomepage() const  { return m_Homepage; }
    void setHomepage(string homepage)  { m_Homepage =(homepage.size() > maxHomepageLength) ? homepage.substr(0,maxHomepageLength) : homepage; }

    // get/set player's profile
    string getProfile() const  { return m_Profile; }
    void setProfile(string profile)  { m_Profile =(profile.size() > maxProfileLength) ? profile.substr(0,maxProfileLength) : profile; }

	// get/set player info's publicability(?) 
	bool getPublic() const  { return m_bPublic; }
	void setPublic(bool bPublic)  { m_bPublic = bPublic; }

private :

	//--------------------------------------------------
	// �÷��̾� �⺻ ����
	//--------------------------------------------------
    string m_ID; 			// ���̵�
    string m_Password; 		// �н�����
	//--------------------------------------------------
	// �÷��̾� ���� ����
	//--------------------------------------------------
    string m_Name; 			// �̸�
    Sex m_Sex; 				// ����
    string m_SSN; 			// �ֹε�Ϲ�ȣ
	//--------------------------------------------------
	// �÷��̾� ����ó/�ּ�
	//--------------------------------------------------
    string m_Telephone; 	// ��ȭ��ȣ
    string m_Cellular; 		// �ڵ���
    string m_ZipCode; 		// �����ȣ
    string m_Address; 		// �ּ�
    Nation m_Nation; 		// ���� �ڵ�
	//--------------------------------------------------
	// �÷��̾� ��������
	//--------------------------------------------------
    string m_Email; 		// ���ڸ���
    string m_Homepage; 		// Ȩ������
	//--------------------------------------------------
	// ��Ÿ 
	//--------------------------------------------------
    string m_Profile; 		// �ϰ��¸�
	bool m_bPublic; 		// ���� ����

};


//--------------------------------------------------------------------------------
//
// class CLRegisterPlayerFactory;
//
// Factory for CLRegisterPlayer
//
//--------------------------------------------------------------------------------

class CLRegisterPlayerFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket()  { return new CLRegisterPlayer(); }

	// get packet name
	string getPacketName() const  { return "CLRegisterPlayer"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_CL_REGISTER_PLAYER; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const 
	{
		// ����ȭ�� �̸� ���� ����� ����ϵ��� �Ѵ�.
		return    szBYTE + maxIDLength 			// ���̵�
				+ szBYTE + maxPasswordLength 	// �н�����
				+ szBYTE + maxNameLength 		// �̸�
				+ szBYTE									// ����
				+ szBYTE + maxSSNLength 		// �ֹε�Ϲ�ȣ
				+ szBYTE + maxTelephoneLength 	// ��ȭ��ȣ
				+ szBYTE + maxCellularLength 	// �޴�����ȣ
				+ szBYTE + maxZipCodeLength 	// �����ȣ
				+ szBYTE + maxAddressLength 	// �ּ�
				+ szBYTE 									// �����ڵ�
				+ szBYTE + maxEmailLength 		// ���ڸ���
				+ szBYTE + maxHomepageLength 	// Ȩ������
				+ szBYTE + maxProfileLength 	// �ڱ�Ұ�
				+ szBYTE;									// ��������
	}


};


//--------------------------------------------------------------------------------
//
// class CLRegisterPlayerHandler;
//
//--------------------------------------------------------------------------------

class CLRegisterPlayerHandler {

public:

	// execute packet's handler
	static void execute(CLRegisterPlayer* pPacket, Player* pPlayer) ;

};

#endif
