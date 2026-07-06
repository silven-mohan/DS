# Deque (Array Representation): Dequeue Operations

---

### Input: A deque Q represented as a circular array of size MAX, with integer indices FRONT and REAR.
### Output: The deque Q with an element removed from either the FRONT end (`dequeueFRONT`) or the REAR end (`dequeueREAR`).

---

### Sub-Algorithm: dequeueFRONT(Q, FRONT, REAR, MAX)

    1. if FRONT = -1 and REAR = -1 then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. if FRONT = REAR then

        3.1. FRONT := -1

        3.2. REAR := -1    // Queue becomes empty

    4. else if FRONT > REAR then

        4.1. FRONT := 0    // Wrap around: FRONT was at end, move to start

    5. else

        5.1. FRONT := FRONT + 1

    6. end if

    7. print "Successfully Dequeued an element from the FRONT."

    8. stop

---

### Sub-Algorithm: dequeueREAR(Q, FRONT, REAR, MAX)

    1. if FRONT = -1 and REAR = -1 then

        1.1. print "Queue Underflow!!"

        1.2. exit

    2. end if

    3. if FRONT = REAR then

        3.1. FRONT := -1

        3.2. REAR := -1    // Queue becomes empty

    4. else if REAR = 0 then

        4.1. REAR := MAX - 1    // Wrap around: REAR was at start, move to end

    5. else

        5.1. REAR := REAR - 1

    6. end if

    7. print "Successfully Dequeued an element from the REAR."

    8. stop

---
