# Circular Singly Linked List: Node Deletion

---

### Input: A circular singly linked list CSLL with a header node and n nodes (last node's `next` wraps back to the first node).
### Output: A circular singly linked list with a node deleted from the Front, a specific Position, or the End.

---

### Sub-Algorithm: deleteFront(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. temp := header -> next

    4. if temp -> next = temp then    // Only one node

        4.1. header -> next := NULL

        4.2. free(temp)

        4.3. return

    5. end if

    6. curr := header -> next

    7. while curr -> next != header -> next do

        7.1. curr := curr -> next

    8. end while

    9. header -> next := temp -> next

    10. curr -> next := header -> next    // Fix circular link

    11. free(temp)

    12. stop

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

    6. do

        6.1. prev := temp

        6.2. temp := temp -> next

        6.3. j := j + 1

    while temp -> next != header -> next and j < pos

    7. prev -> next := temp -> next

    8. free(temp)

    9. stop

---

### Sub-Algorithm: deleteEnd(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. return

    2. end if

    3. temp := header -> next, prev := NULL

    4. if temp -> next = temp then    // Only one node

        4.1. header -> next := NULL

        4.2. free(temp)

        4.3. return

    5. end if

    6. while temp -> next != header -> next do

        6.1. prev := temp

        6.2. temp := temp -> next

    7. end while

    8. prev -> next := header -> next    // New last node points to first node

    9. free(temp)

    10. stop

---
