#include "EffectGDRLairClose.h"
#include "GDRLairManager.h"
#include "GCSystemMessage.h"
#include "ZoneGroupManager.h"
#include <cstdio>

void EffectGDRLairClose::affect() 
{
	setNextTime( 600 );

	char msg[200];
	sprintf(msg, "%d�ֺ�,���ر��ȴ����й����.", m_MinutesCount );
	GCSystemMessage gcSM;
	gcSM.setMessage(msg);
	g_pZoneGroupManager->broadcast( &gcSM );
	m_MinutesCount--;
}

void EffectGDRLairClose::unaffect() 
{
	__BEGIN_TRY

	cout << "���巹 ���� �ݽ��ϴ�." << endl;
	GDRLairManager::Instance().close();

	GCSystemMessage gcSM;
	gcSM.setMessage("�ȴ����й��ѹر�.");
	g_pZoneGroupManager->broadcast( &gcSM );

	__END_CATCH
}
