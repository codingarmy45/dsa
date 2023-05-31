#include <iostream>
using namespace std;

// Structure for a node in the book tree
struct Node {
    string title;
    Node* firstchild;
    Node* nextsibling;
};

// Function to create a new node
Node* createNode(string title) {
    Node* newNode = new Node();
    newNode->title = title;
    newNode->firstchild = NULL;
    newNode->nextsibling = NULL;
    return newNode;
}

// Function to add a child node to a parent node
void addChild(Node* parent, Node* child) {
    if (parent->firstchild == NULL) {
        parent->firstchild = child;
    } else {
        Node* sibling = parent->firstchild;
        while (sibling->nextsibling != NULL) {
            sibling = sibling->nextsibling;
        }
        sibling->nextsibling = child;
    }
}

// Function to perform an in-order traversal of the book tree
void printNodes(Node* node) {
    if (node == NULL) {
        return;
    }

    cout << node->title << endl;
    printNodes(node->firstchild);
    printNodes(node->nextsibling);
}

// Function to display the menu options
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add chapter" << endl;
    cout << "2. Add section" << endl;
    cout << "3. Add subsection" << endl;
    cout << "4. Print nodes" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Node* book = createNode("Book");
    Node* current = book;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string chapterTitle;
                cout << "Enter chapter title: ";
                cin.ignore();
                getline(cin, chapterTitle);

                Node* chapter = createNode(chapterTitle);
                addChild(current, chapter);
                current = chapter;
                break;
            }
            case 2: {
                string sectionTitle;
                cout << "Enter section title: ";
                cin.ignore();
                getline(cin, sectionTitle);

                Node* section = createNode(sectionTitle);
                addChild(current, section);
                current = section;
                break;
            }
            case 3: {
                string subsectionTitle;
                cout << "Enter subsection title: ";
                cin.ignore();
                getline(cin, subsectionTitle);

                Node* subsection = createNode(subsectionTitle);
                addChild(current, subsection);
                break;
            }
            case 4: {
                cout << "Nodes of the book tree:" << endl;
                printNodes(book);
                break;
            }
            case 5: {
                cout << "Exiting the program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}
