#include <iostream>
#include <string>
#include <limits>

class MyPQueue {
    private:
        struct Node {
            std::string name;
            unsigned short pri;
            Node* next;
        };
        Node* head;
    public: 
        MyPQueue();
        ~MyPQueue();
        short enqueue(std::string name, unsigned short pri);
        std::string dequeue();
        short update(std::string name, unsigned short pri);
        std::string print() const;
        void clear();

};

MyPQueue::MyPQueue() {
    head = nullptr;
}

short MyPQueue::enqueue(std::string name, unsigned short pri) {
    Node* n = new (std::nothrow) Node;
    if(n == nullptr) {
        std::cout << "Memory allocation failed for new node." << std::endl;
        return -1;
    }
    n->name = name;
    n->pri = pri;
    n->next = nullptr;
    if(head == nullptr) {
        head = n;
    } else if(pri < head->pri) {
        n->next = head;
        head = n;
    } else {
        Node* p = head;
        while(p->next != nullptr && p->next->pri <= pri) {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }
}