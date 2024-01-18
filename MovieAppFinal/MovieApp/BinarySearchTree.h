#pragma once
#include "NodeBinaryTree.h"
class BinarySearchTree
{
public: 
    // Create a new Node
    NodeBinaryTree* createNode(CinemaHalls data);

    // Insert a Node in BST
    NodeBinaryTree* insertNode(NodeBinaryTree* root, CinemaHalls data);

    // Search a Node in BST
    NodeBinaryTree* searchNode(NodeBinaryTree* root, CinemaHalls data);

    // Find the minimum value Node in BST
    NodeBinaryTree* findMinNode(NodeBinaryTree* node);

    // Delete a Node from BST
    NodeBinaryTree* deleteNode(NodeBinaryTree* root, CinemaHalls data);

    // Inorder Traversal of BST
    void inorderTraversal(NodeBinaryTree* root);

    // Preorder Traversal of BST
    void preorderTraversal(NodeBinaryTree* root);

    // Postorder Traversal of BST
    void postorderTraversal(NodeBinaryTree* root);

}; 