#include <iostream>

using namespace std;

const int max_size = 100;
template<class t>
class queue{
    int front,rear,length;
    t arr[max_size];

public:
    queue(){
        front=0;
        rear=max_size-1;
        length=0;
    }
    bool isEmpty(){
        return length==0;
    }
    bool isFull(){
        return length==max_size;
    }
    void enqueue(t item){
        if(isFull())
            cout<<"Queue is full"<<endl;
        else{
            rear = (rear+1)%max_size;
            arr[rear] = item;
            length++;
        }
    }
    void dequeue(){
        if(isEmpty())
            cout<<"Queue is empty"<<endl;
        else{
            front = (front+1)%max_size;
            length--;
        }
    }
    void getFront(t&frontItem){
        frontItem = arr[front];
    }
    void getRear(t&rearItem){
        rearItem = arr[rear];
    }
    void display(){
        if(isEmpty())
            cout<<"queue is empty"<<endl;
        else{
            int i = front;
            while(i != (rear+1)){
                cout<<arr[i]<<" ";
                i = (i + 1)%max_size;
            }
            cout<<endl;
        }
    }
    int qSearch(t element){
        int pos = -1;
        if(!isEmpty()){
            int i = front;
            while(i != (rear+1)){
                if(arr[i] == element)
                    pos = i;
                    break;
            }
        }
        return pos;
    }

};

int main()
{
    queue<int> q;
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(3);
    int s = 4;
    cout<<q.qSearch(s)<<endl;
    cout<<"------------------------------------"<<endl;
    int f = 0;
    q.getFront(f);
    cout<<f<<endl;
    cout<<"------------------------------------"<<endl;
    int r = 0;
    q.getRear(r);
    cout<<"Rear value : "<<r<<endl;
    cout<<"------------------------------------"<<endl;
    q.display();
    cout<<"------------------------------------"<<endl;
    q.dequeue();
    q.display();

    return 0;
}
