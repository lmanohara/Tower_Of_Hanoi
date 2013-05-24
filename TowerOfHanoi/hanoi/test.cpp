#include<iostream>
#include"hanoi.h"
using namespace std;

//test function for hanoi
int main()
{
	system("color 2e");
	system("mode con lines=30");//for example vertically size is 10 lines 
	system("mode con cols=70");//for example vertically size is 50 characters
	char c1 = 186;
	char c2 = 205;

	Stack setData;
	Solver object;
	int nOfDisk=0;
	int towerSelect;
	char ans;
	
	int select = 0;
	int move= 0;
	
	cout<<"Please enter the Number of disk you want (minimum = 3 , Maximum = 10)";
	cin>>nOfDisk;
	while(!cin ||nOfDisk<3 || nOfDisk >10)
			{
				cout<<"Error: Invalid Input \n";
				cout<<"Please input a number Between 3 , 10 :";
				std::cin.clear();
				cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
				cin>>nOfDisk;
			}

	cout << "If you want to hanoi solver please enter n/y or N/Y: ";
	cin >> ans;
	system("cls");
	if(ans == 'y' || ans == 'Y')
	{
		object.move(nOfDisk,"1","2","3");
	}
	else if( ans=='n' || ans == 'N')
	{
		setData.createDisk(nOfDisk);
		cout<<endl;
		setData.print();

		while(setData.completeGame(nOfDisk)){
	
				cout<<"Enter Starting Tower : ";
				cin>>select;

				cout<<"\nEnter End Tower : ";
				cin>>move;

				if(setData.moveValidate(select,move))
				{
					setData.moveDisk(select,move);
				}
				system("cls");
				setData.print();

	}

	}
	cout <<"YOU WON THE GAME!!!!"<<endl;
	system("pause");

}