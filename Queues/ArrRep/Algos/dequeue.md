# Queue (Array Representation): Dequeue Operation

---

### Input: A queue Q represented as an array, with FRONT and REAR indices.
### Output: The queue Q with the element at the FRONT position removed.

---

### Algorithm: dequeue(Q, FRONT, REAR)

    1. if FRONT = -1 and REAR = -1 then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. if FRONT = REAR then

        3.1. FRONT := -1

        3.2. REAR := -1    // Queue becomes empty

    4. else

        4.1. FRONT := FRONT + 1

    5. end if

    6. print "Successfully Dequeued from the Queue."

    7. stop

---
