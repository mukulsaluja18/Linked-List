#include<iostream>
#include "Node.h"
using namespace std;
Node *take_input(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    tail->next=head;
    return head;
}
void print(Node*head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    Node*temp=head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int length(Node *head){
    int count=1;
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
        count++;
    }
    return count;
}
bool check_cll(Node *head){
    if(head==NULL){
    return true;
    }
    Node *temp=head->next;
    while(temp!=head && temp!=NULL){
        temp=temp->next;
    }
    return (temp==head);
}
void print_l(Node*head){
    if(head==NULL){
        return ;
    }
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
}
int main(){
    /*
    Node *node1=new Node(10);
    Node *node2=new Node(20);
    Node *node3=new Node(30);
    Node *node4=new Node(40);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node1;
    Node*head=node1;
    */
   Node *head=take_input();
    print(head);
//    print_l(head);
    return 0;
}