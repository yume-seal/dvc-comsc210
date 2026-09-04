#include <iostream>
#include <string>
#include <limits>

class MyStack {
    private:
        char* list;
        short int top = -1;
        unsigned short int max;

    public: 
        MyStack(unsigned short s);
        ~MyStack();

        short push(char a);
        short pop();
        char peek();
    };

MyStack::MyStack(unsigned short s) {
    max = s;
    list = new char[max];
}

MyStack::~MyStack() {
    delete[]list;
}

short MyStack::push(char a) {
    if(top < max - 1) {
        top = top + 1;
        list[top] = a;
        return 0;
    } else
        return -1;
}

short MyStack::pop() {
    if(top > -1) {
        top = top -1;
        return 0;
    } else
        return -1;
}

char MyStack::peek() {
    if(top > -1) {
        return list[top];
    } else
        return '\0';
}

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
    max = s;
    front = 0;
    back = 0;
}

MyQueue::~MyQueue() {
    delete[]list;
}

short MyQueue::enqueue(char a) {
    if(front != (back + 1) % max) {
        list[back] = a;
        back = (back + 1) % max;
        return 0;
    } else 
        return -1;
}

short MyQueue::dequeue() {
    if(front != (back + 1) % max) {
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
}

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    MyStack stack(input.length());
    return 0;
}