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

1. `keyExists`, `find`, `remove`, and `size` all be O(1)
2. add uses linear probing (double hashing)
3. grow is O(n) as we have to loop through and add again to new array.
4. does not leak memory.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/
I prefer the method we used as T* can be used to directly change the memory. Seeing as this is our first time working with a hashtable I prefer not having to worry as much with pointers, bad access, ect. 


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

So are hashtables terrible for data where you will be deleting and adding frequently?
