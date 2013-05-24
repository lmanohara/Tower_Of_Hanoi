#ifndef HANOI_H
#define HANOI_H
int const MAX_STACK_SIZE = 10;

//prototype of the functions
class Stack
{
	private:
	int arr[MAX_STACK_SIZE];
	int sizeOf;

public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	int top();
	void push(int n);
	int pop();
	int size();
	void print();
	int getData(int n);
	void Stack:: moveDisk(int towerSelect,int moveTower);
	void createDisk(int disk);
	bool moveValidate(int towerSelect, int moveTower);
	bool completeGame(int complete);

	

};

class Solver
{

public:
	void move(int nOfDisk, char * tower_1, char * tower_2,char * tower_3);
	void print(int nOfDisk, char * tower_1, char * tower_2, char * tower_3);
};
#endif
