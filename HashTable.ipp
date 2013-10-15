//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
 
 
// list of primes numbers
backingArraySize=hashPrimes[0];

//creates
backingArray= new HashRecord[hashPrimes[0]];

numItems=0;

numRemoved=0;
 
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  //TODO
  
     if(numItems + numRemoved >= backingArraySize/2)
   grow();
   
   
 unsigned long index = hash(k)%backingArraySize;
  unsigned long current = index;
   
   
   while(!(backingArray[current].isNull))
     current=(current+1)%backingArraySize;
     
    
      backingArray[current].x=x;
     
     backingArray[current].k =k;
     
     backingArray[current].isNull = false;
     
     numItems=numItems+1;

   
   

   






}
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
    unsigned long index = hash(k)%backingArraySize;
  unsigned long current = index;
  
  while(!(backingArray[current].isNull))
  if(backingArray[current].k==k){
  backingArray[current].isDel=true;
  backingArray[current].isNull=false;
  
  
  numItems--;
  numRemoved++;
  }
  
  current=(current+current)%backingArraySize;
  
  
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
  //TODO
  return 0;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}
