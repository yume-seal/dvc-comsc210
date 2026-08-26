#include <iostream>
#include <string>

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
        return 0;
    }
    else {
        playlist[size] = song;
        size = size + 1;
        return 1;
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
    for(int i =0; i < size; i++) {
        if(playlist[i] == song) {
            break;
        }
        else {
            return 0;
        }
    }
        for(int j =0; j < size - 2; j++) {
            playlist[j] = playlist[j + 1];
        }
        size = size - 1;
        return 1;
    }

int main() {
    return 0;
};