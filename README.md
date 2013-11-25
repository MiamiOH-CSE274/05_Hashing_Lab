Author
==========
"Turner, Chace", turnerce
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

1. All seem to be working in O(1)
2. Add should be working in constant time without calling grow
3. Grow isn't working
4. There are no apparent memory leaks

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

Having only 'find' seemed better to me at first, since 'keyExists' calls 'find' anyway, and returns false if 'find' throws an exception.  But then I thought having 'find' return an object may be confusing.  You are getting a valid object T* as a return object, but you must then always check to see if T* is NULL.  Throwing an exception and using the 'keyExists' function seems like a slightly more safe way to lookup keys.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The most confusing part of the project is getting it to build after calling hash() in your .ipp file.  It says that the function is not visible.  I copied it into HashTable.ipp form main.cpp in order to get it working.