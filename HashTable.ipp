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
  
  delete[] backingArray;

}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  
  if (keyExists(k) == true)
    throw std::string ("Error: an entry with the same key already exists");
  if ((2*(numItems + numRemoved)) >= backingArraySize)
    grow ();
  int itemLocation = hash(k)%backingArraySize;
  while (backingArray[itemLocation].isNull == false && backingArray[itemLocation].isDel == false){
    itemLocation = (itemLocation == backingArraySize-1) ? 0 : itemLocation + 1;
  }
  numItems++;
  backingArray[itemLocation].isNull = false;
  backingArray[itemLocation].k = k;
  backingArray[itemLocation].x = x;

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  
  if (keyExists(k) == false)
    throw std::string ("Error: no item with the given key exists");
  int itemLocation = hash(k)%backingArraySize;
  while (backingArray[itemLocation].isNull == false && backingArray[itemLocation].isDel == false){
    if (backingArray[itemLocation].k == k){
	  backingArray[itemLocation].isDel = true;
	  numItems--;
	  numRemoved++;
	}
	itemLocation = (itemLocation == backingArraySize-1) ? 0 : itemLocation + 1;
  }

}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  
  int itemLocation = hash(k)%backingArraySize;
  while (backingArray[itemLocation].isNull == false){
    if (backingArray[itemLocation].isDel == false && backingArray[itemLocation].k == k)
	  return backingArray[itemLocation].x;
	itemLocation = (itemLocation == backingArraySize-1) ? 0 : itemLocation + 1;
  }
  return NULL;

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
