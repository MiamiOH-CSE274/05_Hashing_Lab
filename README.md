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

1. add() works. By using linear probing. It is O(1).

2. remove() works. 

If no such element, do nothing.

Otherwise, set isNull to be false, isDel to be true.

Increment numRemoved and decrement numItems.

It is O(1).


3. find() works.
If no such an element, throw an exception. Otherwise return the data.
You should invoke keyExists() in this function. It is O(1).


4. grow() works. 

(1) Get a new prime size from hashPrimes.h.
 
(2) Creat a temporary array to store old hash table.

(3) Set new backingArraySize.

(4) Creat a new backingArray with new backingArraySize.

(5) Loop through old hash table and copy keys and data to new backingArray.

(6) Free temporary array.

(7) It is O(n).


5. KeyExists() works. Return bool by checking isNull and isDel.
It is O(1).


6. Size() works. 

return number of item. It is O(1).


7.My program doesn't leak memory.


#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

keyExists will be better. Because return a pointer is very dangerous in C++.


#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I was struggling how to invoke hash function. But I couldn't figure it out.
I then fixed my code according to TA's suggestion and code. 



