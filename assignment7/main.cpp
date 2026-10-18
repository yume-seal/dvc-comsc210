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
    public:
        Tree() {
            root = nullptr;
        }
        short int add(std::string song) {
            return add(root, song);
        }
};

int main() {
    Tree myTree;
    myTree.add("Song 1");
    myTree.add("Song 2");
    myTree.add("Song 3");
}