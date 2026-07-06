# Deque (Linked List Representation): Enqueue Operations

---

### Input: A deque represented as a doubly linked list (each node has `next` and `prev`) with a dummy `FRONT` header node and a dummy `REAR` pointer node. An integer value ITEM to insert.
### Output: The deque with ITEM inserted at either the REAR end (`enqueueREAR`) or the FRONT end (`enqueueFRONT`).

---

### Sub-Algorithm: enqueueREAR(REAR, ITEM)

    1. new := createNode(ITEM)

    2. if new = NULL then

        2.1. print "Memory allocation failed!!"

        2.2. exit

    3. end if

    4. if REAR -> next = NULL and FRONT -> next = NULL then

        4.1. FRONT -> next := new    // Queue was empty

        4.2. REAR -> next := new

        4.3. stop

    5. end if

    6. temp := REAR -> next           // temp = current last data node

    7. temp -> next := new            // Link old last node to new node

    8. REAR -> next := new            // Update REAR pointer to new last node

    9. print "Successfully Enqueued a member to the REAR position of the queue."

    10. stop

---

### Sub-Algorithm: enqueueFRONT(FRONT, ITEM)

    1. new := createNode(ITEM)

    2. if new = NULL then

        2.1. print "Memory allocation failed!!"

        2.2. exit

    3. end if

    4. if REAR -> next = NULL and FRONT -> next = NULL then

        4.1. FRONT -> next := new    // Queue was empty

        4.2. REAR -> next := new

        4.3. stop

    5. end if

    6. temp := FRONT -> next          // temp = current first data node

    7. new -> next := temp            // new node's next points to old front element

    8. FRONT -> next := new           // Update FRONT to point to new node

    9. print "Successfully Enqueued a member to the FRONT position of the queue."

    10. stop

---
