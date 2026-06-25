# Singly Linked List: Reversing the List

---

### Input: A singly linked list SLL with a header node and n nodes.
### Output: A singly linked list whose nodes are arranged in reverse order.

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

        4.3. prev := curr

        4.4. curr := next

    5. end while

    6. header -> next := prev

    7. print "The reversed list is: "

    8. Display the reversed list.

    9. stop

---
