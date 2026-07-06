# Deque (Linked List Representation): Dequeue Operations

---

### Input: A deque represented as a doubly linked list (each node has `next` and `prev`) with a dummy `FRONT` header node and a dummy `REAR` pointer node.
### Output: The deque with an element removed from either the FRONT end (`dequeueFRONT`) or the REAR end (`dequeueREAR`).

---

### Sub-Algorithm: dequeueFRONT(FRONT)

    1. if FRONT -> next = NULL then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. last := FRONT -> next           // last = node to be removed (current front element)

    4. FRONT -> next := last -> next   // Advance FRONT to the next element

    5. if FRONT -> next != NULL then

        5.1. FRONT -> next -> prev := NULL    // Clear the new front's backward link

    6. end if

    7. if FRONT -> next = NULL then

        7.1. REAR -> next := NULL    // Queue is now empty; reset REAR

    8. end if

    9. free(last)

    10. print "Successfully Dequeued a member from the queue."

    11. stop

---

### Sub-Algorithm: dequeueREAR(REAR)

    1. if FRONT -> next = NULL then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. last := REAR -> next            // last = node to be removed (current last element)

    4. REAR -> next := last -> prev    // Move REAR back to the previous node

    5. if REAR -> next != NULL then

        5.1. REAR -> next -> next := NULL    // Sever the removed node from the list

    6. end if

    7. if REAR -> next = NULL then

        7.1. FRONT -> next := NULL    // Queue is now empty; reset FRONT

    8. end if

    9. free(last)

    10. print "Successfully Dequeued a member from the queue."

    11. stop

---
