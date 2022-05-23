#ifndef STACK_H
#define STACK_H
#include <memory>

template<class T>
class Stack
{
private:
    int size;
    struct node {
        T value;
        std::unique_ptr<node> prev;
    };
    std::unique_ptr<node> last;
public:
    Stack()
    {
        last = std::unique_ptr<node>(nullptr);
        size = 0;
    }

    T Top()
    {
        if (last)
            return last->value;
        else
            return 0;
    }

    void Pop()
    {
        if (last)
            last = std::move(last->prev);
        --size;
    }

    void Push(T value)
    {
        std::unique_ptr<node> tmp(new node);
        tmp->value = value;
        tmp->prev = std::move(last);
        last = std::move(tmp);
        ++size;
    }

    int Size() const
    {
        return size;
    }

    bool isEmpty() {
        if(!size)
            return true;
        return false;
    }
};

#endif // STACK_H
