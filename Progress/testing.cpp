#include <iostream>
#include <string>
#include "SplayTree.h"

int main() {
//    SplayTree *T = new SplayTree(100);
//    T->insert(50);
//    T->insert(30);
//    T->insert(20);
//    T->insert(500);
//    T->insert(550);
//    T->insert(0);
//    T->insert(7);
//    T->insert(37);
//    T->insert(35);
//    T->insert(34);
//    T->insert(33);
//    T->insert(29);
//    T->inorder();
//    std::cout << std::endl;
//    std::cout << T->get_root() << std::endl;
//    T->search(37);
//    std::cout << std::endl << T->get_root() << std::endl;
//    T->post_order();
//    std::cout<< std::endl;
//    T->pre_order();

//    SplayTree* H = new SplayTree(50);
//    H->insert(30);
//    H->insert(20);
//    H->insert(40);
//    H->insert(15);
//    H->insert(14);
//    H->insert(70);
//    H->insert(60);
//    H->insert(80);
//    H->insert(75);
//    H->insert(14);
//    H->pre_order();
    std::string file = "test.txt";
    SplayTree *test = new SplayTree(file);
    test->inorder();

//    std::cout << std::endl;
//    H->splay_tree(40);
//    H->pre_order();


//    SplayTree* test1 = new SplayTree(100);
//    test1->insert(50);
//    test1->insert(200);
//    test1->insert(40);
//    test1->insert(30);
//    test1->inorder();
//    test1->search(30);
//    std::cout << std::endl << test1->get_root();
//    test1->pre_order();


    return 0;
}