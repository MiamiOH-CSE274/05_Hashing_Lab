//You will need this so you can make a string to throw in
// remove
#include <string>


unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
//HashTable<char,int> mySillyTable;

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
  if((numItems/backingArraySize)<1/2){
	grow();
  }

  unsigned long kIndex= hash(k);
  unsigned long i = 0;
  while(i!=kIndex){
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
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //TODO

  if(!keyExists(k))
		throw std::string("There is no such item");
 int i = (hash(k)%backingArraySize);
    while (backingArray[i].isNull==false) {
      if (backingArray[i].k == k) 
	  return backingArray[i].x;
      i =  (i+1)%backingArraySize;
    }

}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
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
}
