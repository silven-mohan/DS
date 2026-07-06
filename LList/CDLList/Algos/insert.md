# Circular Doubly Linked List: Node Insertion

---

### Input: A circular doubly linked list CDLL with a header node, n nodes (each with `prev` and `next`, last node's `next` = first node, first node's `prev` = last node), and an integer value to insert.
### Output: A CDLL with the new node inserted at the Front, a specific Position, or the End.

---

### Sub-Algorithm: insertFront(header, new)

    1. temp := header -> next           // temp = current first node

    2. last := temp -> prev             // last = current last node (CDL: first->prev = last)

    3. header -> next := new            // header now points to new node

    4. new -> next := temp              // new node's next = old first

    5. new -> prev := NULL              // new node has no predecessor at the front

    6. last -> next := header -> next   // last node's next updated to new front

    7. stop

---

### Sub-Algorithm: insertEnd(header, new)

    1. temp := header -> next           // temp = first node

    2. while temp -> next != header -> next do

        2.1. temp := temp -> next

    3. end while

    4. temp -> next := new              // Old last node's next = new node

    5. new -> next := header -> next    // New last node's next = first node (circular)

    6. new -> prev := temp             // New last node's prev = old last

    7. header -> next -> prev := new   // First node's prev = new last node

    8. stop

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

    8. while temp != NULL and j < pos do

        8.1. prev := temp

        8.2. temp := temp -> next

        8.3. j := j + 1

    9. end while

    10. prev -> next := new

    11. new -> next := temp

    12. new -> prev := prev

    13. if temp != NULL then

        13.1. temp -> prev := new

    14. end if

    15. stop

---
