#include"Player.h"
#include"LinkedList.h"
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Player::Player()
{
	strcpy(this->name,"Not Given");
	jersey= 0;
	matches= 0;
	runs= 0;
	century= 0;
	wickets= 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Player::Player(char* name,int jersey,int matches,int runs,int century,int wickets)
{
	strcpy(this->name,name);
	this->jersey=jersey;
	this->matches=matches;
	this->runs=runs;
	this->century=century;
	this->wickets=wickets;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Player::setMatches(int match)
{
	this->matches=match;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Player::setRuns(int runs)
{
	this->runs=runs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Player::setWickets(int wickets)
{
	this->wickets=wickets;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Player::setCentury(int century)
{
	this->century=century;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Player::getMatches()
{
	return matches;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* Player::getName()
{
	return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Player::getJersey()
{
	return jersey;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Player::getRuns()
{
	return runs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Player::getWickets()
{
	return wickets;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Player::display()
{

	cout<<name<<"\t"<<jersey<<"\t"<<matches<<"\t"<<runs<<"\t"<<century<<"\t"<<wickets<<"\n";
	cout<<"------------------------------------------------------\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Player::~Player()
//{
//	cout<<"\nPlayer Memory Released\n";
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

