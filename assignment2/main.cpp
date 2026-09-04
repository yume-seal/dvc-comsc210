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

        short push(char*list, short top, unsigned short max, char a);
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

short MyStack::push(char* list, short top, unsigned short max, char a) {
    if(top < max - 1) {
        top = top + 1;
        list[top] = a;
        return 0;
    } else
        return -1;
}

short pop(char* list, short top) {
    if(top > -1) {
        top = top -1;
        return 0;
    } else
        return -1;
}

char peek(char* list, short top) {
    if(top > -1) {
        return(list[top]);
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