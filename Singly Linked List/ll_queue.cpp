// linked list queue adapter
#include<bits/stdc++.h>
using namespace std;
class Queue_adap{
    list<int>li;
    public:
    int getSize(){
        return li.size();
    }
    void push(int val){
        li.push_back(val);
    }
    int pop(){ 
        if(li.size()==0){
            return -1;
        }
        int data=li.front();
        li.pop_front();
        return data;
    }
    int top(){
        if(li.size()==0){
            return -1;
        }
        return li.front();
    }

};
int main(){
    Queue_adap q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.getSize()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.getSize()<<endl;
    
}