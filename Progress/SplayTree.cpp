#include <iostream>
#include "SplayTree.h"
#include "node.h"


// Default constructor
SplayTree::SplayTree() {
    this->root_ = nullptr;
}

// Overloaded constructor, accepts data to create root node
SplayTree::SplayTree(int root) {
    this->root_ = new Node(root);
}

// --------------- PRIVATE METHODS -----------------

Node* SplayTree::insert(int data, Node* root) {
    // Case when the root node does not exist
    // Creates a new node with inputted dats
    if (!root){
        return new Node(data);
    }
    // If the root node is not empty, recursively search left for a valid node location
    if (data < root->value_) {
        root->left_ = insert(data, root->left_);
    }
    // Recursively search right for a valid node location
    else{
        root->right_ = insert(data, root->right_);
    }
    return root;
}

// Method for rebalancing tree
// Addresses case when child node is the left child of a node
Node* SplayTree::left_rotate(Node *root) {
    Node* curr = root->right_;
    root->right_ = curr->left_;
    curr->left_ = root;
    return curr;
}

// Method for rebalancing tree
// Addresses case when child node is the right child of a node
Node* SplayTree::right_rotate(Node *root) {
    Node* curr = root->left_;
    root->left_ = curr->right_;
    curr->right_ = root;
    return curr;
}

Node* SplayTree::search(int data, Node* root) {
    // Edge case when the root node does not exist
    if (!root){
        return root;
    }
    // Edge case when the target node is the root
    if (root->value_ == data) {
        return root;
    }
    // Traverse left
    if (root->value_ > data){
        //check for existens
        if (!root->left_){
            return root;
        }
        // "Zig-zig" step: If the node is a left child of a node that is also a left child
        // Traverse left
        if (root->left_->value_ > data){
            // Traverse as deep as possible on the left branch
            root->left_->left_ = search(data, root->left_->left_);
            // Perform the "zig" step
            root = right_rotate(root);
        }
        // "Zig-zag" step: If the node is a right child of a node that is a left child
        // Traverse right
        else if (root->left_->value_ < data){
            // Traverse as deep as possible on the right branch
            root->left_->right_ = search(data, root->left_->right_);

            if (root->left_->right_){
                root->left_ = left_rotate(root->left_);
            }
        }
        return ((!root) ? root : right_rotate(root));
    }
        //otherwise we have to branch right
    else{

        if (!root->right_){
            return root;
        }

        //zag-zig the node is part of a right child that is a left child
        if (root->right_->value_ > data){

            root->right_->left_ = search(data, root->right_->left_);

            //if the root exist rotate
            if (root->right_->left_){
                root->right_ = right_rotate(root->right_);
            }
        }

        //the node is a right child of a right child
        else if(root->right_->value_ < data){

            root->right_->right_ = search(data, root->right_->right_);
            root = left_rotate(root);
        }

      return ( (!root->right_)? root: left_rotate(root) ) ;
    }


}

int SplayTree::height(Node *root) {

    //nullptr case
    if(!root){
        return -1;
    }

    //else branch the tree
    int left = height(root->left_);
    int right = height(root->right_);

    //the depest depth is the height
    return ( left > right ? left+1 : right+1 );
}

void SplayTree::inorder(Node *root) {

    if (root) {
        inorder(root->left_);
        std::cout << root->value_ << " ";
        inorder(root->right_);
    }
}

void SplayTree::pre_order(Node* root) {
    if (root){
        std::cout << root->value_ << " ";
        pre_order(root->left_);
        pre_order(root->right_);
    }
}

void SplayTree::post_order(Node *root) {
    if (root){
        post_order(root->left_);
        post_order(root->right_);
        std::cout << root->value_ << " ";
    }
}

void SplayTree::destroy(Node *root) {
    if (!root){
        return;
    }
    destroy(root->left_);
    destroy(root->right_);
    delete root->left_;
    delete root->right_;
}

Node* SplayTree::delete_node(int data, Node *root) {

    if (!root) {
        return nullptr;
    }
    else {
        root = search(data, root);
    }

}

// --------------- PRIVATE METHODS -----------------

void SplayTree::insert(int key){
    this->root_ = this->insert(key, this->root_);
}

void SplayTree::inorder() {
    this->inorder(this->root_);
}

void SplayTree::search(int key) {
  this->root_= this->search(key, this->root_);
}

int SplayTree::height() {
    return this->height(this->root_);
}

int SplayTree::get_root(){
    return this->root_->value_;
}

void SplayTree::pre_order() {
    this->pre_order(this->root_);
}

void SplayTree::post_order() {
    this->post_order(this->root_);
}

SplayTree::~SplayTree() {
    this->destroy(this->root_);
}