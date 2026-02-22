# Insertion Sort

---

### Input: An array A[1...n] of unsorted elements of size n.
### Output: A sorted array A[1...n] such that A[1] <= A[2] <= ..... <= A[n].

### Steps:

    1. if n < 1 then 

        1.1. print "No elements for sorting!!"

        1.2 exit

    2. end if

    3. for i = 1 to n do

        3.1. key := A[i]

        3.2. j := i-1

        3.3. while j >= 0 and a[j] < key then do
            
            3.3.1. A[j+1] := A[j]
            
            3.3.2. j := j - 1

        3.4. end while
        
        3.5. A[j+1] := key

    4. end for
    
    5. stop

---
