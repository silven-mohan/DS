# Circular Doubly Linked List: Merge Two Lists

---

### Input: Two circular doubly linked lists — List1 (header1, n1 nodes) and List2 (header2, n2 nodes).
### Output: A third circular doubly linked list (header3) that is the concatenation of List1 followed by List2, with all `prev`, `next`, and circular links intact.

---

### Algorithm: merge(header1, header2, header3)

    1. if header1 -> next = NULL or header2 -> next = NULL then

        1.1. print "One or both lists are empty. Cannot merge!!"

        1.2. exit

    2. end if

    3. first1 := header1 -> next       // First node of List1

    4. last1  := first1 -> prev        // Last node of List1 (CDL: first->prev = last)

    5. first2 := header2 -> next       // First node of List2

    6. last2  := first2 -> prev        // Last node of List2

    7. header3 -> next := first1       // header3 points to first node of merged list

    8. last1 -> next := first2         // Last of List1 links to first of List2

    9. first2 -> prev := last1         // First of List2 backward-links to last of List1

    10. last2 -> next := first1        // Last of List2 circularly links back to first of List1

    11. first1 -> prev := last2        // First of List1 backward-links to last of List2

    12. Display the merged list (header3).

    13. stop

---
