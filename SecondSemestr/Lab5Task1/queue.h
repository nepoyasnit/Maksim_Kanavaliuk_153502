#ifndef QUEUE_H
#define QUEUE_H
#include <memory>

namespace mylib {
    class queue
    {
        struct node {
            int value;
            std::shared_ptr<node> next;

            node(int value) :
                value(value),
                next(nullptr) {}
        };
        std::shared_ptr<node> first;
        std::shared_ptr<node> last;
    public:
        queue()
            : first(nullptr),
              last(nullptr) {}

        template<class... Args>
        queue(Args... args)
            :queue()
        {
            using expander = int[];
            (void)expander{0,
                 (void(push(args)), 0)...
                };

        }

        void push(int value) {
            if(last == nullptr) {
                first = last = std::make_shared<node>(node(value));
                return;
            }
            last->next = std::make_shared<node>(node(value));
            last = last->next;
        }

        void pop()
        {
            if(first == last) {
                first = last = nullptr;
                return;
            }
            first = first->next;
        }

        int& front() {
            return first->value;
        }

    };

}
#endif // QUEUE_H
