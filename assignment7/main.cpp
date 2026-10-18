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
            root = nullptr;
        }
        short int find(std::string song) const {
            return find(root, song);
        }
        ~Tree() {
            clear();
        }
};

int main() {
    Tree myTree;
    myTree.add("Song 1");
    myTree.add("Song 2");
    myTree.add("Song 3");
    if(myTree.find("Song 2") == -1) {
        std::cout << "Song 2 not found in the tree." << std::endl;
    } else {
        std::cout << "Song 2 found in the tree." << std::endl;
    }
    std::cout << myTree.print();
    std::cout << "\nSize of tree: " << myTree.getSize() << std::endl;
    myTree.clear();
}