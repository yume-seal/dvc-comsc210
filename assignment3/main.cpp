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
        short getSize();
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

short MyList::getSize() {
    int count = 0;
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
        head =n;
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
/*
std::string MyList::get(int songNumber) const {
    if (songNumber < 0 || songNumber >= size) {
        return "";
    }
    else {
        return playlist[songNumber];
    }
}

int MyList::remove(std::string song) {
    for(int i = 0; i < size; i++) {
        if (playlist[i] == song) {
            playlist[i] = playlist[size - 1];
            size = size - 1;
            return 0;
        }
    }

    return -1;
}

MyList::~MyList() {
    clear();
}
*/
int main() {
   /* int capacity;
    std::string song;
    std::cout << "How many songs do you want in the playlist?(Enter an integer)";
    std:: cin >> capacity;
    MyList playlist(capacity);
    int choice = 0;
     while(choice != 4) {
        std::cout << "\nMENU:\n1. Show the playlist\n2. Add song\n3. Remove song\n4. Exit";
        std::cout << "\nPlease select a number: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                if(playlist.isEmpty()) {
                    std::cout << "\nThere are no songs in the playlist.";
                } 
                else {
                    std::cout << "\nPLAYLIST:\n";
                    for(int i = 0; i < playlist.getSize(); i++)
                    {
                        std::cout << playlist.get(i) << "\n";
                    }
                }
                break;
            case 2: 
                if(playlist.isFull()) {
                    std::cout << "\nYou cannot add anymore songs, the playlist is full.";
                }
                else {
                    std::cout << "\n Enter the name of a song to add to the playlist:";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, song);
                    playlist.add(song);
                    std::cout << "\nUPDATED PLAYLIST:\n";
                    for(int i = 0; i < playlist.getSize(); i++)
                    {
                        std::cout << playlist.get(i) << "\n";
                    }
                }
                break;
            case 3:
                if(playlist.isEmpty()) {
                    std::cout << "\nThere are no songs to remove";
                }
                else {
                    std::cout << "\n Enter the name of a song to remove: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, song);
                    int found = playlist.remove(song);
                    if(found == -1) {
                        std::cout << "\nError: There is no song titled " << song << " in the playlist.";
                    }
                    else { 
                        std::cout << "\nUPDATED PLAYLIST:\n";
                        for(int i = 0; i < playlist.getSize(); i++) {
                            std::cout << playlist.get(i) << "\n";
                        }
                    }
                }
                break;
            case 4:
                return 0;
        }
        if(choice < 1 || choice > 4) {
            std::cout << "Choice must be between 1 - 4.";
        }
    }*/
   return 0;
};