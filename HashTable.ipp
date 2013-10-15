//You will need this so you can make a string to throw in
//remove

#include <string>
#include "hashPrimes.h"


template <class Key, class T>
HashTable<Key,T>::HashTable(){
  
  backingArray = new HashRecord[53];

  numItems = 0;

  numRemoved = 0;

  //Check out hashPrimes header file.
  backingArraySize = 53;

}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  
    //deallocate the memory
    delete[]backingArray;

    //Avoid dangling pointer.
	backingArray = NULL;

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

 
    //I am so confused where is this hash function?
	//Do I need to wirte my own hash function or using the hash function provided in main.cpp
	//and move that to HashTable.ipp?
	//No matter what, I assumed there is a hash function here.
     unsigned long hashValue = hash(k);

	while( (backingArray[hashValue].isNull) == false && (backingArray[hashValue].isDel == false) ) 
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
  
  if( keyExists(k) == false) throw std::string("There is no such an element");

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
  if(backingArray[hash(k)].isNull == true || backingArray[hash(k)].isDel == false) return false;
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

      if(backingArraySize == hashPrimes[i])
	  {
	      //jump to next prime.
		  i = i + 1;
	      newSize = hashPrimes[i];
		  i++;
	  }
   }

   HashRecord* temp = new HashRecord[newSize];


   for(int k = 0;k<oldSize;k++){
      if( (backingArray[k].isNull) == false && (backingArray[k].isDel == false) ) 
	     
		 {
		      int i = hash(backingArray[k]);

			  while(backingArray[i].isNull == false)
			  {
			       i = (i == newSize-1) ? 0 : i + 1;
			  }
			  temp [i] = backingArray[k];

		 }
		}
		backingArray = temp;

}

