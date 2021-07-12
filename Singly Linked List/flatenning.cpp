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
Node *merge_ll(Node *head1,Node*head2){
    Node* fhead=NULL;
    Node* ftail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(fhead==NULL){
                fhead=head1;
                ftail=head1;
                head1=head1->next;
            }
            else{
                ftail->next=head1;
                ftail=ftail->next;
                head1=head1->next;
            }
        }
        else{
            if(fhead==NULL){
                fhead=head2;
                ftail=head2;
                head2=head2->next;
            }
            else{
                ftail->next=head2;
                ftail=ftail->next;
                head2=head2->next;
            }           
        }
    }
    if(head1!=NULL){
        ftail->next=head1;
    }
    else if(head2!=NULL){
        ftail->next=head2;
    }
    return fhead;
}
Node *flat(Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    head->next=flat(head->next);
    head=merge_ll(head,head->next);
    return head;
}
int main(){

}