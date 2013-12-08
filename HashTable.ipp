//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  //Initialize Variables
  numItems = 0;
  numRemoved = 0;
  backingArraySize = hashPrimes[0];
  HashRecord[] table = new HashRecord[backingArraySize];
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
  int pos = hash(k);
  bool isFull = false;



  if(table[pos].isNull) {
	table[pos] = x;
  }

  for(int i = 0; i < backingArraySize; i++) {
	if((table[pos + i]%backingArraySize).isNull) {
		table[pos + i]%backingArraySize = x;
	}
	else if (i == (backingArraySize - 1))
		isFull == true;
  }

  if(isFull) {
	grow();

  }

}

//Remove the item with Key k. If there is no such item, do nothing.
template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
 
}

 //Return the item with Key k. 
 // If there is no such item, throw an exception.
template <class Key, class T>
T HashTable<Key,T>::find(Key k){

  int j = hash(k);
  T dummy = null;
  
  for (int i = 0; i < t[j].size(); i++) {
	dummy = t[j].get(i);
    if (k == dummy)
		return dummy;
  }
  throw std::string("That is an invalid input");
}

//Return true if there is an item with Key k in the table. If not,
// return false
template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
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
  T* newBackingArray = new T[backingArraySize*2];

  //Check if we are out of memory and throw and exception if so
  if(newBackingArray == NULL)
	throw std::string("Error");
  
  //Copy the old array's contents to the new array
  for (unsigned long i = 0; i < numItems; i++)
	//Use add() method to add items to new array
	
  //Double the array size variable
	backingArraySize = backingArraySize*2;

  //De-allocate the old array
  delete[] backingArray;

  //Set the old array's address location to the new array's location
  backingArray = newBackingArray;
}
