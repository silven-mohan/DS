# Queue (Linked List Representation): Enqueue Operation

---

### Input: A queue represented as a singly linked list with a dummy `FRONT` header node and a dummy `REAR` pointer node (whose `next` points to the current last element). An integer value ITEM to enqueue.
### Output: The queue with ITEM appended at the REAR end.

---

### Algorithm: enqueue(REAR, ITEM)

    1. new := createNode(ITEM)

    2. if new = NULL then

        2.1. print "Memory allocation failed!!"

        2.2. exit

    3. end if

    4. if REAR -> next = NULL and FRONT -> next = NULL then

        4.1. FRONT -> next := new    // Queue was empty; FRONT now points to the only node

        4.2. REAR -> next := new     // REAR also points to the only node

        4.3. stop

    5. end if

    6. temp := REAR -> next           // temp = current last data node

    7. temp -> next := new            // Link old last node to new node

    8. REAR -> next := new            // Update REAR pointer to the new last node

    9. print "Successfully Enqueued a member from the queue."

    10. stop

---
