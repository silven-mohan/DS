# Doubly Linked List: Merge Two Lists

---

### Input: Two doubly linked lists — List1 (header1, n1 nodes) and List2 (header2, n2 nodes).
### Output: A third doubly linked list (header3) that is the concatenation of List1 followed by List2, with all `prev` and `next` links intact.

---

### Algorithm: merge(header1, header2, header3)

    1. if header1 -> next = NULL or header2 -> next = NULL then

        1.1. print "One or both lists are empty. Cannot merge!!"

        1.2. exit

    2. end if

    3. header3 -> next := header1 -> next

    4. temp := header3 -> next

    5. while temp -> next != NULL do

        5.1. temp := temp -> next

    6. end while

    7. h2First := header2 -> next

    8. temp -> next := h2First

    9. h2First -> prev := temp

    10. Display the merged list (header3).

    11. stop

---
