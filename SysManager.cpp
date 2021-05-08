#include "SysManager.h"
SysManager::SysManager()
{
	cout << "欢迎使用演讲比赛系统！" << endl;
	srand((unsigned int)time(NULL));
	Game m_gm;
}
void SysManager::ShowUI()
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 *************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛系统  *************" << endl;
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
	cout << "系统已退出，欢迎下次使用！" << endl;
	system("pause");
	exit(1);
}

SysManager::~SysManager()
{
	
}