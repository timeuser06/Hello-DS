#ifndef HELLO_DS_LINKED_LISTS_H
#define HELLO_DS_LINKED_LISTS_H



/*int popFront() {
    node<T>* temp = head;
    head = head->getNext();
    return temp->getData();   // ← Function **exits immediately**
    delete temp;              // ← This line is **unreachable**
}*/

template <typename T>
class node{
    node* next;
    T data;
public:
    node(T d) : data(d), next(nullptr) {}
    T getData(){return data;}
    node* getNext(){return next;}
    void setNext(node*n){next=n;}
    void setData(int d){data=d;}
};


template <typename T>
class Linear_Single_List {
    node<T>* head=nullptr;
public:

    void pushFront(T d) {
        node<T>* temp=new node(d);
        if (head==nullptr) {
            head=temp;
        }else{
            temp->setNext(head);
            head=temp;
        }
    }

    void pushBack(T d) {
        node<T>* temp=new node(d);
        if (head==nullptr) {
            head=temp;
        }else {
            node<T>* current=head;
            while (current->getNext()!=nullptr) {
                current=current->getNext();
            }
            current->setNext(temp);
        }

    }

    int popFront() {
        if (head==nullptr){throw std::out_of_range("List is empty");}
        if (head->getNext()==nullptr){delete head;}
        node<T>* temp= head;
        head=head->getNext();
        T data=temp->getData();
        delete temp;
        return data;

    }

    int popBack() {
        if (head==nullptr){throw std::out_of_range("List is empty");}
        if (head->getNext()==nullptr){return head->getData();delete head;}
        node<T>* current=head;
        while (current->getNext()->getNext()!=nullptr) {
            current=current->getNext();
        }
        node<T>* last=current->getNext();
        T data=last->getData();
        current->setNext(nullptr);
        delete last;
        return data;
    }

    int front(){return head->getData();}

    int back() {
        node<T>* current=head;
        while (current->getNext()!=nullptr) {
            current=current->getNext();
        }
        return current->getData();
    }

    bool isEmpty(){if (head==nullptr)return true;}

    int size() {
        int size=1;
        node<T>* current=head;
        while (current->getNext()!=nullptr) {
            current=current->getNext();
            size++;
        }
        return size;
    }

    void display() {
        node<T>* current=head;
        while (current->getNext()!=nullptr) {
            std::cout<<current->getData()<<",";
            current=current->getNext();
        }std::cout<<current->getData()<<";"<<std::endl;
    }


    ~Linear_Single_List() {
        while (head) {
            node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

#endif //HELLO_DS_LINKED_LISTS_H