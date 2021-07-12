#include<iostream>
#include "Node.h"
using namespace std;
Node *take_input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next; // or tail=newnode
        }
        cin>>data;
    }
    return head;
}
int length(Node*head){
    if(!head){
        return 0;
    }
    return 1+length(head->next);
}
bool check_palindrome(Node *head){
	if(head==NULL|| length(head)==1){
		return true ;
	}
	Node *temp=head;
	Node *temp1=head;
	while(temp->next!=NULL){
		temp1=temp;
		temp=temp->next;
	}
	if(head->data==temp->data){
		delete temp;
		temp1->next=NULL;
		check_palindrome(head->next);
	}else{
	return false;	
	}
	
}
Node *reverse_it(Node*head){
    Node *prev=NULL;
    Node* current=head;
    Node* nxt=head;
    while(current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
    }
    return prev;
}
bool isPali(Node*head){
    if(head==NULL||head->next==NULL){
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverse_it(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(head->data!=slow->data){
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;
}
int main(){
    Node*head=take_input();
    cout<<check_palindrome(head)<<endl;
    return 0;
}
/* Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1

Sample Output 2 :
false
true */