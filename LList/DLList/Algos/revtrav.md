# Doubly Linked List: Reverse (Backward) Traversal

---

### Input: A doubly linked list DLL with a header node and n nodes, each having a `prev` pointer.
### Output: The nodes of the list printed in reverse order using the `prev` links.

---

### Algorithm: reverseTraverse(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. temp := header -> next

    4. while temp -> next != NULL do

        4.1. temp := temp -> next

    5. end while

    6. lastNode := temp

    7. while lastNode != NULL do

        7.1. print lastNode -> data

        7.2. lastNode := lastNode -> prev

    8. end while

    9. stop

---
