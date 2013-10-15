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

1. All of these return in constant speed, based on how many additional hashes are on the array
2. the key is hashed, then if that spot doesn't fit the next spot is found and checked.
3. grow relies on the number of spaces in the array
4. As far a I can tell, all objects are deleted

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

Yours is a better solution, mostly because users are stupid. Allowing the user to have access to the direct memory address could easily cause a memory failure.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I would tell students to start earlier than I did. Weekend jobs never go well. Especially on a 4 day weekend.