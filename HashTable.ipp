//You will need this so you can make a string to throw in
// remove
#include <string>


unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
HashTable<char,int> mySillyTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  //TODO
  backingArraySize = 53;
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
  unsigned long i = 0;
  while(!(backingArray[kIndex].isNull)){
    kIndex = (kIndex+1)%backingArraySize;
  }
  backingArray[kIndex].x=x;
  backingArray[kIndex].k =k;
  backingArray[kIndex].isNull = false;
  numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO

  int i = hash(k)%backingArraySize;
  while(!(backingArray[i].isNull)){

	if(!(backingArray[i].isDel)&&backingArray[i].k==k){
		backingArray[i].isDel = true;
		numItems--;
		numRemoved++;
	}
	  i = (i == backingArraySize-1) ? 0 : i + 1;
  }
}



template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //TODO

  int i = hash(k)%backingArraySize;
  while(!(backingArray[i].isNull)){
	if(!(backingArray[i].isDel)&& backingArray[i].k==k)
		return backingArray[i].x;
	  i = (i == backingArraySize-1) ? 0 : i + 1;
  }
  if(!keyExists(k))
		throw std::string("There is no such item");
  backingArray[i].isNull = true;
}



template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
  	if(backingArray[hash(k)%backingArraySize].isNull || backingArray[hash(k)%backingArraySize].isDel)
		return false;
	return true;
}




template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}
