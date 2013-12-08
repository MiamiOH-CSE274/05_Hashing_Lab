//You will need this so you can make a string to throw in
// remove
#include <string>
//Most of this was written using the book's methods from 5.2 regarding linear probing
//After many failed attempts of writing the methods from scratch based off logic
template <class Key, class T>
HashTable<Key,T>::HashTable(){
  //Initialize Variables
  numItems = 0;
  numRemoved = 0;
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[backingArraySize];
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  //De-allocate memory that was used to remove chance of memory leaks
  delete[] backingArray;
}

//Add a new item, x, with Key k.
//If an item with Key k already exists, overwrite it
template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){

  //Going to try to use the textbook's linear probing method
  
  if(numItems + numRemoved >= backingArraySize/2) {
	grow();
  }

  unsigned long pos = hash(k)%backingArraySize;

  while (!backingArray[pos].isNull && !backingArray[pos].isDel)
      pos = (pos == backingArraySize-1) ? 0 : pos + 1;
  
  backingArray[pos].k = k;
  backingArray[pos].x = x;
  backingArray[pos].isNull = false;
  numItems++;
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void HashTable<Key,T>::remove(Key k){

	unsigned long pos = hash(k)%backingArraySize;
	
	//Issues so also switching to book method
	while (!backingArray[pos].isNull) {
      if (!backingArray[pos].isDel && backingArray[pos].k == k) {
        backingArray[pos].isDel = true;
        numItems--;
		numRemoved++;
      }
      pos = (pos == backingArraySize-1) ? 0 : pos + 1;
    }
}

 //Return the item with Key k. 
 // If there is no such item, throw an exception.
template <class Key, class T>
T HashTable<Key,T>::find(Key k){

  //Crashing at the moment, going to try switching to book method

  int pos = hash(k)%backingArraySize;

  while (!backingArray[pos].isNull) {
    if (!backingArray[pos].isDel && backingArray[pos].k == k) return backingArray[pos].x;
	   pos = (pos == backingArraySize-1) ? 0 : pos + 1;
  }
    
  throw std::string("Key not found");
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  
  //Was having errors with previous code so using book notation
  int pos = hash(k)%backingArraySize;
  
    while (!backingArray[pos].isNull) {
      if (!backingArray[pos].isDel && backingArray[pos].k == k) return true;
      pos = (pos == backingArraySize-1) ? 0 : pos + 1;
    }
    return false;
}

//Return the number of items currently in the USet
template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

//Whenever numItems + numRemoved >= backingArraySize/2, call
// grow(). grow() should make a new backing array that is twice the
// size of the old one, similar to what we did in the ArrayQueue
// lab.
//Note: You cannot just loop through the old array and copy it to the
// new one! Since the backing array size has changed, each item will likely
// map to a different slot in the array. You may just want to use add()
// after initializing the new array.
template <class Key, class T>
void HashTable<Key,T>::grow(){

  //Re-used some code from the grow() method of my Queue Lab
  int newBackingArraySize = backingArraySize;
  int delBackingArraySize = backingArraySize;

  for(int i = 0; i < NUM_HASH_PRIMES; i++) {
	if(backingArraySize < hashPrimes[i]) {
		newBackingArraySize = hashPrimes[i];
		break;
	}
  }

  HashRecord* delBackingArray = backingArray;
  HashRecord* newBackingArray = new HashRecord[newBackingArraySize];
  numItems = 0;
  numRemoved = 0;

  //Check if we are out of memory and throw and exception if so
  if(newBackingArray == NULL)
	throw std::string("Error");

  //Set the old array's address location to the new array's location
  backingArray = newBackingArray;

  //Change the size variable to new size from hashPrimes
  backingArraySize = newBackingArraySize;
  
  //Copy the old array's contents to the new array
  //Using book example for this method (5.2)
  for (unsigned long i = 0; i < delBackingArraySize; i++) {
	if(!delBackingArray[i].isNull && !delBackingArray[i].isDel) {
		add(delBackingArray[i].k, delBackingArray[i].x);
	}
  }

  //De-allocate the old array
  delete[] delBackingArray;
  
}
