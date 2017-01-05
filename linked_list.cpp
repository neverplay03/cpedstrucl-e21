#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct node {
	int data;
	struct node * next;
} *head;
  
int count() {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
    n = n -> next;
    c++;
  }
  return c;
}

void append(int num) {
  struct node * temp, * right;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  right = (struct node * ) head;
  while (right -> next != NULL)
    right = right -> next;
  right -> next = temp;
  right = temp;
  right -> next = NULL;
}

void add(int num) {
  struct node * temp;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  if (head == NULL) {
    head = temp;
    head -> next = NULL;
  } else {
    temp -> next = head;
    head = temp;
  }
}

void addafter(int num, int loc) {
  int i;
  struct node * temp, * left, * right;
  right = head;
  for (i = 1; i < loc; i++) {
    left = right;
    right = right -> next;
  }
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  left -> next = temp;
  left = temp;
  left -> next = right;
  return;
}

int delete_val(int num) {
  struct node * temp, * prev;
  temp = head;
  while (temp != NULL) {
    if (temp -> data == num) {
      if (temp == head) {
        head = temp -> next;
        free(temp);
        return 1;
      } else {
        prev -> next = temp -> next;
        free(temp);
        return 1;
      }
    } else {
      prev = temp;
      temp = temp -> next;
    }
  }
  return 0;
}


void delete_all(int num){
	struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
  	
  		delete_val(num);
	  
    n = n -> next;
    c++;
  }

}

void insert(int num) {
  int c = 0;
  struct node * temp;
  temp = head;
  if (temp == NULL) {
    add(num);
  } else {
    while (temp != NULL) {
      if (temp -> data <= num)
        c++;
      temp = temp -> next;
    }
    if (c == 0)
      add(num);
   // else if (c < count())
    //  addafter(num, ++c);
    else
      append(num);
  }
}



void display(struct node * r) {
  r = head;
  if (r == NULL) {
    return;
  }
  while (r != NULL) {
    printf("%d ", r -> data);
    r = r -> next;
  }
  printf("\n");
}

int search(int num) {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
  	if(n->data==num){
  		cout<<"Location: "<<c;
	  }
    n = n -> next;
    c++;
  }
  return c;
}



int main() {
  int i, num, loc;
  struct node * n;
  head = NULL;

  while (1) {
  	system("cls");
  	cout<<"Linked List Operations:"<<endl;
  	cout<<"============================"<<endl;
  	cout<<"1. Insert"<<endl;
  	cout<<"2. Display"<<endl;
  	cout<<"3. Size"<<endl;
  	cout<<"4. Delete"<<endl;
  	cout<<"5. Search"<<endl;
  	cout<<"6. Add After"<<endl;
  	cout<<"7. Delete all"<<endl;
  	cout<<"8. Exit"<<endl;
  	cout<<"Enter choice: ";
  	cin >> i;
  	if(i <= 0){
  		cout<<"Enter only integer";
	  }
	else{
		switch(i){
		case 1:
			cout<<"Enter the number to insert: ";
			cin>> num;
			insert(num);
			break;
		case 2:
			if (head==NULL){
			 cout<<"List is Empty"<<endl;	
			}
			else{
			 cout<<"Element(s) in the list are : ";
			}
			display(n);
			break;
		case 3:
			cout<<"Size of the list is: "<<count()<<endl;
			break;
		case 4:
			if(head==NULL)
			  cout<<"List is Empty";
			else{
				cout<<"Enter the number to delete: ";
				cin>> num;
			if(delete_val(num))
			  cout<<num<<" is deleted successfully";
			else
			  cout<<num<<" is not found in the list";
			}
			break;
		case 5:
			cout<<"Enter number to search: ";
			cin>>num;
			search(num);
			break;
		case 6:
			cout<<"Enter number to add: ";
			cin>>num;
			cout<<"Enter location: ";
			cin>>loc;
			addafter(num,loc);
			break;
		case 7:
			cout<<"Enter number to delete: ";
			cin>>num;
			delete_all(num);
			cout<<"Deleted successfully";
			break;
		case 8:
			return 0;
		default:
			cout<<"Invalid option";
		}
		getch();
	}
  	
}
	return 0;
}
