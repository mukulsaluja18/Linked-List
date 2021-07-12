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
 /*   cout<<endl;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<head->data<<" "; 
*/  
}
int length(Node *head){
    int l=1;
    while(head->next!=NULL){
        head=head->next;
        l++;
    }
    return l;
}
Node* insert_after_pos(Node*head,int pos,int data){
    int len=length(head);
    Node* newnode=new Node(data);
    if(pos>len){
        return head;
    }
    else if(pos==len-1){
        // insert at end
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        return head;
    }
    else{
        int count=0;
        Node* temp=head;
        while(count<pos&&temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        Node* a=temp->next;
        temp->next=newnode;
        newnode->next=a;
        newnode->prev=temp;
        a->prev=newnode;
        return head;
    }
}
// insert the node after ith node
int main(){
    int pos,data;
    Node *head=take_input();
    cin>>pos>>data;
    head=insert_after_pos(head,pos,data);
    print(head);
    return 0;
}
