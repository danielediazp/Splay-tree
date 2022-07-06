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
    // Creates a new node with inputted data
    if (!root){
        return new Node(data);
    }
    //Splaying will bring the closest leaf node as the root
    root = splay_tree(data, root);

    // Case when value already exists in the tree
    if (data == root->value_){
        root->counter_++;
        return root;
    }

    //This new node will be inserting
    Node *insert_node = new Node(data);

    //Since the new leaf node is now the root, we insert as we would either left or right

    //If our current root is greater than what we're inserting
    //The current root is now the right child of our inserted node
    //and the left child of the current root is our inserted node;
    if (data < root->value_) {
        insert_node->right_ = root;
        insert_node->left_ = root->left_;
        root->left_ = nullptr;
    }

    //Vise versa
    else {
        insert_node->left_ = root;
        insert_node->right_ = root->right_;
        root->right_ = nullptr;
    }

    return insert_node;
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

Node* SplayTree::splay_tree(int data, Node* root) {
    // Edge case when the root node does not exist
    if (!root || root->value_ == data) {
        return root;
    }
    if (root->value_ > data){
        // Traverse left

        // Check if the target node exists
        if (!root->left_){
            return root;
        }
        // "Zig-zig" step: If the node is a left child of a node that is also a left child
        // Traverse left
        if (root->left_->value_ > data){
            // Traverse as deep as possible on the left branch
            root->left_->left_ = splay_tree(data, root->left_->left_);
            // Perform the "zig" step
            root = right_rotate(root);
        }
            // "Zig-zag" step: If the node is a right child of a node that is a left child
            // Traverse right
        else if (root->left_->value_ < data){
            // Traverse as deep as possible on the right branch
            root->left_->right_ = splay_tree(data, root->left_->right_);

            if (root->left_->right_){
                root->left_ = left_rotate(root->left_);
            }
        }
        return ((!root->left_) ? root : right_rotate(root));
    } else {
        // Otherwise, branch right

        // Check if the target node exists
        if (!root->right_){
            return root;
        }
        // "Zag-zig" step: If the node is a right child of a node that is a left child
        // Traverse left
        if (root->right_->value_ > data){
            // Traverse as deep as possible on the left branch
            root->right_->left_ = splay_tree(data, root->right_->left_);

            // If the root exists, rotate
            if (root->right_->left_){
                root->right_ = right_rotate(root->right_);
            }
        } else if(root->right_->value_ < data){
            // Traverse as deep as possible on the right branch
            root->right_->right_ = splay_tree(data, root->right_->right_);
            root = left_rotate(root);
        }
        return ((!root->right_) ? root : left_rotate(root)) ;
    }
}

int SplayTree::height(Node *root) {
    // Edge case when the tree is empty
    if (!root){
        return -1;
    }

    // Recursively traverse the tree and keep track of current height
    int left = height(root->left_);
    int right = height(root->right_);

    // Deepest depth between the left and right branches of the tree is the height
    return ((left > right) ? left+1 : right+1);
}

// Output values in the tree using inorder ordering
void SplayTree::inorder(Node *root) {
    if (!root){
        return;
    }
    inorder(root->left_);
    std::cout << root->value_ << " ";
    inorder(root->right_);
}

// Output values in the tree using preorder ordering
void SplayTree::pre_order(Node* root) {
    if (!root){
        return;
    }
    std::cout << root->value_ << " ";
    pre_order(root->left_);
    pre_order(root->right_);
}

// Output values in the tree using postorder ordering
void SplayTree::post_order(Node *root) {
    if (!root){
        return;
    }
    post_order(root->left_);
    post_order(root->right_);
    std::cout << root->value_ << " ";
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

void SplayTree::BFS(Node *root, std::vector<int> &target_vector){
    int h = this->height();
    for (int l = 0; l <= h; l++){
        level_order(root, l, target_vector);
    }
}

void SplayTree::level_order(Node *root, int l, std::vector<int> &target_vector){
    if (root == nullptr){
        target_vector.push_back(NULL);
        return;
    }
    if (l == 0){
        target_vector.push_back(root->value_);
    } else if (l > 0){
        level_order(root->left_, l - 1, target_vector);
        level_order(root->right_, l - 1, target_vector);
    }
}

Node* SplayTree::delete_node(int data, Node *root) {

    if (!root) {
        return nullptr;
    }
    else {
        root = splay_tree(data, root);
        if (data != root->value_) {
            return root;
        }
        if (!root->left_) {
            Node* temp = root->right_;
            root->right_ = nullptr;
            delete root;
            return temp;
        } else {

            Node* left_tree = root->left_;
            Node* right_tree = root->right_;
            root = splay_tree(data, left_tree);

            root->right_ = right_tree;
            return root;
        }
    }
}

// void SplayTree::handleInput(const std::string& filename){
//     std::ifstream input(filename);
//     std::string value;
//     std::vector<int> input;
//     int num;
//     while ({
//     }
// }

// --------------- PUBLIC METHODS -----------------

void SplayTree::insert(int key){
    this->root_ = this->insert(key, this->root_);
}

void SplayTree::inorder() {
    this->inorder(this->root_);
}

void SplayTree::splay_tree(int key) {
    this->root_= this->splay_tree(key, this->root_);

}

void SplayTree::delete_node(int key) {
    this->root_= this->delete_node(key, this->root_);
}

int SplayTree::height() {
    return this->height(this->root_);
}

int SplayTree::get_root(){
    return this->root_->value_;
}

void SplayTree::pre_order() {
    std::cout << "Executing preorder" << std::endl;
    this->pre_order(this->root_);
}

void SplayTree::post_order() {
    this->post_order(this->root_);
}

SplayTree::~SplayTree() {
    this->destroy(this->root_);
}

void SplayTree::BFS(std::vector<int> &target_vector){
    this->BFS(this->root_, target_vector);
}