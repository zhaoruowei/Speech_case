#include "SysManager.h"
SysManager::SysManager()
{
	cout << "��ӭʹ���ݽ�����ϵͳ��" << endl;
	srand((unsigned int)time(NULL));
	Game m_gm;
}
void SysManager::ShowUI()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳�����ϵͳ  *************" << endl;
	cout << "********************************************" << endl;
}
void SysManager::PlayGame()
{
	m_gm.Initgm();
	m_gm.Creatplayer();
	m_gm.Showplayer();
	m_gm.Draw();
	m_gm.Gameplay();
	m_gm.Obsolete();
	m_gm.Draw();
	m_gm.Gameplay();
	m_gm.Record();
	m_gm.Save();
}

void SysManager::Query()
{
	m_gm.Read();
}

void SysManager::Clear()
{
	m_gm.Clearfile();
}

void SysManager::exitSys()
{
	cout << "ϵͳ���˳�����ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(1);
}

SysManager::~SysManager()
{
	
}