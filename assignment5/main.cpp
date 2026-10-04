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
bool MyDLL::isEmpty() {
    if(head == nullptr) {
        return true;
    }
    return false;
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

    while (p != nullptr && p->songTitle != song) {
        q = p;
        p = p->next;
    }
    if(p == nullptr) {
        return -1;
    }
    else {
        if(cur == p) {
            cur = p->next;
        }
        if(q == nullptr) {
            head = p->next;
        }
        else {
            q->next = p->next;
        }
        if(p->next == nullptr) {
            tail = q;
        }
        else {
            p->next->prev = q;
        }
        delete(p);
        if(isEmpty()) {
            cur = nullptr;
        }
        return 0;
    }
}

void MyDLL::clear() {
    while(tail != nullptr) {
        Node* p = tail;
        tail = p->prev;
        delete(p);
    }
    head = nullptr;
    return;
}

short MyDLL::find(std::string song) {
    Node* p = tail;
    while(p != nullptr) {
        if(p->songTitle == song) {
            return 0;
        }
        p = p->prev;
    } 
    return -1;
}

unsigned short MyDLL::getSize() {
    unsigned short count = 0;
    Node* p = head;
    while(p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

std::string MyDLL::print() {
    if(isEmpty()) {
        return "Playlist is empty.\n";
    }
    std::string playlist = "";
    Node* p = head;
    while(p != nullptr) {
        playlist = playlist + p->songTitle;
        if(p == cur) {
            playlist = playlist + " (NOW PLAYING)\n";
        }
        else {
            playlist = playlist + "\n";
        }
        p = p->next;
    }
    return playlist;
}

std::string MyDLL::forward() {
    if(cur == nullptr) {
        return "";
    }
    cur = cur->next;
    if(cur == nullptr) {
        cur = head;
    }
    return cur->songTitle;
}

std::string MyDLL::backward() {
    if(cur == nullptr) {
        return "";
    }
    cur = cur->prev;
    if(cur == nullptr) {
        cur = tail;
    }
    return cur->songTitle;
}
MyDLL::~MyDLL() {
    clear();
}

int main() {
    MyDLL playlist;
    char choice;
    std::string song;
    bool plural;
    unsigned short songs;
    while(choice != 'q') {
        plural = false;
        std::cout <<"\nCOMSC210 MUSIC PLAYER MENU\n";
        std::cout <<"(a)dd song\n";
        std::cout <<"(b)ackward\n";
        std::cout <<"(c)lear playlist\n";
        std::cout <<"(f)orward\n";
        std::cout <<"(p)rint playlist\n";
        std::cout <<"(r)emove song\n";
        std::cout <<"(s)earch playlist\n";
        std::cout <<"(q)uit\n";
        std::cout <<"Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                std::cout << "\nEnter song title: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, song);
                if(playlist.add(song) == -1) {
                    std::cout << "Error: Memory allocation failed.\n";
                }
                break;
            case 'b':
                std::cout << "Now playing: " << playlist.backward() << "\n";
                break;
            case 'c':
                playlist.clear();
                std::cout << "Playlist cleared.\n";
                break;
            case 'f':
                std::cout << "Now playing: " << playlist.forward() << "\n";
                break;
            case 'p':
                std::cout << playlist.print();
                songs = playlist.getSize();
                if(songs == 0 || songs > 1) {
                    plural = true;
                    std::cout <<"\n" << songs << " total songs.\n";
                    break;
                }
                std::cout << "\n" << songs << " song.\n";
                break;
            case 'r':
                std::cout << "Enter song title to remove: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, song);
                if(playlist.remove(song) == -1) {
                    std::cout << "Song not found in playlist.\n";
                }
                else {
                    std::cout << "Song removed from playlist.\n";
                }
                break;
            case 's':
                std::cout << "Enter song title to search: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, song);
                if(playlist.find(song) == -1) {
                    std::cout << "Song not found in playlist.\n";
                }
                else {
                    std::cout << "Song found in playlist.\n";
                }
                break;
            case 'q':
                std::cout << "Exiting music player.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}