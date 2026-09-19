#include <iostream>
#include <string>
#include <limits>

class MyStack {
    private:
        struct Node {
            char c;
            Node* next;
        };

        Node* top;

    public: 
        MyStack();
        ~MyStack();
        short push(char a);
        short pop();
        char peek();
    };

MyStack::MyStack() {
    top = nullptr;
}

MyStack::~MyStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

short MyStack::push(char a) {
    Node* n = new (std::nothrow) Node;
    if(n == nullptr) {
        return -1;
    }
    n->c = a;
    n->next = top;
    top = n;
    return 0;
}

short MyStack::pop() {
    if(top != nullptr) {
        Node* p = top;
        top = top->next;
        delete p;
        return 0;
    } else
        return -1;
}

char MyStack::peek() {
    if(top != nullptr) {
        return top->c;
    } else
        return '\0';
}
/*
class MyQueue {
    private:
        char* list;
        unsigned short front;
        unsigned short back;
        unsigned short max;
    public:
        MyQueue(unsigned short s);
        ~MyQueue();
        short enqueue(char a);
        short dequeue();
        char first();
};

MyQueue::MyQueue(unsigned short s) {
    max = s + 1;
    front = 0;
    back = 0;
    list = new char[max];
}

MyQueue::~MyQueue() {
    delete[]list;
}

short MyQueue::enqueue(char a) {
    if((back + 1) % max == front) {
        return -1;
    } else {
        list[back] = a;
        back = (back + 1) % max;
        return 0;
    }
}

short MyQueue::dequeue() {
    if(front != back) {
        front = (front + 1) % max;
        return 0;
    } else
        return -1;
}

char MyQueue::first() {
    if (front != back) {
        return list[front];
    } else
        return '\0';
}*/
int main() {
    return 0;
}