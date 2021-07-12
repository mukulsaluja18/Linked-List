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
Node * insert_at(Node*head,int i,int val){
    if(!head){
        return 0;
    }
    if(i==0){
        Node *newnode=new Node(val);
        newnode->next=head;
        head=newnode;
        return head;
    }
    head->next=insert_at(head->next,i-1,val);
    return head;

}
int main(){
    int i,val;
    Node *head=take_input();
    cin>>i>>val;
    head=insert_at(head,i,val);
    print(head);
    return 0;
}