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
    
   

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "EEmpty list.\n";
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
