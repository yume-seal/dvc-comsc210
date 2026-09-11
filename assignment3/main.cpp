#include <iostream>
#include <string>
#include <limits>

class MyList {
    private:
        struct Node {
           std::string songTitle;
           Node* next = nullptr; 
        };
        Node* head = nullptr;
    public:
        ~MyList();
        bool isEmpty();
        unsigned short getSize();
        short add(std::string song);
        short find(std::string song);
        short remove(std::string song);
        void clear();
        std::string print();
};

bool MyList::isEmpty() {
    if(head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

unsigned short MyList::getSize() {
    unsigned short count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
}

short MyList::add(std::string song) {
    Node* n = new (std::nothrow) Node;
    if(n == nullptr) {
        return -1;
    }
    n->songTitle = song;
    n->next = nullptr;
    if(isEmpty()) {
        head = n;
    }
    else {
        Node* p = head;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = n;
    }
    return 0;
}

short MyList::find(std::string song) {
    Node* p = head;
    while(p != nullptr) {
        if(p->songTitle == song) 
            return 0;
        p = p->next;
    }
    return -1;
}

short MyList::remove(std::string song) {
    Node* p = head;
    Node* q = nullptr;
    while( p != nullptr && p->songTitle != song) {
        q = p;
        p = p->next;
    }
    if(p != nullptr) {
        if(q == nullptr) {
            head = head->next;
        } else {
            q->next = p->next;
        }
        delete p;
        return 0;
    }
    return -1;
}

void MyList::clear() {
    Node* p;
    while(head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}

std::string MyList::print() {
    Node* p = head;
    std::string playlist = "";
    int count = 0;
    while(p != nullptr) {
        playlist = playlist + p->songTitle + "\n";
        p = p->next;
        count++;
    }
    return "\nTotal songs in playlist: " + std::to_string(count) + "\n" + playlist ;
}

MyList::~MyList() {
    clear();
}

int main() {
    std::string song;
    MyList playlist;
    char choice;
    short found;
     while(choice != 'q') {
        std::cout << "\nMENU:\n1. (p)rint the playlist\n2. (a)dd song\n3. (r)emove song\n4. (s)earch Playlist\n5. (c)lear Playlist\n6. (q)uit\n";
        std::cout << "\nPlease select an option: ";
        std::cin >> choice;
        switch (choice) {
            case 'p':
                if(playlist.isEmpty()) {
                    std::cout << "\nThere are no songs in the playlist.";
                    std::cout << playlist.print();
                } 
                else {
                    std::cout << "\nPLAYLIST:\n";
                    std::cout << playlist.print();
                }
                break;
            case 'a': 
                std::cout << "\n Enter the name of a song to add to the playlist:";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, song);
                found =playlist.add(song);
                if(found == -1) {
                    std::cout << "\nFailed to add song; Memory allocation error.";
                }
                std::cout << "\nSong added.";
                break;
            case 'r':
                if(playlist.isEmpty()) {
                    std::cout << "\nThere are no songs to remove";
                }
                else {
                    std::cout << "\n Enter the name of a song to remove: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, song);
                    found = playlist.remove(song);
                    if(found == -1) {
                        std::cout << "\nError: There is no song titled " << song << " in the playlist.";
                    }
                    else { 
                        std::cout << "\nSong removed.\n";
                    }
                }
                break;
            case 's':
                if(playlist.isEmpty()) {
                    std::cout << "\nThere are no songs in the playlist."; 
                } else {
                    std::cout << "\nEnter the name of a song to search for: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, song);
                    short found = playlist.find(song);
                    if(found == -1) {
                        std::cout << "\nThe song " << song << " was not found.";
                    }
                    else {
                        std::cout << "\nThe song titled " << song << " was found.";
                    }
                }
                break;
            case 'c':
                if(playlist.isEmpty()) { 
                    std::cout << "\nThe playlist is already empty.";
                } else {
                    playlist.clear();
                    std::cout << "\nPlaylist cleared.";
                }
                break;
            case 'q':
                return 0;
        }
    }
}