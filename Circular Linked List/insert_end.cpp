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
Node* insert_end(Node*head,int data){
    Node*newnode=new Node(data);
    if(head==NULL){
        newnode->next=newnode;
        return newnode;
    }
    else{
        Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        return head;
    }
}
// efficient solution is maintian tail pointer in constant time 
Node *insert_end_opt(Node *head,int data){
    Node*newnode=new Node(data);
    if(head==NULL){
        newnode->next=newnode;
        return newnode;
    }
    else{
        Node *temp=head->next;
        // swap the node head and newnode;
        int t=head->data;
        head->data=newnode->data;
        newnode->data=t;
        head->next=newnode;
        newnode->next=temp;
        return newnode;
        // or we can insert newnode after the head and swap them this approach also work fine
    }
}
int main(){
    int data;
    Node* head=take_input();
    cin>>data;
    head=insert_end_opt(head,data);
    print(head);
    return 0;
}