#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation error!" << endl;
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
Node* insertNode(Node* current, int value) {
    if (current == NULL) {
        // If the tree is empty, create a new node and set it as the root
        return createNode(value);
    }
    if (value < current->data) {
        // If the value is less than the root's data, insert it in the left subtree
        current->left = insertNode(current->left, value);
    } else if (value > current->data) {
        // If the value is greater than the root's data, insert it in the right subtree
        current->right = insertNode(current->right, value);
    }
    // If the value is equal to the root's data, ignore it (duplicate values not allowed)
    return current;
}

// Function to find the number of nodes in the longest path
int findHeight(Node* current) {
    if (current == NULL) {
        return 0;
    }
    int leftHeight = findHeight(current->left);
    int rightHeight = findHeight(current->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum data value in the tree
int findMinimum(Node* current) {
    if (current == NULL) {
        cout << "Error: Tree is empty!" << endl;
        return -1;
    }
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to swap the roles of left and right pointers at every node
Node* swapRoles(Node* current) {
    if (current == NULL) {
        return NULL;
    }
    Node* temp = current->left;
    current->left = swapRoles(current->right);
    current->right = swapRoles(temp);
    return current;
}

// Function to search for a value in the tree
bool searchValue(Node* current, int value) {
    if (current == NULL) {
        return false;
    }
    if (current->data == value) {
        return true;
    }
    if (value < current->data) {
        return searchValue(current->left, value);
    } else {
        return searchValue(current->right, value);
    }
}

// Function to print the binary search tree (inorder traversal)
void printTree(Node* current) {
    if (current != NULL) {
        printTree(current->left);
        cout << current->data << " ";
        printTree(current->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "------------------------" << endl;
        cout << "Binary Search Tree Menu" << endl;
        cout << "------------------------" << endl;
        cout << "1. Insert a new node" << endl;
        cout << "2. Find number of nodes in longest path" << endl;
        cout << "3. Find minimum data value" << endl;
        cout << "4. Swap roles of left and right pointers" << endl;
        cout << "5. Search for a value" << endl;
        cout << "6. Print the binary search tree" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Number of nodes in the longest path: " << findHeight(root) << endl;
                break;
            case 3:
                cout << "Minimum data value: " << findMinimum(root) << endl;
                break;
            case 4:
                root = swapRoles(root);
                cout << "Roles swapped successfully!" << endl;
                break;
            case 5:
                cout << "Enter the value to search for: ";
                cin >> value;
                if (searchValue(root, value)) {
                    cout << "Value found in the tree!" << endl;
                } else {
                    cout << "Value not found in the tree!" << endl;
                }
                break;
            case 6:
                cout << "Binary Search Tree: ";
                printTree(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
