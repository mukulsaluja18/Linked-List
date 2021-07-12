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
void print_rev(Node*head){
    if(head==NULL){
        return;
    }
    print_rev(head->next);
    cout<<head->data<<" ";

}
int main(){
    Node*head=take_input();
    print_rev(head);
    return 0;
}