#include <iostream>
#include<string>
using namespace std;
template<class t>
class linkedqueue{
    struct node{
        t item;
        node *next;
    };
    node *front;
    node *rear;
    int length;
public:
    linkedqueue(){
        front=rear=NULL;
        length = 0;
    }
    bool isEmpty(){
        return length == 0;
    }
    void enqueue(t element){
        node *newItemPtr = new node;
        newItemPtr->item = element;
        newItemPtr->next = NULL;
        if(isEmpty()){
            rear = newItemPtr;
            front = newItemPtr;
        }
        else{
            rear->next = newItemPtr;
            rear = newItemPtr;
        }
        length++;
    }
    void dequeue(){
        if(isEmpty())
            cout<<"the queue is empty"<<endl;
        else{
            if(length == 1){
                delete front;
                rear = NULL;
                length = 0;
            }
            else{
                node *temp = front;
                front = front->next;
                temp->next = NULL;
                delete temp;
                length--;
            }
        }
    }

    void display(){
        if(isEmpty())
            cout<<"queue is empty"<<endl;
        else{
            node *temp = new node;
            temp = front;
            while(temp != NULL){
                cout<<temp->item<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    t getFront(){
        if(isEmpty())
            return NULL;
        else
            return front->item;
    }
    t getRear(){
        if(isEmpty())
            return NULL;
        else
            return rear->item;
    }
    void qclear(){
        if(!isEmpty()){
            node *cur;
            while(front != NULL){
                cur = front;
                front = front->next;
                delete cur;
            }
            rear = NULL;
            length = 0;
        }
    }

};

int main()
{
    linkedqueue<int> q;
    q.dequeue();
    cout<<"Front Value : "<<q.getFront()<<endl;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    q.display();
    cout<<"----------------------"<<endl;
    cout<<"Front Value : "<<q.getFront()<<endl;
    cout<<"----------------------"<<endl;
    q.dequeue();
    q.display();
    cout<<"----------------------"<<endl;
    q.dequeue();
    q.display();
    cout<<"----------------------"<<endl;
    q.qclear();
    q.display();
    cout<<"----------------------"<<endl;
    return 0;
}
