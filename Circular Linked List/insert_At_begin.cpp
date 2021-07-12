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
Node* insert_begin(Node*head,int data){
    Node * newnode=new Node(data);
    if(head==NULL){
        newnode->next=newnode;
    }
    else{
    Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    }
    return newnode;
}
// above pproach take o(n) so to optimized it we can also pass tail pointer and do in o(1) or conatant time
// we can also do this by just adding data after head node and swap their data
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
int main(){
    int data;
    Node* head=take_input();
    cin>>data;
    head=insert_begin(head,data);
    print(head);
    return 0;

}
