#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

struct StackNode {
    Node *data;
    StackNode *next;
};

class Stack {
    StackNode *top;
public:
    Stack() { top = NULL; }

    bool isEmpty() { return top == NULL; }

    void push(Node *node) {
        StackNode *temp = new StackNode();
        temp->data = node;
        temp->next = top;
        top = temp;
    }

    Node *pop() {
        if (isEmpty()) return NULL;
        StackNode *temp = top;
        Node *node = top->data;
        top = top->next;
        delete temp;
        return node;
    }
};

Node *createPostfixTree(string postfix) {
    Stack s;
    for (char token : postfix) {
        Node *newNode = new Node{token, NULL, NULL};
        if (isalnum(token)) {
            s.push(newNode);
        } else {
            newNode->right = s.pop();
            newNode->left = s.pop();
            s.push(newNode);
        }
    }
    return s.pop();
}

Node *createPrefixTree(string prefix) {
    Stack s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        Node *newNode = new Node{prefix[i], NULL, NULL};
        if (isalnum(prefix[i])) {
            s.push(newNode);
        } else {
            newNode->left = s.pop();
            newNode->right = s.pop();
            s.push(newNode);
        }
    }
    return s.pop();
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = NULL;
    int choice;
    string expression;

    do {
        cout << "\n*** TREE OPERATIONS ***\n";
        cout << "1. Construct tree from postfix/prefix\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int type;
                cout << "1. Postfix\n2. Prefix\nChoose type: ";
                cin >> type;
                cout << "Enter expression: ";
                cin >> expression;
                root = (type == 1) ? createPostfixTree(expression) : createPrefixTree(expression);
                cout << "Tree created successfully!\n";
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
