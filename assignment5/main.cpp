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