#include"hanoi.h"
#include<iostream>
using namespace std;

//stack class implementation
	Stack tower1;
	Stack tower2;
	Stack tower3;

//class memebr size function
int Stack::size()
{
	return sizeOf;
}

//stack class constructor
Stack::Stack()
{
	sizeOf = 0;
}

//stack class destructor
Stack::~Stack()
{
	sizeOf = 0;
}

//class emptty function

bool Stack::isEmpty()
{
	return (sizeOf==0);
}

//class member isfull function

bool Stack::isFull()
{
	return (sizeOf >= MAX_STACK_SIZE);
}

//clas member top function

int Stack::top()
{
	if(!isEmpty())
	{
		return arr[sizeOf-1];
	}
}

//class member push function

void Stack::push(int n)
{
	if(!isFull())
	{
		arr[sizeOf] = n;
		sizeOf++;
	}

}

//class memebr pop function
int Stack::pop()
{
	if(!isEmpty())
	{
		
		sizeOf--;
		return arr[sizeOf];
	}
}

//class member create disk function
void Stack:: createDisk(int disk){
	for(int i=0; i<disk; i++)
	{
		
		tower1.push(disk-i);

	}
}

//Class member getDta from user
void Stack:: moveDisk(int towerSelect,int moveTower){
	

	if(towerSelect==1 && moveTower==2){

			tower2.push(tower1.pop());
	
	}
	else if(towerSelect ==1 & moveTower==3){
	
			tower3.push(tower1.pop());
		
	}
	else if(towerSelect ==2 && moveTower==1){

			tower1.push(tower2.pop());

	}
	else if(towerSelect==2 && moveTower==3){
		tower3.push(tower2.pop());
	
	}
	else if(towerSelect==3 && moveTower==1){
		tower1.push(tower3.pop());
		
	}
	else if(towerSelect ==3 && moveTower==2){
		tower2.push(tower3.pop());
		
	}

}

//class member get data function
int Stack::getData(int n)
{
	return arr[n];
}


//class member print
void Stack::print()
{
	int space =0;
	char symble =220;
	for(int i = 10;i>0;i--)//running the loop for ten line.
	{

		if(i<=tower1.size())//print disk if nessecarry tower1
		{
			space = 10-tower1.getData(i-1);

		for(int y =space;y>0;y--)
		{
			cout<<" ";
		}
		for(int x = 0; x<tower1.getData(i-1); x++)
		{
			cout<<symble;
			cout << symble;
		}
		for(int y =space;y>0;y--)
		{
			cout<<" ";
		}
	}
	else//to print spaces tower1.
	{
		for(int i = 20 ; i> 0; i--)
		{
			cout<<" ";
		}
	}
	if(i<=tower2.size())//print disk if nessecarry tower2
	{
		space = 10-tower2.getData(i-1);
		for(int y =space;y>0;y--)
		{
			cout<<" ";
		}
		for(int x = 0; x<tower2.getData(i-1); x++)
		{
			cout<<symble;
			cout<<symble;
		}
		for(int y =space;y>0;y--)
		{
			cout<<" ";
		}
	}
	else//to print spaces tower2.
	{
		for(int i = 20 ; i> 0; i--)
		{
			cout<<" ";
		}
	}
	if(i<=tower3.size())//print disk if nessecarry tower3
	{
		space = 10 -tower3.getData(i-1);
		for(int y =space;y>0;y--)
		{
			cout<<" ";
		}
		for(int x = 0; x<tower3.getData(i-1); x++)
		{
			cout<<symble;
			cout<<symble;
		}
		for(int y =space;y>0;y--)
		{
			cout<<" ";
		}
	}
	else//to print spaces tower3.
	{
		for(int i = 20; i> 0; i--)
		{	
			cout<<" ";
		}
	}
cout<<endl;
}
cout<<"";
}



//hanoi class implementation

void Solver::move(int nOfDisk, char * tower_1, char * tower_2,char * tower_3)
{
	if(nOfDisk>0)
	{
		//move n-1 disk source tower to intermidate tower
		move(nOfDisk-1, tower_1, tower_3,tower_2);
		print(nOfDisk,tower_1,tower_2,tower_3);
		//move n-1 disk intermidate tower to destination tower 
		move(nOfDisk-1, tower_2,tower_1,tower_3);
	}
}


void Solver::print(int nOfDisk, char * tower_1, char * tower_2,char * tower_3)
{
	
	cout << "disk " << nOfDisk << " is moved from " << "tower " <<tower_1 << " to " << "tower " <<tower_3 << endl;
	
}

//move validation

bool Stack::moveValidate(int towerSelect, int moveTower){

	if(towerSelect == 1 && moveTower==3)
	{
		if(tower1.isEmpty())
		{
			return false;
		}
		else if(tower3.isEmpty())
		{
			return true;
		}
		else if(tower3.top()<= tower1.top())
		{
			cout << "invalid move!!!";
			return false;
		}
	}

	if(towerSelect == 1 && moveTower==2)
	{
		if(tower1.isEmpty())
		{
			return false;
		}
		else if(tower2.isEmpty())
		{
			return true;
		}
		else if(tower2.top() <= tower1.top())
		{
			cout << "invalid move!!!";
			return false;
		}
	}

	if(towerSelect == 2 && moveTower ==1)
	{
		if(tower2.isEmpty())
		{
			return false;
		}
		else if(tower1.isEmpty())
		{
			return true;
		}
		else if(tower1.top()<= tower2.top()){
		cout << "invalid move!!!";
		return false;
		}
	}

	if(towerSelect ==2 && moveTower == 3){

		if(tower2.isEmpty())
		{
			return false;
		}
		else if(tower3.isEmpty())
		{
			return true;
		}
		if(tower3.top() <= tower2.top()){
		cout << "invalid move!!!";
		return false;
		}
	}

	if(towerSelect == 3 && moveTower ==1)
	{
		
		if(tower3.isEmpty())
		{
			return false;
		}
		else if(tower1.isEmpty())
		{
			return true;
		}
		if(tower1.top()<= tower3.top()){
		cout << "invalid move!!!";
		return false;
		}
	}
	if(towerSelect ==3 && moveTower == 2){

		if(tower3.isEmpty())
		{
			return false;
		}
		else if(tower2.isEmpty())
		{
			return true;
		}
		if(tower2.top() <= tower3.top()){
		cout << "invalid move!!!";
		return false;
		}
	}
	
}

//game complete sucessfully

bool Stack::completeGame(int complete)
{
	if(complete != tower3.size()){
		return true;
	}
	else 
		return false;
	

}


