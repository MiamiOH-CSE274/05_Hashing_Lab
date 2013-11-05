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
	//TODO
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	//TODO
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	// Going to try and use T as the return type instead of int. 
	T location = hash(k)%backingArraySize;
	// Make sure spot is has not been total empty by using isNull
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
	//TODO
	return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems; 
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	//TODO
}
