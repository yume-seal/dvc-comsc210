#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
class MyHeap {
    private: 
        struct Patient {
            std::string name;
            unsigned short pri;
        };
        Patient queue[20];
        short bottom;
        unsigned short capacity;

        void ReHeapDown() {
            short parent = 0;
            while(parent < bottom) {
                short lc = 2 * parent + 1;
                short rc = 2 * parent + 2;
                short bc;

                if(lc <= bottom) {
                    if(lc == bottom)
                        bc = lc;
                    else {
                        if(queue[lc].pri > queue[rc].pri)
                            bc = lc;
                        else
                        bc = rc;
                    }
                }
                else {
                    break;
                }

                if(queue[parent].pri < queue[bc].pri) {
                    Patient temp = queue[parent];
                    queue[parent] = queue[bc];
                    queue[bc] = temp;
                    parent = bc;
                }
                else {
                    break;
                }
            }
        }

        void ReHeapUp() {
            short i = bottom;
            while(i != 0) {
                short parent = (i - 1)/2;
                if(queue[i].pri > queue[parent].pri) {
                    Patient temp = queue[parent];
                    queue[parent] = queue[i];
                    queue[i] = temp;
                    i = parent;
                }
                else {
                    break;
                }
            }
        }
    public:
        MyHeap();
        ~MyHeap();
        short enqueue(std::string name, unsigned short pri);
        std::string dequeue();
        short update(std::string name, unsigned short pri);
        std::string print();
        void clear();
};

MyHeap::MyHeap() {
    bottom = -1;
    capacity = 20;
}

MyHeap::~MyHeap() {
}

short MyHeap::enqueue(std::string name, unsigned short pri) {
    if(bottom != capacity - 1) {
        bottom++;
        queue[bottom].name = name;
        queue[bottom].pri = pri;
        ReHeapUp();
        return 0;
    }
    else {
        return -1;
    }
}

std::string MyHeap::dequeue() {
    if(bottom != -1) {
        std::string name = queue[0].name;
        queue[0] = queue[bottom];
        bottom--;
        ReHeapDown();
        return name;
    }
    else {
        return "";
    }
}

short MyHeap::update(std::string name, unsigned short pri) {
    short found = -1;
    for(short i = 0; i <= bottom; i++) {
        if(queue[i].name == name) {
            found = i;
            break;
        }
    }
    if(found == -1) {
        return -1;
    }
    unsigned short oldPri = queue[found].pri;
    queue[found].pri = pri;
    if(pri > oldPri) {
        short i = found;
        while(i > 0) {
            short parent = (i - 1) / 2;
            if(queue[i].pri > queue[parent].pri) {
                Patient temp = queue[i];
                queue[i] = queue[parent];
                queue[parent] = temp;
                i = parent;
            } else {
                break;
            }
        }
    } else if(pri < oldPri) {
        short parent = found;
        while(parent < bottom) {
            short lc = 2 * parent + 1;
            short rc = 2 * parent + 2;
            short bc;

            if(lc <= bottom) {
                if(lc == bottom) {
                    bc = lc;
                } else if(queue[lc].pri > queue[rc].pri) {
                    bc = lc;
                } else {
                    bc = rc;
                }

                if(queue[parent].pri < queue[bc].pri) {
                    Patient temp = queue[parent];
                    queue[parent] = queue[bc];
                    queue[bc] = temp;
                    parent = bc;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}

std::string MyHeap::print() {
    if(bottom == -1) {
        return "";
    }
    
    MyHeap tempHeap = *this;
    std::stringstream ss;
    ss << std::left << std::setw(19) << "Patient" << std::setw(3) << "PR" << "\n";
    while(tempHeap.bottom != -1) {
        std::string name = tempHeap.queue[0].name;
        unsigned short pri = tempHeap.queue[0].pri;
        ss << std::left << std::setw(19) << name << std::setw(3) << pri << "\n";
        tempHeap.dequeue();
    }
    return ss.str();
}

void MyHeap::clear() {
    bottom = -1;
}

int main() {
    MyHeap pq;
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