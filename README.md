This repository contains data structure implementations in C, learned and written from the perspective of system software and embedded programming, not generic application-level programming.

The focus is on:
* Low-level memory behavior
* Heap vs stack allocation
* Pointer discipline
* Deterministic behavior
* Embedded/system-oriented use cases

This repo is meant for:
* Embedded firmware engineers
* System software developers
* Engineers preparing for low-level interviews
* Anyone learning Data Structures with C as a systems language

Goals of This Repository
* Implement core data structures from scratch in C
* Avoid STL / high-level abstractions
* Understand why and where each DS is used in real systems
* Emphasize:
  * Memory layout
  * Pointer manipulation
  * Time & space trade-offs
  * Constraints common in embedded systems
 
Course Content Covered

This repository follows the below learning sequence:

🔹 Basics
  * Introduction to Data Structures
  * List as an Abstract Data Type (ADT)
  * Arrays vs Linked Lists (system-level comparison)

🔹 Linked Lists
  * Singly Linked List
    * Insert (beginning, nth position)
    * Delete (nth position)
    * Reverse (iterative & recursive)
    * Print using recursion
  * Doubly Linked List
    * Implementation and traversal

🔹 Stack
* Stack ADT
* Array-based Stack
* Linked List-based Stack
* Applications:
  * String reversal
  * Linked list reversal
  * Balanced parentheses checking
  * Infix, Prefix, Postfix expressions
  * Expression evaluation

🔹 Queue
* Queue ADT
* Array implementation
* Linked List implementation

🔹 Trees
* Binary Tree
* Binary Search Tree (BST)
* BST implementation in C
* Memory allocation: stack vs heap
* Tree operations:
  * Min / Max
  * Height
  * Level order traversal
  * DFS (Preorder, Inorder, Postorder)
  * BST validation
  * Node deletion
  * Inorder successor

🔹 Graphs
* Introduction to Graphs
* Graph properties
* Graph representations:
  * Edge List
  * Adjacency Matrix
  * Adjacency List
