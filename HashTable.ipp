//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
HashTable<char,int> mySillyTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){ 

  //Creating a new HashTable
  backingArray = new HashRecord[hashPrimes[0]];
  numItems = 0;

}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {

  //Destructor for our HashTable
  delete []backingArray;

}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){ 

  // First, check the load of the array and see if we should grow
  // Next, we'll hash the data and then find where we should put it
  // Afterwards, check the position (HashRecord has isNull and isDel)
  //     - If collision: move down a spot and keep checking
  //     - If no collision: plop that sucker in there and change isNull and isDel
  // Increment numItems by 1


  numItems++;

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){

  // Hash the value, then find where it is (if able)
  //     - Keep comparing the key to the index's key while
  //       incrementing the index by 1 while isNull is false 
  // On find: Set the data to null, set isDel to true,
  //          decrement numItems and increment numRemoved

  numItems--;
  numRemoved++;

}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //TODO
  T dummy;
  return dummy;

  // Same as remove, but on find return the data of the index

}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
  return false;

  // Pretty much the same thing as find, but return boolean values

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){

  // Return the size of the backing array
  return numItems;

}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  
  // Create a new array that's larger than our current one using primes
  // Add all our previous values to the new array
  // Change the flags back to zeroes
  // Change our pointer to the new array
  // Delete the old array


}
