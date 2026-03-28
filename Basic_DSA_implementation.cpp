#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// SINGLY LINKED LIST
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void displayList() {
    Node* temp = head;
    cout << "Singly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


// DOUBLY LINKED LIST
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* dhead = NULL;

void insertDoubly(int val) {
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dhead;

    if (dhead != NULL)
        dhead->prev = newNode;

    dhead = newNode;
}

void displayForward() {
    DNode* temp = dhead;
    cout << "Doubly Linked List (Forward): ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void displayBackward() {
    DNode* temp = dhead;

    if (temp == NULL) return;

    while (temp->next != NULL)
        temp = temp->next;

    cout << "Doubly Linked List (Backward): ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}


// STACK

#define SIZE 5
int stack_arr[SIZE];
int top = -1;

void push(int val) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack_arr[++top] = val;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

void displayStack() {
    cout << "Stack: ";
    for (int i = top; i >= 0; i--)
        cout << stack_arr[i] << " ";
    cout << endl;
}


// QUEUE

int queue_arr[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;
    queue_arr[++rear] = val;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    front++;
}

void displayQueue() {
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
        cout << queue_arr[i] << " ";
    cout << endl;
}


// FILE HANDLING

void writeToFile() {
    ofstream file("data.txt");
    file << " file handling in C++";
    file.close();
}

void readFromFile() {
    ifstream file("data.txt");
    string line;
    cout << "File Content: ";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}


// MAIN

int main() {

    // Singly Linked List
    insert(10);
    insert(20);
    insert(30);
    displayList();

    // Doubly Linked List
    insertDoubly(100);
    insertDoubly(200);
    insertDoubly(300);
    displayForward();
    displayBackward();

    // Stack
    push(1);
    push(2);
    push(3);
    displayStack();
    pop();
    displayStack();

    // Queue
    enqueue(5);
    enqueue(6);
    enqueue(7);
    displayQueue();
    dequeue();
    displayQueue();

    // File Handling
    writeToFile();
    readFromFile();

    return 0;
}