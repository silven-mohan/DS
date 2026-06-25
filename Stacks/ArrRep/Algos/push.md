# Stack (Array Representation): Push Operation

---

### Input: A stack STK represented as an array of size `size`, a `top` index tracking the number of elements, and an item to push.
### Output: The stack STK with the new item pushed onto the top.

---

### Algorithm: PUSH(STK, top, size, item)

    1. if top = size then

        1.1. print "Stack is full! Can't push any item!!"

        1.2. exit

    2. end if

    3. STK[top] := item

    4. top := top + 1

    5. print "Successfully pushed the item to the stack."

    6. stop

---
