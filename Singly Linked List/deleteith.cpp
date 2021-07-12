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
Node *delete_at_i(Node*head,int i){
    if(i==0){
        Node*temp=head->next;
        delete head;
        head=temp;
        return head;
    }
    int count=0;
    Node *temp=head;
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node *a=temp->next->next;
        delete temp->next;
        temp->next=a;
    }
    return head;

}

int main(){
    int i;
    Node* head=take_input();
    cin>>i;
    head=delete_at_i(head,i);
    print(head);
}