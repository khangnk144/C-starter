#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        left = nullptr;
        right = nullptr;
        value = val;
    }
};

class BinarySearchTree {
    Node* root;
    int countNode;
public:
    BinarySearchTree() {
        root = nullptr;
        countNode = 0;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (countNode == 0) {
            root = newNode;
        }
        else {
            Node* temp = root;
            while (true) {
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else if (newNode->value > temp->value) {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
                else {
                    // Value already exists in the tree, do nothing
                    delete newNode;
                    return;
                }
            }
        }
        countNode++;
    }

    void lookup(int value) {
        Node* temp = root;
        while (temp != nullptr) {
            if (value == temp->value) {
                cout << "Found." << endl;
                return;
            }
            else if (value < temp->value) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        cout << "Not found." << endl;
    }

    void remove(int value) {
        if (root == nullptr) {
            cout << "Nothing to remove." << endl;
            return;
        }
        Node* currentNode = root;
        Node* parentNode = nullptr;
        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            }
            else if (value > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            else {
                // Node to be deleted found

                // Case 1: No child
                if (currentNode->left == nullptr && currentNode->right == nullptr) {
                    if (parentNode == nullptr) {
                        root = nullptr;
                    }
                    else {
                        if (parentNode->left == currentNode) {
                            parentNode->left = nullptr;
                        }
                        else {
                            parentNode->right = nullptr;
                        }
                    }
                }
                // Case 2: No right child
                else if (currentNode->right == nullptr) {
                    if (parentNode == nullptr) {
                        root = currentNode->left;
                    }
                    else {
                        if (currentNode->value < parentNode->value) {
                            parentNode->left = currentNode->left;
                        }
                        else {
                            parentNode->right = currentNode->left;
                        }
                    }
                }
                // Case 3: No left child
                else if (currentNode->left == nullptr) {
                    if (parentNode == nullptr) {
                        root = currentNode->right;
                    }
                    else {
                        if (currentNode->value < parentNode->value) {
                            parentNode->left = currentNode->right;
                        }
                        else {
                            parentNode->right = currentNode->right;
                        }
                    }
                }
                // Case 4: Two children
                else {
                    // Find the smallest value in the right subtree (in-order successor)
                    Node* successor = currentNode->right;
                    Node* successorParent = currentNode;
                    while (successor->left != nullptr) {
                        successorParent = successor;
                        successor = successor->left;
                    }

                    // Replace current node's value with successor's value
                    currentNode->value = successor->value;

                    // Delete the successor node
                    if (successorParent->left == successor) {
                        successorParent->left = successor->right;
                    }
                    else {
                        successorParent->right = successor->right;
                    }

                    currentNode = successor;
                }
                delete currentNode;
                return;
            }
        }
    }

    void printTree() {
        if (root == nullptr) {
            return;
        }

        // Calculate the height of the tree
        int height = getHeight(root);

        // Use a queue to perform level-order traversal
        queue<Node*> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            int spaces = (1 << (height - level)) - 1; // Calculate initial spaces

            // Print leading spaces
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }

            while (levelSize > 0) {
                Node* node = q.front();
                q.pop();

                // Print node value
                if (node != nullptr) {
                    cout << node->value;
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    cout << " ";
                }

                // Print spaces between nodes
                for (int i = 0; i < (spaces * 2) + 1; i++) {
                    cout << " ";
                }

                levelSize--;
            }
            cout << endl;
            level++;
        }
    }

    // Helper function to calculate the height of the tree
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    ~BinarySearchTree() {
        // Destructor to free allocated memory
        destroyTree(root);
    }

private:
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinarySearchTree* tree = new BinarySearchTree;
    tree->insert(53);
    tree->insert(41);
    tree->insert(65);
    tree->insert(38);
    tree->insert(46);
    tree->insert(59);
    tree->insert(43);
    tree->insert(48);
    tree->insert(54);
    tree->insert(49);
    tree->remove(46);
    tree->printTree();
    delete tree; // Free allocated memory
    return 0;
}