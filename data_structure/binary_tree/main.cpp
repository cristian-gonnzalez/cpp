#include <iostream>
#include "binary_tree.h"

int main()
{
    BinaryTree<int> tree;

    /* insert in BFS 
    //            
    //          1       
    //       /    \   
    //      2      3    
    //     / \    / \
    //    4   5  7   6
    */ 
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(7);
    tree.add(6);

    std::cout << tree << std::endl;

    std::map<int, int> vertial_sum = tree.vertical_sum();
    
    std::cout << "Vertical sum: " << std::endl;
    for(const auto& [k, v]: vertial_sum)
        std::cout << "level " << k << " -> " << v << std::endl;
    std::cout << std::endl;

    std::cout << "Maximum width: " << tree.max_witdh() << std::endl;
 
    return 0;
}