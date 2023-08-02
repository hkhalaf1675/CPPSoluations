#include <iostream>
#include<string>
using namespace std;
template<class t>
class doublylinkedlist{
    struct node{
        t item;
        node* next;
        node* prv;
    };
    node* head,*tail;
    int length;
public:
    doublylinkedlist(){
        head = tail = NULL;
        length = 0;
    }
    bool isEmpty(){
        return length == 0;
    }
    int getSize(){
        return length;
    }
    void addFirst(t element){
        node* newItemPtr = new node;
        newItemPtr->item = element;
        newItemPtr->prv = NULL;
        if(isEmpty()){
            newItemPtr->next = NULL;
            head = tail = newItemPtr;
        }
        else{
            newItemPtr->next = head;
            head->prv = newItemPtr;
            head = newItemPtr;
        }
        length++;
    }
    void addLast(t element){
        node* newItemPtr = new node;
        newItemPtr->item = element;
        newItemPtr->next = NULL;
        if(isEmpty()){
            newItemPtr->prv = NULL;
            head = tail = newItemPtr;
        }
        else{
            newItemPtr->prv = tail;
            tail->next = newItemPtr;
            tail = newItemPtr;
        }
        length++;
    }
    void addAtPosition(t element,int pos){
        if(pos < 0 || pos > length)
            cout<<"Enter a valid position"<<endl;
        else if(isEmpty() || pos == 0)
            addFirst(element);
        else if(pos == length)
            addLast(element);
        else{
            node* newItemPtr = new node;
            newItemPtr->item = element;
            node* cur = head;
            for(int i=0; i<pos; i++){
                cur = cur->next;
            }
            newItemPtr->next = cur;
            newItemPtr->prv = cur->prv;
            cur->prv = newItemPtr;
            length++;
        }
    }
    void deleteFirst(){
        if(isEmpty())
            cout<<"Empty list to delete"<<endl;
        else{
            node* temp = head;
            head = head->next;
            head->prv = NULL;
            temp->next = NULL;
            delete temp;
            length--;
        }
    }
    void deleteLast(){
        if(isEmpty())
            cout<<"Empty list to delete"<<endl;
        else{
            node* temp = tail;
            tail = tail->prv;
            tail->next = NULL;
            temp->prv = NULL;
            delete temp;
            length--;
        }
    }
    void deleteAtPosition(int pos){
        if(pos < 0 || pos > length)
            cout<<"Enter a valid position"<<endl;
        else if(isEmpty())
            cout<<"Empty List to delete"<<endl;
        else if(pos == 0)
            deleteFirst();
        else if(pos == length)
            deleteLast();
        else{
            node* cur = head;
            for(int i = 0; i<pos; i++)
                cur = cur->next;
            node* prvNode = cur->prv;
            node* nextNode = cur->next;
            prvNode->next = nextNode;
            nextNode->prv = prvNode;
            cur->next = NULL;
            cur->prv = NULL;
            delete cur;
            length--;
        }
    }
    void print(){
        if(isEmpty())
            cout<<"Empty list to print"<<endl;
        else{
            node* temp = head;
            while(temp != NULL){
                cout<<temp->item<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    doublylinkedlist<char> l;
    cout<<"Size First : "<<l.getSize()<<endl;

    l.addAtPosition('H',0);
    l.print();
    l.addAtPosition('a',1);
    l.print();
    l.addAtPosition('s',1);
    l.print();
    /*
    l.addLast('s');
    l.addFirst('H');
    l.addLast('s');
    l.addLast('a');
    l.addLast('n');
    l.addAtPosition('a',1);
    l.print();
    cout<<"Size after :"<<l.getSize()<<endl;
    l.deleteFirst();
    l.print();
    cout<<"Size after :"<<l.getSize()<<endl;
    l.deleteLast();
    l.print();
    cout<<"Size after :"<<l.getSize()<<endl;
    l.deleteAtPosition(0);
    l.print();
    cout<<"Size after :"<<l.getSize()<<endl;
    */

    return 0;
}
