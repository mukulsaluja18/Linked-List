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
Node* after_odd(Node*head){
    Node *temp=head;
    Node* odd_head=NULL;
    Node* odd_tail=NULL;
    Node* even_head=NULL;
    Node* even_tail=NULL;
    while(temp!=NULL){
        if(temp->data%2!=0){
            if(!odd_head){
                odd_head=temp;
                odd_tail=temp;
            }
            else{
                odd_tail->next=temp;
                odd_tail=temp;
            }
        }
        else{
            if(!even_head){
                even_head=temp;
                even_tail=temp;
            }
            else{
                even_tail->next=temp;
                even_tail=temp;
            }
        }
        temp=temp->next;
    }
    if(odd_head!=NULL && even_head!=NULL){
        odd_tail->next=NULL;
        even_tail->next=NULL;
        odd_tail->next=even_head;
        return odd_head;
    }
    else if(even_head==NULL && odd_head!=NULL){
        odd_tail->next=NULL;
        return odd_head;
    }
    else{
        even_tail->next=NULL;
        return even_head;
    }
}
// lly approach we make 2 ll odd and even we traverse throught main ll and remove first and check if it is odd or wvwn if it is even we do add last in even ll and for odd we do add lst in odd
// by this approach there is constant space bcoz we also removing data from main na and adding inn other ll and at end we make head as odd ll head and tail as even tail and return 
int main(){
    Node* head=take_input();
    head=after_odd(head);
    print(head);
    return 0;
}