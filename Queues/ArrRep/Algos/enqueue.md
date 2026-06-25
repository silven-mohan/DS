# Queue (Array Representation): Enqueue Operation

---

### Input: A queue Q represented as an array of size MAX, indices FRONT and REAR tracking the boundaries, and an item ITEM to enqueue.
### Output: The queue Q with ITEM inserted at the REAR position.

---

### Algorithm: enqueue(Q, ITEM, FRONT, REAR, MAX)

    1. if REAR = MAX - 1 then

        1.1. print "Queue Overflow!!"

        1.2. exit

    2. end if

    3. if FRONT = -1 and REAR = -1 then

        3.1. FRONT := 0

        3.2. REAR := 0

        3.3. Q[REAR] := ITEM

    4. else

        4.1. REAR := REAR + 1

        4.2. Q[REAR] := ITEM

    5. end if

    6. print "Successfully Enqueued the ITEM to the Queue."

    7. stop

---
