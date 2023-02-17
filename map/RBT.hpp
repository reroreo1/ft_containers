/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:19:14 by mac               #+#    #+#             */
/*   Updated: 2023/02/17 19:37:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP


template <class T>
struct Node{
    enum {red, black} color;
    T data;
    Node *left;
    Node *right;
    Node *parent;
    void initialize(T a){
        data = a;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = red;
    };
};

template <class T>
class Rbt{
    typedef Node<T> Nodeptr;
    private:
        Nodeptr *root;
        Nodeptr *nil;
        Rbt(){
            nil = new Nodeptr;
            nil->color = Nodeptr::black;
            nil->parent = NULL;
            nil->left = NULL;
            nil->right = NULL;
            root = nil;
        };
        ~Rbt(){
            
        };
        Nodeptr* successorBST(Nodeptr* x){
            if (x.right != nil)
                return minValueNodeptr(x->right);
            Nodeptr* y = x->parent;
            while(y != nil && x == y.right){
                x = y;
                y = y->parent;
            }
            return y;
        };
        Nodeptr* predecessorBST(Nodeptr* x){
            if (x.left != nil)
                return (maxValueNodeptr(x->left));
            Nodeptr* y = x->parent;
            while(y != nil && x == y.left){
                x = y;
                y = y->parent;
            }
            return y
        }
        Nodeptr* getAunt(Nodeptr *x){
            Nodeptr *grandparent = x->parent->parent;
            if (grandparent == nil) {
                // The grandparent is null, so there is no aunt
                return nil;
            }
            if (x->parent == grandparent->left) {
                // The parent is the left child of the grandparent,so the aunt is the right child
                return grandparent->right;
            } else {
                // The parent is the right child of the grandparent,so the aunt is the left child
                return grandparent->left;
            }
        };
        void rotateLeft(Nodeptr* &_root,Nodeptr *&x){
            Nodeptr *y = x->right;
            x->right = y->left;
            if (y->left != nil)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == _root->nil)
                _root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        };
        void rotateRight(Nodeptr* &_root,Nodeptr* &x){
            Nodeptr *y = x->left;
            x->left = y->right;
            if (y->right != nil)
                y->right->parent = x;
            y->parent = x->parent;
            if (x->parent == _root->nil)
                _root = y;
            else if (x == x->parent->root)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;
            x->parent = y;
        };
        void makeRed(Nodeptr *&x){
            x->color = Nodeptr::red;
        };
        void makeBlack(Nodeptr *&x){
            x->color = Nodeptr::black;
        };
        void fixInsertRBTree(Nodeptr* &_root,Nodeptr *&a){
            if (_root == a){
                makeBlack(a);
                return;
            }
            makeRed(a);
            Nodeptr *y, *z;
            y = a->parent;
            z = y->parent->parent;
            if (y->color == Nodeptr::red){
                Nodeptr *aunt = getAunt(y);
                if (s->color == Nodeptr::black){
                    Nodeptr *one, *two, *three;
                    one = a;
                    two = y;
                    three = z;
                    makeBlack(two);
                    makeRed(one);
                    makeRed(three);
                }
                else{
                    makeBlack(y);
                    makeBlack(aunt);
                    makeRed(z);
                    fixInsertRBTree(_root, z);
                }
            }
        };
        void fixDeleteRBTree(Nodeptr *&);
        void inorderBST(Nodeptr *&);
        void preorderBST(Nodeptr *&);
        Nodeptr *minValueNodeptr(Nodeptr* x){
            NodePtr *currrent = x;
            while(current->left != nil)
                current = current->left;
            return current;
        };
        Nodeptr *maxValueNodeptr(Nodeptr* x){
            NodePtr *currrent = x;
            while(current->right != nil)
                current = current->right;
            return current;
        };
        Nodeptr* insertBST(T a){
            Nodeptr *newNode = new Nodeptr;
            newNode.initialize(a);
            Nodeptr *y = nil;
            Nodeptr *x = root;
            while(x != nil){
                y = x;
                if (a < x->left->data)
                    x = x->left;
                else x = x->right;
            }
            newNode->parent = y;
            if (y == nil)
                root = newNode;
            else if(a < y->data)
                y->left = newNode;
            else y.right = newNode;
            newNode->color = Nodeptr::red;
            fixInsertRBTree(newNode);
        };
        NodePtr *searchBST(Nodeptr *_node,T a){
            if (_node == nil || _node->data == a)
                return _node;
            if(a < _node->data)
                return searchBST(_node->left,a);
            else
                return searchBST(_node->right,a);
        };
        Nodeptr* deleteBST(Nodeptr* _root, T a){
            
        };
    public:
        RBTree();
        void insertValue(T a);
        void deleteValue(T a);
        void searchValue(T a);
        
        void inorder();
        void preorder();
};



#endif