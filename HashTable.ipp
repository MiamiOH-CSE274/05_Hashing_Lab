//You will need this so you can make a string to throw in
// remove
#include <string>


template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[backingArraySize];
  numItems = 0;
  numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete [] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  //unsigned long hashV = hash(k)%backingArraySize;
  
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  }

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //TODO
  T dummy;
  return dummy;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}
