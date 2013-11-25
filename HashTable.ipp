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



 
// modified from book
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

// modified from book
template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
 
unsigned long index = hash(k)%backingArraySize;
  unsigned long current = index;
  
  while(!(backingArray[current].isNull)){
  if(backingArray[current].k==k){
  backingArray[current].isDel=true;
  backingArray[current].isNull=false;
  
  }


 current = (current == numItems) ? 0 : current + 1;
   }

numItems--;
numRemoved++;
}

//from book
template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if(!keyExists(k)){
  throw(std::string) "naa man, not here" ;}
  
 T found=backingArray[hash(k)%backingArraySize].x;
     return found;
     

}


template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
unsigned long hasher= hash(k)%backingArraySize;
 
 if(backingArray[hasher].isNull==true || backingArray[hasher].isDel){
    return false;
    }
  
  

  
 
return true;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
return numItems;
}


// was havning problems with this method, used luoy6's code to help understand and make mine
template <class Key, class T>
void HashTable<Key,T>::grow(){
     
     unsigned long primesThrough = 0;
    if(backingArraySize>=hashPrimes[primesThrough])
        
        primesThrough++;


        

  HashRecord* old= backingArray;
  backingArraySize=hashPrimes[primesThrough];
  backingArray= new HashRecord[backingArraySize];
  numItems=0;
int i = 0;
  
 while( i < hashPrimes[primesThrough-1] ) {
    if (!(old[i].isNull) && !(old[i].isDel))
      add(old[i].k,old[i].x);
  i++;
  }
  
  
  delete[]old;



   
    

  
  

}
