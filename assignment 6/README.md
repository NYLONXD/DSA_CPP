# Assignment 6: Doubly and Circular Linked List

## Main Questions Only

### Q1: Menu-Driven DLL and CLL Operations
**File:** `q1_menu_driven_dll_cll.cpp`

Complete menu-driven program for both DLL and CLL:

**DLL Operations:**
- Insert first, last, before, after a node
- Delete a specific node (head, tail, or middle)
- Search for a node
- Display in forward direction

**CLL Operations:**
- Insert first, last, before, after a node
- Delete a specific node (head, tail, or middle)
- Search for a node
- Display with circular connection

Compile: `g++ q1_menu_driven_dll_cll.cpp -o q1`
Run: `./q1`

---

### Q2: Display Circular Linked List
**File:** `q2_display_cll.cpp`

Display all node values in a circular linked list, repeating head node at the end.

Input: 20 → 100 → 40 → 80 → 60
Output: 20 100 40 80 60 20.

---

### Q3: Find Size of DLL and CLL
**File:** `q3_find_size.cpp`

Find the size (number of nodes) for both Doubly Linked List and Circular Linked List.

Features:
- DLL: Traverse forward and count nodes
- CLL: Count nodes until reaching head again

Example output:
- Size of DLL: 4
- Size of CLL: 5

---

### Q4: Check if DLL is Palindrome
**File:** `q4_dll_palindrome.cpp`

Check if a doubly linked list of characters is a palindrome.

Example 1:
- Input: L <-> E <-> V <-> E <-> L
- Output: True

Example 2:
- Input: A <-> B <-> C <-> D
- Output: False

Algorithm: Use two pointers from head and tail, compare until they meet.

---

### Q5: Check if Linked List is Circular
**File:** `q5_check_circular.cpp`

Detect whether a linked list is circular using Floyd's cycle detection algorithm.

Example 1:
- Input: 2 -> 4 -> 6 -> 7 -> 5 -> 2 (circular)
- Output: True

Example 2:
- Input: 1 -> 3 -> 5 -> 7 -> 9 (linear)
- Output: False

Algorithm: Use slow and fast pointers. If they meet, list is circular.

---

## How to Compile and Run All Files

```bash
g++ q1_menu_driven_dll_cll.cpp -o q1 && ./q1
g++ q2_display_cll.cpp -o q2 && ./q2
g++ q3_find_size.cpp -o q3 && ./q3
g++ q4_dll_palindrome.cpp -o q4 && ./q4
g++ q5_check_circular.cpp -o q5 && ./q5
```

---

## Key Features

✓ No comments - clean, readable code
✓ Easy to understand logic
✓ Proper memory management with destructors
✓ Only main questions (no additional FAANG+ questions)
✓ Ready to compile and run
