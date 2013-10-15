//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(class Key);

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  numItems = 0;
  numRemoved = 0;
  backingArraySize = 0;
  backingArray = new HashRecord[backingArraySize];
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  if(numItems + 1 + numRemoved >= backingArraySize/2){
	grow();
  }
  int hashValue = hash(k) % backingArraySize;
  while(!backingArray[hashValue]->isNull && !backingArray[hashValue]->isDel){
	hashValue = (hashValue == backingArraySize - 1) ? 0 : hashValue + 1;
		}
  if(backingArray[hashValue]->isDel){
	backingArray[hashValue]->isDel == false;
  }
  numItems++;
  backingArray[hashValue]->k == k;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	int hashValue = hash(k) % backingArraySize;
	while(!backingArray[hashValue]->isNull){
		if(!backingArray[hashValue]->isDel 
			&& backingArray[hashValue]->k == k){
			return backingArray[hashValue];
		}
		hashValue = (hashValue == backingArraySize - 1) ? 0 : hashValue + 1;
	}
	throw (std::string) "No such a key in the hash table.";
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
  return 0;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}
