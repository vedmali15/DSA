#include <iostream>
#include <string.h>
using namespace std;

struct student {
    int roll;
    char name[20];
    float marks;
};

void swap(student &a, student &b) {
    student temp = a;
    a = b;
    b = temp;
}

void create(student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter roll no: ";
        cin >> s[i].roll;
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter marks: ";
        cin >> s[i].marks;
    }
}

void display(student s[], int n) {
    cout << "\nRoll No\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].marks << endl;
    }
}

void bubble(student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

void insertion(student s[], int n) {
    for (int i = 1; i < n; i++) {
        student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int partition(student s[], int l, int u) {
    float pivot = s[l].marks;
    int p = l, q = u;
    
    while (p < q) {
        while (s[p].marks <= pivot && p < u)
            p++;
        while (s[q].marks > pivot)
            q--;
        if (p < q)
            swap(s[p], s[q]);
    }
    
    swap(s[l], s[q]);
    return q;
}

void quick(student s[], int l, int u) {
    if (l < u) {
        int pi = partition(s, l, u);
        quick(s, l, pi - 1);
        quick(s, pi + 1, u);
    }
}

void binsearch(student s[], int l, int u) {
    int mid;
    insertion(s, u + 1);
    
    cout << "Enter name to search: ";
    char x[20];
    cin >> x;

    while (l <= u) {
        mid = (l + u) / 2;
        if (strcmp(s[mid].name, x) == 0) {
            cout << "Student found!\n";
            cout << s[mid].roll << "\t" << s[mid].name << "\t" << s[mid].marks << endl;
            return;
        } else if (strcmp(s[mid].name, x) < 0) {
            l = mid + 1;
        } else {
            u = mid - 1;
        }
    }
    cout << "Student not found!\n";
}

void same_sgpa(student s[], int n) { 
    float marks;
    cout << "Enter marks of student: ";
    cin >> marks;
    
    cout << "\nStudents with same marks:\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (marks == s[i].marks) {
            cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].marks << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with the given marks.\n";
    }
}

int main() {
    student s[20];
    int ch, n;
    
    do {   
        cout << "\n1. Create Record\n";
        cout << "2. Bubble Sort (by Roll No.)\n";
        cout << "3. Insertion Sort (by Name)\n";
        cout << "4. Quick Sort (by Marks)\n";
        cout << "5. Find Students with Same Marks\n";
        cout << "6. Binary Search (by Name)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                cout << "Enter number of students: ";
                cin >> n;
                create(s, n);
                display(s, n);
                break;
            case 2:
                bubble(s, n);
                display(s, n);
                break;
            case 3:
                insertion(s, n);
                display(s, n);
                break;
            case 4:
                quick(s, 0, n - 1);
                display(s, n);
                break;
            case 5:
                same_sgpa(s, n);
                break;
            case 6:
                binsearch(s, 0, n - 1);
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 7);
    
    return 0;
}
