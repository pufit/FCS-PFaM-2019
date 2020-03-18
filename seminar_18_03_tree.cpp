#include <cassert>
#include <iostream>

struct Node {
    Node() = default;

    Node(Node* left, Node* right) : left(left), right(right) {
    }

    ~Node() {
        delete left;
        delete right;
    }

    Node* left = nullptr;
    Node* right = nullptr;
    int value = 0;
};

size_t Depth(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return std::max(Depth(node->left), Depth(node->right)) + 1;
}

              //
           //   //
            //
         //
      //

int main() {
    Node* tree = new Node(new Node(), new Node());

    tree->left->right = new Node(new Node(), nullptr);
    tree->left->right->left->left = new Node();

    assert(Depth(tree) == 5);

    delete tree;

    return 0;
}
