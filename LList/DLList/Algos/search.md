# Doubly Linked List: Linear Search

---

### Input: A doubly linked list DLL with a header node, n nodes, and a key element to be searched.
### Output: The position of the key element in the list, if found. Otherwise, a message indicating it was not found.

---

### Algorithm: search(header, key)

    1. if header -> next = NULL then

        1.1. print "The list is empty!!"

        1.2. exit

    2. end if

    3. temp := header -> next, i := 0

    4. while temp != NULL do

        4.1. if temp -> data = key then

            4.1.1. print "key is found at position i."

            4.1.2. exit

        4.2. end if

        4.3. i := i + 1

        4.4. temp := temp -> next

    5. end while

    6. print "Element was not found."

    7. stop

---
