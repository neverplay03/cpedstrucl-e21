#include<iostream>
#include<conio.h>
using namespace std;
 
 class LinkedList{
     struct Node {
         int x;
         Node *next;
         
     };
 
 public:
     LinkedList(){
         head = NULL; 
     }
 
     void addValue(int number){
         Node *n = new Node();   
         n->x = number;             
         n->next = head;         
                                
         head = n;    
 		
 		          
     }

     void display(){
     int counter=1;
     temp=head;
     if(temp == 0){
     	cout<<"List is Empty";
	 }
     while(head!=0){
     Node *n = head;
     int ret = n->x;
     head = head->next;
   	counter++;
     cout<<ret<<endl;
     }
     
     head=temp;
 	}
 	
 
     
 private:
     Node *head; 
     Node *temp;
 };
 
 int main()
 {
 	LinkedList list;
 	int choice,number,counter;
 	while (1)
 	{	
 	system("cls");
 	cout<<"        MENU"<<endl;
 	cout<<"[1] Push"<<endl;
 	cout<<"[2] Pop"<<endl;
 	cout<<"[3] Display"<<endl;
 	cout<<"[4] Exit"<<endl;
 	cout<<"Enter your choice:";
 	cin>>choice;
 	switch(choice)
 	{
 	
 		case 1:
 			cout<<"Enter a number:";
 			cin>>number;
 			list.addValue(number);
 			break;
 			
 		
 		case 2:
 		break;
 		
 		case 3:
 		list.display();
 		break;
 		
 		case 4:
 			exit(1);
 		
 		default:
 			cout<<"Error, Try again";
 							
 	}
 	getch();
 	}	
 }
 
