#include"LinkedList.h"
#include<string.h>
#include<iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinkedList::LinkedList()
{
	start=NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::insert(Player &d,int pos)
{
	// 1. create new node
	
	Node *temp = new Node(d);
	
	if(start == NULL)
	{
		start = temp;
		return false;
	}
	
	// Insert at beginning
	
	if(pos==1)
	{
		temp->setNext(start);
		start = temp;
		return true;
	}
	
	int i = 1;		
	Node *p = start;
		
	while(i<pos-1 && p->getNext()!= NULL)
	{
		p = p->getNext();
		i++;
	}
	
	// Attach The new Node
	
	temp->setNext(p->getNext());
	p->setNext(temp);
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::searchName(char* name)
{
	if(start==NULL)
	{
		cout<<"\n------------------------------------------------------\n";
		cout<<"\nData is Not Available ? Insert Data...\n";
		return false;
	}
	else
	{
		Node *p = start;
		
		while(p!=NULL)
		{
			if(strcmp(name,p->getData().getName())==0)
			{
				cout<<"\nList of All Players:\n";
				cout<<"------------------------------------------------------\n";
				cout<<" Name  Jersey  Matches  Runs  Century  Wickets\n";
				cout<<"------------------------------------------------------\n";
				p->getData().display();
				return true;
			}
			p=p->getNext();
		}
		
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::searchJersey(int jersey)
{
	if(start==NULL)
	{
		cout<<"\n------------------------------------------------------\n";
		cout<<"\nData is Not Available ? Insert Data...\n";
		return false;
	}
	else
	{
		Node *p = start;
		
		while(p!=NULL)
		{
			if(p->getData().getJersey()==jersey)
			{
				cout<<"\nList of All Players:\n";
				cout<<"------------------------------------------------------\n";
				cout<<" Name  Jersey  Matches  Runs  Century  Wickets\n";
				cout<<"------------------------------------------------------\n";
				p->getData().display();
				return true;
			}
			p=p->getNext();
		}
		

	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::updateData()
{
	
	if(start==NULL)
	{
		cout<<"\n------------------------------------------------------\n";
		cout<<"\nData is Not Available ? Insert Data...\n";
		return false;
	}
	else
	{
		int jerseyNo,ch;
		cout<<"\nEnter Jersey Number Of Player To Update : ";
		cin>>jerseyNo;
		
		Node *p = start;
		
		Player p1;
		
		while(p!=NULL)
		{
			if(p->getData().getJersey()==jerseyNo)
			{
				p1=p->getData();
			 do{
					cout<<"\nWhich Data You Want To Update : \n";
					cout<<"1. Player Matches\n";
					cout<<"2. Player Runs\n";
					cout<<"3. Player Century\n";
					cout<<"4. Player Wickets\n";
					cout<<"0. Back To Main Menu\n";
					
					cout<<"\nEnter your choice : ";
					cin>>ch;
					
					switch(ch)
					{
						case 1:
							{
								int match;
								cout<<"\nUpdate Matches Of "<<p->getData().getName()<<" : ";
								cin>>match;
								cout<<"\n";
							
							 //	cout<<"Matches : "<<p->getData().getMatches();
							 	p1.setMatches(match);
							
							 	p->setData(p1);
	
							}
							break;
						case 2:
							{
								int runs;
								cout<<"\nUpdate Runs Of "<<p->getData().getName()<<" : ";
								cin>>runs;
								cout<<"\n";
								
								p1.setRuns(runs);
								
								p->setData(p1);
							}
							break;
						case 3:
							{
								int century;
								cout<<"\nUpdate Century Of "<<p->getData().getName()<<" : ";
								cin>>century;
								cout<<"\n";
								
								p1.setCentury(century);
								p->setData(p1);
							}
							break;
						case 4:
							{
								int wickets;
								cout<<"\nUpdate Wickets Of "<<p->getData().getName()<<" : ";
								cin>>wickets;
								cout<<"\n";
								
								p1.setWickets(wickets);
								
								p->setData(p1);
							}
							break;
						case 0:
							{
								cout<<"\n------------------------------------------------------\n";
								cout<<"\nUpdation Done :)\n";
							}
							break;	
						default:
							{
								cout<<"\n------------------------------------------------------\n";
								cout<<"\n*Invalid Input*\n";
							}
							break;				
					}	
					
				}while(ch!=0);
				
			//	return true;
			}
			
			p=p->getNext();
		}
		return true;
		
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::sortData()
{
	
	if(start==NULL)
	{
		cout<<"\n------------------------------------------------------\n";
		cout<<"\nData is Not Available ? Insert Data...\n";
		return false;
	}
	else
	{
		int ch,i,j;
		Player temp;
		cout<<"1. Sort By Runs\n";
		cout<<"2. Sort By Wickets\n";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		cout<<"\n";
		
		Node *p = start;             // prev
		
		Node *q = start->getNext();  // current	
			
		if(ch==1)
		{
			
			while(q!=NULL)
			{
				if(q->getData().getRuns()>p->getData().getRuns())
				{
					p->setNext(q->getNext());
				
					q->setNext(start);
					
					start=q;
					
					q=p;
			
				}
				else
				{
					p=q;
					
					q=q->getNext();
				}
			}	
		}
		else if(ch==2)
		{
			while(q!=NULL)
			{
				if(q->getData().getWickets()>p->getData().getWickets())
				{
					p->setNext(q->getNext());
				
					q->setNext(start);
					
					start=q;
					
					q=p;
			
				}
				else
				{
					p=q;
					
					q=q->getNext();
				}
			}	
		}
		else
		{
			cout<<"\n------------------------------------------------------\n";
			cout<<"\n*Invalid Input*\n";
			return false;
		}
		
		cout<<"\nList of All Players:\n";
		cout<<"------------------------------------------------------\n";
		cout<<" Name  Jersey  Matches  Runs  Century  Wickets\n";
		cout<<"------------------------------------------------------\n";
		
		Node *d = start;
		
		for(int i = 0;i<=2;i++)
		{
			d->getData().display();
			d=d->getNext();
		}
		
		return true;
	}	
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::deleteData()
{
	if(start==NULL)
	{
		cout<<"\n------------------------------------------------------\n";
		cout<<"\nData is Not Available ? Insert Data...\n";
		return false;
	}
	else
	{
		int jerseyNo;
		int pos=1;
		int flag=0;
		cout<<"\nEnter Jersey Number To Delete Player Data : ";
		cin>>jerseyNo;
		Node *p = start;
		
		while(p!=NULL)               // To find index
		{
			if(p->getData().getJersey()==jerseyNo)
			{
				flag++;
				break;
			}
			
			p=p->getNext();
			pos++;
		}
		
		if(flag==0)
		{
			cout<<"\nJersey Number Not Found\n";
		}
		else
		{
			Node *q = start;
			
			if(pos==1)
			{
		
				start = q->getNext();
				cout<<"\n"<<q->getData().getName()<<" is deleted...";
				delete q;
				return true;
			}
			else
			{
				int i = 1;
				while(i<pos-1 && q->getNext()!=NULL)
				{
					q=q->getNext();
					i++;
				}
				if(i == pos-1)
				{
					Node *d = q->getNext();
					q->setNext(d->getNext());
					cout<<"\n"<<d->getData().getName()<<" is deleted... ";
					delete d;
					return true;
				}
				
			}
		} 	
		
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LinkedList::displayData()
{
	if(start==NULL)
	{
		cout<<"\n------------------------------------------------------\n";
		cout<<"\n*Data Is Not Available*\n\n";
	}
	else
	{
		cout<<"\nList of All Players:\n";
		cout<<"------------------------------------------------------\n";
		cout<<" Name  Jersey  Matches  Runs  Century  Wickets\n";
		cout<<"------------------------------------------------------\n";
		
		Node *p = start;
		
		while(p!=NULL)
		{
			p->getData().display();
			p=p->getNext();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinkedList::~LinkedList()
{
	while(start!=NULL)
	{
		Node *p = start;
		
		start=start->getNext();
		
		cout<<"\nData Deleted\n";
		delete p;
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

