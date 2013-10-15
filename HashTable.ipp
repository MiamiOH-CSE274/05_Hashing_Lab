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


// list of primes numbers
backingArraySize=hashPrimes[0];

//creates
backingArray= new HashRecord[hashPrimes[0]];

numItems=0;

numRemoved=0;

  
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  
  
  delete[] backingArray;


}



 

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
   
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

//I would like to give some credit to shearar, I was having problems with this function when I saw that you could do it this easily.
template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if(!keyExists(k)){
  throw(std::string) "naa man, not here" ;}
  
  
  
  T found=backingArray[hash(k)].x;
     return found;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
unsigned long hasher= hash(k);
 
 if(backingArray[hasher].isNull || backingArray[hasher].isDel){
    return false;
  
  
  }
  
 
return true;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
     unsigned long primesThrough = 0;
    
    
    while (backingArraySize>=hashPrimes[primesThrough]){
        
        primesThrough++;
        backingArraySize=hashPrimes[primesThrough];
        }
        

  HashRecord* old= backingArray;
  backingArray= new HashRecord[backingArraySize];

  for (int i = 0; i < hashPrimes[primesThrough-1]; i++) {
    if (!(old[i].isNull) && !(old[i].isDel))
      add(old[i].k,old[i].x);
  }
  delete[]old;




  
  

}
