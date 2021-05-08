#include "Game.h"

Game::Game() 
{
	//���������¼
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\�ݽ���������\\������¼.csv", ios::in);
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
	//	ifs.open("D:\\Programmer\\C++\\�ݽ���������\\������¼.csv", ios::in);
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
	cout << "��" << m_count << "���ݽ�������ʼ" << endl;
	string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < MAXPLAYER; i++)
	{
		string name = "ѡ��";
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
		cout << "ѡ�֣�" << it->m_name << " ���䣺" << it->m_age << " �������" << it->m_id << endl;
	}
	system("pause");
}

void Game::Draw()
{
	cout << "=======================================" << endl;
	random_shuffle(m_v.begin(), m_v.end());
	if (m_round == 1)
	{
		cout << "��һ�ֳ�ǩ��" << endl;
		cout << "��һ�飺";
		for (int i = 0; i < MAXPLAYER / 2; i++)
		{
			cout << m_v[i].m_id << " ";
			m_v[i].m_group = 1;
		}
		cout << endl;
		cout << "�ڶ��飺";
		for (int i = MAXPLAYER / 2; i < MAXPLAYER; i++)
		{
			cout << m_v[i].m_id << " ";
			m_v[i].m_group = 2;
		}
		cout << endl;
	}
	else 
	{
		cout << "�ڶ��ֳ�ǩ��" << endl;
		cout << "�ݽ�˳�����£�" << endl;
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
		cout << "===========��һ���ݽ�������ʼ==========" << endl;
		Getscore();
		vector<Player>::iterator it = m_v.begin();
		cout << "��һ��������" << endl;
		while (it != m_v.end())
		{
			if (it->m_group == 1)
			{
				cout.setf(ios::fixed);
				cout << "��ţ�" << it->m_id << " ������" << it->m_name << " �ɼ���" << fixed << setprecision(2) << it->m_avescore << endl;
			}
			it++;
		}

		it = m_v.begin();
		cout << "�ڶ���������" << endl;
		while (it != m_v.end())
		{
			if (it->m_group == 2)
			{
				cout << "��ţ�" << it->m_id << " ������" << it->m_name << " �ɼ���" << fixed << setprecision(2) << it->m_avescore << endl;
			}
			it++;
		}
		m_round++;
	}
	else
	{
		cout << "===========�ڶ����ݽ�������ʼ==========" << endl;
		Getscore();
		cout << "�ڶ��ֱ���������" << endl;
		for (vector<Player>::iterator it = m_v.begin(); it != m_v.end(); it++)
		{
			cout << "��ţ�" << it->m_id << " ������" << it->m_name << " �ɼ���" << fixed << setprecision(2) << it->m_avescore << endl;
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
		//ȥ�������߷�
		it->m_score.pop_back();
		it->m_score.pop_front();
		//���
		float sum = accumulate(it->m_score.begin(), it->m_score.end(), 0);
		//ƽ����
		float average = sum / it->m_score.size();
		it->m_avescore = average;
	}
	//��ƽ��������
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
	cout << "������������Ϊ��" << endl;
	for (int i = 0; i < 3; i++)
	{
		m_v.pop_back();
		cout << "��" << i+1 << "����" << "��ţ�" << m_v[i].m_id << " ������" << m_v[i].m_name << " �ɼ���" << fixed << setprecision(2) << m_v[i].m_avescore << endl;
	}
}

void Game::Save()
{
	cout << "=======================================" << endl;
	ofstream ofs;
	if (m_isfile == false)
	{
		ofs.open("D:\\Programmer\\C++\\�ݽ���������\\������¼.csv", ios::out);
		if (!ofs.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		ofs << "#��" << m_count << "��������" << endl;
		for (int i = 0; i < 3; i++)
		{
			ofs << "��" << i + 1 << "����" << m_v[i].m_name << "," << "���䣺" << m_v[i].m_age << "," << "��ţ�" << m_v[i].m_id << "," << "�ڶ��ֵ÷֣�" << fixed << setprecision(2) << m_v[i].m_avescore << endl;
		}
		ofs.close();
		m_isfile = true;
	}
	else
	{
		ofs.open("D:\\Programmer\\C++\\�ݽ���������\\������¼.csv", ios::app);
		if (!ofs.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		ofs << "#��" << m_count << "��������" << endl;
		for (int i = 0; i < 3; i++)
		{
			ofs << "��" << i + 1 << "����" << m_v[i].m_name << "," << "���䣺" << m_v[i].m_age << "," << "��ţ�" << m_v[i].m_id << "," << "�ڶ��ֵ÷֣�" << fixed << setprecision(2) << m_v[i].m_avescore << endl;
		}
		ofs.close();
		m_isfile = true;
	}
	cout << "��¼�Ѿ�����" << endl;
	cout << "���α�������" << endl;
	cout << "=======================================" << endl;
}

void Game::Read()
{
	if (m_isfile == false)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		ifstream ifs;
		ifs.open("D:\\Programmer\\C++\\�ݽ���������\\������¼.csv", ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
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
	cout << "�Ƿ��������[y/n]��" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		if (m_isfile == false)
		{
			cout << "��¼�ļ������ڻ��¼Ϊ�գ�" << endl;
		}
		else
		{
			ofstream ofs;
			ofs.open("D:\\Programmer\\C++\\�ݽ���������\\������¼.csv", ios::trunc);
			if (!ofs.is_open())
			{
				cout << "ɾ���ļ�ʧ�ܣ�" << endl;
				return;
			}
			ofs.close();
			cout << "��ռ�¼�ɹ���" << endl;
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
