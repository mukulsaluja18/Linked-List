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
void print(Node *head){
    Node *temp=head;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* travel_to_n(Node*head,int n){
    int c=0;
    while(head!=NULL && c<n){
        c++;
        head=head->next;
    }
    return head;
}
Node* swap_nodes(Node*head,int i,int j){
    Node *current1=head;
    Node*current2=head;
    Node*prev1=NULL;
    Node*prev2=NULL;
    int count=0;
    while(count<i && current1!=NULL){
        prev1=current1;
        current1=current1->next;
        count++;
    }
    count=0;
    while(count<j && current2!=NULL){
        prev2=current2;
        current2=current2->next;
        count++;
    }
    prev1->next=current2;
    prev2->next=current1;
    current1->next=current2->next;
    return head;
}
int main(){
    int i,j;
    Node *head=take_input();
    cin>>i>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}