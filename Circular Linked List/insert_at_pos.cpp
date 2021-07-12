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
Node *insert_opt(Node*head,int data){
    Node *newnode=new Node(data);
    if(head==NULL){
        newnode->next=newnode;
        return newnode;
    }
    else{
        // first add newnode after the head;
        newnode->next=head->next;
        head->next=newnode;
        //swap the data
        int t;
        t=head->data;
        head->data=newnode->data;
        newnode->data=t;
        return head;
    }
}
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
Node* insert_at(Node* head,int pos,int data){
    int len=length(head);
    if(pos>len){
        return head;
    }
    else if(pos==len){
        //insert at end;
        return insert_end_opt(head,data);
    }
    else if(pos==1){
        // insert at begin
        return insert_opt(head,data);
    }
    else{
        // insert at any pos
        Node *temp=head->next;
        int count=1;
        while(temp!=NULL && count<pos){
            temp=temp->next;
            count++;
        }
        Node *newnode=new Node(data);
        Node * a=temp->next;
        temp->next=newnode;
        newnode->next=a;
        return head;
    }
}
int main(){
    int pos,data;
    Node *head=take_input();
    cin>>pos>>data;
    head=insert_at(head,pos,data);
    print(head);
    return 0;
}