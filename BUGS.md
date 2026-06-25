# BUGS.md — Bug Report

A consolidated record of all bugs found across the `ops/` source files.

---

## LList / SLList

---

### `ops/search.c` — Wrong Traversal Start & Last Node Skipped

**Location:** `search()` function.

**Bug 1 — Header node compared against key:**
The traversal pointer is initialized as `temp = header` (the dummy header node). The comparison `temp -> data == key` is then checked before advancing `temp`. This means the header node's uninitialized `data` field is compared against the search key, which is a logic error.

**Bug 2 — Last data node never checked:**
The loop condition is `while(temp -> next != NULL)`. Since the loop advances `temp` at the end of each iteration, the last actual data node (whose `next` is NULL) is never checked.

**Fix:**
```c
// Wrong:
temp = header;
while(temp -> next != NULL) { ... }

// Correct:
temp = header -> next;
while(temp != NULL) { ... }
```

---

### `ops/modify.c` — Off-by-One in Bounds Check & Inconsistent Indexing

**Location:** `modify()` function.

**Bug 1 — Off-by-one in upper bounds check:**
The condition `if(key < 1 || key >= n)` uses `>=` which excludes position `n` (the last valid node). The last node can never be modified.

**Bug 2 — Counter starts at 0 but position is 1-based:**
The traversal counter `i` starts at `0` and the match check is `if(i == key)`. This makes position `0` reach the first node, which conflicts with the 1-based position the user is asked to enter.

**Fix:**
```c
// Wrong:
if(key < 1 || key >= n) { ... }
int i = 0;

// Correct:
if(key < 1 || key > n) { ... }
int i = 1;
```

---

### `ops/insert.c` — No NULL Guard Before Traversal in `insertEnd()`

**Location:** `insertEnd()` function.

**Bug:** The function starts traversal with `temp = header -> next` and enters the while loop `while(temp -> next != NULL)` without first checking if the list is empty (`header -> next == NULL`). Calling `insertEnd()` on an empty list causes a NULL pointer dereference.

**Fix:**
```c
// Add before the while loop:
if(header -> next == NULL) {
    header -> next = new;
    new -> next = NULL;
    return 0;
}
```

---

## LList / DLList

---

### `ops/insert.c` — Missing `temp -> prev` Link in `insertPos()`

**Location:** `insertPos()` function.

**Bug:** After linking `new -> next = temp` (connecting the new node to the node at position `pos`), the code does not set `temp -> prev = new`. The forward `next` links are correct, but the backward `prev` link of the displaced node is left pointing to the old predecessor — breaking reverse traversal.

**Fix:**
```c
// After: new -> next = temp;
if(temp != NULL) {
    temp -> prev = new;
}
```

---

### `ops/delete.c` — NULL Dereference in `deletePos()` When Deleting Last Node

**Location:** `deletePos()` function.

**Bug:** After unlinking `temp` from the list (`prev -> next = temp -> next`), a local pointer `next` is set to `temp -> next` and then `next -> prev = prev` is executed unconditionally. If `temp` is the last node, `temp -> next` is NULL, so `next` is NULL, and `next -> prev` causes a NULL pointer dereference and crash.

**Fix:**
```c
// Wrong:
next = temp -> next;
next -> prev = prev;

// Correct:
if(temp -> next != NULL) {
    temp -> next -> prev = prev;
}
```

---

### `ops/search.c` — Same Bug as SLList `search.c`

**Location:** `search()` function.

**Bug:** Identical to the SLList search bug — traversal starts at `temp = header` instead of `temp = header -> next`, and the loop condition `while(temp -> next != NULL)` causes the last real node to be skipped.

**Fix:** Same as SLList — initialize `temp = header -> next` and use `while(temp != NULL)`.

---

### `ops/modify.c` — Same Bug as SLList `modify.c`

**Location:** `modify()` function.

**Bug:** Identical to the SLList modify bug — the bounds check `if(key < 1 || key >= n)` excludes the last node, and the counter `i` starts at `0` instead of `1`.

**Fix:** Same as SLList — change `>=` to `>` and initialize `i = 1`.

---

### `ops/reverse.c` — Wrong `prev` Pointer Assignment During Reversal

**Location:** `reverse()` function.

**Bug:** Inside the reversal loop, the code sets:
```c
curr -> prev = prev;
```
This sets `curr -> prev` to the **old predecessor** of `curr` in the original list — which is the same as what `curr -> prev` already was. It does not update the pointer to correctly reflect the reversed structure.

In a properly reversed DLL, after the loop body `curr -> next := prev`, the `curr -> prev` should point to `next` (the node that will become `curr`'s successor in the original list, which is now `curr`'s predecessor in the reversed list).

**Fix:**
```c
// Wrong:
curr -> prev = prev;

// Correct:
curr -> prev = next;
```

---

## LList / CSLList

---

### `ops/delete.c` — Bounds Check After Traversal in `deletePos()`

**Location:** `deletePos()` function.

**Bug:** The validation `if(pos < 0) { ... return 1; }` is placed **after** the do-while traversal loop. By the time the check runs, the loop has already advanced `prev` and `temp` pointers. A negative position is traversed before being rejected.

**Fix:** Move the bounds check to **before** the traversal loop:
```c
// Add before the do-while:
if(pos < 1) {
    printf("\nPosition out of range.\n");
    return 1;
}
```

---

### `ops/modify.c` — Last Node Unreachable in `modify()`

**Location:** `modify()` function.

**Bug:** The do-while loop condition is `while(temp -> next != header -> next)`. The loop exits when `temp` is the **second-to-last** node (because the next iteration would make `temp` the last node, but the condition is checked and found true, stopping the loop). This means the last node in the list can **never be reached** for modification even if the requested position is valid.

**Fix:**
```c
// Wrong:
} while(temp -> next != header -> next);

// Correct:
} while(temp != header -> next);
```

---

### `ops/insert.c` — Fragile Last-Node Re-link in `insertFront()`

**Location:** `insertFront()` function.

**Bug:** After inserting the new node at the front, the code must re-link the old last node to point to the new front. It does so by traversing from the new front node looking for the node whose `next == new -> next` (the old first node). This traversal logic is confusing and breaks on a single-node list, where the old first node points to itself. The do-while loop condition may not terminate correctly.

**Fix:** Find the last node **before** performing the insertion:
```c
// Find the tail first:
struct node *last = header -> next;
while(last -> next != header -> next) {
    last = last -> next;
}
// Then insert:
header -> next = new;
new -> next = temp;        // temp = old first
last -> next = header -> next;  // last node points to new front
```

---

## Stacks / LLRep

---

### `ops/push.c` — `malloc` Allocates Wrong Size

**Location:** `main()` function.

**Bug:** Both `top` and `header` are allocated with `malloc(sizeof(struct node*))`, which allocates memory for a **pointer** (typically 8 bytes on 64-bit systems) rather than for a full `struct node` (which includes `int data` + a pointer). Writing to `data` or `next` fields on an under-sized allocation causes **heap corruption and undefined behavior**.

**Fix:**
```c
// Wrong:
top    = malloc(sizeof(struct node*));
header = malloc(sizeof(struct node*));

// Correct:
top    = malloc(sizeof(struct node));
header = malloc(sizeof(struct node));
```

---

### `ops/pop.c` — `malloc` Wrong Size + NULL Dereference on Single-Element Stack

**Location:** `main()` function and `POP()` function.

**Bug 1 — Same `malloc` wrong size as `push.c`:**
Identical issue — `malloc(sizeof(struct node*))` instead of `malloc(sizeof(struct node))`.

**Bug 2 — NULL dereference when popping last element:**
In `POP()`, if the stack has only **one element**, the while loop body never executes (`temp -> next` is already NULL). So `prev` remains NULL. Then the code executes `top -> next = prev` (makes top point to NULL — acceptable) followed immediately by `prev -> next = NULL` — which dereferences NULL and crashes.

**Fix for Bug 2:**
```c
// Wrong:
top -> next = prev;
prev -> next = NULL;   // crashes if prev == NULL

// Correct:
top -> next = prev;
if(prev != NULL) {
    prev -> next = NULL;
} else {
    header -> next = NULL;  // stack is now empty
}
```

---

## Queues / ArrRep

---

### `ops/enqueue.c` & `ops/dequeue.c` — Typo in `createQ()` Success Message

**Location:** `createQ()` function (present in both files).

**Bug:** The success message is:
```c
printf("\nSuccessfully created he Queue.\n\n");
```
The word "the" is misspelled as "he".

**Fix:**
```c
printf("\nSuccessfully created the Queue.\n\n");
```

---
