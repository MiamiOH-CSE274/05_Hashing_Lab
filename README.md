Author
==========
"Proctor, Patrick", proctopj
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

1. All of these methods run in constant time as far as I can tell. Worst case scenario the first three end up in linear time if you seriously must hash through the entire table to get to 
   your desired key. Given the randomness nature of each individual hash, I suppose it is possible, but highly unlikely. O(1) is the mean result from extensive testing.

2. Oh please, double hashing, and the average time is a constant between 1 and 3 jumps.

3. I'm pretty sure this is running in linear time. items are only copied over once, though one could argue it's technically O(2n) because two operations must occur to copy over the data from
   one table to the other.

4. I'm 99% certain I have no memory leaks.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think this separated function, while cumbersome, fits more truly with the idea of data abstraction. The user could potentially distort the data if given access to a T*, regardless if it is NULL or not.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Take notes on the double hashing function in class. Don't forget like I did. Also, don't put this project off until the last few minutes. This one can warp your brain even more than the BinarySearchTree lab.