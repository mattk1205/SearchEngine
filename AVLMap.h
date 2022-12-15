//
// Created by mattw on 11/13/2022.
//

#ifndef FINALPROJEXAMPLES_AVLMAP_H
#include <utility>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#define FINALPROJEXAMPLES_AVLMAP_H
using namespace std;

template <typename K, typename V>
class AVLMap{

private:

    struct AvlNode{
        AvlNode *left;
        AvlNode *right;
        int height;
        K key;
        V value;
        AvlNode(const K &k, const V &v, AvlNode *lt, AvlNode *rt, int h = 0){
            key = k;
            value = v;
            left = lt;
            right = rt;
            height = h;

        }
    };
    AvlNode *root;

public:

    void clear(){
        clear(root);
    }

    void insert(const K &key, V &val) {
        insert(key, val, root);
    }

    int getSize(){
        return getSize(root);
    }

    bool isEmpty() const{
        return root == nullptr;
    }

    bool containsByKey(K key) const{
        return containsByKey(key, root);
    }

    bool containsByVal(V val) const{
        return containsByVal(val, root);
    }

    void prettyPrintTree() const{
        prettyPrintTree("", root, false);
    }

    void print_inOrder(){
        print_inOrder(root, 0);
    }

    AVLMap(){           //Default Constructor
        root = nullptr;
    }
    AVLMap(const AVLMap &rhs){     //copy constructor
        root = clone(rhs.root);
    }
    ~AVLMap(){//Destructor
        clear();
    }
    AVLMap& operator=(const AVLMap &rhs){         //Assignment Operator Overload
        clear();
        root = clone(rhs.root);
        return *this;
    }
    const V& operator[](const K &key){
        AvlNode* node = find(this->root,key);
        return node->value;
    }

    AvlNode* clone(AvlNode *rhs) const{
        if(rhs== nullptr)
            return nullptr;

        return new AvlNode(rhs->key, rhs->value, clone(rhs->left), clone(rhs->right), rhs->height);

    }
private:

    bool containsByKey(const K key, AvlNode* node) const{
        if (node == nullptr)
            return false;

        else if (key < node->key)
            return containsByKey(key, node->left);
        else if (node->key < key)
            return containsByKey(key, node->right);
        else
            return true; // found
    }

    bool containsByVal(const V val, AvlNode* node) const{
        if (node == nullptr)
            return false;

        else if (val < node->value)
            return containsByVal(val, node->left);
        else if (node->value < val)
            return containsByVal(val, node->right);
        else
            return true; // found
    }

    bool isEmpty(AvlNode* node) const{
        return node == nullptr;
    }

    AvlNode* find(AvlNode* node, const K key){
        if(node == nullptr)
            throw runtime_error("not found");
        if(key==node->key)
            return node;
        if(key < node->key)
            find(node->left, key);
        else
            find(node->right, key);
    }

    void insert(const K &key, const V &val, AvlNode* &node){
        if (node == nullptr){
            node = new AvlNode(key, val, nullptr, nullptr, 0);
            return; // single node
        }
        if (val < node->value)
            insert(key, val, node->left);
        else if (node->value < val)
            insert(key, val, node->right);
        else{} // Duplicate; do nothing
        balance(node);
    }
    void clear(AvlNode* &node){
       if(node!=nullptr) {
           clear(node->left);
           clear(node->right);
           delete node;
       }
       node = nullptr;
    }
    int getSize(AvlNode* node){
        int size = 0;
        if (node == nullptr)
            return size;
        else
            return(getSize(node->left) + 1 + getSize(node->right));
    }
    int getHeight(AvlNode* rhs){
            return rhs == nullptr ? -1 : rhs->height;
    }
    AvlNode *findMin(AvlNode *node) const
    {
        if(node == nullptr)
            return nullptr;
        if(node->left == nullptr)
            return node;
        return findMin(node->left);
    }

    // Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    void prettyPrintTree(const std::string &prefix, const AvlNode *node, bool isRight) const
    {
        if (node == nullptr)
            return;

        cout << prefix;
        cout << (isRight ? "---" : "|___");
        // print the value of the node
        std::cout << node->key << ": " << node->value << std::endl;

        // enter the next tree level - left and right branch
        prettyPrintTree(prefix + (isRight ? "   |" : "    "), node->right, true);
        prettyPrintTree(prefix + (isRight ? "   |" : "    "), node->left, false);
    }

    void rotateWithLeftChild(AvlNode *&k2){
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
        k1->height = max(getHeight(k1->left), getHeight(k2)) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode *& k1){
        AvlNode *k2 = k1->right;

        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
        k2->height = max(getHeight(k2->right), k1->height) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild(AvlNode *&k3){
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AvlNode *&k1){
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }
    static const int ALLOWED_IMBALANCE = 1;
    void balance(AvlNode*& curr){
            if (curr == nullptr)
                return;

            if (getHeight(curr->left) - getHeight(curr->right) > ALLOWED_IMBALANCE)  // unbalancing insertion was left
            {
                if (getHeight(curr->left->left) >= getHeight(curr->left->right))
                    rotateWithLeftChild(curr); // case 1 (outside)
                else
                    doubleWithLeftChild(curr); // case 2 (inside)
            }
            else if (getHeight(curr->right) - getHeight(curr->left) > ALLOWED_IMBALANCE) // unbalancing insertion was right
            {
                if (getHeight(curr->right->right) >= getHeight(curr->right->left))
                    rotateWithRightChild(curr); // case 4 (outside)
                else
                    doubleWithRightChild(curr); // case 3 (inside)
            }

            curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
    }
    int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    void deleteMin(AvlNode* node){
        delete findMin(node);
        balance(node);
    }

    void print_inOrder(AvlNode* curr, int level){
        if(curr == nullptr)
            return;
        print_inOrder(curr->left, level + 1);
        cout << "key:" << curr-> key << "\tvalue: " << curr-> value << endl;
        print_inOrder(curr->right, level + 1);
    }

    void print_Preorder(AvlNode* curr, int level){
        if(curr == nullptr)
            return;
        cout << setw(level * 2) << curr-> key << ": " << curr-> value << endl;
        print_Preorder(curr->left, level + 1);
        print_Preorder(curr->right, level + 1);
    }
    void print_Post_Order(AvlNode* curr, int level) {
        if (curr == nullptr)
            return;
        print_Post_Order(curr->left, level + 1);
        print_Post_Order(curr->right, level + 1);
        cout << setw(level * 2) << curr->key << ": " << curr->value << endl;
    }
};


#endif //FINALPROJEXAMPLES_AVLMAP_H
