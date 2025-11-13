#ifndef HELLO_DS_STACKS_H
#define HELLO_DS_STACKS_H

#include "Linked_Lists.h"
template<typename T>
class node;
template<typename T>
class Linear_Single_List;

template<typename T>
class Stack : public Linear_Single_List{
public:
    void push(T d){pushFront(d);}
    int pop(){popFront();}
    int top(){return head->getData();}
};

#endif //HELLO_DS_STACKS_H