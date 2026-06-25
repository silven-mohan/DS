# Circular Singly Linked List: Modify a Node's Value

---

### Input: A circular singly linked list CSLL with a header node, n nodes, a position `pos` (0-indexed), and a new value `newValue`.
### Output: A circular singly linked list with the node at position `pos` updated to `newValue`.

---

### Algorithm: modify(header, n, pos, newValue)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. if pos < 0 or pos >= n then

        3.1. print "Position of the node is out of bounds. Can't Access!!"

        3.2. exit

    4. end if

    5. temp := header -> next, i := 0

    6. do

        6.1. if i = pos then

            6.1.1. temp -> data := newValue

            6.1.2. print "Successfully modified the node."

            6.1.3. exit

        6.2. end if

        6.3. i := i + 1

        6.4. temp := temp -> next

    while temp != header -> next

    7. Display the modified list.

    8. stop

---
