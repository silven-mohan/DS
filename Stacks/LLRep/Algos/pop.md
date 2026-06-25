# Stack (Linked List Representation): Pop Operation

---

### Input: A stack represented as a singly linked list with a `header` node and a `top` pointer node. The list holds elements from `header -> next` to the top.
### Output: A stack with the topmost item removed.

---

### Algorithm: POP(header, top)

    1. if header -> next = NULL then

        1.1. print "Stack is empty! Can't pop!!"

        1.2. exit

    2. end if

    3. temp := header -> next, prev := NULL

    4. while temp -> next != NULL do

        4.1. prev := temp

        4.2. temp := temp -> next

    5. end while

    6. top -> next := prev        // Update top pointer to the new top node

    7. if prev != NULL then

        7.1. prev -> next := NULL

    8. else

        8.1. header -> next := NULL    // Stack is now empty

    9. end if

    10. free(temp)

    11. print "Successfully popped an element from the stack."

    12. stop

---
