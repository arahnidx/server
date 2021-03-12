//////////////////////////////////////////////////////////////////////////////
// Filename    : ConnectionInfo.h
// Written by  : reiot@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __CONNECTION_INFO_H__
#define __CONNECTION_INFO_H__

#include "Types.h"
#include "Exception.h"
#include "Timeval.h"

//////////////////////////////////////////////////////////////////////////////
// class ConnectionInfo;
// ������ �̵����� ������ ���ῡ ���� ������ ��Ÿ���� ��ü
//////////////////////////////////////////////////////////////////////////////

class ConnectionInfo 
{
public:
	ConnectionInfo() ;
	~ConnectionInfo() ;

public:
	string getClientIP() const  { return m_ClientIP; }
	void setClientIP(const string & clientIP)  { m_ClientIP = clientIP; }

	string getPlayerID() const  { return m_PlayerID; }
	void setPlayerID(const string & PlayerID)  { m_PlayerID = PlayerID; }
	
	string getPCName() const  { return m_PCName; }
	void setPCName(const string & name)  { m_PCName = name; }

	Timeval getExpireTime() const  { return m_ExpireTime; }
	void setExpireTime(Timeval tv)  { m_ExpireTime = tv; }
	
	DWORD getKey() const  { return m_Key; }
	void setKey(DWORD key)  { m_Key = key; }

	string toString() const ;

private:
	string  m_ClientIP;   // valid client's ip
	string  m_PlayerID;   // PlayerID
	string  m_PCName;     // PC name
	Timeval m_ExpireTime; // expire time : �������� �� ������ �����ϰ� �־�� �ϴ���..
	DWORD   m_Key;        // validation key
};

//////////////////////////////////////////////////////////////////////////////
// CompareConnectionInfo
//
// priority_queue ���� ConnectionInfo ���� ���� �� ����ϴ� Ŭ�����
//
// *CAUTION*
//
// �ð������� �̸�(�ð����� ����) ���� PQ �� top �� ��ġ�ؾ� �Ѵ�.
// �� PQ �� ascending order �� �̷�� �Ѵ�. �� �׷����� �� ���캸�⸦..
// �ð��� ���� �����.. - -;
//////////////////////////////////////////////////////////////////////////////

class CompareConnectionInfo 
{
public:
	// compare which is more recent
    bool operator()(const ConnectionInfo & left, const ConnectionInfo & right)
    {
		// Ascending Order
        return left.getExpireTime() > right.getExpireTime();

		// Descending Order
        //return left.getExpireTime() < right.getExpireTime();
    }
};

#endif
