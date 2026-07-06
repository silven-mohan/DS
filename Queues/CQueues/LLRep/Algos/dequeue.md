# Circular Queue (Linked List Representation): Dequeue Operation

---

### Input: A circular queue represented as a singly linked list (last node's `next` points to first node) with a dummy `FRONT` header and dummy `REAR` pointer node.
### Output: The circular queue with the FRONT element removed and the circular link updated.

---

### Algorithm: dequeue(FRONT)

    1. if FRONT -> next = NULL then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. last := FRONT -> next    // last = node to be removed (current front element)

    4. if last -> next != last then    // More than one element

        4.1. FRONT -> next := last -> next    // Advance FRONT to the next element

    5. else

        5.1. FRONT -> next := NULL    // Queue has only one element; now empty

    6. end if

    7. if FRONT -> next = NULL then

        7.1. REAR -> next := NULL     // Reset REAR since queue is now empty

    8. else

        8.1. temp := FRONT -> next

        8.2. while temp -> next != last do    // Find the new last node

            8.2.1. temp := temp -> next

        8.3. end while

        8.4. temp -> next := FRONT -> next    // Re-link new last node to new front (circular)

    9. end if

    10. free(last)

    11. print "Successfully Dequeued a member from the queue."

    12. stop

---
