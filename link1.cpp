/*Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/
//define library
#include<iostream>
using namespace std;
//class Node
class Node{
//make it public
public:
	//define variable that stores the value of the Nodes
	int value;
	//define a Node type pointer 
	Node *next;
	//the constructor that takes the next to be NULL by defult
	Node(){
		next=NULL;
	}
};
//class Link
class Link{
//make it public
public:
	//head of the likedlist
	Node *head;
	//tail of linkedlist
	Node *tail;
	//define a defult constructor that takes the head to NULL
	Link(){
		head=NULL;	
	}
	//insert function inserts the data in the Nodes given from main
	void insert(int data){
		//first create a new node in 
		Node *temp=new Node;
		//asign the the value of data
		temp->value=data;
		//if it is start Node of the linkedlist
		if(head==NULL){
			head=temp;
		}
		//otherwise head will not be changed
		else{
			tail->next=temp;
		}
		tail=temp;
	}
	//insertAt function that inserts a new node in the given position
	void insertAt(int pos,int data){
		//to know how many lists exist we shoud call countItems function
		int a=countItems();
		//now if pos>a then this position is not possible
		if(pos>a){
			cout<<"Linked list does not have many elements."<<endl;
		}
		else{
			Node *current=head;
			//number position
			int i=1;
			//use loop
			while(i<pos-1){
				i++;
				current=current->next;
			}
			//create new node
			Node *ada=new Node;
			//store the data in new Node
			ada->value=data;
			//enter the address in the new node
			ada->next=current->next;
			//enter the address of the new node in the previous node
			current->next=ada;
		}	
	}
	//delet function will delete the last node
	void delet(){
		Node *current=head;
		Node *temp=tail;
		//use loop to reach at the list which stores the address NULL
		while(current->next!=tail){
			current=current->next;
		}
		//make the address stored in last but one null
		current->next=NULL;
		//change the tail
		tail=current;
		//delete the last one
		delete temp; 
	}
	//deleteAt function deletes the node at given position
	void deleteAt(int pos){
		//define a node address that will be changed and find the position address
		Node *current=head;
		int i=1;
		//use loop
		while(i<pos-1){
			i++;
			current=current->next;
		}
		Node *temp=current->next;//the address of the position
		//update the address stored in the previous node of the position to be deleted
		current->next=temp->next;
		//delete the position
		delete temp;
	}
	//reverseprint function that prints in the reverse order
	void reverseprint(){
		//call revprint function that will do recursion and print in the reverse order
		revprint(head);
		cout<<endl;
	}
	//revprint function
	void revprint(Node* current){
		//stoping condition
		if(current==NULL){return;}
		else{
			//recursion
			revprint(current->next);
			cout<<current->data<<"->";
		}
	}
	//countItems function will count the number of nodes and returns it
	int countItems(){
		Node *current=head;
		int i=1;
		//use loop 
		while(current->next!=NULL){
			i++;
			current=current->next;
		}
		return i+1;	
	}
	//display fuction will display the values of the nodes
	void display(){
		Node *current=head;
		//use loop
		while(current!=NULL){
			cout<<current->value<<"->";
			current=current->next;
		}	
	}
};
//main function
int main(){
	//define object
	Link l;
	l.insert(1);l.insert(2);l.insert(3);l.insert(4);l.insertAt(3,55);l.insertAt(8,6);
	l.delet();l.deleteAt(2);l.display();
	l.reverseprint();
	l.countItems();
	return 0;
}
