#include <iostream>

using namespace std;

template<class t>
class linkedList{
    struct node{
    t item;
    node *next;
    };
    node *head;
    node *tail;
    int length;
public:
    linkedList(){
        head = tail =NULL;
        length = 0;
    }

    bool isEmpty(){
        return length == 0;
    }
    int getLength(){
        return length;
    }
    t getHead(){
        if(isEmpty()){
            cout<<"list is empty ...!"<<endl;
            return NULL;
        }
        else
            return head->item;
    }
    t getTail(){
        if(isEmpty()){
            cout<<"list is empty ...!"<<endl;
            return NULL;
        }
        else
            return tail->item;
    }
    void insertAtFirst(t element){
        node *newItem = new node;
        newItem->item = element;
        if(isEmpty()){
            head = tail = newItem;
            newItem->next = NULL;
        }
        else{
            newItem->next = head;
            head = newItem;
        }
        length++;
    }
    void insertAtEnd(t element){
        node *newItem = new node;
        newItem->item = element;
        if(isEmpty()){
            head = tail = newItem;
            newItem->next = NULL;
        }
        else{
            tail->next = newItem;
            newItem->next = NULL;
            tail = newItem;
        }
        length++;
    }
    void insertAtPos(int pos, t element){
        if(pos < 0 || pos > length)
            cout<<"Out Of Range "<<endl;
        else{
            if(pos == 0)
                insertAtFirst(element);
            else if(pos == length)
                insertAtEnd(element);
            else{
                node *newItem = new node;
                newItem->item = element;
                node *cur = head;
                for(int i =1;i < pos; i++)
                    cur = cur->next;
                newItem->next = cur->next;
                cur->next = newItem;
            }
            length++;
        }
    }
    void display(){
        if(isEmpty())
            cout<<"List Is Empty "<<endl;
        else{
            node *cur = head;
            while(cur != NULL){
                cout<<cur->item;
                cur = cur->next;
            }
            cout<<endl;
        }
    }

};

int main()
{
    linkedList<char> l;
    l.insertAtFirst('H');
    l.insertAtEnd('A');
    l.insertAtPos(2,'S');
    l.insertAtPos(2,'S');
    l.insertAtEnd('A');
    l.insertAtEnd('N');
    l.display();
    cout<<"-------------------------"<<endl;
    cout<<"List Length : "<<l.getLength()<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Head Value : "<<l.getHead()<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Tail Value : "<<l.getTail()<<endl;
    return 0;
}
