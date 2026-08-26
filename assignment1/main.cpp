#include <iostream>
#include <string>
#include <limits>

class MyList {
    private:
        std::string* playlist;
        int size;
        int max;
    public:
        MyList(int m = 10);
        ~MyList();

        bool isFull() const;
        bool isEmpty() const;
        int getSize() const;
        int add(std::string song);
        std::string get(int songNumber) const;
        int remove(std::string song);
};

MyList::MyList(int m) {
    max = m;
    size = 0;
    playlist = new std::string[max];
}

MyList::~MyList() {
    delete[]playlist;
}

bool MyList::isFull() const { 
    if (size == max) {
        return true;
    }
    else {
        return false;
    }
}

bool MyList::isEmpty() const {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

int MyList::getSize() const {
    return size;
}

int MyList::add(std::string song) {
    if (isFull()) {
        return -1;
    }
    else {
        playlist[size] = song;
        size = size + 1;
        return 0;
    }
}

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

int main() {
    int capacity;
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
    }
};