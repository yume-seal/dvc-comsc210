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
        return -1;
    }
    n->name = name;
    n->pri = pri;
    n->next = nullptr;
    if(head == nullptr) {
        head = n;
    } else if(pri > head->pri) {
        n->next = head;
        head = n;
    } else {
        Node* p = head;
        while(p->next != nullptr && p->next->pri >= pri) {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }
    return 0;
}
std::string MyPQueue::dequeue() {
    if(head == nullptr) {
        return "";
    }
    Node* n = head;
    std::string name = n->name;
    head = n->next;
    delete n;
    return name;
}

short MyPQueue::update(std::string name, unsigned short pri) {
    Node* p = head;
    while(p != nullptr) {
        if(p->name == name) {
            p->pri = pri;
            return 0;
        }
        p = p->next;
    }
    return -1;
}

std::string MyPQueue::print() const {
    std::string result;
    Node* p = head;
    while(p != nullptr) {
        result = result + p->name + " " + std::to_string(p->pri) + "\n";
        p = p->next;
    }

    return result;
}

void MyPQueue::clear() {
    Node* p = head;
    while(p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    head = nullptr;
}

MyPQueue::~MyPQueue() {
    clear();
}
