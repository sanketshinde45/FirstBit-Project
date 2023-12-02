#include <iostream>
#include<windows.h>
#include"LinkedList.h"
#include"Player.h"
using namespace std;

int main() 
{
	char username[20] = "sanket45";
	char password[20] = "shinde45";
	
	start:
	
	cout<<"\n\t\t\tPLAYER DATA MANAGEMENT \n";
	cout<<"\n\n\t\tSIGN UP \n";
	cout<<"\n\t\tEnter Username : ";
	cin>>username;
	cout<<"\n\t\tEnter Password : ";
	cin>>password;
	cout<<"\n\n\t\tPlease wait";
	for(int i=0;i<=1;i++)
	{
		cout<<".";
		Sleep(1000);
		
	}
	
	if((strcmp(username,"sanket45")==0)&&(strcmp(password,"shinde45")==0))
	{
	
	system("CLS");
		
	cout<<"/*PLAYERS STATS AND RECORD DATA*/\n\n";
	
	LinkedList player;   // this constructor is call only one time in this program
	
	int ch;
	do{
		cout<<"\n------------------------------------------------------\n";
        cout<<"\t\t\tMenu\n";
        cout<<"------------------------------------------------------\n"; 
		cout<<"1. Insert Player Data   \n";  
	    cout<<"2. Display Players Data \n";
		cout<<"3. Search Player Name   \n";
		cout<<"4. Search Player Jersey \n";
		cout<<"5. Update Player Data   \n";
		cout<<"6. Top 3 Players Data   \n";
		cout<<"7. Delete Player Data   \n";
		cout<<"0. Exit                 \n";
		cout<<"\n------------------------------------------------------\n";
		
		cout<<"Enter Your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					char name[20];
					int jersey;
					int matches;
					int runs;
					int century;
					int wickets;
					int pos;
					cout<<"------------------------------------------------------";
			      	cout<<"\n\t\tEnter Details of Player - ";
			      	cout<<"\n------------------------------------------------------";
			      	cout<<"\n Name Of Player         : ";
			      	cin>>name;
			      	cout<<"\n Player Jersey no       : ";
			      	cin>>jersey;
			      	cout<<"\n Player Total Matches   : ";
			      	cin>>matches;
			      	cout<<"\n Player Total Runs      : ";
			      	cin>>runs;
			      	cout<<"\n Player Total Centuries : ";
			      	cin>>century;
			      	cout<<"\n Player Total Wickets   : ";
			      	cin>>wickets;
			      				      						 
			        Player p1(name,jersey,matches,runs,century,wickets);
			        
			        cout<<"\n Enter At Position      : ";
			        cin>>pos;
			       
			      	if(player.insert(p1,pos))          // passing address of pd
			      	{
			      		cout<<"\n------------------------------------------------------\n";
			      		cout<<"\n*Insertion Successful*\n";
					}    	
				}
				system("CLS");
				break;
			case 2:
				{
					player.displayData();
				}
				break;
			case 3:
				{
					char name[20];
					cout<<"\nEnter Jersey Name Of Player to Search  : ";
					cin>>name;
					
					if(player.searchName(name))
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\n*Jersey Name Found*\n";
					}
					else
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\n*Jersey Name Not Found*\n";
					}
				}
				break;
			case 4:
				{
					int jersey;
					cout<<"\nEnter Jersey Number Of Player To Search  : ";
					cin>>jersey;
					
					int index = player.searchJersey(jersey); 
					
					if(index!=-1)
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\n*Jersey Number Found Successful*\n";
					}
					else
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\n*Jersey Number Not Found*\n";			
					}
				}
				break;
			case 5:
				{
					
					player.updateData();
					
				}
				break;
			case 6:
				{
				
					if(player.sortData())
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\nData Sort Succesfully\n";
					}
					else
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\nSomething Went Wrong ! Try again\n";
					}
				}
				break;
			case 7:
				{				
					if(player.deleteData())
					{
						cout<<"\n------------------------------------------------------\n";
						cout<<"\n*Data Deleted Succesfully*\n";
					}
					
						
				}
				break;
			case 0:
				{
					cout<<"\n------> THANK YOU :) \n";
				}
				break;
			default:
				{
					cout<<"\n*INVALID INPUT ! Try Again *\n";
				}
				break;								
		}
		
		
	}while(ch!=0);
	
	}
	else if((strcmp(password,"shinde45")!=0)&&(strcmp(username,"sanket45")!=0))
	{
		cout<<"\n\n\t\tIncorrect Username & Password";
		Sleep(1000);
		system("CLS");
		goto start;
	}
	else if(strcmp(username,"sanket45")!=0)
	{
		cout<<"\n\n\t\tIncorrect Username";
		Sleep(1000);
		system("CLS");
		goto start;
	}
	else
	{
		cout<<"\n\n\t\tIncorrect Password";
		Sleep(1000);
		system("CLS");
		goto start;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

