# Doubly Linked List: Node Deletion

---

### Input: A doubly linked list DLL with a header node and n nodes (each with `prev` and `next` pointers).
### Output: A doubly linked list with a node deleted from the Front, a specific Position, or the End.

---

### Sub-Algorithm: deleteFront(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. temp := header -> next

    4. if temp -> next = NULL then

        4.1. header -> next := NULL

        4.2. free(temp)

        4.3. return

    5. end if

    6. header -> next := temp -> next

    7. free(temp)

    8. stop

---

### Sub-Algorithm: deletePos(header, pos)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. if pos < 1 then

        3.1. print "Position out of range."

        3.2. return

    4. end if

    5. temp := header -> next, prev := NULL, j := 0

    6. while temp != NULL and j < pos do

        6.1. prev := temp

        6.2. temp := temp -> next

        6.3. j := j + 1

    7. end while

    8. if temp = NULL then

        8.1. print "Position out of range."

        8.2. return

    9. end if

    10. prev -> next := temp -> next

    11. if temp -> next != NULL then

        11.1. temp -> next -> prev := prev

    12. end if

    13. free(temp)

    14. stop

---

### Sub-Algorithm: deleteEnd(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. temp := header -> next, prev := NULL

    4. if temp -> next = NULL then

        4.1. header -> next := NULL

        4.2. free(temp)

        4.3. return

    5. end if

    6. while temp -> next != NULL do

        6.1. prev := temp

        6.2. temp := temp -> next

    7. end while

    8. prev -> next := NULL

    9. free(temp)

    10. stop

---
