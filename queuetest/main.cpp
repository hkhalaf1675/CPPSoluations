#include <iostream>
#include<string>
using namespace std;
template<class t>
class queue{
    int front,rear,length;
    t arr[100];
public:
    queue(){
        front = rear = -1;
        length = 0;
    }
    bool isEmpty(){
        return length == 0;
    }
    bool isFull(){
        return length == 100;
    }
    void inqueue(t element){
        if(isEmpty())
            front = rear =0;
        else
            rear++;
        arr[rear] = element;
        length++;
    }
    void dequeue(){
        if(isEmpty())
            cout<<"No items to delete"<<endl;
        else if(length == 1){
            front = rear = -1;
            length--;
        }
        else{
            front++;
            length--;
        }
    }
    void print(){
        if(isEmpty())
            cout<<"No items to show it"<<endl;
        else{
            for(int i=front; i<=rear; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    int getLength(){
        return length;
    }
};
using namespace std;

int main()
{
    queue<char> q;
    cout<<"Length before : "<<q.getLength()<<endl;
    q.inqueue('H');
    q.inqueue('a');
    q.inqueue('s');
    q.inqueue('s');
    q.inqueue('a');
    q.inqueue('n');
    q.print();
    cout<<"Length before delete : "<<q.getLength()<<endl;
    q.dequeue();
    cout<<"Length after delete : "<<q.getLength()<<endl;
    q.print();
    return 0;
}
