#include "LinkedList.inl"
#include "BinaryTree.inl"

#include <iostream>

int main(int argc, char **argv)
{
    // linked list with iterator
    LinkedList<int> list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    for (auto item : list)
    {
        std::cout << item << std::endl;
    }

    list.Remove(2);

    for (auto item : list)
    {
        std::cout << item << std::endl;
    }

    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    tree.print();

    BinaryTree<int> tree2(std::move(tree));

    std::cout << "tree2" << std::endl;
    tree2.print();

    std::cout << "tree" << std::endl;
    tree.print();

    return 0;
}