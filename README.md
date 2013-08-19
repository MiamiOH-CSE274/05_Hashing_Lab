Author
==========
Andy Shear, shearar
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

1. Find, remove, and keyExists methods all take O(n) time.  They all use the hash(k) method from main to loop through the string to compute the correct hash value. 
2. Add method uses simple linear probing to find the next open slot if the current one is empty.  It calls grow if the array is full.
3. Grow takes O(n) time, as it loops through the list of primes, then through the backingArray to copy items to the new array.  Still having trouble with this method.
4. The destructor, remove and grow properly delete dynamically allocated memory.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

Using the keyExists in combination with find allows that item to be inspected as a part of the table, and not just the value its referencing had find returned a T*.  When it is inspected as a part of the table, the programmer can access other attributes such as isDel for that position.  The program already contains all necessary operations using just a key, so the reference to an item is unnecessary.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

How are we supposed to use add() in the grow method to create the new hash table array when there is not a reference to the array passed to add?  Add is set up to work with backingArray only.
