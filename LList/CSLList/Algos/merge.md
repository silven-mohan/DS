# Circular Singly Linked List: Merge Two Lists

---

### Input: Two circular singly linked lists — List1 (header1, n1 nodes) and List2 (header2, n2 nodes).
### Output: A third circular singly linked list (header3) that is the concatenation of List1 followed by List2, maintaining the circular property.

---

### Algorithm: merge(header1, header2, header3)

    1. if header1 -> next = NULL or header2 -> next = NULL then

        1.1. print "One or both lists are empty. Cannot merge!!"

        1.2. exit

    2. end if

    3. header3 -> next := header1 -> next

    4. temp := header3 -> next

    5. do

        5.1. temp := temp -> next

    while temp -> next != header3 -> next    // Find last node of List1

    6. temp -> next := header2 -> next    // Link last of List1 to first of List2

    7. do

        7.1. temp := temp -> next

    while temp -> next != header2 -> next    // Find last node of List2

    8. temp -> next := header3 -> next    // Link last of List2 back to first of merged list

    9. Display the merged list (header3).

    10. stop

---
