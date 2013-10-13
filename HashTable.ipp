//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  backingArray= new HashRecord[53];
  //backingArray->x;
  //backingArray->x= new T[53];
  numItems=0;
  numRemoved=0;
  backingArraySize=53;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  //~backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  if(!keyExists(k)){
	HashRecord* hash = new HashRecord();
	hash->isNull=false;
	hash->k=k;
	hash->x=x;
	int q=0;
    for(unsigned int i=0;i<k.length()-1;i++){
		char c =k.at(i);
		q=q+((int) (c));
}
	backingArray[q%backingArraySize]=*hash;

	numItems++;
  }
  else{throw (std::string) "Can't add a copy of a key";}
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	if(keyExists(k)){
	  int q=0;
  for(unsigned int i=0;i<k.length()-1;i++){
	char c =k.at(i);
	q=q+((int) (c));
}
	HashRecord x= backingArray[q];
	x.isDel=true;
	}
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  if(keyExists(k)){
  int q=0;
  for(unsigned int i=0;i<k.length()-1;i++){
	char c =k.at(i);
	q=q+((int) (c));
}
	T z=backingArray[q%backingArraySize].x;
  return z;
  }
  else
  throw((std::string) "That key doesn't exist");
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  int q=0;
  for(int i=0;i<k.length()-1;i++){
	char c =k.at(i);
	q=q+((int) (c));
}
  if(!backingArray[q%backingArraySize].isNull||!backingArray[q%backingArraySize].isDel){
  return false;
  }
  return true;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
}

