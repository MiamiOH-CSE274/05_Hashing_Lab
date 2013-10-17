Author
==========
"Bailey, Sam", baileys2
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

1. These methods should all be in O(1) time.  keyExists, find and remove should all take constant time mainly because of the fact that the load factor will never exceed 1/2, meaning that only a certain amount of the locations in the total array will have to be checked.  Size, on the other hand, simply makes a call to a single variable, which is obviously constant in time.
2. The add method acts as it should.  It is usually constant time because it will only have to search through a portion of the slots in the arrray before finding an appropriate slot to fill (again, due to the load factor always being 1/2 at most). However, when grow is called the add method will take linear time.
3. The grow method also acts as fast as is to be expected.  This method takes linear time as opposed to constant time because the larger the overall array has to be, the more space it will require, and it takes an increasing amount of time to acquire more space and (more importantly) transfer a larger amount of data from the older, smaller array to the newer, larger one.
4. There should be no memory leakage, as a destructor has been implemented, and every time grow is called to create a larger array the older, smaller array is deleted.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I believe that the design you chose for this lab is more appropriate, as it eliminates the need for pointers in a large portion of the lab (which can lead to many mistakes and memory issues). It also helps to separate out the task of finding and validating information in any given array location, rather than having one larger method do everything.  This could potentially lead to accidental programming errors, which are never a good thing.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

One piece of advice I would give to future students is to stress the importance of setting up the project correctly with the constructor and destructor.  By doing this correctly, looking at all the different files to see what needed to be included, and including all of the necessary pieces to be used in the rest of the methods, it made writing the rest of the methods significantly easier and straightforward.