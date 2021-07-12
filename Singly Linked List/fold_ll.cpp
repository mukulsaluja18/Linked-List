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
int len(Node*head){
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
// how about ki 1st vale ko last se coonect and last vale ko 1st ke next se and 1st ke next se second last ko
Node *rleft;
/*
void fold_hleper(Node* right,int floor){
    if(right==NULL){
        return;
    }
    fold_hleper(right->next,floor+1);
    if(floor>len(right/2)){
        Node *temp=rleft->next;
        rleft->next=right;
        right->next=temp;
        rleft=temp;
    }
    else if(floor==size/2){
        tail=right;
        tail->next=NULL;
    }
}
*/
void fold(Node *head){
    rleft=head;

    fold_hleper(head,0);
}
int main(){
    Node*head=take_input();

}