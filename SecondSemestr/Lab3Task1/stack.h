#ifndef STACK_H
#define STACK_H
#include "pointers.h"

template<class T>
class stack
{
private:
    int size;
    struct Node {
        T value;
        pointers::UniquePtr<Node> prev;
    };
    pointers::UniquePtr<Node> last;

public:
    stack(){
        last = pointers::UniquePtr<Node>();
        size = 0;
    }

    T Top() {
        if(last)
            return last->value;
        else
            return 0;
    }

    void Pop() {
        if(last)
            last = std::move(last->prev);
        --size;
    }

    void Push(T val) {
        pointers::UniquePtr<Node> tmp(new Node);
        tmp->value = val;
        tmp->prev = std::move(last);
        last = std::move(tmp);
        ++size;
    }

    int getSize() const {
        return size;
    }
};

#endif // STACK_H
