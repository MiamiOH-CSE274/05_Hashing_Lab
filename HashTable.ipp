//You will need this so you can make a string to throw in
// remove
#include <string>

int sizeOfArrayIndex = 0;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArraySize = hashPrimes[0];
	backingArray = new HashRecord[backingArraySize];
	numItems = 0;
	numRemoved = 0;
	}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  
}




template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  
  unsigned long index = hash(k)%backingArraySize;
  if (backingArray[index].isNull) {
    backingArray[index].isNull = false;
	backingArray[index].k = k;
	backingArray[index].x = x;
	numItems++;
	if ( numItems >= (backingArraySize/2) )
	grow();

	return;
  }
  while (!(backingArray[index].isNull)){
	index = (index+index)%backingArraySize;

	 if (backingArray[index].isNull) {
		backingArray[index].isNull = false;
		backingArray[index].k = k;
		backingArray[index].x = x;
		numItems++;
		if ( numItems >= (backingArraySize/2) )
	grow();

		return;
	}

	if (backingArray[index].isDel) {
	  backingArray[index].isDel = false;
	  backingArray[index].isNull = false;
	  backingArray[index].k = k;
	  backingArray[index].x = x;
	  numRemoved--;
	  numItems++;
	  if ( numItems >= (backingArraySize/2) )
	grow();

	  return;
	  }
  }

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
unsigned long index = hash(k)%backingArraySize;
 while(!(backingArray[index].isNull)) {
	if (k == backingArray[index].k) {
	  backingArray[index].isDel = true;
	  numItems --;
	  numRemoved ++;
	  }
	  index = (index+index)%backingArraySize;
  }
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if (!keyExists(k))
    throw std::string("This key does not exist. Please choose a different one");

  unsigned long index = hash(k)%backingArraySize;
 while(!(backingArray[index].isNull)) {
   if (!(backingArray[index].isDel)) {
	 if(k == backingArray[index].k) {
	    return backingArray[index].x;
	  }
	  index = (index+index)%backingArraySize;
	 }
  }
return 0;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  unsigned long index = hash(k)%backingArraySize;
  while(!(backingArray[index].isNull)) {
	if ((backingArray[index].k == k)&& !(backingArray[index].isDel))
	  return true;
	
	index = (index + index) % backingArraySize;
	}


  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	HashTable<Key,T> second;

   sizeOfArrayIndex++;
	second.backingArraySize = hashPrimes[sizeOfArrayIndex];
	second.backingArray = new HashRecord[backingArraySize];
	for (int i = 0; i < (int)hashPrimes[sizeOfArrayIndex-1]; i++) {
	  if (!(backingArray[i].isNull) && !backingArray[i].isDel) {
		second.add(backingArray[i].k,backingArray[i].x);
		}

	}
	backingArray = second.backingArray;
	backingArraySize = second.backingArraySize;
	numRemoved = 0;
	

  
}
