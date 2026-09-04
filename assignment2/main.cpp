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