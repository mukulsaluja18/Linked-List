#include<iostream>
#include "Node.h"
using namespace std;
int main(){
    // making nodes statically

    Node n1(10);
    // for storng the address of first node we we use head pointer which store the address of first node of ll
    Node *head=&n1;

    Node n2(20);

    n1.next=&n2;

    cout<<n1.data<<"  "<<n2.data<<endl;

    cout<<head->data<<" "<<head->next->data<<endl;


    // making nodes dynamically
    Node * n3=new Node(30);
    Node *temp=n3;
    Node* n4=new Node(40);
    n3->next=n4;

    cout<<temp->data<<" "<<temp->next->data<<endl;
    return 0;
    

}