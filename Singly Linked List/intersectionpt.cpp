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
int len(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
Node *trav(Node *head,int d){
    int c=0;
    while(c!=d){
        head=head->next;
        c++;
    }
    return head;
}
int intersection_point(Node*head1,Node*head2){
    int ans=-1;
    int size1=len(head1);
    int size2=len(head2);
    int delta=abs(size1-size2);
    if(size1>size2){
        head1=trav(head1,delta);
    }
    else{
        head2=trav(head2,delta);
    }
    while(head1!=NULL && head2!=NULL){
        if(head1=head2){
            ans=head1->data;
            break;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return ans;
}
// optimal approach
int intersection(Node*head1,Node*head2){
    if(head1==NULL||head2==NULL){
        return NULL;
    }
    Node*a=head1;
    Node*b=head2;
    while(a!=b){
        a= a==  NULL?head2:a->next;
        b= b==  NULL?head1:b->next;
    }
    return a;
}
int main(){
    Node* head1=take_input();
    Node*head2=take_input();
    cout<<intersection_point(head1,head2)<<endl;
    return 0;
}