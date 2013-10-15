Author
==========
"Monnin, Sebastian", monninse
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

1. KeyExists, find, remove, and size all work correctly
2. add words correctly
3. grow is O(n)
4. good to go

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think the design you picked makes it a lot easier and faster to lookup keys. Also returning the pointer T* would give users access to the memory which is usally not a good idea

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester One thing that really slowed me down was making the hash function work. Even the one you gave me didn't seem to work for some reason. So I just copied Hash() out of main.cpp and put it at the top of .ipp, this seemed to fix my problems. Over all I thought the hardest part was add, it was dificult for me to visualize. The advice I would give would be to start early and to do extra reading. Reading more about hash tables really helped me feel more confident in what I was coding and it make it easier and faster for me to do.

TODO
