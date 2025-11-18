//
// Created by timeu on 11/17/2025.
//

#ifndef HELLO_DS_BST_H
#define HELLO_DS_BST_H



class node{
public:
    int data;
    node* left;
    node* right;
    node(int d) : data(d),left(nullptr),right(nullptr) {}
};




class bst {
    node* mainRoot=nullptr;
    node* root=nullptr;
public:
    void add(int d) {
        node* temp=new node(d);
        if (!mainRoot){
            mainRoot=temp;
            root=temp;
        }

        else if (root->data < temp->data) {
            if (root->right==nullptr) {
                root->right=temp;
                root=mainRoot;
            } else {
                delete temp;
                root=root->right;
                add(d);
            }
        }

        else if (root->data > temp->data) {
            if (root->left==nullptr) {
                root->left=temp;
                root=mainRoot;
            }
            else {
                delete temp;
                root=root->left;
                add(d);
            }
        }
    }




    node* search(int d) {
        if (root->data==d) {
            node* temp=root;
            root = mainRoot;
            return temp;
        }
        if (root->data<d && root->right != nullptr) {
            root=root->right;
             return search(d);
        }
        if (root->data>d && root->left!=nullptr) {
            root=root->left;
             return search(d);
        }
        root=mainRoot;
        return nullptr;
    }

    /*
                                (50)
                               /    \
                          (30)        (70)
                         /   \        /   \
                     (20)   (40)  (60)   (80)
                    /   \     \           / \
                 (10)  (25)   (45)      (75) (90)
                 /         \            /  \
               (5)        (27)        (68)  (77)

*/
    node* prenode(node* child) {
        if (child==mainRoot){return nullptr;}

        node* Parent = mainRoot;
        if (Parent->left==child || Parent->right==child){return Parent;}
        while (Parent->left!=child && Parent->right!=child) {
            if (Parent->data < child->data){
                Parent = Parent->right;
            }  else  if (Parent->data>child->data) {
                Parent = Parent-> left;
            }
        }
        return Parent;
    }

    void deleteValue(int d){
        node* temp=search(d);
        if (temp!=nullptr) {
            if (temp->right==nullptr && temp->left==nullptr) {
                node* parent= prenode(temp);
                if (parent==nullptr){delete temp;}
                else if (parent->left==temp){parent->left=nullptr;}
                else{parent->right=nullptr;}
                delete temp;
            }
            if (temp->right!=nullptr && temp->left==nullptr) {
                node* newLeft=temp->right->left;
                node* newRight=temp->right->right;
                temp->data=temp->right->data;
                delete temp->right;
                temp->left=newLeft;
                temp->right=newRight;
            }
            if (temp->right==nullptr && temp->left!=nullptr) {
                node* newLeft=temp->left->left;
                node* newRight=temp->left->right;
                temp->data=temp->left->data;
                delete temp->left;
                temp->left=newLeft;
                temp->right=newRight;
            }
            //TAKING ONLY left BRANCH
            if (temp->right!=nullptr && temp->left!=nullptr) {
                node* biggest=temp->left;
                while (biggest->right!=nullptr) {
                    biggest=biggest->right;
                }
                temp->data=biggest->data;
                node* parent=prenode(biggest);
                if (parent->left==biggest){parent->left=nullptr;}
                else{parent->right=nullptr;}
                delete biggest;
            }
        }
    }
};

#endif //HELLO_DS_BST_H