#include<iostream>
#include"Node.h"
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
void print_ith(Node* head,int i){
    while(head!=NULL && i!=0){
        head=head->next;
        i--;
    }
    cout<<head->data<<endl;
}
int main(){
    Node* head=take_input();
    int i;
    cin>>i;
    print_ith(head,i);
    return 0;
}