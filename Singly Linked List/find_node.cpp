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
int find_node(Node*head,int n){
    if(!head){
        return -1;
    }
    if(head->data==n){
        return 0;
    }
    int ans=find_node(head->next,n);
    if(ans==-1){
        return -1;
    }
    else{
        return 1+ans;
    }
}
int find_node_iter(Node*head,int n){
    Node *temp=head;
    int c=0;
    while(temp!=NULL){
        if(temp->data==n){
            return c;
        }
        temp=temp->next;
        c++;
    }
    if(temp==NULL){
        return -1;
    }
}
int main(){
    int n;
    Node *head=take_input();
    cin>>n;
    cout<<find_node(head,n)<<endl;
    cout<<find_node_iter(head,n)<<endl;
    return 0;
}