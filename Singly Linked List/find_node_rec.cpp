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
int find_node(Node*head,int data){
    if(head==NULL){
        return -1;
    }
    //checking
    if(head->data==data){
        return 0;
    }
    return 1+find_node(head->next,data);
}
int main(){
    int data;
    Node*head=take_input();
    cin>>data;
    cout<<find_node(head,data)<<endl;
    return 0;
}