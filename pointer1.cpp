#include<iostream>
using namespace std;

int main()
{
	int *point;
	int inputNum;
	point=&inputNum;
	cout<<"Enter a number: ";
	cin>>inputNum;
	cout<<"The pointer values is "<< *point <<" the memory address is: "<<point;

}
