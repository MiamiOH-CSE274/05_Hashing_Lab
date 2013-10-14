Author
==========
"Blase, Douglas", blasedd
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

1. `keyExists`, `find`, `remove`, and `size` are all O(1) since even though all of these methods loop through the array, it won't loop through most of the array since grow() would have been called before hand.

2. `add` is fairly fast for the same reason the methods in requirement 1 are quick. There won't be a lot of jumping through the array since grow would have been called.

3. `grow` is O(n), as it involves looping through the old array and adding the data to the new array.

4. `delete` is called in the `grow`, and destructor methods, preventing memory from being leaked

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think the T* method would be better because the two function method involves a lot of code copying, and either way, I can't pass the location back to `add`, so I have to jump anyway to find the place to add the new data. If find returned the T*, I could easily determine the index in the find method and have the add method add the data in the T* returned from find.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I was confused at how to call `hash` from the main.cpp file. I thought it would simply be `hash(k)`, but XCode reported an error basically saying that it couldn't see the method in main.cpp. So when I was working on it over the weekend I overloaded the method myself, and didn't think about until Dr. Brinkman said in class that he would prefer that we use his method. I can't figure out how to use the method, so I'm using my overloaded version instead.