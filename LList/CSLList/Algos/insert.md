# Circular Singly Linked List: Node Insertion

---

### Input: A circular singly linked list CSLL with a header node, n nodes (last node's `next` points back to the first node), and an integer value to insert.
### Output: A circular singly linked list with the new node inserted at the Front, a specific Position, or the End.

---

### Sub-Algorithm: insertFront(header, new)

    1. temp := header -> next

    2. header -> next := new

    3. new -> next := temp

    4. Traverse from new -> next until the node whose next = temp (old first node).

    5. last -> next := header -> next    // Re-link last node to the new front

    6. stop

---

### Sub-Algorithm: insertEnd(header, new)

    1. temp := header -> next

    2. do

        2.1. temp := temp -> next

    while temp -> next != header -> next

    3. temp -> next := new

    4. new -> next := header -> next    // New last node points back to first node

    5. stop

---

### Sub-Algorithm: insertPos(header, new, pos, n)

    1. if pos < 0 or pos > n+1 then

        1.1. print "Cannot insert at that position."

        1.2. return

    2. end if

    3. if pos = 0 then

        3.1. call insertFront(header, new)

        3.2. return

    4. end if

    5. if pos = n+1 then

        5.1. call insertEnd(header, new)

        5.2. return

    6. end if

    7. temp := header -> next, prev := NULL, j := 0

    8. while temp -> next != header -> next and j < pos do

        8.1. prev := temp

        8.2. temp := temp -> next

        8.3. j := j + 1

    9. end while

    10. prev -> next := new

    11. new -> next := temp

    12. stop

---
