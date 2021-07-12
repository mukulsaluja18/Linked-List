#include<iostream>
#include "Node.h"
using namespace std;
Node *take_input(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    tail->next=head;
    return head;
}
void print(Node*head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    Node*temp=head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node *kth_dlt(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        head->data=head->next->data;
        Node *temp=head->next;
        head->next=head->next->next;
        delete temp;
        return head;
    }
    else{
        Node* temp=head;
        for(int count=0;count<k-2;count++){
            temp=temp->next;
        }
        Node *temp1=temp->next;
        temp->next=temp->next->next;
        delete temp1;
        return head;
    }
}
int main(){
    int k;
    Node* head=take_input();
    cin>>k;
    head=kth_dlt(head,k);
    print(head);
    return 0;

}