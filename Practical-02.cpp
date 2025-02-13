#include <iostream>
#include <cctype> // For isalnum
using namespace std;

struct node {
    char data;
    node *next;
};

class stack {
    node *top;

public:
    stack() { top = NULL; }

    ~stack() { // Destructor to free memory
        while (!isempty()) pop();
    }

    bool isempty() { return top == NULL; }

    void push(char x) {
        node *p = new node();
        p->data = x;
        p->next = top;
        top = p;
    }

    char pop() {
        if (isempty()) {
            cout << "Stack Underflow!";
            return '\0';
        }
        node *p = top;
        char x = p->data;
        top = top->next;
        delete p;
        return x;
    }

    char topdata() {
        if (isempty()) return '\0';
        return top->data;
    }
};

void infix_postfix(char infix[], char postfix[]);
void reverse(char a[], char b[]);
void infix_prefix(char infix[], char prefix[]);
int evaluate(int op1, int op2, char op);
void evaluate_postfix(char postfix[]);
int precedence(char x);
void evaluate_prefix(char prefix[]);

void infix_postfix(char infix[], char postfix[]) {
    stack s;
    int i, j = 0;
    char token, x;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else {
            if (token == '(') {
                s.push(token);
            } else if (token == ')') {
                while (!s.isempty() && (x = s.pop()) != '(') {
                    postfix[j++] = x;
                }
            } else {
                while (!s.isempty() && precedence(token) <= precedence(s.topdata())) {
                    postfix[j++] = s.pop();
                }
                s.push(token);
            }
        }
    }

    while (!s.isempty()) {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
}

void reverse(char a[], char b[]) {
    int i, j = 0;
    for (i = 0; a[i] != '\0'; i++);
    i--;
    for (; i >= 0; i--, j++) {
        if (a[i] == '(') b[j] = ')';
        else if (a[i] == ')') b[j] = '(';
        else b[j] = a[i];
    }
    b[j] = '\0';
}

void infix_prefix(char infix[], char prefix[]) {
    char prefix1[20], infix1[20];
    reverse(infix, infix1);
    infix_postfix(infix1, prefix1);
    reverse(prefix1, prefix);
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 3;
}

int evaluate(int op1, int op2, char op) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return (op2 != 0) ? op1 / op2 : 0; // Avoid division by zero
        case '%': return op1 % op2;
        default: return 0;
    }
}

void evaluate_postfix(char postfix[]) {
    stack s;
    int i, op1, op2, result;
    char token;
    int x;

    for (i = 0; postfix[i] != '\0'; i++) {
        token = postfix[i];

        if (isalnum(token)) {
            cout << "Enter value for " << token << ": ";
            cin >> x;
            s.push(x);
        } else {
            op2 = s.pop();
            op1 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(result);
        }
    }
    result = s.pop();
    cout << "Result = " << result << endl;
}

void evaluate_prefix(char prefix[]) {
    stack s;
    int i, op1, op2, result;
    char token;
    int x;

    for (i = 0; prefix[i] != '\0'; i++);
    i--;

    for (; i >= 0; i--) {
        token = prefix[i];

        if (isalnum(token)) {
            cout << "Enter value for " << token << ": ";
            cin >> x;
            s.push(x);
        } else {
            op1 = s.pop();
            op2 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(result);
        }
    }
    result = s.pop();
    cout << "Result = " << result << endl;
}

int main() {
    char infix[20], postfix[20], prefix[20];
    int ch;

    do {
        cout << "\n1. Infix to Postfix conversion";
        cout << "\n2. Infix to Prefix conversion";
        cout << "\n3. Evaluate Postfix";
        cout << "\n4. Evaluate Prefix";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter Infix expression: ";
                cin >> infix;
                infix_postfix(infix, postfix);
                cout << "\nPostfix Expression: " << postfix << endl;
                break;
            case 2:
                cout << "\nEnter Infix expression: ";
                cin >> infix;
                infix_prefix(infix, prefix);
                cout << "\nPrefix Expression: " << prefix << endl;
                break;
            case 3:
                evaluate_postfix(postfix);
                break;
            case 4:
                evaluate_prefix(prefix);
                break;
        }
    } while (ch != 5);

    return 0;
}
