Author
==========
"Decker, Benjamin", deckerbd
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

1. Fully-functional and performs at expected time.
2. ^
3. ^
4. No plumbing work needed, as there are no leaks.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

If you were to pass back a T*, you would be able to manipulate the "buckets" in the hash map, in addition to being given a pointer to the data in the hash map, enabling you to then edit these and other values, which can create a lot of errors and unexpected results.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Watch out for your use of == and =, because they might not give you compile errors, but instead runtime errors in which you have no idea what is wrong. Also, once I got past the second set of tests, for the third test (testing the grow() method), it seemed like my program would hang. Via using the debugger, it seemed to go in an endless loop in add() and the main.cpp, and I couldn't figure out why until I realized stepping through the debugger that the value for the backingArray's size never changed in grow, causing the errors. Basically, keep in mind what should and shouldn't change when entering and exiting a specific method.