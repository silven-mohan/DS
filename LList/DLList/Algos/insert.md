# Doubly Linked List: Node Insertion

---

### Input: A doubly linked list DLL with a header node, n nodes (each with `prev` and `next` pointers), and an integer value to insert.
### Output: A doubly linked list with the new node inserted at the Front, a specific Position, or the End.

---

### Sub-Algorithm: insertFront(header, new)

    1. temp := header -> next

    2. header -> next := new

    3. new -> next := temp

    4. new -> prev := NULL

    5. stop

---

### Sub-Algorithm: insertEnd(header, new)

    1. temp := header -> next, prev := NULL

    2. while temp -> next != NULL do

        2.1. prev := temp

        2.2. temp := temp -> next

    3. end while

    4. temp -> next := new

    5. new -> next := NULL

    6. new -> prev := temp

    7. stop

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
