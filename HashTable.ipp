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

//template <class Key, class T>


template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	//TODO
	if (2*numItems > backingArraySize) {
	//grow();
	}
	
	int place = hash(k);
	int index = place%backingArraySize;
	int jump = 1+ (place % (backingArraySize - 1));

	int i = index;
	//while (backingArray[i].isNull == true){	
		std::cout << "HERE";
		//backingArray[i] = x;
		backingArray[index].x = x;
		backingArray[i].isNull = false;
		backingArray->k = k;
		//std::cout << "DAFDA" << backingArray->k << std::endl;
		//std::cout << "kk" << backingArray[i].k << std::endl;
		//i = i + jump;
	//}
	
  numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	//HashTable<Key, T> temp = find(k);
	int place = hash(k);
	int index = place%backingArraySize;
	int jump = 1+ (place % (backingArraySize - 1));
	
	backingArray[index].x = NULL;
	
	backingArray[index].isDel = true;
	numItems--;
	numRemoved++;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){

	int place = hash(k);
	int index = place % backingArraySize;

	return backingArray[index].x;

	/*HashRecord p;
	p.k = k;
	int place = hash(k);
	int index = place % backingArraySize;
	std::cout << "p.k" << p.k << std::endl;
	p.k = backingArray[index].k;
	std::cout << "p.k" << p.k << std::endl;
	
	int jump = 1 + (place%(backingArraySize - 1));
	std::cout << "HERE!!!!2" << std::endl;
	int i = index;
	std::cout << "Hash" << hash(backingArray[i].k) << std::endl;
	while (!backingArray[i].isNull) {
	std::cout << "HERE!!!!3" << std::endl;
		if (hash(backingArray[i].k) == index){
			std::cout << "HERE!!!!1" << std::endl;
			return backingArray[i].x;
		}
		else {
			i = i + jump;
		}
	}*/
	//return backingArray[i].x;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	
	int place = hash(k);
	int index = place % backingArraySize;
	std::cout << backingArray[index].x << std::endl;
	std::cout << k << std::endl;
	//int place1 = hash(backingArray[index].k);
	std::cout << "DD" << backingArray->k;

	if (backingArray[index].isNull == false && backingArray[index].isDel == false){
		//if (hash(backingArray[index].k) == place)
			return true;
	}
	else {
		//throw (std::string) "Invalid Key!";
	}

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
temp[i].x = backingArray[i].x;
if (backingArraySize < hashPrimes[i]){
backingArraySize = hashPrimes[i];
//backingArray.add(temp[i]);
}
}
backingArray = temp;
}
