#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>

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
    Node* current = p;
    while(p != nullptr) {
        if(p->name == name) {
            p->pri = pri;
              if(p->pri > current->pri) {
                p->next = current;
            }
            return 0;
        }
        p = p->next;
        current = p;
    }
    return -1;
}

std::string MyPQueue::print() const {
    if(head == nullptr) {
        return "";
    }
    std::ostringstream oss;
    oss << std::left << std::setw(19) << "PATIENT" << std::right << std::setw(3) << "PR" << "\n";
    Node* p = head;
    while(p != nullptr) {
        oss << std::left << std::setw(19) << p->name << std::right << std::setw(3) << p->pri << "\n";
        p = p->next;
    }

    return oss.str();
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

int main() {
    MyPQueue pq;
    char choice;
    std::string name;
    unsigned short pri;
    while(choice != 'q') {
        std::cout << "COMSC-210 TRIAGE SYSTEM\n";
        std::cout << "(a)dd patient\n";
        std::cout << "(c)lear patients\n";
        std::cout << "(l)ist patients\n";
        std::cout << "(n)ext patient\n";
        std::cout << "(u)pdate patient\n";
        std::cout << "(q)uit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case 'a': {
                std::cout << "Enter patient name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                std::cout << "Enter patient priority: ";
                std::cin >> pri;
                if(pq.enqueue(name, pri) == -1) {
                    std::cout << "Error: Memory allocation failed.\n";
                }
                break;
            }
            case 'c':
                pq.clear();
                break;
            case 'l':
                std::cout << pq.print();
                break;
            case 'n': {
                std::string nextPatient = pq.dequeue();
                if(nextPatient.empty()) {
                    std::cout << "No patients in queue.\n";
                } else {
                    std::cout << "Next patient: " << nextPatient << "\n";
                }
                break;
            }
            case 'u': {
                std::cout << "Enter patient name to update: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                std::cout << "Enter new priority: ";
                std::cin >> pri;
                if(pq.update(name, pri) == -1) {
                    std::cout << "Patient not found.\n";
                }
                break;
            }
            case 'q':
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
