# Deque (Array Representation): Enqueue Operations

---

### Input: A deque Q represented as a circular array of size MAX, integer indices FRONT and REAR. An item ITEM to insert.
### Output: The deque Q with ITEM inserted at either the REAR end (`enqueueREAR`) or the FRONT end (`enqueueFRONT`).

---

### Sub-Algorithm: enqueueREAR(Q, ITEM, FRONT, REAR, MAX)

    1. if (FRONT = 0 and REAR = MAX-1) or (FRONT = REAR+1) then

        1.1. print "Queue Overflow!!"

        1.2. exit

    2. end if

    3. if FRONT = -1 and REAR = -1 then

        3.1. FRONT := 0

        3.2. REAR := 0

    4. else if REAR = MAX - 1 then

        4.1. REAR := 0    // Wrap around

    5. else

        5.1. REAR := REAR + 1

    6. end if

    7. Q[REAR] := ITEM

    8. print "Successfully Enqueued the ITEM to the REAR."

    9. stop

---

### Sub-Algorithm: enqueueFRONT(Q, ITEM, FRONT, REAR, MAX)

    1. if (FRONT = 0 and REAR = MAX-1) or (FRONT = REAR+1) then

        1.1. print "Queue Overflow!!"

        1.2. exit

    2. end if

    3. if FRONT = -1 and REAR = -1 then

        3.1. FRONT := 0

        3.2. REAR := 0

    4. else if FRONT = 0 then

        4.1. FRONT := MAX - 1    // Wrap around to end of array

    5. else

        5.1. FRONT := FRONT - 1

    6. end if

    7. Q[FRONT] := ITEM

    8. print "Successfully Enqueued the ITEM to the FRONT."

    9. stop

---
