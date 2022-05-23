#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

namespace stlMax {
template <class T>
class vector
{
private:
    int sz = 0;
    int cap = 1;
    T* v{};
public:
    class iterator
    {
    private:
        T* value;
    public:

        iterator(T* vec)
        {
            value = vec;
        }

        T& operator*()
        {
            return *value;
        }

        iterator& operator++()
        {
            ++value;
            return *this;
        }

        iterator operator++(int)
        {
            return iterator(value++);
        }

        iterator& operator--()
        {
            --value;
            return *this;
        }

        iterator operator--(int)
        {
            return iterator(value--);
        }

        int operator-(const iterator& next)
        {
            return this->base() - next.base();
        }

        T* base() const
        {
            return value;
        }

        inline bool operator==(iterator rhs)
        { return value == rhs.base(); }

        inline bool operator!=(iterator rhs)
        { return value != rhs.base(); }

        inline bool operator<(iterator rhs)
        { return value < rhs.base(); }

        inline bool operator>(iterator rhs)
        { return value > rhs.base(); }

        inline bool operator<=(iterator rhs)
        { return value <= rhs.base(); }

        inline bool operator>=(iterator rhs)
        { return value >= rhs.base(); }

        inline iterator operator+(int i){
            return iterator(value + i);
        }
    };

    class reverse_iterator{
    private:
        T* value;
    public:

        reverse_iterator(T* vec)
        {
            value = vec;
        }

        T& operator*()
        {
            return *value;
        }

        reverse_iterator& operator++()
        {
            --value;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            return reverse_iterator(value++);
        }

        reverse_iterator& operator--()
        {
            ++value;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            return reverse_iterator(value--);
        }


        T* base() const
        {
            return value;
        }

        inline bool operator==(reverse_iterator rhs)
        { return value == rhs.base(); }

        inline bool operator!=(reverse_iterator rhs)
        { return value != rhs.base(); }

        inline bool operator<(reverse_iterator rhs)
        { return value < rhs.base(); }

        inline bool operator>(reverse_iterator rhs)
        { return value > rhs.base(); }

        inline bool operator<=(reverse_iterator rhs)
        { return value <= rhs.base(); }

        inline bool operator>=(reverse_iterator rhs)
        { return value >= rhs.base(); }
    };

    ~vector(){
        delete[] v;
    }

    vector(){
        v = new T[1];
        //_capacity = 1;
    }

    vector(int _size) {
        sz = _size;
        while(cap <= sz){
            cap *= 2;
        }
        v = new T[cap];
        for(int i = 0; i < sz; ++i){
            v[i] = {};
        }
    }

    vector(const vector& other) {
        if (this != &other) {
            delete[] v;
            v = new T[other.cap];
            for(int i = 0; i < other.sz; ++i) v[i] = other.v[i];
            sz = other.sz;
            cap = other.sz;
        }
    }

    void push_back(const T& value){
        if(!cap){
            cap = sz + 1;
            v = new T[cap];
        }
        else if (sz == cap){
            cap *= 2;
            T* tmp = v;
            v = new T[cap];
            for (int i = 0; i < sz; ++i) v[i] = tmp[i];
            delete[] tmp;
        }
        ++sz;
        v[sz-1] = value;
    }
    void pop_back(){
        if(!sz){
            return;
        }
        --sz;
        if (cap / 2 >= sz ){
            cap /= 2;
            T* tmp = v;
            v = new T[cap];
            for (int i = 0; i < sz; ++i) v[i] = tmp[i];
            delete[] tmp;
        }
    }

    vector operator=(const vector& other) {
        if (this != &other) {
            delete[] v;
            v = new T[other.cap];
            for(int i = 0; i < other.sz; ++i) v[i] = other.v[i];
            sz = other.sz;
            cap = other.sz;
        }
        return *this;
    }

    T& operator[](int index)  {
        return v[index];
    }

    const T& operator[](int index) const {
        return v[index];
    }

    int size() const {
        return sz;
    }

    int capacity() const {
        return cap;
    }

    iterator begin(){
        return iterator(v);
    }

    const iterator cbegin() const{
        return iterator(v);
    }

    iterator end(){
        if(!sz){
            return nullptr;
        }
        return iterator(&v[sz]);
    }

    const iterator cend() const{
        if(!sz){
            return nullptr;
        }
        return iterator(&v[sz]);
    }

    void assign(iterator start, iterator end){
        delete[] v;
        v = nullptr;
        sz = 0;
        cap = 1;
        iterator tmp = start;
        while(tmp != end){
            tmp++;
            ++sz;
            if(sz > cap){
                cap *= 2;
            }
        }
        v = new T[cap];
        for(int i = 0; start <= end; ++start, ++i){
            v[i] = *start.base();
        }
    }

    T& at(int i){
        if(i > sz - 1){
            return *v;
        }
        return v[i];
    }

    T& back() {
        if(!sz){
            return *v;
        }
        return v[sz-1];
    }

    T& front() {
        return v[0];
    }

    void clear(){
        delete[] v;
    }

    T* data() {
        return v;
    }

    bool empty(){
        return sz == 0;
    }

    void reserve(const int& n){
        cap = n;
        T* tmp = v;
        v = new T[cap];
        for(int i = 0; i < sz; ++i){
            v[i] = tmp[i];
        }
    }

    void resize(const int& n){
        if(!cap){
            cap = 1;
            while (cap < n) {
                cap *= 2;
            }
            v = new T[cap];
            for (int i = 0; i < n; ++i) v[i] = {};
            sz = n;
        }
        else{
            while(cap < n){
                cap *= 2;
            }
            T* tmp = v;
            v = new T[cap];
            for (int i = 0; i < sz; ++i) v[i] = tmp[i];
            for(int i = sz; i < n; ++i) v[i] = 0;
            sz = n;
            delete[] tmp;
        }

    }

    void swap(vector& other){
        if(this != &other){
           vector<T> tmp(other);
           other = *this;
           *this = tmp;
        }
    }

    reverse_iterator rend(){
        return reverse_iterator(v-1);
    }

    reverse_iterator rbegin(){
        if(!sz){
            return nullptr;
        }
        return reverse_iterator(v + sz - 1);
    }

    const reverse_iterator crend() const {
        return iterator(v);
    }

    const reverse_iterator crbegin() const {
        if(!sz){
            return nullptr;
        }
        return iterator(&v[sz]);
    }

    unsigned long long max_size(){
        return pow(2, 64-sizeof(T)) - 1;
    }

    void insert(const iterator& it, const T& value){
        ++sz;
        int ind = it.base() - v;
        if(sz > cap){
            cap *= 2;
            T* tmp = v;
            v = new T[cap];
            for (int i = 0; i < ind; ++i) v[i] = tmp[i];
            v[ind] = value;
            for(int i = ind + 1; i < sz; ++i) v[i] = tmp[i-1];
            delete[] tmp;
        }
        else{
            for(int i = sz; i > ind; --i){
                v[i] = v[i-1];
            }
            v[ind] = value;
        }
    }

    void erase(const iterator& it){
        int ind = it.base() - v;
        --sz;
        for(int i = ind; i < sz; ++i){
            v[i] = v[i+1];
        }
    }

    void reverse(){
        for (int i = 0; i < sz / 2; ++i){
            std::swap(v[i], v[sz - i - 1]);
        }
    }

    template<class... Args>
    void emplace_back(Args&&... args) noexcept {
        using expander = int[];
        (void)expander{0,
        (void(push_back(args)), 0)...};
    }

    template<class... Args>
    void emplace(const iterator& it, Args&&... args) noexcept {
        int pos = it.base() - v;
        int oldSize = sz;
        T* newV = new T[sz - pos];
        for(int i = pos - 1, j = 0; i < sz; ++i, ++j){
            newV[j] = v[i];
        }
        sz -= pos;
        emplace_back(args...);
        for(int i = 0; i < oldSize - pos + 1; ++i){
            push_back(newV[i]);
        }
        delete[] newV;
    }

    static int _Countl_zero_fallback(T _Val) noexcept {
        T _Yy = 0;

        unsigned int _Nn = std::numeric_limits<T>::digits;
        unsigned int _Cc = std::numeric_limits<T>::digits / 2;
        do {
            _Yy = static_cast<T>(_Val >> _Cc);
            if (_Yy != 0) {
                _Nn -= _Cc;
                _Val = _Yy;
            }
            _Cc >>= 1;
        } while (_Cc != 0);
        return static_cast<int>(_Nn) - static_cast<int>(_Val);
    }

    static int _Countr_zero_fallback(const T _Val) noexcept {
        constexpr int _Digits = std::numeric_limits<T>::digits;
        return _Digits - _Countl_zero_fallback(static_cast<T>(static_cast<T>(~_Val) & static_cast<T>(_Val - 1)));
    }

    template <class _Ret>
    struct _Vbase_compare_three_way {
        _Ret operator()(const T _Left, const T _Right) const noexcept {
            using _Vbase = T;
            const _Vbase _Differing_bits = _Left ^ _Right;

            if (_Differing_bits == 0) {
                return 0;
            }
            const int _Bit_index = _Countr_zero_fallback(_Differing_bits);
            const _Vbase _Mask = _Vbase{1} << _Bit_index;
            return (_Left & _Mask) == 0 ? -1 : 1;
        }
    };

    bool operator<(const vector<T>& rhs){
        auto _First = v;
        auto _Other = rhs.v;

        const auto _Last = _First + std::min(sz, rhs.sz);

        for (; _First != _Last; ++_First, (void) ++_Other) {
            using _Comp = _Vbase_compare_three_way<signed char>;
            const auto _Result = _Comp{}(*_First, *_Other);

            if (_Result < 0) {
                return true;
            } else if (_Result > 0) {
                return false;
            }
        }

        return sz < rhs.sz;
        for (int i = 0, sz = std::min(size(), rhs.size()); i < sz; ++i){
            if (v[i] < rhs[i]) {
                return true;
            }
            if (v[i] > rhs[i]){
                return false;
            }
        }
        return size() < rhs.sz();
        return std::lexicographical_compare(v, v + sz, rhs.v, rhs.v + rhs.sz);
    }

    bool operator>(const vector<T>& rhs){
        return rhs < this;
    }

};
}

#endif // VECTOR_H
