//You will need this so you can make a string to throw in
// remove
#include <string>
unsigned long hash(char c){ return 10*((unsigned long)c)%13; }

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  //TODO
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[backingArraySize];
  numItems =0;
  numRemoved =0;
}


template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  //TODO
  delete[] backingArray;
}


template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  //TODO

  if(numItems + numRemoved >= backingArraySize/2){
	grow();
  }

  unsigned long kIndex= hash(k)%backingArraySize;
  unsigned long jump = 1+(hash(k)%(backingArraySize-1));

	while(!(backingArray[kIndex].isNull)){
		if(backingArray[kIndex].k==k){
			backingArray[kIndex].x=x;
			backingArray[kIndex].k =k;
			backingArray[kIndex].isNull = false;
			numItems++;
		}
		kIndex = (kIndex+jump)%backingArraySize;
	}

	backingArray[kIndex].x=x;
	backingArray[kIndex].k =k;
	backingArray[kIndex].isNull = false;
	numItems++;

}




template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO

   unsigned long kIndex= hash(k)%backingArraySize;
   unsigned long jump = 1+(hash(k)%(backingArraySize-1));
 
	while(!(backingArray[kIndex].isNull)){
		if(backingArray[kIndex].isDel==false && backingArray[kIndex].k==k){
			backingArray[kIndex].isDel=true;
			backingArray[kIndex].isNull = false;
			numItems--;
			numRemoved++;
			break;
		}
		kIndex = (kIndex+jump)%backingArraySize;
	}
}




template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //TODO

   if(!keyExists(k))
		throw std::string("There is no such item");

  int i = hash(k)%backingArraySize;
  unsigned long jump = 1+(hash(k)%(backingArraySize-1));

  while(!(backingArray[i].isNull)){
	if(!(backingArray[i].isDel)&& backingArray[i].k==k)
		return backingArray[i].x;
	 i = (i+jump)%backingArraySize;
  }
}



template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
  int index = hash(k)%backingArraySize;
  unsigned long jump = 1+(hash(k)%(backingArraySize-1));
  while(!backingArray[index].isNull){
	if(backingArray[index].isDel==false && backingArray[index].k==k)
	return true;

	index = (index +jump)%backingArraySize;
  }
  return false;
}




template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
    unsigned long index = 0;
    while (backingArraySize>=hashPrimes[index]){
        index++;
    }
   HashRecord* temp = backingArray;
   int tempSize = backingArraySize;
   backingArraySize = hashPrimes[index];
   backingArray = new HashRecord[hashPrimes[index]];
  
  numItems = 0;
  for(int i = 0; i<tempSize; i++){
	if(!temp[i].isNull && !temp[i].isDel)
		add(temp[i].k, temp[i].x);
  }
  delete[] temp;
   
}
