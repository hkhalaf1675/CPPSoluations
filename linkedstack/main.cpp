#include <iostream>

using namespace std;
template<class t>
class stack{
    struct node{
        t item;
        node *next;
    };
    node *top;
    node *cur;

public:
    stack(){top = NULL;}
    bool isEmpty(){
        return top == NULL;
    }
    void push(t newItem){
        node *newItemPtr = new node;
        if(newItemPtr == NULL){
            cout<<"the stack cannot allocated memory"<<endl;
        }
        else{
            newItemPtr->item = newItem;
            newItemPtr->next = top;
            top = newItemPtr;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"the stack is empty"<<endl;
        }
        else{
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"the stack is empty"<<endl;
        }
        else{
            cur = top;
            while(cur != NULL){
                cout<<cur->item<<"  ";
                cur = cur->next;
            }
            cout<<endl;
        }
    }
    void getTop(){
        if(isEmpty()){
            cout<<NULL<<endl;
        }
        else{
            cout<<top->item<<endl;
        }
    }
};

int main()
{
    stack<int> s;

    s.getTop();
    cout<<"-------------------"<<endl;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    cout<<"-------------------"<<endl;
    s.pop();
    s.display();
    cout<<"-------------------"<<endl;
    s.getTop();
    return 0;
}
