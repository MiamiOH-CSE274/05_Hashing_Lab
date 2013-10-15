//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ return 10*((unsigned long)c)%11; }
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

	if (numItems+numRemoved >= backingArraySize/2){
		//grow();
	}
	
	int place = hash(k);
	int index = place % backingArraySize;
	//int jump = 1 + (place % (backingArraySize - 1));
		
			backingArray[index].x = x;
			backingArray[index].isNull = false;
			backingArray->k = k;
			
	numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	
	int place = hash(k);
	int index = place%backingArraySize;
	int jump = 1 + (place % (backingArraySize - 1));
	
	backingArray[index].x = NULL;
	
	backingArray[index].isDel = true;
	numItems--;
	numRemoved++;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	if (keyExists(k) == 0){
		//throw (std::string) "invalid key";
	}
	int place = hash(k);
	int index = place % backingArraySize;

	return backingArray[index].x;

	/*HashRecord p;
	p.k = k;
	int place = hash(k);
	int index = place % backingArraySize;
	p.k = backingArray[index].k;
	
	int jump = 1 + (place%(backingArraySize - 1));
	int i = index;
	while (!backingArray[i].isNull) {
		if (hash(backingArray[i].k) == index){
			return backingArray[i].x;
		}
		else {
			i = i + jump;
		}
	}*/
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	
	int place = hash(k);
	int index = place % backingArraySize;
	
	if (backingArray[index].isNull == false && backingArray[index].isDel == false){
		return true;
	}
 	return false;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	
 /* HashRecord* temp = new HashRecord();
    HashTable<std::string,int> test = temp;
	int cnt;
	int size = backingArraySize;
	for (int i = 0; i < size; i++){
		temp.add(backingArray[i].k,backingArray[i].x);
		temp[i] = backingArray[i];
		temp->k = backingArray->k;
		if (backingArraySize < hashPrimes[i]){
			backingArraySize = hashPrimes[i];
			HashTable temp = new HashTable[backingArraySize];
			backingArray.add(temp[i]);
	}
	
	
	}

backingArray = temp;
delete temp;*/
}
