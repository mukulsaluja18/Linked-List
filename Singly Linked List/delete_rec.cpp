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
Node *delete_at(Node*head,int i){
    if(head==NULL){
        return 0;
    }
    if(i==0){
        Node *temp=head->next;
        delete head;
        head=temp;
        delete temp;
        return head;
    }
    head->next=delete_at(head->next,i-1);
    return head;
}
int main(){
    int i;
    Node*head=take_input();
    cin>>i;
    head=delete_at(head,i);
    print(head);
    return 0;

}