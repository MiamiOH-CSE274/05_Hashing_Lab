//You will need this so you can make a string to throw in
//remove

#include <string>


template <class Key, class T>
HashTable<Key,T>::HashTable(){
   //Check out hashPrimes header file.
  backingArraySize = hashPrimes[NUM_HASH_PRIMES-2];

  backingArray = new HashRecord[backingArraySize];

  numItems = 0;

  numRemoved = 0;


}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {

    //deallocate the memory
    delete[]backingArray;

    //Avoid dangling pointers.
        backingArray = NULL;

}

//I moved hash function from main.
//If you want to make this program runs successfully, you need to add hash(Key k) declaration in USet.h and HashTable.h
template <class Key, class T>
unsigned long HashTable<Key,T>::hash(Key k){
  unsigned long m = hashPrimes[NUM_HASH_PRIMES-2];
  unsigned long ret = 0;
  for(int i=0;i<k.size();i++){
    ret = (256*ret + k[i])%m;
  }
  return ret;
}



template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  //Whenever numItems + numRemoved >= backingArraySize/2, call
  //grow(). grow() should make a new backing array that is twice the
  //size of the old one, similar to what we did in the ArrayQueue
  //lab.
  // If an item with Key k already exists, overwrite it


    if( numItems + numRemoved >= backingArraySize/2 ) grow();

    //You must define method called "hash" that takes a Key as input, and returns
    //an unsigned long (which is the hash value)


     unsigned long hashValue = hash(k);

        while( (backingArray[hashValue].isNull) == false && (backingArray[hashValue].isDel == false))
        {

         //Linear probing.
         hashValue = (hashValue + 1) %  backingArraySize;

        }

        //Set data
        backingArray[hashValue].x = x;

        //Set key(hash value)
        backingArray[hashValue].k = k;

        //Slot now is not empty.
    backingArray[hashValue].isNull = false;

        //increment numItems
        numItems++;


}


 //If the slot used to have something in it, but doesn't now, set
 //isDel to true, and isNull to false. isNull is only for slots
 //that have never been used

template <class Key, class T>
void HashTable<Key,T>::remove(Key k)
{

  if( keyExists(k) == false) {/*Do nothing*/}

  backingArray[hash(k)].isNull = false;

  backingArray[hash(k)].isDel = true;

  numItems--;

  numRemoved++;

}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){

   if(keyExists(k) == false) throw std::string("There is no such an element");

   //return data.
   return backingArray[hash(k)].x;

}



//If the slot used to have something in it, but doesn't now, set
//isDel to true, and isNull to false. isNull is only for slots
//that have never been used.
template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  if(backingArray[hash(k)].isNull == true || backingArray[hash(k)].isDel == true) return false;
  return true;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size()
{

   return numItems;

}

template <class Key, class T>
void HashTable<Key,T>::grow()
{

   int oldSize = backingArraySize;
   int newSize = 0;

   for(int i = 0;i<26;i++)
   {

      if(oldSize == hashPrimes[i])
          {
              //jump to next prime.
              newSize = hashPrimes[i+1];
          }
   }

   HashRecord* temp = backingArray;
   backingArraySize = newSize;
   backingArray = new HashRecord[backingArraySize];

   //Re-calculating.
   numItems = 0;
   numRemoved = 0;

   for(int k = 0;k<oldSize;k++){
      if( (temp[k].isNull) == false && (temp[k].isDel == false) )

                 {
                     add(temp[k].k,temp[k].x);

                 }
                }
                delete [] temp;
                temp = NULL;


}

