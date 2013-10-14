//You will need this so you can make a string to throw in
// remove
#include <string>

int p;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArray = new HashRecord[hashPrimes[0]];
  p = 1;
  numItems = 0;
  numRemoved = 0;
  backingArraySize = hashPrimes[0];
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	if(numItems + numRemoved >= backingArraySize/2){
		grow();
	}
	int placeHere = hash(k)%backingArraySize;
	int checkHere = placeHere;
	bool noIncrease = false;
	while(!backingArray[checkHere].isNull){
		checkHere = (checkHere+jump(k))%backingArraySize;
		if(!backingArray[checkHere].isNull && backingArray[checkHere].k.compare(k)==0){
			placeHere = checkHere;
			noIncrease = true;
			break;
		}
		if(backingArray[checkHere].isNull){
			placeHere = checkHere;
			break;
		}
	}
	while(backingArray[checkHere].isDel || !backingArray[checkHere].isNull){
		checkHere = (checkHere+jump(k))%backingArraySize;
		if(backingArray[checkHere].isNull && !backingArray[checkHere].isDel){
			break;
		}
		if(backingArray[checkHere].k.compare(k)==0 && !backingArray[checkHere].isNull){
			placeHere = checkHere;
			noIncrease = true;
			break;
		}
	}
	backingArray[placeHere].x = x;
	backingArray[placeHere].k = k;
	if(!noIncrease){
		numItems++;
	}
	backingArray[placeHere].isNull = false;
	backingArray[placeHere].isDel = false;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	int remove = hash(k)%backingArraySize;
	while(!backingArray[remove].isNull || backingArray[remove].isDel){
		if(backingArray[remove].k.compare(k) == 0){
			backingArray[remove].isNull = true;
			backingArray[remove].isDel = true;
			numItems--;
			numRemoved++;
		}
		remove = (remove+jump(k))%backingArraySize;
	}
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	int checkHere = hash(k)%backingArraySize;
	while(!backingArray[checkHere].isNull || backingArray[checkHere].isDel){
		if(backingArray[checkHere].k.compare(k) == 0 && !backingArray[checkHere].isDel){
			return backingArray[checkHere].x;
		}
		checkHere = (checkHere+jump(k))%backingArraySize;
	}
	throw (std::string)"No such key exists.";
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	int checkHere = hash(k)%backingArraySize;
	while(!backingArray[checkHere].isNull || backingArray[checkHere].isDel){
		if(backingArray[checkHere].k.compare(k) == 0 && !backingArray[checkHere].isDel){
			return true;
		}
		checkHere = (checkHere+jump(k))%backingArraySize;
	}
  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  HashRecord* oldArray = backingArray;
  backingArray = new HashRecord[hashPrimes[p]];
  int oldBackingArraySize = backingArraySize;
  backingArraySize = hashPrimes[p];
  p++;
  numItems = 0;
  for(int i = 0; i<oldBackingArraySize; i++){
	if(!oldArray[i].isNull)
		add(oldArray[i].k, oldArray[i].x);
  }
  delete[] oldArray;
}

template <class Key, class T>
int HashTable<Key,T>::jump(Key k){
	return 1+(hash(k)%(backingArraySize-1));
}
