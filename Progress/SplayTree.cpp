#include "SplayTree.h"
#include "Node.h"
#include "Splay.h"
// Default constructor


SplayTree::SplayTree() {
    this->root_ = nullptr;
    this->global_font.loadFromFile("../coolvetica.otf");
}

// Overloaded constructor, accepts data to create root node
SplayTree::SplayTree(int root) {
    this->root_ = new Node(root);
}

//Overloaded constructor, accepts a file name and creates a tree
SplayTree::SplayTree(std::string file_name) {
    int root_catcher = 0;
    std::ifstream inFile(file_name);
    std::string line;
    while(std::getline(inFile, line)){
        std::istringstream stream(line);
        char data;
        while(stream >> data){
            if (root_catcher == 0){
                this->root_ = new Node(data);
                root_catcher = 1;
            }else{
                root_ =  insert(data, root_);
            }
        }
    }
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
    if (root->value_ > data) {
        // Traverse left

        // Check if the target node exists
        if (!root->left_) {
            return root;
        }
        // "Zig-zig" step: If the node is a left child of a node that is also a left child
        // Traverse left
        if (root->left_->value_ > data) {
            // Traverse as deep as possible on the left branch
            root->left_->left_ = splay_tree(data, root->left_->left_);
            // Perform the "zig" step
            root = right_rotate(root);
        }
            // "Zig-zag" step: If the node is a right child of a node that is a left child
            // Traverse right
        else if (root->left_->value_ < data) {
            // Traverse as deep as possible on the right branch
            root->left_->right_ = splay_tree(data, root->left_->right_);

            if (root->left_->right_) {
                root->left_ = left_rotate(root->left_);
            }
        }
        return ((!root->left_) ? root : right_rotate(root));
    } else {
        // Otherwise, branch right

        // Check if the target node exists
        if (!root->right_) {
            return root;
        }
        // "Zag-zig" step: If the node is a right child of a node that is a left child
        // Traverse left
        if (root->right_->value_ > data) {
            // Traverse as deep as possible on the left branch
            root->right_->left_ = splay_tree(data, root->right_->left_);

            // If the root exists, rotate
            if (root->right_->left_) {
                root->right_ = right_rotate(root->right_);
            }
        } else if (root->right_->value_ < data) {
            // Traverse as deep as possible on the right branch
            root->right_->right_ = splay_tree(data, root->right_->right_);
            root = left_rotate(root);
        }
        return ((!root->right_) ? root : left_rotate(root));
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
    std::cout << root->value_ << ":" << root->counter_ << " ";
    inorder(root->right_);
}

// Output values in the tree using preorder ordering
void SplayTree::pre_order(Node* root) {
    if (!root){
        return;
    }
//    std::cout << root->value_ << ":" << root->counter_ << " ";
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
    std::cout << root->value_ << ":" <<" ";
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

void SplayTree::BFS(Node *root, std::vector<Node *> &target_vector){
    int h = this->height();
    for (int l = 0; l <= h; l++){
        level_order(root, l, target_vector);
    }
}

void SplayTree::level_order(Node *root, int l, std::vector<Node *> &target_vector){
    if (root == nullptr){
        target_vector.push_back(nullptr);
        return;
    }
    if (l == 0){
        target_vector.push_back(root);
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

void SplayTree::pre_order_vector(Node* root, std::vector<Node*> &target_vector, int x, int y, sf::RenderWindow *window, char type, float scale, std::vector<positionalNode> &positional_nodes) {
    int size = 30;
    sf::CircleShape node;
    node.setRadius(size);
    node.setFillColor(sf::Color::White);
    node.setOrigin(0.0f, 0.0f);
    sf::Text value;
    value.setCharacterSize(size);
    value.setFont(this->global_font);
    value.setFillColor(sf::Color::Red);

    if (!root){
        target_vector.push_back(nullptr);
        positionalNode temp = positionalNode(nullptr, x - 30, y - 30);
        positional_nodes.push_back(temp);
        return;
    }
    target_vector.push_back(root);
    positionalNode temp = positionalNode(root, x - 30, y - 30);
    positional_nodes.push_back(temp);
    node.setPosition(x - 30, y - 30);
    std::string string_value = std::to_string(root->value_);
    value.setString(string_value);
    value.setPosition(x - 17 , y - 20);

    if (type == 'l') {
        if (root->left_ != nullptr) {
            sf::VertexArray left_p(sf::LinesStrip, 2);
            left_p[0].position = sf::Vector2f(x, y);
            left_p[1].position = sf::Vector2f(x - 50 - scale * 4, y + scale/2);
            window->draw(left_p);
        }


        if (root->right_ != nullptr) {
            sf::VertexArray right_p(sf::LinesStrip, 2);
            right_p[0].position = sf::Vector2f(x,y);
            right_p[1].position = sf::Vector2f(x + 50 + scale/2, y + scale * 2);
            window->draw(right_p);
        }

    } else if (type == 'r') {
        if (root->left_ != nullptr) {
            sf::VertexArray left_p(sf::LinesStrip, 2);
            left_p[0].position = sf::Vector2f(x, y);
            left_p[1].position = sf::Vector2f(x - 50 - scale/2, y + scale * 2);
            window->draw(left_p);
        }
        if (root->right_ != nullptr) {
            sf::VertexArray right_p(sf::LinesStrip, 2);
            right_p[0].position = sf::Vector2f(x,y);
            right_p[1].position = sf::Vector2f(x + 50 + scale * 4, y + scale/2);
            window->draw(right_p);

        }
    } else if (type == 'm') {
        if (root->left_ != nullptr) {
            sf::VertexArray left_p(sf::LinesStrip, 2);
            left_p[0].position = sf::Vector2f(x, y);
            left_p[1].position = sf::Vector2f(x - 50 - scale * 4, y + scale/2);
            window->draw(left_p);
        }
//
        if (root->right_ != nullptr) {
            sf::VertexArray right_p(sf::LinesStrip, 2);
            right_p[0].position = sf::Vector2f(x,y);
            right_p[1].position = sf::Vector2f(x + 50 + scale * 4, y + scale/2);
            window->draw(right_p);
        }

        //pre_order_vector(root->left_, target_vector, x - 50 - scale * 2, y + scale/2, window, 'l', scale, positional_nodes);
        //pre_order_vector(root->right_, target_vector, x + 50 + scale * 2, y + scale/2, window, 'r', scale, positional_nodes);//
    //}
   }

    window->draw(node);
    window->draw(value);

    if (type == 'l') {
        pre_order_vector(root->left_, target_vector, x - 50 - scale * 4, y + scale/2, window, 'l', scale, positional_nodes);
        pre_order_vector(root->right_, target_vector, x + 50 + scale/2, y + scale * 2, window, 'l', scale/2, positional_nodes);
    }
    else if (type == 'r') {
        pre_order_vector(root->left_, target_vector, x - 50 - scale/2, y  + scale * 2, window, 'r', scale/2, positional_nodes);
        pre_order_vector(root->right_, target_vector, x + 50 + scale * 4, y  + scale/2, window, 'r', scale, positional_nodes);
    } else if (type == 'm') {
        pre_order_vector(root->left_, target_vector, x - 50 - scale * 4, y + scale/2, window, 'l', scale, positional_nodes);
        pre_order_vector(root->right_, target_vector, x + 50 + scale * 4, y + scale/2, window, 'r', scale, positional_nodes);//
    }
}

// --------------- PUBLIC METHODS -----------------

void SplayTree::force_delay(){
    sf::Clock clock;
    clock.restart();
    sf::Time time1 = clock.getElapsedTime();
    while (time1.asSeconds() != 1){
        time1 = clock.getElapsedTime();
    }
//    std::cout << "5 seconds elapsed" << '\n';
    return;
}

void SplayTree::insert(int key, std::vector<Node *> &target_vector, sf::RenderWindow *window, float scale, std::vector<positionalNode> &positional_nodes, int start_x){
    this->root_ = this->insert(key, this->root_);
    force_delay();
    this->pre_order_vector(target_vector, window, scale, positional_nodes, start_x);
    target_vector.clear();
    positional_nodes.clear();
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

void SplayTree::pre_order_vector(std::vector<Node *> &target_vector, sf::RenderWindow *window, float scale, std::vector<positionalNode> &positional_nodes, int start_x) {
    this->pre_order_vector(this->root_, target_vector, start_x, 50, window, 'm', scale/3, positional_nodes);
}
