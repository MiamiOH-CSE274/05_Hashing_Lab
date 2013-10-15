//You will need this so you can make a string to throw in
// remove
#include <string>

int table;
template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArray= new HashRecord[53];
  table=1;
  numItems=0;
  numRemoved=0;
  backingArraySize=53;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
//if(!keyExists(k)){
	if(numItems + numRemoved >= backingArraySize/2)
		grow();
	int place=hash(k)%backingArraySize;
	int check = place;
	bool increase=true;
	while( !backingArray[check].isNull){
		check= (check+1+(hash(k)%(backingArraySize-1)))%backingArraySize;
		if(backingArray[check].isNull && backingArray[check].k.compare(k)==0){
			place=check;
			break;
		}
		if(backingArray[check].isNull){
			place = check;
			//increase=false;
			break;
		}
	}
	while(backingArray[check].isDel || !backingArray[check].isNull){
		check = check+(hash(k)%(backingArraySize-1))%backingArraySize;
			if(backingArray[check].isNull && !backingArray[check].isDel){
				increase=false;
				break;
			}
			if(backingArray[check].k.compare(k)==0 && !backingArray[check].isNull){
				place = check;
				break;
			}
	}
	backingArray[place].x = x;
	backingArray[place].k = k;
	if(increase)
		numItems++;
	backingArray[place].isNull = false;
	backingArray[place].isDel = false;
	
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	 if(keyExists(k)){
	 int hasher = hash(k)%backingArraySize;
	 HashRecord z=backingArray[hasher];
	 while(z.k.compare(k)!=0){
		hasher++;
		z=backingArray[hasher];
	}
	backingArray[hasher].k="antidisastablishmentarianism";
	backingArray[hasher].isDel=true;
	numItems--;
	numRemoved++;
	}
    else
  throw((std::string) "That key doesn't exist");
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if(keyExists(k)){
	 int hasher = hash(k)%backingArraySize;
	 HashRecord z=backingArray[hasher];
	 while(z.k.compare(k)!=0){
		hasher++;
		z=backingArray[hasher];
	}
	return z.x;

	}
    else
  throw((std::string) "That key doesn't exist");
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	int q = hash(k)%backingArraySize;
	//HashRecord x=backingArray[q];
	while(!backingArray[q].isNull || backingArray[q].isDel){
		if(backingArray[q].k.compare(k) == 0 && !backingArray[q].isDel){
			return true;
		}
		q = (q+1+(hash(k)%(backingArraySize-1)))%backingArraySize;
	}
  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  HashRecord* old= backingArray;
  backingArraySize=hashPrimes[table];
  backingArray= new HashRecord[backingArraySize];
  table++;
  for(unsigned int i=0;i<hashPrimes[table-2];i++){
	if(!old[i].isNull||!old[i].isDel)
		add(old[i].k, old[i].x);
  }
  delete[] old;
}
