#include <iomanip>
#include <iostream>
#include <string>
class Tree {
    private:
        struct Node {
            std::string songTitle;
            Node* left;
            Node* right;
        };
        Node* root;
        short int add(Node*& r, std::string song) {
            if(r == nullptr) {
                r = new Node;
                r->songTitle = song;
                r->left = nullptr;
                r->right = nullptr;
                return 0;
            } else if (song < r->songTitle) {
                return add(r->left, song);
            } else {
                return add(r->right, song);
            }
        }
        short int remove(Node*&r, std::string song) {
            Node* p = nullptr;
            if(r == nullptr) {
                return -1;
            } else if (song < r->songTitle) {
                return remove(r->left, song);
            } else if (song > r->songTitle) {
                return remove(r->right, song);
            } else {
                if(r->left == nullptr && r->right == nullptr) {
                    delete r;
                    r = nullptr;
                } else if (r->left == nullptr && r->right != nullptr) {
                    p = r;
                    r = r->right;
                    delete p;
                } else if(r->left != nullptr && r->right == nullptr) {
                    p = r;
                    r = r->left;
                    delete p;
                }
                else {
                    p = r->right;
                    while(p->left != nullptr) {
                        p = p->left;
                    }
                        p->left = r->left;
                        p = r;
                        p = r->right;
                        delete p;
                }
                return 0;
            }
        }
        
        std::string print(Node* r) const {
            if(r == nullptr) {
                return "";
            } else {
                return print(r->left) + r->songTitle + "\n" + print(r->right);
            }
        }
        unsigned short int getSize(Node* r) const {
            if(r == nullptr) {
                return 0; 
            } else {
                return 1 + getSize(r->left) + getSize(r->right);
            }
        }
        void clear(Node*& r) {
            if(r != nullptr) {
                clear(r->left);
                clear(r->right);
                delete r;
                r = nullptr;
            }
        }

        short int find(Node* r, std::string song) const {
            if(r == nullptr) {
                return -1;
            } else if (song == r->songTitle) {
                return 0;
            } else if (song < r->songTitle) {
                return find(r->left, song);
            } else {
                return find(r->right, song);
            }
        }
    public:
        Tree() {
            root = nullptr;
        }
        short int add(std::string song) {
            return add(root, song);
        }
        short int remove(std::string song) {
            return remove(root, song);
        }
        std::string print() {
            return print(root);
        }
        unsigned short int getSize() const {
            return getSize(root);
        }
        void clear() {
            clear(root);
        }
        short int find(std::string song) const {
            return find(root, song);
        }
        ~Tree() {
            clear();
        }
};

int main() {
    std::string song;
    Tree playlist;
    char choice;
    short found;
     while(choice != 'q') {
        std::cout << "\nMENU:\n1. (p)rint the playlist\n2. (a)dd song\n3. (r)emove song\n4. (s)earch Playlist\n5. (c)lear Playlist\n6. (q)uit\n";
        std::cout << "\nPlease select an option: ";
        std::cin >> choice;
        switch (choice) {
            case 'p':
                std::cout << "\nPLAYLIST:\n";
                std::cout << playlist.print();
                std::cout << "\n" << playlist.getSize() << " total songs\n";
                break;
            case 'a': 
                std::cout << "\n Enter the name of a song to add to the playlist: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, song);
                found = playlist.add(song);
                if(found == -1) {
                    std::cout << "\nFailed to add song; Memory allocation error.";
                } else {
                    std::cout << "\nSong added.";
                }
                break;
            case 'r':
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
                break;
            case 's':
                 std::cout << "\nEnter the name of a song to search for: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, song);
                found = playlist.find(song);
                if(found == -1) {
                    std::cout << "\nThe song " << song << " was not found.";                 
                }
                else {
                  std::cout << "\nThe song titled " << song << " was found.";
                }
                break;
            case 'c':
                playlist.clear();
                std::cout << "\nPlaylist cleared.";
                std::cout << "\n" << playlist.getSize() << " total songs.\n";
                break;
            case 'q':
                playlist.~Tree();
                return 0;
        }
    }
}