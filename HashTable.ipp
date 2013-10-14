//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(std::string k){
  unsigned long m = hashPrimes[NUM_HASH_PRIMES-2];
  unsigned long ret = 0;
  for(int i=0;i<k.size();i++){
    ret = (256*ret + k[i])%m;
  }
  return ret;
}

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[backingArraySize];
  numItems = 0;
  numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete [] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  unsigned long hashV = hash(k)%backingArraySize;
  backingArray[hashV].k = k;
  backingArray[hashV].x = x;
  numItems++;
  
  
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
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
void HashTable<Key,T>::grow(){
  HashRecord* temp = new HashRecord[hashPrimes[1]];
  for (int i = 0; i < backingArraySize; i++) {
    if (backingArray[i].isNull)
      break;
    if (backingArray[i].isDel) {
      temp[i].isDel = true;
      break;
      }
    else
      temp[i]->k = backingArray[i]->k;
      temp[i]->x = backingArray[i]->x;
    }
    backingArraySize = hashPrimes[1];
    
    delete [] backingArray;
    backingArray = temp;
    temp = NULL;
}
