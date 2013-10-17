Author
==========
"Zhong, Mingwei", zhongm2
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

1. add() works. By using linear probing.
2. remove() works. If no such an element to remove, throw an exception. 
Otherwise set inNULL to be false, isDel to be true because the slot used to have an element but it doesn't now.
3. find() works. If no such an element, throw an exception. Otherwise return the data.
4. grow() works. (Checkout details in my code).

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

keyExists will be better. Because return a pointer is very dangerous in C++.



#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I wrote my own hash function to test my program. I don't know how to find out
the hash function in this project.


