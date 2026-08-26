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

int main() {
    return 0;
}