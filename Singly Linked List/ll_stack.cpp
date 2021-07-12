//ll to stack adapter(linked list ko adaapt krkr stack jaisa bna denge)
#include<list>
#include<bits/stdc++.h>
using namespace std;
// as we know in stack remove and addition are take at first place and to impelemnt thrigh linked list we have 2 option either to do 
// addlast getlastmremove last conbination or addfirst getfirst remove first combination so in this we will choose second combination bcoz
// firt combi take o(n) time each time it has to traverse the ll and do its operation so we use second combination
class stack_adapter{
    public:
    list<int> li;
    int getSize(){
        return li.size();
    }
    void push(int val){
        li.push_front(val);
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
    stack_adapter s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<s1.getSize()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

}