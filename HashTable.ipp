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

	unsigned long index = hash(k)%backingArraySize; //this is the initial hashing for the index. Jump for double hashing needs to be added later.

	if(backingArray[curIndex].isNull){
		backingArray[curIndex].isNull = false;
        backingArray[curIndex].k = k;
        backingArray[curIndex].x = x;
        numItems++;
        return; //get out to avoid double hashing when unnecessary.
	}

	//does backingArraySize need to be cast to an int for this comparison?
	for(int i=0; i<backingArraySize; i++){//Can this be reduced to i<(backingArraySize/2)+1 and still guarantee all collisions will be handled?
		curIndex += 1+(key%(numItems-1)); //minimum jump of 1

		if(backingArray[curIndex].isNull || backingArray[curIndex].isDel){ //could this be done recursively perhaps? Would reduce code size, would decrease speed(I think)...
            backingArray[curIndex].isNull=false;
            backingArray[curIndex].k = k;
            backingArray[curIndex].x = x;
            numItems++;
			if(backingArray[curIndex].isDel){
				backingArray[curIndex].isDel=false;
				numRemoved--;
			}//end internal if
            return;
		}//end if
	}//end for
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
		if(!(backingArray[i].isNull) && !(backingArray[i].isDel)) //hmm, && or ||? && because you want neither a null item or a deleted one added.
		newArray.add(backingArray[i].k,backingArray[i].x);
	}

	delete[]backingArray;
	backingArray = newArray; //valid?
}
