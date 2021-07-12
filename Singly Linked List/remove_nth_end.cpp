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
Node *remove_nth(Node*head,int n){
    Node*start;
    start->next=head;
    Node*fast=start;
    Node*slow=start;
    for(int i=1;i<=n;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return start->next;


}
Node * remove_nth_from_end(Node*head,int n){
    Node*dummy=NULL;
    dummy->next=head;
    Node*fast=dummy;
    Node* slow=dummy;
    for(int i=1;i<=n;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    return dummy->next;
}
int main(){

}