//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[hashPrimes[0]];
  numItems = 0;
  numRemoved = 0;

}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	if( numItems + numRemoved > backingArraySize/2){
		grow();
	}
  
  int place = hash(k);
  int index = place % backingArraySize;

  backingArray[index].x = x;
  backingArray[index].isNull = false;
  backingArray -> k = k;
  numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  int place = hash(k)%backingArraySize;
  while(!backingArray[place].isNull || backingArray[place].isDel){
    backingArray[place].isNull = true;
	backingArray[place].isDel = true;
	numRemoved++;
	numItems--;
  }
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if(keyExists(k) == false)
    throw std::string("This key does not exists.");

	int place = hash(k)%backingArraySize;
	int jump = 1 + (hash(k)%(backingArraySize - 1));

	while(backingArray[place].isNull == false && backingArray[place].isDel == false){
		if(backingArray[place].k == k){
		   return backingArray[place].x;
		   }
		place = place + jump;
	} 
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	bool exists;
	int place = hash(k)%backingArraySize;
		
	if (backingArray[place].k == k && backingArray[place].isDel == false)
		exists = true;
	else 
		exists = false;
   return exists;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}
