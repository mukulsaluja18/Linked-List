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
Node* midpoint(Node* head){
    Node *slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* merge_sort(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    //finding mp
    Node*mid=midpoint(head);
    Node *second_half=mid->next;
    mid->next=NULL;
    Node*t1=merge_sort(head);
    Node*t2=merge_sort(second_half);
    Node*c=merge_ll(t1,t2);
    return c;
}
int main(){
    Node *head=take_input();
    head=merge_sort(head);
    print(head);
    return 0;
}