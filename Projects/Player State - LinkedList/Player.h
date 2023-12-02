#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Player
{
		char name[20];
		int jersey;
		int matches;
		int runs;
		int century;
		int wickets;
		
		public:
			
			Player();
			
			Player(char*,int,int,int,int,int);
			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			void setName();
				
			void setJersey();
				
			void setMatches(int);
				
			void setRuns(int);
				
			void setCentury(int);
				
			void setWickets(int);
						
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			char* getName();
				
			int	getJersey();
				
			int	getMatches();
				
			int	getRuns();
				
			int	getCentury();
				
			int	getWickets();
			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
			
			void display();
				
		//	~Player();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
};
#endif