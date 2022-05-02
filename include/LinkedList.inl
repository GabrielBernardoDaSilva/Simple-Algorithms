#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <memory>

template <typename T>
class LinkedListIterator;
template <typename T>
struct Node
{
    T data;
    std::shared_ptr<Node<T>> next;
};

template <typename T>
class LinkedList
{

public:
    using RealType = T;
    using ValueType = std::shared_ptr<Node<T>>;
    using Iterator = LinkedListIterator<LinkedList<T>>;

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

    int size;

public:
    explicit LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;

        this->size = 0;
    };

    LinkedList(const LinkedList<T> &other)
    {
        this->head = other.head;
        this->tail = other.tail;

        this->size = other.size;
    };

    LinkedList(LinkedList<T> &&other)
    {
        this->head = other.head;
        this->tail = other.tail;

        this->size = other.size;

        other.head = nullptr;
        other.tail = nullptr;

        other.size = 0;
    };

    ~LinkedList(){

    };

    constexpr inline void  push(T data)
    {
        if (this->isEmpty())
        {
            this->head = std::make_shared<Node<T>>(Node<T>{data, nullptr});
            this->tail = this->head;
        }
        else
        {
            this->tail->next = std::make_shared<Node<T>>(Node<T>{data, nullptr});
            this->tail = this->tail->next;
        }

        this->size++;
    };
    constexpr inline T pop() const noexcept
    {
        if (this->isEmpty())
        {
            return -1;
        }
        else
        {
            int data = this->head->data;
            this->head = this->head->next;
            return data;
        }
    };

    constexpr inline T remove(T data) noexcept
    {
        if (this->isEmpty())
        {
            return -1;
        }
        else
        {
            std::shared_ptr<Node<T>> current = this->head;
            std::shared_ptr<Node<T>> previous = nullptr;

            while (current != nullptr)
            {
                if (current->data == data)
                {
                    if (previous == nullptr)
                    {
                        this->head = current->next;
                    }
                    else
                    {
                        previous->next = current->next;
                    }

                    if (current == this->tail)
                    {
                        this->tail = previous;
                    }

                    this->size--;
                    return current->data;
                }

                previous = current;
                current = current->next;
            }

            return -1;
        }
    };

    constexpr int getSize() const noexcept{return size;}

    constexpr bool isEmpty() const noexcept{return size == 0;}

    Iterator begin(){
        return Iterator(this->head);
    };
    Iterator end(){
        return Iterator(this->tail->next);
    };   
};

template <typename LinkedList>
class LinkedListIterator
{
public:
    using ValueType = typename LinkedList::ValueType;
    using PointerType = ValueType;
    using ReferenceType = ValueType &;
    using RealType = typename LinkedList::RealType;

public:
    LinkedListIterator(
        PointerType ptr) : m_ptr(ptr){};

    LinkedListIterator &operator++()
    {
        m_ptr = m_ptr->next;
        return *this;
    }

    LinkedListIterator operator++(int)
    {
        LinkedListIterator tmp(*this);
        ++(*this);
        return tmp;
    }

    PointerType operator->()
    {
        return m_ptr;
    }

    RealType operator*()
    {
        return m_ptr->data;
    }

    bool operator==(const LinkedListIterator &rhs)
    {
        return m_ptr == rhs.m_ptr;
    }

    bool operator!=(const LinkedListIterator &rhs)
    {
        return !(*this == rhs);
    }

private:
    PointerType m_ptr;
};

#endif // __LINKEDLIST_H__