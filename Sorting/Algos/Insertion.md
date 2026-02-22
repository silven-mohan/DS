# Insertion Sort

---

### Input: An array A[1...n] of unsorted elements of size n.
### Output: A sorted array A[1...n] such that A[1] <= A[2] <= ..... <= A[n].

### Steps:

    1. for i = 1 to n do

        1.1. key := A[i]

        1.2. j := i-1

        1.3. while j >= 0 and a[j] < key then do
            
            1.3.1. A[j+1] := A[j]
            
            1.3.2. j := j - 1

        1.4. end while
        
        1.5. A[j+1] := key

    2. end for
    
    3. stop

---
