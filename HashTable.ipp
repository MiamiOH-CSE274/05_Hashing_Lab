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
  
  if (find(k) != NULL)
    throw std::string ("Error: item already exists in memory");
  if ((2*(numItems + numRemoved)) >= backingArraySize)
    grow ();
  int itemLocation = hash(k);
  while (backingArray[itemLocation].isNull == false && backingArray[itemLocation].isDel == false){
    itemLocation = (itemLocation == backingArraySize-1) ? 0 : itemLocation + 1;
  }
  numItems++;
  backingArray[itemLocation] = x;

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  
  int itemLocation = hash(k);
  while (backingArray[itemLocation].isNull == false){
    if (backingArray[itemLocation].isDel == false && backingArray[itemLocation] == k)
	  return *backingArray[itemLocation];
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
