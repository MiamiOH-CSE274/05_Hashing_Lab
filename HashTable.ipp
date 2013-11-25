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

	if(keyExists(k)){
        T toChange = find(k);
        toChange= x;
    }
	if((numItems+numRemoved) >= (backingArraySize/2))//Make sure table load size never exceeds n/2 to avoid as many collisions as possible.
		grow();

	unsigned long index = hash(k)%backingArraySize; //this is the initial hashing for the index. Jump for double hashing needs to be added later.

	if(backingArray[index].isNull){
		backingArray[index].isNull = false;
        backingArray[index].k = k;
        backingArray[index].x = x;
        numItems++;
        return; //get out to avoid double hashing when unnecessary.
	}

	//backingArraySize needs to be cast to an int for this comparison!!! Dummy...
	
	for(int i=0; i<(int)backingArraySize; i++){//Can this be reduced to i<(backingArraySize/2)+1 and still guarantee all collisions will be handled?
		index = (index+(1+hash(k)%(backingArraySize-1)))%backingArraySize; //minimum jump of 1 -fixed k to index because I was not originally paying attention... key got converted to an unsigned long earlier...
		if(backingArray[index].isNull || backingArray[index].isDel){ //could this be done recursively perhaps? Would reduce code size, would decrease speed(I think)...
            backingArray[index].isNull=false;
            backingArray[index].k = k;
            backingArray[index].x = x;
            numItems++;
			if(backingArray[index].isDel){
				backingArray[index].isDel=false;
				numRemoved--;
			}//end internal if
            return;
		}//end if
	}//end for
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	unsigned long index = hash(k)%backingArraySize;
	while(!(backingArray[index].isNull)){
		if(k == backingArray[index].k) {
			backingArray[index].isDel = true; //could this be made better by perhaps eliminating isDel and simply turning backingArray[i].k = NULL? Would it make line 81 go faster?
			numItems--;
			numRemoved++;
        }//end if
		index = (index+(1+hash(k)%(backingArraySize-1)))%backingArraySize;
	}//end while
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	if(keyExists(k)==false)
		throw std::string("Given key is non-existent in this table. Try another.");

	unsigned long index = hash(k)%backingArraySize;
	while(!(backingArray[index].isNull) || !(backingArray[index].isDel)){//checks if null or deleted
		if(k == backingArray[index].k) //checks if key matches
			return backingArray[index].x; //returns data if match
		index = (index+(1+hash(k)%(backingArraySize-1)))%backingArraySize; //jumps if not a match
	}
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	unsigned long index = hash(k)%backingArraySize; //initial hash
	while(!(backingArray[index].isNull)){//will always end up at a null value because we never have a full array, so the loop should not get stuck 
		if((backingArray[index].k == k)&& !(backingArray[index].isDel))
			return true;
        
		index = (index+(1+hash(k)%(backingArraySize-1)))%backingArraySize; //double hash/jumping
	}//end while
  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){//already have a hashprimes array, simply move index up one, then copy over old array.
	int hashPrimesPosition = 0;
	do{ //will happen at least once
		hashPrimesPosition++;
	}while(hashPrimes[hashPrimesPosition] <= backingArraySize);

	backingArraySize = hashPrimes[hashPrimesPosition];
	HashRecord* initial = backingArray;
	HashRecord* newArray = new HashRecord[backingArraySize];
	backingArray = newArray;
	numItems = 0; //value set to 0 due to creation of new hashtable
	numRemoved = 0; //value set to 0 due to creation of new hashtable

	for (int i=0; i < (int)hashPrimes[hashPrimesPosition-1]; i++){ //cast to int dummy! -fixed which variable was being used to determine the copy count. Was not thinking...
		if(!(initial[i].isNull) && !(initial[i].isDel)) //hmm, && or ||? && because you want neither a null item or a deleted one added.
			add(initial[i].k,initial[i].x);
	}

	delete[]initial;
	backingArray = newArray; //valid?
}
