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
int length(Node*head){
    if(!head){
        return 0;
    }
    return 1+length(head->next);
}
void deleteNode(Node* some_node){
    // this if node given is not a tail node if it is then we simply assign him null
    Node* a=some_node->next;
    some_node->data=some_node->next->data;
    some_node->next=some_node->next->next;
    delete a;
}
int main(){
    Node*head=take_input();
    Node* some_snode;// here we pass the node which is in ll
    deleteNode(some_snode);
    print(head);
}