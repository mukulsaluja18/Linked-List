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
int length(Node *head){
    if(!head){
        return 0;
    }
    return 1+length(head->next);

}
int main(){
    int i,val;
    Node* head=take_input();
    cout<<length(head)<<endl;
    return 0;
}