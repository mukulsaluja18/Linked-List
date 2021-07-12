#include<iostream>
#include "Node.h"
using namespace std;
void printll(Node *head){
    Node *temp=head;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node* n1=new Node(10);
    Node* n2=new Node(20);
    Node* n3=new Node(30);
    Node* n4=new Node(40);
    Node* n5=new Node(50);

    Node *head=n1;
    // assigning address
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;

    printll(head);
    return 0;
}