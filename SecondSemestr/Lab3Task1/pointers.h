#ifndef POINTERS_H
#define POINTERS_H
#include <utility>

namespace pointers {
    template<class T>
    class UniquePtr;

    template<class T>
    class SharedPtr;

    template<class T>
    class WeakPtr;

    template<class T>
    class UniquePtr {
      private:
        T* ptr;

      public:
        UniquePtr() : ptr(nullptr) {}

        UniquePtr(const UniquePtr& other_ptr) {
            Reset(other_ptr.Release());
        }

        UniquePtr(T* unObj) : ptr(unObj) {}

        UniquePtr(UniquePtr&& other_ptr) noexcept
            : ptr(other_ptr.Release()){}

        void Reset(T* pointer) {
            delete this->ptr;
            this->ptr = pointer;
        }

        T* Release() {
            T* tmp = ptr;
            ptr = nullptr;
            return tmp;
        }

        T* Get() const {
            return ptr;
        }

        ~(){};

        ~UniquePtr() {
            delete ptr;
        }

        T* operator->() const noexcept {
            return ptr;
        }

        T& operator*() const noexcept {
            return *ptr;
        }

        UniquePtr& operator=(UniquePtr&& other_ptr) noexcept {
            Reset(other_ptr.Release());
            return *this;
        }

        operator bool() const noexcept {
            return static_cast<bool>(ptr);
        }
    };

    template<class T>
    class SharedPtr {
    private:
        T* ptr = nullptr;

        unsigned* strongCounter = nullptr;
        unsigned* weakCounter = nullptr;

    public:
        friend class WeakPtr<T>;
        SharedPtr() : ptr(nullptr), strongCounter(nullptr), weakCounter(nullptr) {}

        SharedPtr(T* shObj) : ptr(shObj) {
            if(ptr == nullptr) {
                return;
            }
            strongCounter = new unsigned(1);
            weakCounter = new unsigned(1);
        }

        SharedPtr(const SharedPtr<T>& other_ptr)
            : strongCounter(other_ptr.strongCounter),
              weakCounter(other_ptr.weakCounter),
              ptr(other_ptr.ptr)
        {
            if(ptr == nullptr || !(*weakCounter)) {
                return;
            }

            ++(*strongCounter);
            ++(*weakCounter);
        }

        SharedPtr(WeakPtr<T>& other_ptr)
            : strongCounter(other_ptr.strongCounter),
              weakCounter(other_ptr.weakCounter),
              ptr(other_ptr.ptr)
        {
            if(ptr == nullptr) {
                return;
            }

            ++(*strongCounter);
            ++(*weakCounter);
        }

        ~SharedPtr() {
            if(ptr == nullptr || weakCounter == nullptr) {
                return ;
            }

            if(*strongCounter == 1) {
                delete weakCounter;
                delete strongCounter;
                delete ptr;
            }
            else {
                --(*strongCounter);
                --(*weakCounter);
            }
        }

        unsigned* useCount() const {
            return *strongCounter;
        }

        void Reset(T* ptr) {
            delete this->ptr;
            delete this->strongCounter;
            delete this->weakCounter;
            strongCounter = new unsigned(1);
            weakCounter = new unsigned(1);
            this->ptr = ptr;
        }

        T* Get() {
            return ptr;
        }

        T* operator->() const noexcept {
            return ptr;
        }

        T& operator*() const noexcept {
            return *ptr;
        }

        operator bool() const noexcept {
            return static_cast<bool>(ptr);
        }
    };

    template<class T>
    class WeakPtr {
    private:
        T* ptr;

        unsigned* strongCounter;
        unsigned* weakCounter;

    public:
        friend class SharedPtr<T>;
        WeakPtr() noexcept
            : ptr(nullptr), strongCounter(nullptr) {}

        WeakPtr(T* shObj) : ptr(shObj) {
            if(ptr == nullptr) {
                return;
            }
            weakCounter = new unsigned(1);
            strongCounter = new unsigned(0);
        }

        WeakPtr(const WeakPtr<T>& other_ptr) noexcept
            : strongCounter(other_ptr.strongCounter),
            weakCounter(other_ptr.weakCounter),
            ptr(other_ptr.ptr){

            if(ptr == nullptr) {
                return;
            }
            ++(*weakCounter);
        }

        WeakPtr(SharedPtr<T>& other_ptr)
            : strongCounter(other_ptr.strongCounter),
            weakCounter(other_ptr.weakCounter),
            ptr(other_ptr.ptr)
        {
            if(ptr == nullptr) {
                return;
            }
            ++(*weakCounter);
        }

        ~WeakPtr() {
            if(ptr == nullptr || weakCounter == nullptr) {
                return;
            }
            if(*strongCounter == 1)
            {
                delete weakCounter;
                delete strongCounter;
                delete ptr;
            }
            else {
                --(*weakCounter);
                --(*strongCounter);
            }
        }

        void Reset(T* ptr) {
            delete this->ptr;
            delete this->strongCounter;
            delete this->weakCounter;
            strongCounter = new unsigned(1);
            weakCounter = new unsigned(1);
            this->ptr = ptr;
        }

        T* Get() const {
            return ptr;
        }

        SharedPtr<T> lock() {
            SharedPtr<T>* tmp = new SharedPtr<T>;
            if(*(this ->weakCounter))
            {
                tmp->ptr = this->ptr;
                tmp->strongCounter = this->strongCounter;
                tmp->weakCounter = this->weakCounter;
                *(tmp->strongCounter)++;
                *(tmp->weakCounter)++;
            }
            return *tmp;
        }

        T& operator*() const noexcept
        {
            return *ptr;
        }

        operator bool() const noexcept
        {
            return static_cast<bool>(ptr);
        }
    };
}

#endif // POINTERS_H
