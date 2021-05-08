#include "Player.h"
Player::Player() {}
Player::Player(string name, int age, int id)
{
	m_name = name;
	m_age = age;
	m_id = id;
	m_avescore = 0;
	m_group = 0;
}
Player::Player(const Player& p)
{
	m_name = p.m_name;
	m_age = p.m_age;
	m_id = p.m_id;
	m_avescore = p.m_avescore;
	m_group = p.m_group;
}
Player::~Player() {}