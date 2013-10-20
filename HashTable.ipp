//You will need this so you can make a string to throw in
// remove
#include <string>

 unsigned long hash(std::string str){
 unsigned long m = hashPrimes[NUM_HASH_PRIMES-2];
  unsigned long ret = 0;
  for(int i=0;i<str.size();i++){
    ret = (256*ret + str[i])%m;
  }
  return ret;
 

 }
 HashTable<std::string,int> mySillyTable;


template <class Key, class T>
HashTable<Key,T>::HashTable(){
 int backingArraySize=hashPrimes[0];
backingArray = new HashRecord[backingArraySize];
   numItems=0;
   numRemoved = 0;
  int currentHashPrime=0;
  
  Key k;
  T x;


    bool isNull;

    //If the slot used to have something in it, but doesn't now, set
    // isDel to true, and isNull to false. isNull is only for slots
    // that have never been used
    bool isDel;



}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
for (int i=0; i<backingArraySize; i++) {
//remove(i);
}

}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
int hashValue=hash(k);
////backingArray[hashValue%backingArraySize] = x;
//how to add the key and the data in the spot on the array.
numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
    //Remove the item with Key k. If there is no such item, do nothing.

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
  //T* newArray = new T[hash[currentHashPrime+1]];
    //or HashTable* H = new T[hash[currentHashPrime+1]];
    for (int i=0; i<backingArraySize; i++) {
    
    }
}
