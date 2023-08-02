#include <iostream>
#include<string>
using namespace std;

template<class t>
class dynamicQueue{
    int front;
    int rear;
    int length;
    int max_size;
    t *arr;
public:
    dynamicQueue(int size){
        front = 0;
        if(size<=0)
            max_size = 100;
        else
            max_size = size;
        rear = max_size - 1;
        length = 0;
        arr = new t[max_size];
    }
    bool isEmpty(){
        return length == 0;
    }
    bool isFull(){
        return length == max_size;
    }
    void enqueue(t element){
        if(isFull())
            cout<<"the queue is full"<<endl;
        else{
            rear = (rear+1)%max_size;
            arr[rear] = element;
        }
    }
    void dequeue(){
        if(isEmpty())
            cout<<"the queue is empty"<<endl;
        else{
            front = (front+1)%max_size;
        }
    }
    void getFront(t&element){
        if(isEmpty())
            element = NULL;
        else
            element = arr[front];
    }
    void getRear(t&element){
        if(isEmpty())
            element = NULL;
        else
            element = arr[rear];
    }
    int getSize(){
        return length;
    }
    void display(){
        if(isEmpty())
            cout<<"the queue is empty"<<endl;
        else{
            int i = front;
            while(i != (rear+1)){
                cout<<arr[i]<<" ";
                i = (i+1)%max_size;
            }
            cout<<endl;
        }
    }
    int qSearch(t element){
        int index = -1;
        if(isEmpty())
            index = -1;
        else{
            int i = front;
            while(i != (rear+1)){
                if(arr[i] == element){
                    index = i;
                    break;
                }
                i = (i+1)%max_size;
            }
        }
        return index;
    }


};

int main()
{
    dynamicQueue<int> q(5);
    q.dequeue();
    cout<<"--------------------------"<<endl;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    cout<<"--------------------------"<<endl;
    int f;
    q.getFront(f);
    cout<<"front element : "<<f<<endl;
    cout<<"--------------------------"<<endl;
    int r;
    q.getRear(r);
    cout<<"rear element : "<<r<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Queue Size : "<<q.getSize()<<endl;
    cout<<"--------------------------"<<endl;
    q.display();
    cout<<"--------------------------"<<endl;
    cout<<"search on 25 : "<<q.qSearch(25)<<endl;;
    cout<<"--------------------------"<<endl;

    return 0;
}
