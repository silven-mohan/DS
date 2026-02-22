# Selection Sort

---

### Input: An array A[1...n] with unsorted elements of size of n.
### Output: A sorted array A[1...n] such that A[1] <= A[2] <= ....... <= A[n].

### Steps:

    1. if n < 1 then 

        1.1. print "No elements for sorting!!"

        1.2. exit

    2. for i=1 to n do
        
        2.1. min_index = i

        2.2. for j = i+1 to n then do

            2.2.1. if A[j] < A[min_index] then

                2.2.1.1. min_index = j

            2.2.2. exit
        
        2.3 end for
        
        2.4 swap(a[i], a[min_index])
        
    3. end for

    4. stop

---
    
