#include <iostream>

using namespace std;
template<class t>
class stack{
    int top=-1;
    t arr[100];

public:
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == 99;
    }
    int getTop(){
        return arr[top];
    }
    void push(t newItem){
        if(isFull()){
            cout<<"the stack is full"<<endl;
        }
        else{
            top++;
            arr[top] = newItem;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"the stack is empty"<<endl;
        }
        else{
            top--;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"the stack is empty"<<endl;
        }
        else{
            for(int i=0; i<=top; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    cout<<"-----------------------------------------"<<endl;
    s.pop();
    s.display();
    cout<<"-----------------------------------------"<<endl;
    cout<<s.getTop()<<endl;
    return 0;
}
