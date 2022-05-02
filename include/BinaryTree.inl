#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <memory>
#include <queue>
#include <iostream>

template <typename T>
struct TreeNode
{

    TreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    T data;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;
};

template <typename T>
class BinaryTree
{
private:
    std::shared_ptr<TreeNode<T>> root;
    int size;

public:
    explicit BinaryTree()
    {
        this->root = nullptr;
        this->size = 0;
    };

    BinaryTree(const BinaryTree<T> &other)
    {
        this->root = other.root;
        this->size = other.size;
    }

    BinaryTree(BinaryTree<T> &&other)
    {
        this->root = other.root;
        this->size = other.size;

        other.root = nullptr;
        other.size = 0;
    }

    BinaryTree<T> &operator=(const BinaryTree<T> &other)
    {
        this->root = other.root;
        this->size = other.size;
        return *this;
    }

    ~BinaryTree(){};

    inline void insert(int data) noexcept
    {
        if (this->root == nullptr)
        {
            this->root = std::make_shared<TreeNode<T>>(data);
            this->size++;
        }
        else
        {
            std::shared_ptr<TreeNode<T>> current = this->root;
            while (current != nullptr)
            {
                if (data < current->data)
                {
                    if (current->left == nullptr)
                    {
                        current->left = std::make_shared<TreeNode<T>>(data);
                        this->size++;
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = std::make_shared<TreeNode<T>>(data);
                        this->size++;
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    };
    inline void remove(int data) noexcept
    {
        if (this->root == nullptr)
        {
            return;
        }
        else
        {
            std::shared_ptr<TreeNode<T>> current = this->root;
            std::shared_ptr<TreeNode<T>> parent = nullptr;
            while (current != nullptr)
            {
                if (data < current->data)
                {
                    parent = current;
                    current = current->left;
                }
                else if (data > current->data)
                {
                    parent = current;
                    current = current->right;
                }
                else
                {
                    if (current->left == nullptr && current->right == nullptr)
                    {
                        if (parent->left == current)
                        {
                            parent->left = nullptr;
                        }
                        else
                        {
                            parent->right = nullptr;
                        }
                        this->size--;
                        break;
                    }
                    else if (current->left == nullptr)
                    {
                        if (parent->left == current)
                        {
                            parent->left = current->right;
                        }
                        else
                        {
                            parent->right = current->right;
                        }
                        this->size--;
                        break;
                    }
                    else if (current->right == nullptr)
                    {
                        if (parent->left == current)
                        {
                            parent->left = current->left;
                        }
                        else
                        {
                            parent->right = current->left;
                        }
                        this->size--;
                        break;
                    }
                    else
                    {
                        std::shared_ptr<TreeNode<T>> temp = current->right;
                        while (temp->left != nullptr)
                        {
                            temp = temp->left;
                        }
                        current->data = temp->data;
                        current->right = temp->right;
                        this->size--;
                        break;
                    }
                }
            }
        }
    };

    inline const void print() noexcept
    {
        if (this->root == nullptr)
        {
            return;
        }
        else
        {
            auto current = this->root;
            std::queue<std::shared_ptr<TreeNode<T>>> queue;
            queue.push(current);
            while (!queue.empty())
            {
                current = queue.front();
                queue.pop();
                std::cout << current->data << " ";
                if (current->left != nullptr)
                    queue.push(current->left);

                if (current->right != nullptr)
                    queue.push(current->right);
            }
        }
    };

    const int getSize() const { return size; };
};

#endif // __BINARYTREE_H__