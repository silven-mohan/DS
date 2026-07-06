# Circular Queue (Linked List Representation): Enqueue Operation

---

### Input: A circular queue represented as a singly linked list (last node's `next` points back to first node) with a dummy `FRONT` header node and a dummy `REAR` pointer node. An integer value ITEM to enqueue.
### Output: The circular queue with ITEM appended at the REAR end, maintaining the circular link.

---

### Algorithm: enqueue(REAR, ITEM)

    1. new := createNode(ITEM)

    2. if new = NULL then

        2.1. print "Memory allocation failed!!"

        2.2. exit

    3. end if

    4. if REAR -> next = NULL and FRONT -> next = NULL then

        4.1. FRONT -> next := new    // FRONT points to the only node

        4.2. REAR -> next := new     // REAR points to the only node

        4.3. new -> next := new      // Single-node circular link (points to itself)

        4.4. stop

    5. end if

    6. temp := REAR -> next           // temp = current last data node

    7. temp -> next := new            // Link old last node to new node

    8. new -> next := FRONT -> next   // New node's next points to first data node (circular link)

    9. REAR -> next := new            // Update REAR pointer to new last node

    10. print "Successfully Enqueued a member from the queue."

    11. stop

---
