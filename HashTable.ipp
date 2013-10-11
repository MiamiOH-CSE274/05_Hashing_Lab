//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){

  numItems = 0;
  numRemoved = 0;
  backingArraySize = hashPrimes[0];

}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  
  int totalNumItems = numItems;
  for (int index = 0; index < totalNumItems; index++){
	remove (0);
  }
  backingArraySize = 0;

}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  //TODO
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
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
