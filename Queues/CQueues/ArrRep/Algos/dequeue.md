# Circular Queue (Array Representation): Dequeue Operation

---

### Input: A circular queue Q represented as an array of size MAX, with integer indices FRONT and REAR.
### Output: The circular queue Q with the element at FRONT removed, advancing FRONT circularly.

---

### Algorithm: dequeue(Q, FRONT, REAR, MAX)

    1. if FRONT = -1 and REAR = -1 then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. if FRONT = REAR then

        3.1. FRONT := -1

        3.2. REAR := -1    // Queue becomes empty

    4. else

        4.1. FRONT := (FRONT % MAX) + 1    // Advance FRONT circularly

    5. end if

    6. print "Successfully Dequeued from the Queue."

    7. stop

---
