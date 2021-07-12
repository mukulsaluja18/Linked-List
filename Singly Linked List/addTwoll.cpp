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
int len(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
int helper(Node* head1,int pv1,Node* head2,int pv2,list<int> &head3){
    if(head1==NULL||head2==NULL){
        return 0;
    }
    int data=0;
    int old_carry;
    if(pv1 > pv2){
        helper(head1->next,pv1-1,head2,pv2,head3);
        data=head1->data+ old_carry;
    }
    else if(pv1 < pv2){
        helper(head1,pv1,head2->next,pv2-1,head3);
        data=head2->data +old_carry;
    }
    else{
        old_carry= helper(head1->next,pv1-1,head2->next,pv2-1,head3);
       data=head1->data+ head2->data +old_carry;
    }
    int nd=data%10;
    int nc=data/10;
    head3.push_front(nd);
    return nc;
}
list<int> add_them(Node* head1,Node* head2){
    list<int>head3;
    int size1=len(head1);
    int size2=len(head2);
    int oc=helper(head1,size1,head2,size2,head3);
    if(oc>0){
        head3.push_front(oc);
    }
    return head3;
}
 Node* add_ll(Node*head1,Node*head2){
     Node* dummy;
     Node*temp=dummy;
     int carry=0;
     while(head1!=NULL||head2!=NULL||carry){
         int sum=0;
         if(head1!=NULL){
             sum+=head1->data;
             head1=head1->next;
         }
         if(head2!=NULL){
             sum+=head2->data;
             head2=head2->next;
         }
         sum+=carry;
         carry=sum/10;
         Node *newnode=new Node(sum%10);
         temp->next=newnode;
         temp=newnode;
     }
     if(carry){
         temp->next=new Node(carry);
     }
     return dummy->next;

 }
int main(){
    Node* head=take_input();
    Node *head2=take_input();
    list<int>head3=add_them(head,head2);
    cout<<head3.size()<<endl;
    while(head3.size()!=0){
        cout<<head3.front();
        head3.pop_front();
    }
    return 0;
}