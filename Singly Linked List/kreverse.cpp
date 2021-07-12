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
Node *reverse(Node *head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node *newnode=reverse(head->next);
	Node *tail=head->next;
	tail->next=head;
	head->next=NULL;
	return newnode;
}
Node *k_reverse(Node*head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1||k==0){
        return head;
    }
    int count=1;
    Node *h1=head;
    Node*t1=head;
    while(count<k && t1->next){
        t1=t1->next;
        count++;
    }
    Node *temp=t1->next;
    t1->next=NULL;
    Node *a=reverse(h1);
    Node*tail_rev=a;
    while(tail_rev->next!=NULL){
        tail_rev=tail_rev->next;
    }
    tail_rev->next=k_reverse(temp,k);
    return a;
}
// while mainll.size()>0
// other approach is we make 2 ll previous and current and in current we do remove girst from main ll and add last in curreent after it do k time then 
// if(prev==NULL)then prev=current and current=new and again do this for current k time and in this prev has some so we do prev ->tail->next=current->head and prev->ttail=current->ttail
// and now we reset current and do this k times  
// if we do rf al order dont change if we do rf af order changed agr k se choti hai mainll ki size to same ka same kreng 
// if(size>=k ) then wwork is ok else we dont do k time loop we do mainll siz and do main.removefirst nd current.addlast

Node* reverse_k(Node*head,int k){
    if(head==NULL||k==1){
        return head;
    }
    Node*dummy=new Node(0);
    dummy->next=head;
    Node*prev=dummy;
    Node* next=dummy;
    Node*cur=dummy;
    int count=0;
    while(cur->next!=NULL){
        cur=cur->next;
        count++;
    }
    while(count>=k){
        cur=prev->next;
        next=cur->next;
        for(int i=1;i<k;i++){
            cur->next=next->next;
            next->next=prev->next;
            prev->next=next;
            next=cur->next;
        }
        prev=cur;
        count-=k;
    }
    return dummy->next;
}
int main(){
    int k;
    Node* head=take_input();
    cin>>k;
    head=k_reverse(head,k);
    print(head);
    return 0;

}