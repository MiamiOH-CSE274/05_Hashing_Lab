//You will need this so you can make a string to throw in
// remove
// This Lab was implemented based on the reading materia
// http://opendatastructures.org/ods-cpp/5_2_Linear_Probing.html 
#include <string>

unsigned long hash(class Key);

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  numItems = 0;
  numRemoved = 0;
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[backingArraySize];
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  if(numItems + 1 + numRemoved >= backingArraySize / 2){
	grow();
  }
  unsigned long hashValue = hash(k) % backingArraySize;
  while(!backingArray[hashValue].isNull &&
   !backingArray[hashValue].isDel){
		hashValue = (hashValue == backingArraySize - 1) ? 0 : hashValue + 1;
		}
  if(backingArray[hashValue].isDel){
	backingArray[hashValue].isDel = false;
  }
  numItems++;
  backingArray[hashValue].k = k;
  backingArray[hashValue].x = x;
  backingArray[hashValue].isNull = false;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  unsigned long hashValue = hash(k) % backingArraySize;
  while(!backingArray[hashValue].isNull){
	if(!backingArray[hashValue].isDel && backingArray[hashValue].k ==k){
		backingArray[hashValue].isDel = true;
		numItems--;
		numRemoved++;
	}
	hashValue = (hashValue == backingArraySize - 1) ? 0 : hashValue + 1;
  }
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	unsigned long hashValue = hash(k) % backingArraySize;
	while(!backingArray[hashValue].isNull){
		if(!backingArray[hashValue].isDel 
			&& backingArray[hashValue].k == k){
			return backingArray[hashValue].x;
		}
		hashValue = (hashValue == backingArraySize - 1) ? 0 : hashValue + 1;
	}
	throw (std::string) "No such a key in the hash table.";
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  try{
	find(k);
  }catch(std::string a){
	return false;
  }
  return true;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){	
  int newNumItems = backingArraySize;
  for(int index = 0; index < NUM_HASH_PRIMES; index++){
	if(hashPrimes[index] == backingArraySize &&
		index != NUM_HASH_PRIMES - 1){
		newNumItems = hashPrimes[index + 1];
	}
  }
  HashRecord* temp = new HashRecord[newNumItems];
  HashRecord* removal = backingArray;
  backingArray = temp;
  for(int i = 0; i < backingArraySize; i++){
	add(removal[i].k, removal[i].x);
  }
  backingArraySize = newNumItems;
  delete[] removal;
}
