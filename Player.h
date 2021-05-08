#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<deque>
class Player
{
public:
	string m_name;
	int m_age;
	int m_id;
	deque<float> m_score;
	float m_avescore;
	int m_group;
	Player();
	Player(string name, int age, int id);
	Player(const Player& p);
	~Player();
};

