Author
==========
"Contini, Nick", continnd
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

1. All functions are not in theory O(1), for if you continually get collisions it will become a linear efficiency. However, since it is not practical to get so many collisions in a row, especially using jump, the functions in a real life setting are really constant.
2. Add uses jump rather than linear probing, but is definitely very quick in all situations where there aren't an unreasonable amount of collisions (which should rarely happen).
3. grow is definitely constant, since it has to readd every item from the old array to the new array, which definitely scales with the number of items.
4. I was sure to delete the old array in grow, as well as properly implementing the destructor.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

If you return the T*, then the object can be altered through undesirable methods. Using the implemented method, data is not altered that is meant to stay the same.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

It's very confusing how the provided has works, especially the part that uses NUM_HASH_PRIMES.