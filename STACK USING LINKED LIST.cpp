#include <iostream>
using namespace std;

class Node {  // DEFINE A NODE CLASS TO REPRESENT EACH NODE IN THE LINKED LIST
public:
    int data;
    Node* next;

    Node() : data(NULL), next(NULL) {}  // DEFAULT CONSTRUCTOR INITIALIZING DATA AND NEXT TO NULL
    Node(int data) : data(data), next(NULL) {}  // PARAMETERIZED CONSTRUCTOR TO INITIALIZE THE NODE WITH A GIVEN DATA
};

class StackUisngLinkedList { // DEFINE A STACK CLASS USING A LINKED LIST
    Node* HEAD; // POINTER TO THE TOP OF THE STACK (HEAD OF THE LINKED LIST)
    int ListSize; // VARIABLE TO KEEP TRACK OF THE SIZE OF THE STACK
public:
    StackUisngLinkedList() : HEAD(NULL), ListSize(0) {}  // DEFAULT CONSTRUCTOR INITIALIZING HEAD TO NULL AND LISTSIZE TO 0

    Node* CreateNode(int data) {    // FUNCTION TO CREATE A NEW NODE WITH GIVEN DATA
        Node* newNode = new Node(data);
        return newNode;
    }
    bool isEmpty() const { return HEAD == NULL; }  // FUNCTION TO CHECK IF THE STACK IS EMPTY
    int get_ListSize() const { return ListSize; }  // FUNCTION TO GET THE CURRENT SIZE OF THE STACK

    int peek() const {  // FUNCTION TO GET THE DATA OF THE TOP ELEMENT IN THE STACK
        if (isEmpty()) {
            cout << "ERROR! LIST IS ALREADY EMPTY" << endl;
            return -1;
        }
        return HEAD->data;
    }
    void push(int data) {  // FUNCTION TO PUSH AN ELEMENT ONTO THE STACK
        Node* newNode = CreateNode(data);

        newNode->next = HEAD;  // LINK THE NEW NODE TO THE PREVIOUS HEAD
        HEAD = newNode;  // UPDATE HEAD TO POINT TO THE NEW NODE

        ListSize++;  // INCREMENT THE SIZE OF THE STACK
        cout << "VALUE: " << data << " PUSHED" << endl;
    }

    int pop() {  // FUNCTION TO POP AN ELEMENT FROM THE STACK
        if (isEmpty()) {
            cout << "ERROR! LIST IS ALREADY EMPTY" << endl;
            return -1;
        }
        Node* temp = HEAD;  // STORE THE CURRENT HEAD IN A TEMPORARY VARIABLE
        HEAD = HEAD->next;  // UPDATE HEAD TO POINT TO THE NEXT NODE
        int DeletedData = temp->data;  // STORE THE DATA OF THE DELETED NODE

        ListSize--;  // DECREMENT THE SIZE OF THE STACK
        delete temp;  // FREE THE MEMORY OF THE DELETED NODE
        cout << "VALUE: " << DeletedData << " POPPED" << endl;
        return DeletedData;
    }

    void displayList() {  // FUNCTION TO DISPLAY ALL ELEMENTS IN THE STACK
        Node* temp = HEAD;
        cout << "LIST DATA : ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackUisngLinkedList s1;

    s1.push(1);  // PUSH ELEMENTS ONTO THE STACK
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);

    cout << "---------------------------------------------------------" << endl;
    s1.displayList();  // DISPLAY THE ELEMENTS IN THE STACK
    cout << "---------------------------------------------------------" << endl;
    cout << "CURRENT LIST SIZE " << s1.get_ListSize() << endl;  // DISPLAY THE CURRENT SIZE OF THE STACK
    cout << "---------------------------------------------------------" << endl;
    cout << "POPPED DATA : " << endl;
    while (!s1.isEmpty()) {
        s1.pop();  // POP ELEMENTS FROM THE STACK UNTIL IT IS EMPTY
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "CURRENT LIST SIZE " << s1.get_ListSize() << endl;  // DISPLAY THE SIZE OF THE STACK AFTER POPPING ALL ELEMENTS
    return 0;
}
