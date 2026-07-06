# Circular Doubly Linked List: Node Deletion

---

### Input: A circular doubly linked list CDLL with a header node and n nodes (each with `prev` and `next`, circular links maintained).
### Output: A CDLL with a node deleted from the Front, a specific Position, or the End.

---

### Sub-Algorithm: deleteFront(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. temp := header -> next           // temp = node to delete (current front)

    4. if temp -> next = temp then      // Only one node

        4.1. header -> next := NULL

        4.2. free(temp)

        4.3. return

    5. end if

    6. last := temp -> prev             // last = last node (CDL: first->prev = last)

    7. header -> next := temp -> next   // Advance front to second node

    8. header -> next -> prev := last   // New front's prev = last node

    9. last -> next := header -> next   // Last node's next = new front

    10. free(temp)

    11. stop

---

### Sub-Algorithm: deletePos(header, pos)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. if pos < 1 or pos > n then

        3.1. print "Position out of bounds."

        3.2. return

    4. end if

    5. temp := header -> next, prev := NULL, j := 0

    6. do

        6.1. prev := temp

        6.2. temp := temp -> next

        6.3. j := j + 1

    while temp -> next != header -> next and j < pos

    7. prev -> next := temp -> next      // Unlink temp

    8. temp -> next -> prev := prev      // Fix backward link of successor

    9. free(temp)

    10. stop

---

### Sub-Algorithm: deleteEnd(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. temp := header -> next

    4. if temp -> next = temp then      // Only one node

        4.1. header -> next := NULL

        4.2. free(temp)

        4.3. return

    5. end if

    6. last := temp -> prev             // CDL: first->prev = last node

    7. secondLast := last -> prev

    8. secondLast -> next := header -> next    // New last node's next = first node

    9. header -> next -> prev := secondLast    // First node's prev = new last node

    10. free(last)

    11. stop

---
