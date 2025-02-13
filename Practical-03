#include <iostream>
#define MAX_SIZE 5
using namespace std;

class CircularQueue
{
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    int isFull()
    {
        return (front == 0 && rear == MAX_SIZE - 1) || ((rear + 1) % MAX_SIZE == front);
    }

    int isEmpty()
    {
        return front == -1;
    }

    void enQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        cout << "Enqueued element: " << value << endl;
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int element = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Dequeued element: " << element << endl;
        return element;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in the queue: [";
        int i = front;
        while (true)
        {
            cout << arr[i];
            if (i == rear)
                break;
            cout << ", ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << "]" << endl;
    }
};

int main()
{
    CircularQueue q;
    int num, ch;
    do
    {
        cout << "\nQueue Operations";
        cout << "\n1. Add an element to Queue";
        cout << "\n2. Delete an element from Queue";
        cout << "\n3. Display elements in the Queue";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> num;
            q.enQueue(num);
            break;
        case 2:
            q.deQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (ch != 4);

    return 0;
}
