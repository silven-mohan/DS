# Doubly Linked List: Reversing the List

---

### Input: A doubly linked list DLL with a header node and n nodes.
### Output: A doubly linked list whose nodes are arranged in reverse order with both `prev` and `next` links correctly updated.

---

### Algorithm: reverse(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. prev := NULL, curr := header -> next, next := NULL

    4. while curr != NULL do

        4.1. next := curr -> next

        4.2. curr -> next := prev

        4.3. curr -> prev := next

        4.4. prev := curr

        4.5. curr := next

    5. end while

    6. header -> next := prev

    7. print "The reversed list is: "

    8. Display the reversed list.

    9. stop

---
