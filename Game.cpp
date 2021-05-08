#include "Game.h"

Game::Game() 
{
	//加载往届记录
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\演讲比赛案例\\比赛记录.csv", ios::in);
	if (!ifs.is_open())
	{
		m_isfile = false;
		m_count = 0;
	}
	else if (ifs.get() == EOF)
	{
		m_isfile = false;
		m_count = 0;
	}
	else
	{
		m_isfile = true;
		char buf[1024];
		int num = 0;
		while (ifs.getline(buf, sizeof(buf)))
		{
			if (buf[0] == '#')
			{
				num++;
			}
		}
		m_count = num + 1;
	}
	ifs.close();
}

void Game::Initgm()
{
	//if (m_isfile == false)
	//{
	//	m_count = 1;
	//}
	//else
	//{
	//	ifstream ifs;
	//	ifs.open("D:\\Programmer\\C++\\演讲比赛案例\\比赛记录.csv", ios::in);
	//	char buf[1024];
	//	int num = 0;
	//	while (ifs.getline(buf, sizeof(buf)))
	//	{
	//		if (buf[0] == '#')
	//		{
	//			num++;
	//		}
	//	}
	//	m_count = num + 1;
	//	ifs.close();
	//}
	m_round = 1;
	m_count++;
	m_v.clear();
}

void Game::Creatplayer()
{
	cout << "第" << m_count << "届演讲比赛开始" << endl;
	string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < MAXPLAYER; i++)
	{
		string name = "选手";
		name += name_seed[i];
		int age = rand() % 8 + 18;
		int id = 10001 + i;
		m_v.push_back(Player(name, age, id));
	}
}

void Game::Showplayer()
{
	cout << "=======================================" << endl;
	for (vector<Player>::iterator it = m_v.begin(); it != m_v.end(); it++)
	{
		cout << "选手：" << it->m_name << " 年龄：" << it->m_age << " 参赛编号" << it->m_id << endl;
	}
	system("pause");
}

void Game::Draw()
{
	cout << "=======================================" << endl;
	random_shuffle(m_v.begin(), m_v.end());
	if (m_round == 1)
	{
		cout << "第一轮抽签：" << endl;
		cout << "第一组：";
		for (int i = 0; i < MAXPLAYER / 2; i++)
		{
			cout << m_v[i].m_id << " ";
			m_v[i].m_group = 1;
		}
		cout << endl;
		cout << "第二组：";
		for (int i = MAXPLAYER / 2; i < MAXPLAYER; i++)
		{
			cout << m_v[i].m_id << " ";
			m_v[i].m_group = 2;
		}
		cout << endl;
	}
	else 
	{
		cout << "第二轮抽签：" << endl;
		cout << "演讲顺序如下：" << endl;
		random_shuffle(m_v.begin(), m_v.end());
		for (int i = 0; i < 6; i++)
		{
			cout << m_v[i].m_id << " ";
		}
		cout << endl;
	}
	system("pause");
}

void Game::Gameplay()
{
	cout << "=======================================" << endl;
	if (m_round == 1)
	{
		cout << "===========第一轮演讲比赛开始==========" << endl;
		Getscore();
		vector<Player>::iterator it = m_v.begin();
		cout << "第一组排名：" << endl;
		while (it != m_v.end())
		{
			if (it->m_group == 1)
			{
				cout.setf(ios::fixed);
				cout << "编号：" << it->m_id << " 姓名：" << it->m_name << " 成绩：" << fixed << setprecision(2) << it->m_avescore << endl;
			}
			it++;
		}

		it = m_v.begin();
		cout << "第二组排名：" << endl;
		while (it != m_v.end())
		{
			if (it->m_group == 2)
			{
				cout << "编号：" << it->m_id << " 姓名：" << it->m_name << " 成绩：" << fixed << setprecision(2) << it->m_avescore << endl;
			}
			it++;
		}
		m_round++;
	}
	else
	{
		cout << "===========第二轮演讲比赛开始==========" << endl;
		Getscore();
		cout << "第二轮比赛排名：" << endl;
		for (vector<Player>::iterator it = m_v.begin(); it != m_v.end(); it++)
		{
			cout << "编号：" << it->m_id << " 姓名：" << it->m_name << " 成绩：" << fixed << setprecision(2) << it->m_avescore << endl;
		}
	}
	system("pause");
}

void Game::Getscore()
{
	for (vector<Player>::iterator it = m_v.begin(); it != m_v.end(); it++)
	{
		for (int i = 0; i < MAXJUDGE; i++)
		{
			float score = (rand() % 401 + 600) / 10.f;
			(*it).m_score.push_back(score);
		}
		sort(it->m_score.begin(), it->m_score.end());
		//去除最低最高分
		it->m_score.pop_back();
		it->m_score.pop_front();
		//求和
		float sum = accumulate(it->m_score.begin(), it->m_score.end(), 0);
		//平均分
		float average = sum / it->m_score.size();
		it->m_avescore = average;
	}
	//按平均分排序
	sort(m_v.begin(), m_v.end(), Playersort);
}

void Game::Obsolete()
{
	vector<Player>::iterator it = m_v.begin();
	vector<Player> p1;
	vector<Player> p2;
	while (it != m_v.end())
	{
		if ((*it).m_group == 1)
		{
			p1.push_back(Player(*it));
		}
		else
		{
			p2.push_back(Player(*it));
		}
		it++;
	}
	for (int i = 0; i < 3; i++)
	{
		p1.pop_back();
		p2.pop_back();
	}
	m_v.clear();
	for (int i = 0; i < 3; i++)
	{
		m_v.push_back(p1[i]);
		m_v.push_back(p2[i]);
	}
}

void Game::Record()
{
	cout << "=======================================" << endl;
	cout << "比赛最终排名为：" << endl;
	for (int i = 0; i < 3; i++)
	{
		m_v.pop_back();
		cout << "第" << i+1 << "名：" << "编号：" << m_v[i].m_id << " 姓名：" << m_v[i].m_name << " 成绩：" << fixed << setprecision(2) << m_v[i].m_avescore << endl;
	}
}

void Game::Save()
{
	cout << "=======================================" << endl;
	ofstream ofs;
	if (m_isfile == false)
	{
		ofs.open("D:\\Programmer\\C++\\演讲比赛案例\\比赛记录.csv", ios::out);
		if (!ofs.is_open())
		{
			cout << "文件打开失败！" << endl;
			return;
		}
		ofs << "#第" << m_count << "届比赛结果" << endl;
		for (int i = 0; i < 3; i++)
		{
			ofs << "第" << i + 1 << "名：" << m_v[i].m_name << "," << "年龄：" << m_v[i].m_age << "," << "编号：" << m_v[i].m_id << "," << "第二轮得分：" << fixed << setprecision(2) << m_v[i].m_avescore << endl;
		}
		ofs.close();
		m_isfile = true;
	}
	else
	{
		ofs.open("D:\\Programmer\\C++\\演讲比赛案例\\比赛记录.csv", ios::app);
		if (!ofs.is_open())
		{
			cout << "文件打开失败！" << endl;
			return;
		}
		ofs << "#第" << m_count << "届比赛结果" << endl;
		for (int i = 0; i < 3; i++)
		{
			ofs << "第" << i + 1 << "名：" << m_v[i].m_name << "," << "年龄：" << m_v[i].m_age << "," << "编号：" << m_v[i].m_id << "," << "第二轮得分：" << fixed << setprecision(2) << m_v[i].m_avescore << endl;
		}
		ofs.close();
		m_isfile = true;
	}
	cout << "记录已经保存" << endl;
	cout << "本次比赛结束" << endl;
	cout << "=======================================" << endl;
}

void Game::Read()
{
	if (m_isfile == false)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		ifstream ifs;
		ifs.open("D:\\Programmer\\C++\\演讲比赛案例\\比赛记录.csv", ios::in);
		if (!ifs.is_open())
		{
			cout << "文件打开失败！" << endl;
			return;
		}
		char buf[1024] = { 0 };
		while (ifs.getline(buf, sizeof(buf)))
		{
				cout << buf << endl;
		}
		ifs.close();
	}	
}

void Game::Clearfile()
{
	cout << "是否清空数据[y/n]：" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		if (m_isfile == false)
		{
			cout << "记录文件不存在或记录为空！" << endl;
		}
		else
		{
			ofstream ofs;
			ofs.open("D:\\Programmer\\C++\\演讲比赛案例\\比赛记录.csv", ios::trunc);
			if (!ofs.is_open())
			{
				cout << "删除文件失败！" << endl;
				return;
			}
			ofs.close();
			cout << "清空记录成功！" << endl;
			m_isfile = false;
			m_count = 0;
		}
	}
	else
	{
		return;
	}
}

Game::~Game() {}

bool Playersort(const Player& p1, const Player& p2)
{
	return p1.m_avescore > p2.m_avescore;
}
