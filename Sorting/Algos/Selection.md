# Selection Sort

---

### Input: An array A[1...n] with unsorted elements of size of n.
### Output: A sorted array A[1...n] such that A[1] <= A[2] <= ....... <= A[n].

### Steps:

    1. if n < 1 then 

        1.1. print "No elements for sorting!!"

        1.2. exit

    2. end if

    3. for i=1 to n do
        
        3.1. min_index = i

        3.2. for j = i+1 to n then do

            3.2.1. if A[j] < A[min_index] then

                3.2.1.1. min_index = j

            3.2.2. exit
        
        3.3 end for
        
        3.4 swap(a[i], a[min_index])
        
    4. end for

    5. stop

---
    
