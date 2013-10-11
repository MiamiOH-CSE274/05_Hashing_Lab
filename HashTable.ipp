//You will need this so you can make a string to throw in
// remove
#include <string>
unsigned long hash(std::string k, unsigned long bAS){
    unsigned long m = bAS;
    unsigned long ret = 0;
    for(int i=0;i<k.size();i++){
        ret = (256*ret + k[i])%m;
    }
    return ret;
}
template <class Key, class T>
HashTable<Key,T>::HashTable(){
    backingArraySize = hashPrimes[0];
    backingArray = new HashRecord[backingArraySize];
    numRemoved = 0;
    numItems = 0;
    
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
    delete [] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
    unsigned long index = hash(k, backingArraySize);
    
    if(keyExists(k)){
        T data = find(k);
        data= x;
        
    }
    
    else{
        
        if (backingArray[index].isDel || backingArray[index].isNull) {
            //Avoids the unecessary searching and jumping if we can
            //add it right away
        }
            else{
                unsigned long jumpDist = 1+(index%(backingArraySize-1));
                index = (index+jumpDist)%backingArraySize;
                
                while(!backingArray[index].isNull || !backingArray[index].isDel){
                    index = (index+jumpDist)%backingArraySize;
                }
                
            }
        }
    backingArray[index].k = k;
    backingArray[index].x = x;
    backingArray[index].isNull = false;
    if(backingArray[index].isDel == true)
        backingArray[inde].isDel = false;
    backingArray[index].isDel=false;
    
    numItems++;
    
    if (numItems + numRemoved >=backingArraySize/2) {
        grow();
    }
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key key){
    if (keyExists(key)) {
        unsigned long index = hash(key, backingArraySize);
        
        while (backingArray[index].k !=key) {
            unsigned long jumpDist = 1+(index%(backingArraySize-1));
            index = (index+jumpDist)%backingArraySize;

        }
        numItems--;
        numRemoved++;
        backingArray[index].isDel = true;
    }

}

template <class Key, class T>
T HashTable<Key,T>::find(Key key){
    unsigned long index = hash(key, backingArraySize);
    
    if (backingArray[index].isDel || !backingArray[index].isNull) {
        if (backingArray[index].k == key) {
            return backingArray[index].x;
        }
        else{
            unsigned long jumpDist = 1+(index%(backingArraySize-1));
            unsigned long startingIndex = index;
            index = (index+jumpDist)%backingArraySize;
            
            while(!backingArray[index].isNull || index!=startingIndex){
                if (backingArray[index].k == key) {
                    return backingArray[index].x;
                }
                else index = (index+jumpDist)%backingArraySize;
            }
        }
    }
    throw (std::string) "Data not in the HashTable.";
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key key){
  unsigned long index = hash(key, backingArraySize);
  
    if (!backingArray[index].isDel && !backingArray[index].isNull) {
        if (backingArray[index].k == key) {
            return true;
        }
        else{
            unsigned long jumpDist = 1+(index%(backingArraySize-1));
            unsigned long startingIndex = index;
            index = (index+jumpDist)%backingArraySize;
            
            while(!backingArray[index].isNull || index!=startingIndex){
                if (!backingArray[index].isDel && backingArray[index].k == key) {
                    return true;
                }
                else index = (index+jumpDist)%backingArraySize;
            }
        }
    }
    
    return false;
    
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
    
    
    
}