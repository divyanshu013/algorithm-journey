/*******************************************************************************

BT to CLL
=========

Ref - http://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/

--------------------------------------------------------------------------------

Problem
=======
1) Write a general purpose function that concatenates two given circular doubly lists (This function is explained below).
2) Now traverse the given tree
  a) Recursively convert left subtree to a circular DLL. Let the converted list be leftList.
  b) Recursively convert right subtree to a circular DLL. Let the converted list be rightList.
  c) Make a circular linked list of root of the tree, make left and right of root to point to itself.
  d) Concatenate leftList with list of single root node.
  e) Concatenate the list produced in step above (d) with rightList.

--------------------------------------------------------------------------------

Time Complexity
===============
O(n)

--------------------------------------------------------------------------------

Output
======
10 -> 20 -> 30 -> 40 -> 50 

*******************************************************************************/

#include <stdio.h>

struct Node {
  int data;
  Node *left;
  Node *right;
};

struct Node * getNode(int data)  {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void printList(Node *head)  {
  Node *temp = head;
  do {
      printf("%d -> ", temp->data);
      temp = temp->right;
  } while(temp != head);
  printf("\b\b\b   \n");
}

struct Node * concatenate(Node *leftList, Node *rightList)  {
  // if either list is empty return the other
  if(!leftList)
    return rightList;
  if(!rightList)
    return leftList;

  Node *leftLast = leftList->left;
  Node *rightLast = rightList->left;

  leftLast->right = rightList;
  rightList->left = leftLast;
  rightLast->right = leftList;
  leftList->left = rightLast;

  return leftList;
}

struct Node * toCLL(Node *root) {
  if(root)  {
    Node *left = toCLL(root->left);
    Node *right = toCLL(root->right);

    root->left = root->right = root;
    return concatenate(concatenate(left, root), right);
  }

  return root;  // if NULL
}

int main()  {

  /* BST
           40
           /    \
        20      50
       /  \
      10   30           */

  Node *root = getNode(40);
  root->left = getNode(20);
  root->right = getNode(50);
  root->left->left = getNode(10);
  root->left->right = getNode(30);

  root = toCLL(root);
  printList(root);
  return 0;
}
