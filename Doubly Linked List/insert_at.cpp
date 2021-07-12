#include<iostream>
#include "Node.h"
using namespace std;
Node* take_input(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            head->prev=NULL;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    // below code is for printing in reverse order
 /*   cout<<endl;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<head->data<<" "; 
*/  
}
Node* insert_begin(Node* head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        return head;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    }
}
Node *insert_end(Node*head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        return head;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        return head;
    }
}
Node *insert_sorted(Node*head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        return head;
    }
    else if(head->data > data){
        return insert_begin(head,data);
    }
    else{
        Node*temp=head;
        while(temp->next!=NULL){
            if(data>temp->data){
                temp=temp->next;
            }
            else{
                Node *a=temp->prev;
                a->next=newnode;
                newnode->prev=a;
                newnode->next=temp;
                return head;
            }
        }
    }
    
}
int main(){
    int data;
    Node* head=take_input();
    cin>>data;
    head=insert_sorted(head,data);
    print(head);
    return 0;
}