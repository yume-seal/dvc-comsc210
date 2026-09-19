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
        Node* temp = top;
        top = top->next;
        delete temp;
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

class MyQueue {
    private:
        struct Node {
            char c;
            Node* next;
        };
        Node* front;
        Node* back;

    public:
        MyQueue();
        ~MyQueue();
        short enqueue(char a);
        short dequeue();
        char first();
};

MyQueue::MyQueue() {
    front = nullptr;
    back = nullptr;
}

MyQueue::~MyQueue() {
    while(front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

short MyQueue::enqueue(char a) {
    Node* n = new (std::nothrow) Node;
    if(n == nullptr) {
        return -1;
    } else {
        n->c = a;
        n->next = nullptr;
        if(front == nullptr) {
            front = n;
            back = n;
        } else {
            back->next = n;
            back = back->next;
        }
    }
    return 0;
}

short MyQueue::dequeue() {
    if(front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
        return 0;
    }
    back = nullptr;
    return -1;
}

char MyQueue::first() {
    if(front != nullptr) {
        return front->c;
    }
    return '\0';
    }
int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    while (!input.empty() && (input.back() == '\r' || input.back() == '\n')) {
        input.pop_back();
    }

    MyStack stack;
    MyQueue queue;
    for (char c : input) {
        stack.push(c);
        queue.enqueue(c);
    }

    std::cout << "Stack contents: ";
    while (stack.peek() != '\0') {
        std::cout << stack.peek();
        stack.pop();
    }
    std::cout << std::endl;
    std::cout << "Queue contents: ";
    while (queue.first() != '\0') {
        std::cout << queue.first();
        queue.dequeue();
    }
    std::cout << std::endl;
    return 0;
}