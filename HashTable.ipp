//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
HashTable<char,int> mySillyTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArray = new HashRecord();
	numItems = 0;
	//backingArraySize = 0;
	//numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	if (2*numItems < backingArraySize) {
	//	grow();
		}
	//Change key to int
	int key = 0;
	//for (int i = 0; i < k.length(); i++){
	//	key = (key * 256 + k.charAt(i)) % backingArraySize;
	//	}
	//backingArray[k] = x;
	numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
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




  T dummy;
  return dummy;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){

/*	int i = hash(k);
	while (backingArray[i].isNull == false){
		if (backingArray[i].isDel == false && backingArray[i] == k)
			//return backingArray[i];
			return true;
		}*/
	
//	for (int i = 0; i < backingArraySize; i++){
//		if (backingArray[i] == k)
//			return true;
//	}

  return false;
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
		temp[i] = backingArray[i];
		}
	//backingArraySize = hashPrimes[cnt+1];
	//cnt++;
}
