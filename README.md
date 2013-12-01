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

1. WORKING
2. WORKING
3. WORKING
4. WORKING

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

For a public function, I think setting a pointer as the return type is risky sometimes, because, in that case, you'll give an access to the users so that they can manipulate your keyExists and find functions the way you do not expect. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Just a suggestion: Future students will probably be wrong with the running time of add(), because add() can be O(n) in the worst case if implemented with linear probing. So, please make sure they know why the running time of add() in real cases is not
O(n).    