#ifndef HELLO_DS_LINKED_LISTS_H
#define HELLO_DS_LINKED_LISTS_H

#include <iostream>

class Node{
    Node* next;
    int data;
public:
    Node(int d) : data(d), next(nullptr) {}
    int getData(){return data;}
    Node* getNext(){return next;}
    void setNext(Node*n){next=n;}
    void setData(int d){data=d;}
};

class Single_LinkedList {
    Node* head=nullptr;
public:
    Single_LinkedList(){}

    void addFront(int d) {
        Node* temp=new Node(d);
        if (head==nullptr) {
            head=temp;
        }else{
            temp->setNext(head);
            head=temp;
        }
    }

    void addEnd(int d) {
        Node* temp=new Node(d);
        if (head==nullptr) {
            head=temp;
        }else {
            Node* current=head;
            while (current->getNext()!=nullptr) {
                current=current->getNext();
            }
            current->setNext(temp);
        }

    }

    void deleteFront() {
        if (head==nullptr){return;}
        if (head->getNext()==nullptr){delete head;}
        Node* temp= head;
        head=head->getNext();
        delete temp;
    }

    void deleteEnd() {
        if (head==nullptr){return;}
        if (head->getNext()==nullptr){delete head;}
        Node* current=head;
        while (current->getNext()->getNext()!=nullptr) {
            current=current->getNext();
        }
        delete current->getNext();
        current->setNext(nullptr);
    }

    void display() {
        Node* current=head;
        while (current->getNext()!=nullptr) {
            std::cout<<current->getData()<<",";
            current=current->getNext();
        }std::cout<<current->getData()<<";"<<std::endl;
    }

    ~Single_LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

#endif //HELLO_DS_LINKED_LISTS_H