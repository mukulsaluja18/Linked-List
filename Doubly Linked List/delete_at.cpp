#include<iostream>
#include "Node.h"
using namespace std;
Node* take_input(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            head->prev=NULL;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    // below code is for printing in reverse order
    cout<<endl;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<head->data<<" "; 

}
// delete heead
Node* delete_head(Node *head){
    if(head==NULL){
        return head;
    }
    else if(head->next==head){
        delete head;
        return NULL;
    }
    else{
        Node *newhead=head->next;
        delete head;
        newhead->prev=NULL;
        return newhead;
    }
}
// delete last of dll
Node *delete_last(Node*head){
    if(head==NULL){
        return head;
    }
    else if(head->next==head){
        delete head;
        return NULL;
    }
    else{
        Node*temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
        return head;
    }
}
int length(Node *head){
    int l=1;
    while(head->next!=NULL){
        head=head->next;
        l++;
    }
    return l;
}
// delete ith node
Node* delete_ith(Node*head,int pos){
    int len=length(head);
    cout<<len<<endl;
    if(head==NULL){
        return head;
    }
    else if(pos=1){
        return delete_head(head);
    }
    else if(pos==len){
        return delete_last(head);
    }
    else{
        int l=1;
        Node* temp=head;
        while(temp->next!=NULL && l<pos){
            temp=temp->next;
            l++;
        }
        Node *a=temp->prev;
        a->next=temp->next;
        temp->next->prev=a;
        delete temp;
        return head;
    }
}
int main(){
    int pos;
    Node *head=take_input();
    cin>>pos;
    //head=delete_head(head);
    //head=delete_last(head);
    head=delete_ith(head,pos);
    print(head);
    return 0;
}