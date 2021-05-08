#pragma once
#include<iostream>
using namespace std;
#include "Player.h"
#include<vector>
#include<string>
#include<ctime>
#include<algorithm>
#include<numeric>
#include<iomanip>
#include<fstream>
#define MAXPLAYER 12
#define MAXJUDGE 10

class Game
{
public:
	vector<Player> m_v;
	int m_count;
	int m_round;
	bool m_isfile;
	Game();
	void Initgm();
	void Creatplayer();
	void Showplayer();
	void Draw();
	void Gameplay();
	void Getscore();
	void Obsolete();
	void Record();
	void Save();
	void Read();
	void Clearfile();
	~Game();
};

bool Playersort(const Player& p1, const Player& p2);