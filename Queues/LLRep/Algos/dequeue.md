# Queue (Linked List Representation): Dequeue Operation

---

### Input: A queue represented as a singly linked list with a dummy `FRONT` header node and a dummy `REAR` pointer node. The first data node is `FRONT -> next`.
### Output: The queue with the FRONT element removed.

---

### Algorithm: dequeue(FRONT)

    1. if FRONT -> next = NULL then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. last := FRONT -> next          // last = node to be removed (current front element)

    4. FRONT -> next := last -> next  // Advance FRONT to the next element

    5. if FRONT -> next = NULL then

        5.1. REAR -> next := NULL     // Queue is now empty; reset REAR too

    6. end if

    7. free(last)

    8. print "Successfully Dequeued a member from the queue."

    9. stop

---
