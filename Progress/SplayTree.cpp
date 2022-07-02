#include <iostream>
#include "SplayTree.h"
#include "node.h"


//constructor
SplayTree::SplayTree() {
    this->root_ = nullptr;
}

SplayTree::SplayTree(int root) {
    this->root_ = new Node(root);
}


//private methods
Node* SplayTree::insert(int data, Node* root) {

    //case where root is empty
    if (!root){
        return new Node(data);
    }

    //otherwise, search for the spot to insert
    //branch left
    if (data < root->value_) {
        root->left_ = insert(data, root->left_);
    }
    //branch right
    else{
        root->right_ = insert(data, root->right_);
    }

    return root;
}

Node* SplayTree::left_rotate(Node *root) {
    Node* curr = root->right_;
    root->right_ = curr->left_;
    curr->left_ = root;
    return curr;
}

Node* SplayTree::right_rotate(Node *root) {
    Node* curr = root->left_;
    root->left_ = curr->right_;
    curr->right_ = root;
    return curr;
}

Node* SplayTree::search(int data, Node* root) {

    //case the node is the root
    if (root->value_ == data || !root) {
        return root;
    }
    //branch left
    if (root->value_ > data){

        //check for existens
        if (!root->left_){
            return root;
        }
        //zig-zig: check for the node to be a left child of a left child
        //keep searching left
        if (root->left_->value_ > data){
            //go as deep as possible on the left branch
            root->left_->left_ = search(data, root->left_->left_);
            //perform the zig step
            root = right_rotate(root);
        }

        //else perform the zig-zag step the node is a right child of a left child
        else if (root->left_->value_ < data){
            root->left_->right_ = search(data, root->left_->right_);

            if (root->left_->right_){
                root->left_ = left_rotate(root->left_);
            }
        }

        return ( (!root)? root: right_rotate(root) );

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


//public methods
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