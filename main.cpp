#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};


Node* push_front(Node* head, float v){
    Node* newVal = new Node;
    newVal->value = v;
    newVal->next  = head;
    return newVal;   // new head
}
Node* push_back(Node* head, float v){
    Node* newVal = new Node;
    newVal->value = v;
    newVal->next  = nullptr;
    if (!head) return newVal; 

    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newVal;
    return head;
}
Node* delete_at(Node* head, int indx){
    if (indx < 1 || !head) return head;        
    if (indx == 1) {     
        Node* nxt = head->next;
        delete head;
        return nxt;
    }

    Node* prev = head;
    Node* curr = head->next;
    for (int i = 2; i < indx && curr; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return head; 

    prev->next = curr->next; 
    delete curr;
    return head;
    
}


void clear(Node*& head) {
    Node* current = head;
    while (current)
    {
        head = current ->next;
        delete current;
        current = head; 
    }
    head = nullptr;
}

void output(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = push_front(head, tmp_val);//adding node at the beginning
    }
    output(head);

    for (int i = 0; i < 1; i++) {
        int tmp_val = rand() % 100;
        head = push_back(head, tmp_val);//adding node at the tail
        
    }
    output(head); 

    cout << "Which node to delete?\n";
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    head = delete_at(head, entry);  // ← do the deletion
    output(head);



/*

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);*/

    clear(head);
    output(head); 

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}