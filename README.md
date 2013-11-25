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
1. Add takes constant time O(1), unless it calls grow() method.
if the add method calls grow(), then the running time would be O(n).
The while loop takes constant time. This is because I am doing double
hashing with my method, so the chance of collisions in the while loop
is really low.Also, since I am using prime numbers for my my array size, and
I am keeping the load factor 
less than 1/2, When we call the grow function, 
we are doubling the array size from previous size. 
So every time when we call the grow function,  
it significantly reduce the possibility to call grow function again. 

2. Remove takes constant time O(1). Every line of code in the remove
method takes constant time, including the while loop. The reason is 
that I am doing double hashing with this method. So the chance of 
collision is really low. 

3. find takes constant time O(1). Here, I am assuming that the throw method
call takes constant time. I am also calling keyExists method from 
my class. I know that my keyExists method also takes constant time. 
The while loop in the method takes constant time because I am using
double hashing, so the chances of collision is really low. 

4. keyExists method takes constant time O(1). The while loop in the 
method takes constant time because I am suing double hashing, so
the chances of collision is really low. 

5. Size method takes constant time O(1). 

6. Grow method takes linear time O(n). When I grow my backingArray, 
I will have to copy the data from the old array to the new array. 
so the running time is depending on the number of items in my 
old backingArray n. 


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