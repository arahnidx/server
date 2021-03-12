////////////////////////////////////////////////////////////////////////////////
// Filename    : PropertyBuffer.h
// Written By  : 
// Description :
// DB�� TEXT �� ����� Condition/Action �ʵ带 �Ľ����ش�.
// Properties �� �ٸ� ����, Properties �� ���� ������ ��� �Ľ��ؼ� map ����
// ��ȯ�� ����, getProperty() �� ȣ��Ǹ� ������ value �� ����������,
// PropertyBuffer �� ���ο� ū ��Ʈ���� ���۸� �ΰ�, getProperty()�� ȣ���
// ������ ������ �տ������� �Ľ��� �ѹ��� �����Ѵٴ� ���̴�.
////////////////////////////////////////////////////////////////////////////////

#ifndef __PROPERTY_BUFFER_H__
#define __PROPERTY_BUFFER_H__

#include "Types.h"
#include "Exception.h"

//////////////////////////////////////////////////////////////////////////////
// class PropertyBuffer;
//////////////////////////////////////////////////////////////////////////////

class PropertyBuffer 
{
public:
	static const char Comment;
	static const char Separator;
	static const char EOL;
	static const char* WhiteSpaces;
	static const char* SpaceTab;
	
public:
	PropertyBuffer(const string & buffer) ;
	~PropertyBuffer() ;
	
public:
	string getProperty(string key) ;
	int getPropertyInt(string key) ;

	bool getProperty(string key, string& value) ;
	bool getPropertyInt(string key, int& value) ;

	string toString() const ;
	
private:
	size_t   m_Index;
	string m_Buffer;
	
};

#endif
