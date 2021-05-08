#pragma once
#include<iostream>
using namespace std;
#include"Game.h"

class SysManager
{
public:
	Game m_gm;
	SysManager();
	void ShowUI();
	void PlayGame();
	void Query();
	void Clear();
	void exitSys();
	~SysManager();
};

