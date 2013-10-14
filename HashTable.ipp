//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
HashTable<char,int> mySillyTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArray = new HashRecord();
	numItems = 0;
	backingArraySize = 13;
	numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	//TODO
	if (2*numItems > backingArraySize) {
	//grow();
	}

	int place = hash(k);
	std::cout << hash(k) << std::endl;

	int index = place%backingArraySize;
	//std::cout << index;

	//for (int i = 0; i < backingArraySize; i++){
	if (backingArray[index].isNull == false){
		int jump = 1+ (place % (backingArraySize - 1));
		backingArray[index+jump].x = x;
		backingArray[index+jump].isNull = false;
		backingArray[index+jump].k = k;
	}
	else {
		backingArray[index].x = x;
		backingArray[index].isNull = false;
		//backingArray[index].k = k;
	}
	//}

//for (int i = 0; i < backingArraySize; i++){
//}
	
  numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  numItems--;
  numRemoved++;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	int place = hash(k);
	int index = place % backingArraySize;
	int jump = 1 + (place%(backingArraySize - 1));
	
	int i = index;
	std::cout << "INDEX" << i << std::endl;
	std::cout << "hey" << backingArray[i].isNull << std::endl;
	while (!backingArray[i].isNull) {
		std::cout << "returning" << hash(backingArray[index].k) << std::endl;
		std::cout << "key2" << hash(k)%backingArraySize << std::endl;
		if (hash(backingArray[i].k) == hash(k)%backingArraySize){
			std::cout << "HERE";
			return backingArray[i].x;
			backingArray[i].isNull = false;
		}
		i = i + jump;
		std::cout << "INDEX.." << i << std::endl;
	}
	//return backingArray[i].x;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){

	if (find(k) == true){
		return true;
	}

 	return false;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}
