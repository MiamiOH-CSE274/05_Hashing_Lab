Author
==========
"Mullins, Harrison", mullingh
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

1. All working and are O(1) based from examples in book
2. Working, used the linear probing technique from the book where we search t[i], t[(i+1)%t.length], t[(i+2)%t.length] and so on.
3. Working, I'm not sure if there is a way to do grow() without creating/copying to a new HashRecord but its a lot easier that way.  Also I made use of the hashPrimes list to ensure good hashtable sizes as suggested.
4. No memory leaks, I de-allocate the backingArray in the destructor and in grow I check if we have run out of memory before allocating any more memory

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I believe the design we used for our lab was the better option. Reason being is that by returning the value in find() we can throw a descriptive error message to tell the user exactly what happened.  Also pointers can cause issues if used incorrectly, so for both stupidity and security reasons it is safer to avoid the use of pointers and barely affect the running time by using our lab method format.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I think this topic needs to be covered a bit more in depth in the future.  For me, and I know a couple other students hashing was a little confusing and the different kinds of hashing techniques made stepping into this lab a little difficult.  But definitely suggest students look to the book for answers after understanding the concepts the book was very helpful.