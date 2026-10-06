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