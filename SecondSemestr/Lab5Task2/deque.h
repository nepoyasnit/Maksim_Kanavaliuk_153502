#ifndef DEQUE_H
#define DEQUE_H
#include <QString>
#include <memory>
#include <QDebug>
#include <deque>

const int SIZE = 10;

template<class T>
class deque
{
private:
    T** arr;
    std::pair<int,int> front{}, _end{};
    int cap;
    int sz;
public:

    class iterator
    {
    private:
        T** value;
        std::pair<int,int> curr;
    public:

        iterator(T** vec, std::pair<int,int> s)
        {
            value = vec;
            curr = s;
        }

        T& operator*()
        {
            return value[curr.first][curr.second];
        }

        iterator& operator++()
        {
            if(curr.second == SIZE - 1){
                curr.second = 0;
                ++curr.first;
            }
            else{
                ++curr.second;
            }

            return *this;
        }

        iterator operator++(int)
        {
            return iterator(value++);
        }

        T* base() const
        {
            return value;
        }

        inline bool operator!=(iterator rhs)
        { return curr <= rhs.curr; }

        inline bool operator<(iterator rhs)
        {
            //qDebug() << rhs.current_elem.first << rhs.current_elem.second << "lol1";
            return curr <= rhs.curr; }
    };

    iterator begin(){
        return iterator(arr, front);
    }

    iterator end(){

        //qDebug() << _end.first << _end.second << "lol";
        return iterator(arr, _end);
    }

    deque() : cap(8), sz(0) , arr(new T* [cap]){
        for(int i = 0; i < cap; ++i){
            arr[i] = nullptr;
        }
        front.second = _end.second = -1;
        front.first = _end.first = -1;
    }

    ~deque(){
        for(int i = front.first; i <= _end.first; ++i){
            delete arr[i];
        }
        delete arr;

    }

    void push_front(T value){
        ++sz;
        if(front.second == -1){
            T* tmp = new T[SIZE];
            arr[cap/2] = tmp;
            front.first = _end.first = cap/2;
            front.second = _end.second = 0;
            arr[front.first][front.second] = value;
            return;
        }
        else if(!front.second){
            if(!front.first){
                resize();
            }
            --front.first;
            front.second = SIZE - 1;
            T* tmp = new T[SIZE];
            arr[front.first] = tmp;
            arr[front.first][front.second] = value;
            return;
        }
        else{
            --front.second;
            arr[front.first][front.second] = value;
        }
    }

    void pop_front(){
        if(front.first < _end.first){
            --sz;
            if(front.second == SIZE - 1){
                delete arr[front.first];
                ++front.first;
                front.second = 0;
                return;
            }
            else{
                ++front.second;
            }
        }
        else if(front.second < _end.second){
            --sz;
            ++front.second;
            return;
        }
        else if(front.second == _end.second && front.first != -1){
            --sz;
            delete arr[front.first];
            front.first = _end.first = -1;
            front.second = _end.second = -1;
            return;
        }
    }

    void push_back(T value){
        ++sz;
        if(_end.second == -1){
            T* tmp = new T[SIZE];
            arr[cap/2] = tmp;
            front.first = _end.first = cap/2;
            front.second = _end.second = 0;
            arr[_end.first][_end.second] = value;
            return;
        }
        else if(_end.second == SIZE - 1){
            if(_end.first == cap - 1){
                resize();
            }
            ++_end.first;
            _end.second = 0;
            T* tmp = new T[SIZE];
            arr[_end.first] = tmp;
            arr[_end.first][_end.second] = value;
            return;
        }
        else{
            ++_end.second;
            arr[_end.first][_end.second] = value;
        }
    }

    void pop_back(){
        if(_end.first > front.first){
            --sz;
            if(_end.second == 0){
                delete arr[_end.first];
                --_end.first;
                _end.second = SIZE - 1;
                return;
            }
            else{
                --_end.second;
            }
        }
        else if(_end.second > front.second){
            --sz;
            --_end.second;
            return;
        }
        else if(front.second == _end.second && front.first != -1){
            --sz;
            delete arr[front.first];
            front.first = _end.first = -1;
            front.second = _end.second = -1;
            return;
        }
    }

    QString toString(){
        QString str;
        if(sz){
            for(int i = front.first; i <= _end.first; ++i){
                if(i == front.first && i == _end.first){
                    for(int j = front.second; j <= _end.second; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
                else if(i == front.first){
                    for(int j = front.second; j < SIZE; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
                else if(i == _end.first){
                    for(int j = 0; j <= _end.second; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
                else{
                    for(int j = 0; j < SIZE; ++j){
                        str += QString::number(arr[i][j]) + ' ';
                    }
                }
            }
        }

        return str;
    }

    void clear(){
        if(!empty()){
            cap = 8;
            sz = 0;
            for(int i = front.first; i <= _end.first; ++i){
                delete arr[i];
            }
            front.first = _end.first = -1;
            front.second = _end.second = -1;
        }
    }

    T& operator[](int k){
        if(k < sz && k >= 0){
            int i = (k + front.second) / SIZE + front.first;
            int j = (k + front.second) % SIZE;
            return arr[i][j];
        }
    }

    bool empty(){
        return !sz;
    }

    int size(){
        return sz;
    }

    int capacity(){
        return cap * SIZE;
    }

private:
    void resize(){
        cap *= 2;
        T** tmp = new T* [cap];
        int ind = cap / 2 - (_end.first - front.first) / 2;
        for(int i = front.first; i <= _end.first; ++i, ++ind){
            tmp[ind] = arr[i];
        }
        delete arr;
        front.first = cap / 2 - (_end.first - front.first) / 2;
        _end.first = ind - 1;
        arr = tmp;
    }
};

#endif // DEQUE_H
