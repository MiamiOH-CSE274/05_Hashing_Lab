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
 //HashTable<std::string,int> mySillyTable;
int hashPrimeIndex;

template <class Key, class T>
HashTable<Key,T>::HashTable(){

        hashPrimeIndex=1;
    backingArraySize=hashPrimes[0];

    backingArray = new HashRecord[hashPrimes[0]];

    numItems=0;
    numRemoved = 0;
    
    //If the slot used to have something in it, but doesn't now, set
    // isDel to true, and isNull to false. isNull is only for slots
    // that have never been used
  
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
    delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
//HashRecord temp = *new HashRecord(x);
//temp.k = k;
//temp.x = x;
    
    //Whenever numItems + numRemoved >= backingArraySize/2, call
    // grow(). grow() should make a new backing array that is twice the
    // size of the old one, similar to what we did in the ArrayQueue
    // lab.
    if (numItems + numRemoved >= backingArraySize/2) {
        grow();
    }
    
    
    
int index= hash(k)%backingArraySize;
int jump = (hash(k)%(backingArraySize-1))+1;

    while (backingArray[index].isNull==false) {
index=(index+jump) %backingArraySize;
}
backingArray[index].k=k;
backingArray[index].x=x;

backingArray[index].isNull=false;
numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){

    //Remove the item with Key k. If there is no such item, do nothing.
    if (keyExists(k)==false) {
        return;
    }
int index= hash(k)%backingArraySize;
int jump = (hash(k)%(backingArraySize-1))+1;

    while (backingArray[index].k!=k) {
index=(index+jump) %backingArraySize;
}
backingArray[index].isDel=true;
backingArray[index].isNull=false;
    numItems--;
    numRemoved++;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //Return the item with Key k. 
  // If there is no such item, throw an exception.
    //int value = hash(k);
    //return backingArray[value];
    int index= hash(k)%backingArraySize;
    int jump = (hash(k)%(backingArraySize-1))+1;
    if (keyExists(k)==false) {
          throw (std::string) "Key does not exist";
    }
    while (backingArray[index].k!=k) {
          index=(index+jump) %backingArraySize;
    }
        return backingArray[index].x;
    
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
    int index= hash(k)%backingArraySize;
    int jump = (hash(k)%(backingArraySize-1))+1;
    
    
    
    while (backingArray[index].k!=k) {
        index=(index+jump) %backingArraySize;
        if (backingArray[index].isNull==true) {
            return false;
        }
        
        
    }
    if (backingArray[index].isDel==true) {
        return false;
    }
    return true;
//    if (backingArray[index].isDel==true) {
//        return false;
//    }
//    else {
//        return true;
//    }
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){

  return numItems;
  
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
    
    //looked at https://github.com/MiamiOH-CSE274/05_Hashing_Lab/blob/continnd/HashTable.ipp
    //but didn't make any changes as I am still stuck in a permanent lupe.
    //update: changed hashPrimeIndex to global variable and seems to have removed the loop.
    
    
    //worked on grow method at office hours.
    
    
    int oldBackingArraySize = backingArraySize;

    HashRecord* oldArray = backingArray;
    backingArray = new HashRecord[hashPrimes[hashPrimeIndex]];
    backingArraySize = hashPrimes[hashPrimeIndex];
    hashPrimeIndex++;
    //reset numItems before reinserting as add increments numItems.
    numItems = 0;
    for (int i=0; i<oldBackingArraySize; i++){
        if(!(oldArray[i].isNull) && oldArray[i].isDel==false)
            add(oldArray[i].k, oldArray[i].x);
    }
    //deallocate memory.
    delete[] oldArray;
    
}
