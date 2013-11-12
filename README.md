Author
==========
"Griffith, David", griffid5
05_Hashing_Lab
==============

Implement a hash table in C++

Requirements
------------

1. `keyExists`, `find`, `remove`, and `size` should all be O(1)
2. `add` should be reasonably fast. Use linear probing to find an open slot in the hash table. This will be O(1), on average, except when `grow` is called.
3. `grow` should be O(n)
4. Do not leak memory


Reading
=======
"Open Data Structures," Chapter 5, except for 5.2.3. http://opendatastructures.org/ods-cpp/5_Hash_Tables.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. All of these methods work since they passed all of Dr. Brinkman's test cases in which he calls each method. We know that size is constant time for sure since we just call numItems. Since we are using an array for the implementation of the hashtable we know that the 3 other methods will be
constant time as well, since we are primarily searching by using key k. 
2. The add method works properly since it only calls grow when the load factor becomes more than 1/2. Since we are roughly doubling the size of the array we don't have
to call the grow method that often. Even when we need to call grow the worst case running time is linear which is still relatively fast. 
3. We are simply doubling the array size then adding each element into the new array which is where we get grow to be linear time.
4. As we have learned in class and past labs/projects by calling delete [] and not just delete we ensure that the whole array is deleted and that no
memory leak will occur. 

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think that the design Dr. Brinkman choose was the better of the two. I believe this because we throw an exception instead of simply returning null which doesn't tell the user/programmer(s) anything without
them having to assume that the item was not there. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
One thing that I am still a little confused about is why we have to call: unsigned long hash(char c){ return 10*((unsigned long)c)%13; } HashTable<char,int> mySillyTable;