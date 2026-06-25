# Circular Singly Linked List: Reversing the List

---

### Input: A circular singly linked list CSLL with a header node and n nodes.
### Output: A circular singly linked list whose nodes are arranged in reverse order, maintaining the circular property.

---

### Algorithm: reverse(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. prev := NULL, curr := header -> next, next := NULL

    4. prevFirst := header -> next    // Remember original first node (will become the last)

    5. do

        5.1. next := curr -> next

        5.2. curr -> next := prev

        5.3. prev := curr

        5.4. curr := next

    while curr != header -> next

    6. header -> next := prev    // New first node is the old last node

    7. prevFirst -> next := header -> next    // Old first node now circles back to new first node

    8. print "The reversed list is: "

    9. Display the reversed list.

    10. stop

---
