# Circular Queue (Array Representation): Enqueue Operation

---

### Input: A circular queue Q represented as an array of size MAX, integer indices FRONT and REAR tracking boundaries, and an item ITEM to enqueue.
### Output: The circular queue Q with ITEM inserted at the next REAR position, wrapping around if necessary.

---

### Algorithm: enqueue(Q, ITEM, FRONT, REAR, MAX)

    1. if REAR = MAX - 1 then

        1.1. next := (REAR % MAX) + 1    // Compute wrapped-around next index

        1.2. if FRONT = next then

            1.2.1. print "Queue Overflow!!"

            1.2.2. exit

        1.3. else

            1.3.1. REAR := next

            1.3.2. Q[REAR] := ITEM

            1.3.3. print "Successfully Enqueued the ITEM."

            1.3.4. stop

        1.4. end if

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
