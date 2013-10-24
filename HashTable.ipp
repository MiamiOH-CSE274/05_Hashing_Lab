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
int hashPrimeIndex=0;
 backingArraySize=hashPrimes[hashPrimeIndex];

backingArray = new HashRecord[backingArraySize];
   numItems=0;
   numRemoved = 0;
 //isNull=true;
// isNull=true;
    //If the slot used to have something in it, but doesn't now, set
    // isDel to true, and isNull to false. isNull is only for slots
    // that have never been used
  //  isDel=false;
//isDel;
  
  //Key k;
 // T x;




}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
for (int i=0; i<backingArraySize; i++) {
//remove(i);
}

}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
//Add a new item, x, with Key k.
// If an item with Key k already exists, overwrite it
//HashRecord temp = *new HashRecord(x);
//temp.k = k;
//temp.x = x;
int index= hash(k)%backingArraySize;
int jump = (hash(k)%(backingArraySize-1))+1;

    while (backingArray[index].isNull==false) {
index=(index+jump) %backingArraySize;
}
//backingArray[hash(k)%backingArraySize].k=k;
//backingArray[hash(k)%backingArraySize].x=x;
backingArray[index].k=k;
backingArray[index].x=x;

backingArray[index].isNull=false;
numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
    //Remove the item with Key k. If there is no such item, do nothing.
    if (keyExists(k)==false) {
        return;
    }
int index= hash(k)%backingArraySize;
int jump = (hash(k)%(backingArraySize-1))+1;

    while (backingArray[index].isNull==false) {
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
    
    while (backingArray[index].k!=k) {
        if (backingArray[index].isNull==true) {
            if (backingArray[index].isDel==true) {
            throw (std::string) "Key does not exist";
        }
        }
        index=index+jump;
    }
        return backingArray[index].x;
    
return backingArray[hash(k)%backingArraySize].x;
  //T dummy;
  //return dummy;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
    int index= hash(k)%backingArraySize;
    int jump = (hash(k)%(backingArraySize-1))+1;
    
    while (backingArray[index].k!=k) {
        if (backingArray[index].isNull==true) {
            if (backingArray[index].isDel==true) {
            return false;
            }
        }
        index=index+jump;
    }
        return true;
    
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){

  return numItems;
  
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
//  //T* newArray = new T[hash[currentHashPrime+1]];
//    //or HashTable* H = new T[hash[currentHashPrime+1]];
//    hashPrimeIndex++;
//    HashRecord* oldArray = backingArray;
//    HashRecord* tempArray = new HashRecord[hashPrimes[hashPrimeIndex]];
//    backingArray=tempArray;
////old attributes here.
////    int oldNumItems = numItems;
////    int oldNumRemoved = numRemoved;
////    int oldHashPrimeIndex = hashPrimeIndex;
//    for (int i=0; i<backingArraySize; i++) {
//    if (oldArray[i].isNull==false && oldArray[i].isDel==false){
//        add(oldArray[i]);
//
//    }
    //delete[]backingArray;
//    numItems = oldNumItems;
//    numRemoved=oldNumRemoved;
//    hashPrimeIndex=oldHashPrimeIndex;
}
