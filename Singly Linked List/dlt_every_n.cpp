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
Node* delete_every_n(Node*head,int m,int n){
    if(m==0){
      return NULL;
    }
    int count;
    Node *temp1=head;
    Node* temp2;
    while(temp1!=NULL){
        for(count=1;count<m && temp1!=NULL;count++){
            temp1=temp1->next;
            if(!temp1){
                return head;
            }
            temp2=temp1->next;
        }
        for(count=1;count<=n && temp2!=NULL;count++){
            Node* temp=temp2;
            temp2=temp2->next;
            delete temp;
        }
        temp1->next=temp2;
        temp1=temp2;
    }
    return head;
}
int main(){
    int m,n;
    Node* head=take_input();
    cin>>m>>n;
    head=delete_every_n(head,m,n);
    print(head);
}