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
Node* bubble_Sort(Node* head){
    if(head==NULL && head->next==NULL){
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    while(temp->next!=NULL){
        if(temp->data > temp->next->data){
            // swap
            prev->next=current->next;

        }
        prev=temp;
        temp=temp->next;
    }
}
/*
int len(node *head){
    node *temp=head;
    int count=1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
node* bubble_sort_LinkedList_itr(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    
   // node *curr=head;
    //node *prev=NULL;
    //node *n=head->next;
    for(int i=0;i<len(head);i++){
        node *curr=head;
        node *prev=NULL;
          // node *n=head->next;
        
        while(curr->next!=NULL) // traverse though LL
        {
            if(curr->data > curr->next->data)  // if nodes are to be swapped
            {
				if(prev)   //check if previous of the current node exist , u cant point on a garbage value
                {
                    // swapping using those 4 steps
                    node* t=curr->next->next;
                    curr->next->next= curr;
                    prev->next=curr->next;
                    curr->next=t;
                    prev=prev->next;
                }
                else  //is it doent exist it would be head node 
                {
                    head= curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                }
                
            }
            else    // else you simply move to next node
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }

  
    return head;
}
*/
int main(){
    Node* head=take_input();
    head=bubble_Sort(head);
    print(head);
    return 0;
}