Author
==========
"Bickley, Daniel", bickledb
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

1. 'keyExists' should take constant time, as it checks values until it finds a null area of the array. Because the HashTable is designed to have a load factor that is less than one half, the method should not have to cycle through the entire table to find if the key exists, and will only have to check a few places in the array, and should therefore take constant time.
    'find' should take constant time for the same reason why 'keyExists' does, as the first comparison to a null block in the array, the key does not exist, as the HashTable utilizes double probing, and it's speed is not dependent on the size of the data set, as long as the load factor is less than one half.
	'remove' takes constant time for the exact same reason why 'keyExists' and 'find' both take constant time.
	'size'  takes constant time, because the number of items in the array is constantly being tracked by a variable, and the 'size' method simply returns the variable's value.
2.  'add' is reasonably fast, as I utiilize double hashing in the HashTable. Therefore, the 'add' method will not take linear time, assuming the load factor is less than one half. If the load factor is equal to or greater than one half, 'grow' is called, bumping 'add's runtime up to linear time.
3.   'grow' takes linear time because it has to allocate more memory space for a secondary array, and then read all of the data from the old array, one by one, and add it to the new array. Because the method has to read through of the data in the array, it has to go check the array 'n' times, and so takes linear time.
4.  The program should not leak memory, due to the deconstructor being defined, as well as the deletion of any object created with 'new'.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think that using the two different functions helps to reduce the chance that the object in the array has not been messed with or changed accidently. Returning pointers is unnecessarily risky, considering C++ lets you do pretty much anything you want with them, which can accidently screw up your program. I agree that having two seperate methods is better, because it is much less likely to accidently cause problems.
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
	My advice would be to pay close attention to what is the most efficent way to fix a problem. Many times, the less efficent ways can cause logistic proglems that you do not expect, and you spend two to three hours trying to fix a bug when it should only take around fifteen minutes to solve, providing you try to fix the bug in the most efficent way.