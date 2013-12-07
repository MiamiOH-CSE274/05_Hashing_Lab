//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
HashTable<char,int> mySillyTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){ 

  //Creating a new HashTable
  backingArraySize = hashPrimes[0];
  backingArray = new HashRecord[backingArraySize];
  numItems = 0;
  numRemoved = 0;

}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {

  //Destructor for our HashTable
  delete []backingArray;

}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){ 

  // First, check the load of the array and see if we should grow
  // Next, we'll hash the data and then find where we should put it
  // Afterwards, check the position (HashRecord has isNull and isDel)
  //     - If collision: move down a spot and keep checking
  //     - If no collision: plop that sucker in there and change isNull and isDel
  // Increment numItems by 1

  if(2*(numRemoved+numItems)>=backingArraySize){
	grow();
  }
  int i = hash(k)%backingArraySize;
  while(backingArray[i].isNull==false && backingArray[i].isDel==false)
  {
		i=i++;
		i=i%backingArraySize;
  }

  // We're now at the place to add
  backingArray[i].x=x;
  backingArray[i].k=k;
  backingArray[i].isNull=false;
  numItems++;

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){

  // Hash the value, then find where it is (if able)
  //     - Keep comparing the key to the index's key while
  //       incrementing the index by 1 while isNull is false 
  // On find: Set the data to null, set isDel to true,
  //          decrement numItems and increment numRemoved

  int i = hash(k)%backingArraySize;
  while(backingArray[i].isNull==false)
  {
	if(backingArray[i].isDel == false && backingArray[i].k == k){
		backingArray[i].isDel = true;
		numItems--;
		numRemoved++;}
	i=i++;
	i=i%backingArraySize;
  }


}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){

  // Hash the data and then iterate through trying to find it
  //  - check the position using HashRecord isNull and isDel)
  // If found, return it, else keep iterating so long as it isn't null

  /*for(int i = hask(k)%backingArraySize; backingArray[i].isNull==false; i++%backingArraySize){
	if(backingArray[i].k == k && backingArray[i].isDel == false)
		return backingArray[i].x;
  }*/

  int i = hash(k)%backingArraySize;
  while(backingArray[i].isNull==false)
  {
	if(backingArray[i].isDel == false && backingArray[i].k == k)
		return backingArray[i].x;
	i=i++;
	i=i%backingArraySize;
  }
  
  //We didn't find it, captain.
  throw std::string("Your item doesn't exist, captain!");

}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
 
  // Pretty much the same thing as find, but return boolean values
    int i = hash(k)%backingArraySize;
  while(backingArray[i].isNull==false)
  {
	if(backingArray[i].isDel == false && backingArray[i].k == k)
		return true;
	i=i++;
	i=i%backingArraySize;
  }
  return false;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){

  // Return the size of the backing array
  return numItems;

}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  
  // Create a new array that's larger than our current one using primes
  // Add all our previous values to the new array
  // Change the flags back to zeroes
  // Change our pointer to the new array
  // Delete the old array
  //std::cout << "backingArraySize" << backingArraySize << std::endl;

  
  unsigned long biggerSize=0;
  unsigned long currentHashPrime = 0;
  /*for(int i=0; biggerSize<=backingArraySize; i++)
  {
	currentHashPrime++;
	biggerSize=hashPrimes[currentHashPrime];
	backingArraySize=hashPrimes[currentHashPrime];
  }*/

  while(backingArraySize>=hashPrimes[currentHashPrime]){
	currentHashPrime++;
  }
  biggerSize=hashPrimes[currentHashPrime];
  
  HashRecord* oldBackingArray = backingArray;
  backingArraySize = biggerSize;
  backingArray = new HashRecord[backingArraySize];
  numItems=0;

  for(unsigned long i=0; i<hashPrimes[currentHashPrime-1]; i++) {
	if(!oldBackingArray[i].isNull&&!oldBackingArray[i].isDel)
		add(backingArray[i].k, backingArray[i].x);
  }

  delete [] oldBackingArray;
  
  
}
