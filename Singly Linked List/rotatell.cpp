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
Node* rotate(Node*head,int k){
    if(k==0||!head||!head->next){
        return head;
    }
    Node *cur=head;
    int len=1;
    while(cur->next && ++len){
        cur=cur->next;
    }
    // go till that node;
    cur->next=head;
    k=k%len;
    k=len-k;
    while(k--) cur=cur->next;
    head=cur->next;
    cur->next=NULL;
    return head;
}
int main(){

}