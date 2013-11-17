Author
==========
"Luo, Yu", luoy6
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


Running Time Analysis
======================


Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. keyExists, find, remove, and size are all O(1).
2. add is reasonably fast. I am using double probing. add would be O(1) except when grow is called. 
3. grow is O(n).
4. I am not leaking memory

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

During the process of doing the homework, I wished there is a lookup that returns a T*. However, the more I think about it, I think the 'keyExists' and 'find' would be a better choice. In an Uset, one data could be in multiple locations, thus each of them has different key. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I was confused with why there is a while loop inside the add and remove method. I understood that the while loop is for probing