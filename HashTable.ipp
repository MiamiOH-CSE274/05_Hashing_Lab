//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ 
	//return ((unsigned long)c);
	int total = 0;
	return ((unsigned long)c)%11; 
}

HashTable<char,int> myTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArray = new HashRecord();
	numItems = 0;
	backingArraySize = 11;
	numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	
	if (2*numItems < backingArraySize) {
		//grow();
	}

	int place = hash(k);
	std::cout << hash(k) << std::endl;

	int index = place%backingArraySize;
	//std::cout << index;
	
	//for (int i = 0; i < backingArraySize; i++){
		if (backingArray[index].isNull == false){
			// JUMP
			//index = index*2;
		}
		backingArray[index].x = x;

	//}
	
	for (int i = 0; i < backingArraySize; i++){
	}
	numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  numRemoved++;
  numItems--;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	int place = hash(k);
	int index = place % backingArraySize;

	if (backingArray[index].k == k){
		return backingArray[index].x;
	}
	//T dummy;
	//return dummy;
	//int j = backingArray(k);
	//for (int i = 0; i < backingArraySize; i++){
		//if (k == backingArray[i])
	//		return i;
//			}
  //TODO
  //int i = hash(k);
  //while(backingArray[i] != null) {
	//if (backingArray[i] !=
//for (int i = 0; i < backingArraySize; i++){
//	if (backingArray[i] == (k)){
//		return i;
//		}
//		}
  //T dummy;
  //return dummy;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	if (find(k)== true){
		return true;
	}
	return false;


/*	int i = hash(k);
	while (backingArray[i].isNull == false){
		if (backingArray[i].isDel == false && backingArray[i] == k)
			//return backingArray[i];
			return true;
		}*/
	
  //return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){

	HashRecord temp = new HashRecord();
	//int cnt;
	for (int i = 0; i < backingArraySize; i++){
		temp[i].x = backingArray[i].x;
		if (backingArraySize < hashPrimes[i]){
			backingArraySize = hashPrimes[i];
			//backingArray.add(temp[i]);
			}
		}
	backingArray = temp;
}