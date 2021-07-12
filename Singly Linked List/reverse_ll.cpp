#include<iostream>
#include "Node.h"
using namespace std;
class Pair{
    public:
    Node* head;
    Node*tail;
};
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
Node* reverse(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node*temp=reverse(head->next);
    Node*a=temp;
    while(a->next!=NULL){
        a=a->next;
    }
    a->next=head;
    head->next=NULL;
    return temp;
}
// above approach take n^2 time so we optimized it let see
Pair reverse_0(Node*head){
    if(head==NULL||head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair temp=reverse_0(head->next);
    temp.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=temp.head;
    ans.tail=head;
    return ans;
}
//below is more optimized version
Node *reverse_1(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* next_node=head->next;
    Node* temp=reverse_1(head->next);
    next_node->next=head;
    head->next=NULL;
    return temp;
}
Node *reverse_it(Node*head){
    Node *prev=NULL;
    Node* current=head;
    Node* nxt=head;
    while(current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
    }
    return prev;
}
int length(Node* head){
    int l=1;
    while(head->next!=NULL){
        head=head->next;
    }
    return l;
}
Node * node_at_u(Node* head,int index){
    Node *temp=head;
    for(int i=0;i<length(head)-2;i++){
        temp=temp->next;
    }
    return temp;
}
void reverse_it1(Node *head){
    int li=0;
    int ri=length(head)-1;
    while(li<ri){
        Node*left=node_at_u(head,li);
        Node* right=node_at_u(head,ri);
        li++;
        ri--;
        int temp=left->data;
        left->data=right->data;
        right->data=temp;
    }
    
}
int len(Node *head){
    if(head==NULL){
        return 0;
    }
    return 1+len(head->next);
}
// reverse a linked list and rember we have to do data recursive that is we havr to do only data in reverse order not the pointers and contrain is do this in O(n) time
// dont use any extra space and do this by revcusrion only 
Node *rleft; 
void reverse_DR_helper(Node* right,int floor){
    if(right==NULL){
        return;
    }
    reverse_DR_helper(right->next,floor+1);
    if(floor > len(right)/2){
        int temp=right->data;
        right->data=rleft->data;
        rleft->data=temp;
        rleft=rleft->next;
    }
}
// we do fllor for do swapppning of two elements only  and for even size ll we have to go till florr>= 
void reverseDR(Node*head){
    rleft=head;
    reverse_DR_helper(head,0);
}
// above wale me kya hua ki rleft rhgea starting me and right rhega end me and after this we have to swap the data only like tqo piunter approach

Node * reverse_link(Node*head){
    // using iterative approach
    Node* dummy=NULL;
    while(head!=NULL){
        Node* next=head->next;
        head->next=dummy;
        dummy=head;
        head=next;
    }
    return dummy;
}
int main(){
    Node*head=take_input();
    head=reverse_it(head);
    print(head);
    return 0;
}