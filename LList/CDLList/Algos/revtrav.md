# Circular Doubly Linked List: Reverse (Backward) Traversal

---

### Input: A circular doubly linked list CDLL with a header node and n nodes, each having a `prev` pointer and circular links.
### Output: The nodes of the list printed in reverse order using the `prev` links, starting from the last node.

---

### Algorithm: reverseTraverse(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. lastNode := header -> next -> prev    // CDL: first node's prev = last node

    4. curr := lastNode

    5. do

        5.1. print curr -> data

        5.2. curr := curr -> prev

    while curr != lastNode

    6. stop

---
