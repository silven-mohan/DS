# Circular Doubly Linked List: Reversing the List

---

### Input: A circular doubly linked list CDLL with a header node and n nodes.
### Output: A CDLL whose nodes are arranged in reverse order, with all `prev` and `next` circular links correctly updated.

---

### Algorithm: reverse(header)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. curr := header -> next

    4. prevFirst := header -> next    // Remember original first node (becomes last after reversal)

    5. do

        5.1. temp := curr -> next     // Save old next

        5.2. curr -> next := curr -> prev    // Swap: next becomes prev

        5.3. curr -> prev := temp    // Swap: prev becomes old next

        5.4. curr := temp            // Advance using old next

    while curr != prevFirst

    6. header -> next := prevFirst -> prev    // After swap, prevFirst->prev = old last = new first

    7. print "The reversed list is: "

    8. Display the reversed list.

    9. stop

---
