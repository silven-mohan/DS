# Binary Search

---

### Input: An array A[1...n] of elements in sorted order (ascending) of size n, and an element that is to be searched in that array.
### Output: The position of the key element if it is present in that array A[1...n].

### Steps:

    1. if n < 1 then 
        
        1.1. print "No elements for sorting!!"

        1.2. exit

    2. end if

    3. l := 0, u := n.
        
    4. while 1 <= u  then do
        
        4.1. mid = (l + u)/2.

        4.2. if A[mid] = key then 
            
            4.2.1. print "Element is found at positon {mid}."

            4.2.2. exit

        4.3. end if

        4.4. else
            
            4.4.1. if A[mid] < key then
                
                4.4.1.1. u := mid-1.

            4.4.2. end if.

            4.4.3. else

                    4.4.3.1. l := mid+1.

            4.4.4. end else.

        4.5. end else.

    5. end while.

    6. print "Element is not found in the array."

    7.  stop.

---
