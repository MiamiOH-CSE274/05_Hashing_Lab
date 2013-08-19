
//unsigned long hash(char c){ return 10*((unsigned long)c)%13; }




template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArraySize = 53;
	backingArray = new HashRecord[backingArraySize];
	numItems = 0;
	numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable(){
	delete [] backingArray;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
	if(numItems + numRemoved >= backingArraySize/2){
		grow();
	}

	unsigned long hashed = hash(k);
	
	while(!backingArray[hashed].isNull){
		hashed = (hashed+1)%backingArraySize;
	}
	backingArray[hashed].x = x;
	backingArray[hashed].k = k;
	backingArray[hashed].isNull = false;
	numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	if(!keyExists(k))
		return;
	backingArray[hash(k)].isDel = true;
	backingArray[hash(k)].isNull = false;
	numItems--;
	numRemoved++;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	T item = backingArray[hash(k)].x;
	if(!keyExists(k))
		throw std::string("No such item");
	return item;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	if(backingArray[hash(k)].isNull || backingArray[hash(k)].isDel)
		return false;
	return true;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	int prime = 0;
	int oldPrime = 0;
	for(int i=0;i<=25;i++){
		if(hashPrimes[i] == backingArraySize){
			oldPrime = hashPrimes[i];
			prime = hashPrimes[i+1];
			break;
		}
	}

	HashRecord* tmp = backingArray;
	backingArraySize = prime;
	backingArray = new HashRecord[backingArraySize];
	numItems = 0;
	numRemoved = 0;

	for(int j=0;j<oldPrime;j++){
		if(!tmp[j].isNull && !tmp[j].isDel){
			add(tmp[j].k,tmp[j].x);
		}
	}
	delete [] tmp;
	
}