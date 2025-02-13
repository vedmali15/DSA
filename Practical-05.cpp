#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
    Node *root;

    Node* insert(Node *node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node *node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node *node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    bool search(Node *node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return val < node->data ? search(node->left, val) : search(node->right, val);
    }

    void inorder(Node *node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    int depth(Node *node) {
        if (!node) return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }

    Node* mirror(Node *node) {
        if (!node) return NULL;
        Node *newNode = new Node(node->data);
        newNode->left = mirror(node->right);
        newNode->right = mirror(node->left);
        return newNode;
    }

    Node* copyTree(Node *node) {
        if (!node) return NULL;
        Node *newNode = new Node(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void displayParents(Node *node) {
        if (!node || (!node->left && !node->right)) return;
        cout << node->data << " -> ";
        if (node->left) cout << node->left->data << " ";
        if (node->right) cout << node->right->data;
        cout << endl;
        displayParents(node->left);
        displayParents(node->right);
    }

    void displayLeaves(Node *node) {
        if (!node) return;
        if (!node->left && !node->right) cout << node->data << " ";
        displayLeaves(node->left);
        displayLeaves(node->right);
    }

    void levelOrder(Node *node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node *temp = q.front(); q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

public:
    BST() { root = NULL; }
    void insert(int val) { root = insert(root, val); }
    void deleteNode(int val) { root = deleteNode(root, val); }
    bool search(int val) { return search(root, val); }
    void inorder() { inorder(root); cout << endl; }
    int depth() { return depth(root); }
    void mirror() { root = mirror(root); }
    void copyTree() { root = copyTree(root); }
    void displayParents() { displayParents(root); }
    void displayLeaves() { displayLeaves(root); cout << endl; }
    void levelOrder() { levelOrder(root); cout << endl; }
};

int main() {
    BST tree;
    int choice, val;
    do {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Depth\n6. Mirror Image\n7. Copy Tree\n8. Display Parent Nodes\n9. Display Leaf Nodes\n10. Level Order\n11. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; tree.insert(val); break;
            case 2: cout << "Enter value: "; cin >> val; tree.deleteNode(val); break;
            case 3: cout << "Enter value: "; cin >> val; cout << (tree.search(val) ? "Found\n" : "Not Found\n"); break;
            case 4: tree.inorder(); break;
            case 5: cout << "Depth: " << tree.depth() << endl; break;
            case 6: tree.mirror(); cout << "Tree mirrored\n"; break;
            case 7: tree.copyTree(); cout << "Tree copied\n"; break;
            case 8: tree.displayParents(); break;
            case 9: tree.displayLeaves(); break;
            case 10: tree.levelOrder(); break;
        }
    } while (choice != 11);
    return 0;
}
