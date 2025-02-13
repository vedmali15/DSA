#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    bool rightThread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        rightThread = false;
    }
};

class ThreadedBST {
public:
    Node *root;

    ThreadedBST() {
        root = nullptr;
    }

    void insert(int key) {
        Node *ptr = root, *par = nullptr;

        while (ptr) {
            if (key == ptr->data)
                return;
            par = ptr;
            if (key < ptr->data)
                ptr = ptr->left;
            else {
                if (ptr->rightThread)
                    break;
                ptr = ptr->right;
            }
        }

        Node *newNode = new Node(key);
        if (!root)
            root = newNode;
        else if (key < par->data)
            par->left = newNode;
        else {
            newNode->right = par->right;
            newNode->rightThread = par->rightThread;
            par->right = newNode;
            par->rightThread = false;
        }
    }

    Node *leftMost(Node *node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    void inorder() {
        Node *cur = leftMost(root);
        while (cur) {
            cout << cur->data << " ";
            if (cur->rightThread)
                cur = cur->right;
            else
                cur = leftMost(cur->right);
        }
        cout << endl;
    }

    void preorder(Node *node) {
        while (node) {
            cout << node->data << " ";
            if (node->left)
                node = node->left;
            else if (!node->rightThread)
                node = node->right;
            else
                node = nullptr;
        }
        cout << endl;
    }
};

int main() {
    ThreadedBST t;
    int n, val, choice;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        t.insert(val);
    }

    do {
        cout << "\n1. Inorder Traversal\n2. Preorder Traversal\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Inorder Traversal: ";
                t.inorder();
                break;
            case 2: 
                cout << "Preorder Traversal: ";
                t.preorder(t.root);
                break;
        }
    } while (choice != 3);

    return 0;
}
