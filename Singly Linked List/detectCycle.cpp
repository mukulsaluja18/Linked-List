#include<iostream>
#include<list>
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
bool hasCycle(Node*head){
    if(head==NULL||head->next==NULL){
        return false;

    }
    Node*slow=head;
    Node*fast=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
// start point of cycle
Node *start_point(Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;

    }
    Node*slow=head;
    Node*fast=head;
    Node* entry=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
}
int main(){

    Node *head=take_input();
}