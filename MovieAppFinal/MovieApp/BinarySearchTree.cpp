#include "BinarySearchTree.h"

// Create a new Node
NodeBinaryTree* BinarySearchTree::createNode(CinemaHalls data) {
    NodeBinaryTree* newNode = new NodeBinaryTree();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a Node in BST
NodeBinaryTree* BinarySearchTree::insertNode(NodeBinaryTree* root, CinemaHalls data) {
    if (root == NULL)
        return createNode(data);

    if (data.number < root->data.number)
        root->left = insertNode(root->left, data);
    else if (data.number > root->data.number)
        root->right = insertNode(root->right, data);

    return root;
}

// Search a Node in BST
NodeBinaryTree* BinarySearchTree::searchNode(NodeBinaryTree* root, CinemaHalls data) {
    if (root == NULL || root->data.number == data.number)
        return root;

    if (data.number < root->data.number)
        return searchNode(root->left, data);

    return searchNode(root->right, data);
}

// Find the minimum value Node in BST
NodeBinaryTree* BinarySearchTree::findMinNode(NodeBinaryTree* node) {
    NodeBinaryTree* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a Node from BST
NodeBinaryTree* BinarySearchTree::deleteNode(NodeBinaryTree* root, CinemaHalls data) {
    if (root == nullptr)
        return root;

    if (data.number < root->data.number)
        root->left = deleteNode(root->left, data);
    else if (data.number > root->data.number)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr) {
            NodeBinaryTree* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            NodeBinaryTree* temp = root->left;
            delete root;
            return temp;
        }

        NodeBinaryTree* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder Traversal of BST
void BinarySearchTree::inorderTraversal(NodeBinaryTree* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data.number << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal of BST
void BinarySearchTree::preorderTraversal(NodeBinaryTree* root) {
    if (root == nullptr)
        return;

    cout << root->data.number << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal of BST
void BinarySearchTree::postorderTraversal(NodeBinaryTree* root) {
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data.number << " ";
}
