//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c) { return 10*((unsigned long)c)%13; }
HashTable<char, int> myHashTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArraySize = hashPrimes[0];
	backingArray = new HashRecord[backingArraySize];
	numItems = 0;
	numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
	delete [] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){	
	// Don't need to check if a key exists already
	// because we are going to overwrite it if it does
	if (2*(numRemoved + numItems) >= backingArraySize-1)
		grow();

	int location = hash(k)%backingArraySize;

	while(backingArray[location].isNull == false && backingArray[location].isDel == false) {
		location = (location == backingArraySize-1) ? 0 : location + 1;
	}
	// Update information
	backingArray[location].k = k;
	backingArray[location].x = x;
	backingArray[location].isNull = false;
	numItems++;

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	int location = hash(k)%backingArraySize;

	while(backingArray[location].isNull == false && backingArray[location].isDel == false) 
		if(backingArray[location].k == k) {
			backingArray[location].x = NULL;
			backingArray[location].isDel = true;
			numItems--;
			numRemoved++;
		}
		location = (location == backingArraySize-1) ? 0 : location + 1;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	int location = hash(k)%backingArraySize;
	// Make sure spot has not been total empty by using isNull
	while(backingArray[location].isNull == false) {
		// Make sure that there is something in the location and see if that
		// locations.k is equal to the k that we were given
		if (backingArray[location].isDel == false && backingArray[location].k == k)
			return backingArray[location].x;
		location = (location == backingArraySize-1) ? 0 : location + 1;
	}
	throw std::string("Couldn't find item!");
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	int location = hash(k)%backingArraySize;
	// Make sure spot has not been total empty by using isNull
	while (backingArray[location].isNull == false) {
		if (backingArray[location].isDel == false && backingArray[location].k == k)
			return true;
		location = (location == backingArraySize-1) ? 0 : location + 1;	
	}
	// If not found then return false
	return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems; 
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	int primesCount = 0; // Keeps track of what prime number we should be on
	int newSize = hashPrimes[primesCount]; //new size of the new array
	while (newSize <= backingArraySize) {
		primesCount++;
		newSize = hashPrimes[primesCount];
	}

	HashRecord* currentArray = backingArray; // The original array
	HashRecord* temp = new HashRecord[newSize]; // New array to point to
	backingArray = temp; // Set the backingArray to the new pointer
	backingArraySize = newSize;
	numItems = 0;
	numRemoved = 0;

	for (int i = 0; i < hashPrimes[primesCount-1]; i++) { // i < Size of the old array
		if (currentArray[i].isNull == false && currentArray[i].isDel == false) {
			add (currentArray[i].k, currentArray[i].x);
		}
	}
	// Make sure to delete the original array  
	delete [] currentArray;
}
