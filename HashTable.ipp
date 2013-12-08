//You will need this so you can make a string to throw in
// remove
#include <string>

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

  if(backingArray[pos].isNull) {
    backingArray[pos].k = k;
	backingArray[pos].x = x;
	backingArray[pos].isNull = false;
	numItems++;
  }

  else {
	for(int i = 0; i < backingArraySize; i++) {
		if(backingArray[(pos + i)%backingArraySize].isNull) {
			backingArray[(pos + i)%backingArraySize].x = x;
			backingArray[(pos + i)%backingArraySize].isNull = false;
			numItems++; 
			break;
		}
	}
  }
}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	unsigned long pos = hash(k);

	if(keyExists(k)) {

		if(backingArray[pos].k == k) {
			backingArray[pos].isNull = true;
			backingArray[pos].isDel  = true;
			numItems--;
			numRemoved++;
		}

		else {

			for(int i = 0; i < backingArraySize; i++) {
				if(backingArray[(pos + i)%backingArraySize].k == k) {
					backingArray[(pos + i)%backingArraySize].isNull = true;
					backingArray[(pos + i)%backingArraySize].isDel  = true;
					numItems--;
					numRemoved++;
				}
			}	
		}
	}
}

 //Return the item with Key k. 
 // If there is no such item, throw an exception.
template <class Key, class T>
T HashTable<Key,T>::find(Key k){

  if(!keyExists(k))
	throw std::string("Does not exist");
  else {
	int pos = hash(k)%backingArraySize;

	if(backingArray[pos].k == k)
		return backingArray[pos].x;
	else {
		for(int i = 0; i < backingArraySize; i++) {
			if(backingArray[(pos + i)%backingArraySize-1].k == k)
				return backingArray[(pos + i)%backingArraySize-1].x;
		}
	}
  }
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  
  int pos = hash(k)%backingArraySize;
  
  if(backingArray[pos].k == k)
	return true;
  else {
	for(int i = 0; i < backingArraySize; i++) {
		if(backingArray[(pos + i)%backingArraySize-1].k == k)
			return true;
	}
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

  for(int i = 0; i < NUM_HASH_PRIMES; i++) {
	if(backingArraySize < hashPrimes[i]) {
		newBackingArraySize = hashPrimes[i];
		break;
	}
  }

  HashRecord* delBackingArray = backingArray;
  HashRecord* newBackingArray = new HashRecord[newBackingArraySize];

  //Check if we are out of memory and throw and exception if so
  if(newBackingArray == NULL)
	throw std::string("Error");

  //Set the old array's address location to the new array's location
  backingArray = newBackingArray;
  
  //Copy the old array's contents to the new array
  //Using book example for this method (5.2)
  for (unsigned long i = 0; i < backingArraySize; i++) {
	if(!delBackingArray[i].isNull && !delBackingArray[i].isDel) {
		add(delBackingArray[i].k, delBackingArray[i].x);
	}
  }
	
  //Double the array size variable
	backingArraySize = newBackingArraySize;

  //De-allocate the old array
  delete[] delBackingArray;

  
}
