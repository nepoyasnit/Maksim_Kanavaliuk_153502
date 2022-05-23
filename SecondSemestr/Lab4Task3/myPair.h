#ifndef MYPAIR_H
#define MYPAIR_H

template<class T1, class T2>
struct pair {
public:
    T1 first{};
    T2 second{};
    pair() {};
    pair(const T1& x, const T2& y) : first(x), second(y){};
    pair(const pair<T1, T2>& p)
        : first(p.first), second(p.second){};
    void operator=(const pair& other) {
        first = other.first;
        second = other.second;
    }
    void swap(pair& other) {
        pair<T1,T2> tmp(*this);
        *this = other;
        other = tmp;
    }

    bool operator<(const pair& other) {
        if(this->first == other.first)
            return this->second < other.second;
        return this->first < other.first;
    }

    bool operator>(const pair& other) {
        if(this->first == other.first)
            return this->second < other.second;
        return this->first < other.first;
    }

    bool operator<=(const pair& other) {
        return this->first <= other.first;
    }

    bool operator>=(const pair& other) {
        return this->first >= other.first;
    }
};

template<class T1, class T2>
bool operator==(const pair<T1,T2>& lpair, const pair<T1,T2>& rpair) {
    if(lpair.first == rpair.first && lpair.second == rpair.second) {
        return true;
    }
    return false;
}

template<class T1, class T2>
bool operator!=(const pair<T1,T2>& lpair, const pair<T1,T2>& rpair) {
    if(lpair.first == rpair.first && lpair.second == rpair.second) {
        return false;
    }
    return true;
}

template<class T1, class T2>
pair<T1, T2>& make_pair(const T1& lpair, const T2& rpair) {
    return *(new pair<T1, T2>(lpair, rpair));
}

#endif // MYPAIR_H
