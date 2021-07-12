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
Node *rleft;
bool isPalindrome_helper(Node*head){
    if(head==NULL){
        return true;
    }
    bool ans=isPalindrome_helper(head->next);
    if(ans==false){
        return false;
    }
    else if(head->data != rleft->data){
        return false;
    }
    else{
        rleft=rleft->next;
        return true;
    }
}
// in this we can also take fllor to do this in half
void isPalindrome(Node*head){
    rleft=head;
    isPalindrome_helper(head);
}
int main(){
    Node*head=take_input();

}