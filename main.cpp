#include "LinkedList.inl"
#include "BinaryTree.inl"

#include <iostream>

#include <vector>
#include <list>

#define SIZE 100000

int main(int argc, char **argv)
{
    std::vector<int> testV;

    for (size_t i = 0; i < SIZE; i++)
        testV.push_back(i);

    std::cout << "testV.size() = " << testV.size() << std::endl;

    if (argc > 1)
    {

        std::cout << "Insetion linked List std" << std::endl;

        std::list<int> list;

        for (size_t i = 0; i < SIZE; i++)
            list.emplace_back(i);

        for (auto item : list)
            std::cout << item << "\r";
        printf("\n");

        auto removedItem = list.remove(50);
        std::cout << "removedItem = " << removedItem << std::endl;
    }
    else
    {
        std::cout << "Insetion linked List" << std::endl;
        // linked list with iterator
        LinkedList<int> list;

        for (size_t i = 0; i < SIZE; i++)
            list.push(i);

        for (auto item : list)
            std::cout << item << "\r";
        printf("\n");
        auto removedItem = list.remove(50);
        std::cout << "removedItem = " << removedItem << std::endl;
    }

    return 0;
}