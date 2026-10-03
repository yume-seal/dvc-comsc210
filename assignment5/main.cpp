#include <iostream>
#include <string>
#include <limits>

class MyDLL {
    private:
        struct Node {
            std::string songTitle;
            Node* next;
            Node* prev;
        };
        Node* head = nullptr;
        Node* tail = nullptr;
        Node*cur = nullptr;
    public:
        ~MyDLL();
        MyDLL();
        bool isEmpty();
        short add(std::string song);
        short remove(std::string song);
        void clear();
        short find(std::string song);
        unsigned short getSize();
        std::string print();
        std::string forward();
        std::string backward();
};

MyDLL::MyDLL() {
    head = nullptr;
    tail = nullptr;
    cur = nullptr;
}

short MyDLL::add(std::string song) {
    Node* n = new (std::nothrow) Node;
    if(n == nullptr) {
        return -1;
    }
    n->songTitle = song;
    n->next = nullptr;
    n->prev = nullptr;
    if(head == nullptr) {
        head = n;
        tail = n;
        cur = n;
    }
    else {
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
    
    return 0;

}

short MyDLL::remove(std::string song) {
    Node* p = head;
    Node*q = nullptr;

    while (p != 0 && p->songTitle != song) {
        q = p;
        p = p->next;
    }
    if(p == 0) {
        return -1;
    }
    else {
        if(q == 0) {
            head = p->next;
        }
        else {
            q->next = p->next;
        }
        if(p->next = 0) {
            tail = q;
        }
        else {
            p->next->prev = q;
        }
        delete(p);
    }
}

void MyDLL::clear() {
    while(tail != 0) {
        Node* p = tail;
        tail = p->prev;
        delete(p);
    }
    head = nullptr;
}

short MyDLL::find(std::string song) {
    Node* p = tail;
    while(p != 0) {
        if(p->songTitle == song) {
            return 0;
        }
        p = p->prev;
    } 
    return -1;
}