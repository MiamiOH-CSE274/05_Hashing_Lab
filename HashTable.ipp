//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArraySize = hashPrimes[sizeOfArrayIndex];
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
	if((numItems+numRemoved) >= (backingArraySize/2))//Make sure table load size never exceeds n/2 to avoid as many collisions as possible.
		grow();
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
void HashTable<Key,T>::grow(){//already have a hashprimes array, simply move index up one, then copy over old array.
  sizeOfArrayIndex++;

  HashRecord* newArray = new HashRecord[hashPrimes[sizeOfArrayIndex]];
  backingArraySize = hashPrimes[sizeOfArrayIndex];
  numItems = 0; //value set to 0 due to creation of new hashtable
  numRemoved = 0; //value set to 0 due to creation of new hashtable

  for (int i=0; i < hashPrimes[sizeOfArrayIndex-1]; i++) {
	if (!(backingArray[i].isNull) && !(backingArray[i].isDel)) //hmm, && or ||? && because you want neither a null item or a deleted one added.
		newArray.add(backingArray[i].k,backingArray[i].x);
  }

  delete[]backingArray;
  backingArray = newArray; //valid?
}
