#include <iostream>
#include <conio.h>
using namespace std;
void display (struct Book[]);
void insert (int,int,double, struct Book[]);
void del (int, struct Book[]);
void swap (int, int, struct Book[]);
struct Book {
  	int copies;
  	double price;
}book[5];
	
int main()
{
	int arr[20]={1,2,3,4,5,6,7,8,9,10};
	while(1)
	{
		system ("cls");
		int choice,copies,position,position2;
		double price;
		cout << "Array Manipulation\n";
		cout << "[1] Display \n";
		cout << "[2] Insert \n";
		cout << "[3] Delete \n";
		cout << "[4] SWAP \n";
		cout << "[5] Exit \n";
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					display(book);
				} break;
			case 2:
				{
					cout << "Enter number of copies: ";
					cin >> copies;
					cout<<"Enter price: ";
					cin>>price;
					cout<<"Enter position";
					cin>>position;
					insert(copies,position,price,book);
					display(book);
				} break;
			case 3:
				{
					cout << "Enter position: ";
					cin >> position;
					del(position,book);
					display(book);
				} break;
			case 4:
				{
					cout << "Enter position 1: ";
					cin >> position;
					cout<<"Enter position you want to swap with: ";
					cin>>position2; 
					swap(position,position2,book);
					display(book);
				} break;
			case 5:
				{
					exit(1);
				} break;
			
			default: cout << "Invalid Choice!\n"; break;					
		}
		cout << endl;
		system("pause");
	}
	getch();
	return 0;
}

void display(struct Book book[])
{
	for(int i=0; i<5; i++)
	{
		cout << "[" << i << "]" << book[i].copies << endl;
	}
}

void insert(int position, int copies, double price, struct Book book[])
{
    int i;
    Book temp[20];
    book[position].copies = copies;
    for(i=position; i<20; i++)
    {
        temp[i-position].copies=book[i].copies;
        temp[i-position].price=book[i].price;
    }

    book[position]=copies;
    for (i=position; i<=20; i++)
    {
        book[i+1]=temp[i-position];
    }
}

void del(int position, int a[])
{
	int i;
	for (i=position; i<20; i++)
	{
		a[i]=a[i+1];
	}
	a[20-1]=0;
}

void swap (int p, int p2, int a[])
{
	int temp;
	temp=a[p];
	a[p]=a[p2];
	a[p2]=temp;
}
