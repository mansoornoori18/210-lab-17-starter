#include <iostream>   //              COMSC-210 | Lab 15 | Mansoor Noori
#include <cstdlib>    // for rand IDE Visual Studio 
#include <ctime>      // for time()
using namespace std;  

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// function prototype 
void addToFront(Node* &head, float val);
void addToTail(Node* &head, float val);
void deleteNode(Node* &head, int position);
void insertAfter(Node* &head, int position, float val);
void deleteList(Node* &head);
void output(Node* head);


int main() {
    srand(time(0));               // seed random generator 

    Node *head = nullptr;

    // size random eleamnt to front 
    for (int i = 0; i < SIZE; i++) {
        float val = rand() % 100;
        addToFront(head, val);
    }      
    cout << "initial List\n";
    output(head);
    
    // delete a node 
    cout << "which node to delete? \n";
    output(head);
    int delPosition;
    cout << "Choice ---> ";
    cin >> delPosition;
    deleteNode(head, delPosition);
    cout << "\nList after deletation:\n";
    output(head);

    //insert a Node 
    cout << "After which node to insert 10000? \n";
    output(head);
    int insPosition;
    cout << "Choice ---> ";
    cin >> insPosition;
    insertAfter(head, insPosition, 10000);
    cout << "\nList after insertion:\n";
    output(head);
    
    // delete entire lsit 
    deleteList(head);
    cout << "\nAfter deleting entire list:\n";
    output(head);
    
    return 0;
}

// function definfition
void addToFront(Node* &head, float val){
    Node* newNode = new Node{val, head};
    head = newNode;
}

void addToTail(Node* &head, float val){
    Node* newNode = new Node{val, nullptr};
    if (!head){
        head = newNode;
    } else {
        Node* current = head;
        while (current->next){
            current = current->next;
        }
        current->next = newNode;
    }
}
void deleteNode(Node* &head, int Position){
    if (!head || Position < 1) return;

    if (Position == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    for (int i = 1; current && i < Position - 1; ++i){
        current = current->next;
    }
    if (current && current->next){
        Node*temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
void insertAfter(Node* &head, int Position, float cal){
    if (Position< 1)return;

    Node* current = head;
    for (int i = 1; current && i < Position; i++){
        current = current->next;
    }
    
}