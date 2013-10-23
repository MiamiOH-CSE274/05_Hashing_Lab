//You will need this so you can make a string to throw in
//remove

#include <string>


/**
   Implement hash table by using double hashing.

**/


template <class Key, class T>
HashTable<Key,T>::HashTable()
{

  //Check out hashPrimes header file.
  backingArraySize = hashPrimes[0];

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




template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x)
{

     //First one is double-hashing.

     if( numItems + numRemoved >= backingArraySize/2 )
     {
        grow();
     }

     unsigned long index = hash(k) % backingArraySize;


     while(backingArray[index].isNull == false && backingArray[index].k != k)
     {

                index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;
     }

          backingArray[index].x = x;
          backingArray[index].k = k;
          backingArray[index].isNull = false;
          numItems++;

     }



 //If the slot used to have something in it, but doesn't now, set
 //isDel to true, and isNull to false. isNull is only for slots
 //that have never been used

template <class Key, class T>
void HashTable<Key,T>::remove(Key k)
{
    unsigned long index = hash(k) % backingArraySize;

    if(keyExists(k) == false) {/*Do nothing*/}

    for(int i = 0;i<(int)backingArraySize;i++)
    {

        if(backingArray[index].k == k)
        {
            backingArray[index].isNull = false;
            backingArray[index].isDel = true;
            numItems--;
            numRemoved++;
            break;
        }

        index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;

    }
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k)
{

   if(keyExists(k) == false)
   {
       throw std::string("There is no such an element");

   }

   else
   {
      unsigned long index = hash(k) % backingArraySize;

      for(int i = 0;i<(int)backingArraySize;i++)
      {

          if(backingArray[index].k == k)
          {
              return (backingArray[index].x);
          }

          index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;

      }

   }
}



//If the slot used to have something in it, but doesn't now, set
//isDel to true, and isNull to false. isNull is only for slots
//that have never been used.
template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k)
{


      unsigned long index = hash(k) % backingArraySize;


      for(int i = 0;i< (int)backingArraySize;i++)
      {

        if(backingArray[index].k == k && backingArray[index].isDel == false)
          {
                return true;

          }

          {
            index = (index + (1 + index % (backingArraySize-1))) % backingArraySize;

          }
     }
          return false;
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



