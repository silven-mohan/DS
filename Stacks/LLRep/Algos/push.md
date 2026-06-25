# Stack (Linked List Representation): Push Operation

---

### Input: A stack represented as a singly linked list with a `header` node and a `top` pointer node (whose `next` points to the current top element). An integer value to push.
### Output: A stack with the new item pushed as the new top element.

---

### Algorithm: PUSH(top, value)

    1. new := createNode(value)

    2. if new = NULL then

        2.1. print "Memory allocation failed!!"

        2.2. exit

    3. end if

    4. top -> next -> next := new    // Link old top node to the new node

    5. top -> next := new            // Update top pointer to new node

    6. print "Successfully pushed the item to the stack."

    7. stop

---
