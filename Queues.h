#ifndef HELLO_DS_QUEUES_H
#define HELLO_DS_QUEUES_H

//Rule: Never delete the same pointer twice.

#include "Linked_Lists.h"
template<typename T>
class node;
template<typename T>
class Linear_Single_List;

template<typename T>
class Queue {
    node<T>* front=nullptr;
    node<T>* rear=nullptr;
    int size=0;
public:
    void enqueue(T d) {
        node<T>* temp=new node(d);
        if (front==nullptr&&rear==nullptr) {
            front=rear=temp;
            size++;
        }
        if (front==rear) {
            front->setNext(temp);
            rear=temp;
            size++;
        }
        if (front!=rear) {
            rear->setNext(temp);
            rear=temp;
            size++;
        }
    }

    void dequeue() {
        if (front==nullptr&&rear==nullptr) {
            std::cout<<"Queue is empty";
        }
        if (front==rear) {
            delete front;
            front=nullptr;
            rear=nullptr;
            size--;
        }
        if (front!=rear) {
            node* temp=front->getNext();
            delete front;
            front =temp;
            size--;
        }
    }

    T front(){return front->getData;}
    int size(){return size;}
    bool isEmpty() {if (front==nullptr&&rear==nullptr)return true;}
    void clear() {
        while (front!=rear) {
            dequeue();
        }
        dequeue();
    }
};

#endif //HELLO_DS_QUEUES_H