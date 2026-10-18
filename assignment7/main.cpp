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
};

int main() {
    Tree myTree;
    myTree.add("Song 1");
    myTree.add("Song 2");
    myTree.add("Song 3");
    myTree.remove("Song 2");
}