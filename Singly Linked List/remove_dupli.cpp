#include<iostream>
#include<bits/stdc++.h>
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
/*
Node* remove_dupli(Node*head){
    if(head==NULL){
        return 0;
    }
    Node*temp=remove_dupli(head->next);
    if(head->data == temp->data && temp->next!=NULL){
        head->next=temp->next;
        delete temp;
        return head;
    }
    head->next=temp;
    return head;
}
*/
Node *remove_dupli(Node*head){
    Node*temp=head;
    Node*temp_new=head->next;
    while(temp_new!=NULL){
        if(temp->data==temp_new->data){
            temp->next=temp_new->next;
            delete temp_new;
            temp_new=temp->next;
        }
        else{
            temp=temp_new;
            temp_new=temp_new->next;
        }
    }
    return head;
}
// another appriach is make new ll and do remove first from first ll and add this data in lst in new ll but whenver we remove from first and add in second ll
// we have to sure ki vo tail ke sath match nhi kre agr kr gya to add nhi krenge
/*void remove_du(list<int> li){
    list<int> res;
    while(li.size()>0){
        int data=li.front();
        li.pop_front();

        if(res.size()==0||res.tail.data!=data){
            res.push_back(data);
        }
    }
}
*/


int main(){
    Node *head=take_input();
    head=remove_dupli(head);
    print(head);
    return 0;
}