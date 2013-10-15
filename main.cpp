#include "hashPrimes.h"
#include "HashTable.h"
#include <string>
#include <iostream>
#include <sstream>

/**
 * This is a hash function for strings, based on Horner's method. See
 * http://en.wikipedia.org/wiki/Horner's_method
 *
 * If you want to use the HashTable class with a different Key type, then
 * you would need to overload the hash() function, creating a version
 * with the appropriate input type.
 */
unsigned long hash(std::string k){
  unsigned long m = hashPrimes[NUM_HASH_PRIMES-2];
  unsigned long ret = 0;
  for(int i=0;i<k.size();i++){
    ret = (256*ret + k[i])%m;
  }
  return ret;
}

//Check to make sure that numItems returns correct result on a fresh
// instance of the LinkedList class
void testCtor(){
  HashTable<std::string,int> testTable;
  if(testTable.size() == 0){
    std::cout << "SUCCESS: Fresh hash table has 0 items" << std::endl;
  } else {
    std::cout << "ERROR: Fresh hash table should have 0 items, but has " << testTable.size() << std::endl;
    return;
  }
}

//Add and remove some items, making sure they come back in the
// correct order
void testBasicMethods(){
  HashTable<std::string,int> testHash;
  testHash.add("how",0);
  testHash.add("now",1);
  testHash.add("brown",2);
  testHash.add("cow",3);
  testHash.add("metal",4);
  testHash.add("daffodil",5);
  
  
  if(testHash.size() == 6){
    std::cout << "SUCCESS: 6 items added" << std::endl;
  } else {
    std::cout << "ERROR: Added 6 items, but size says " << testHash.size() << std::endl;
    return;
  }

  int x0 = testHash.find("how");
  int x1 = testHash.find("now");
  int x2 = testHash.find("brown");
  int x3 = testHash.find("cow");
  int x4 = testHash.find("metal");
  int x5 = testHash.find("daffodil");
  

  if(x0 != 0 || x1 != 1 || x2 != 2 || x3 != 3 || x4 != 4 || x5 != 5){
    std::cout << "ERROR: Expected 0,1,2,3,4,5, but got " << x0 <<"," << x1 << "," << x2 << "," << x3 << "," << x4 << "," << x5 << std::endl;
    return;
  } else {
    std::cout << "SUCCESS: 6 added items came back out with correct keys" << std::endl;
  }
  
  
  if(testHash.keyExists("daffodil")){
    std::cout << "SUCCESS: keyExists found 'daffodil'" << std::endl;
  } else {
    std::cout << "ERROR: 'daffodil' is a valid key, but keyExists said false" << std::endl;
    return;
  }
  
  if(!testHash.keyExists("shiny")){
    std::cout << "SUCCESS: keyExists did not find 'shiny'" << std::endl;
  } else {
    std::cout << "ERROR: 'shiny' is not a valid key, but keyExists said true" << std::endl;
    return;
  }
  
  /*
  bool didException = false;
  try {

    int xq = testHash.find("shiny");

  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << s << std::endl;
    didException = true;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
    return;
  }
  if(didException == false){
    std::cout << "ERROR: find did not throw an exception when given a non-existen key" << std::endl;
    return;
  }*/
  
  testHash.remove("how");
  testHash.remove("now");

  if(testHash.size() == 4){
    std::cout << "SUCCESS: 4 items after removing" << std::endl;
  } else {
    std::cout << "ERROR: After remove, expected 4 items, but size says " << testHash.size() << std::endl;
    return;
  }

  if(testHash.numRemoved == 2){
    std::cout << "SUCCESS: numRemoved is 2, as expected" << std::endl;
  } else {
    std::cout << "ERROR: After remove, expected numRemoved == 2, but got " << testHash.numRemoved << std::endl;
    return;
  }

  if(testHash.keyExists("how") == false){
    std::cout << "SUCCESS: Removed key 'how' is no longer in hash table." << std::endl;
  } else {
    std::cout << "ERROR: Removed key 'how' is still in the table" << std::endl;
    return;
  }

  if(testHash.keyExists("brown") && testHash.keyExists("cow") &&
       testHash.keyExists("metal") && testHash.keyExists("daffodil")){
    std::cout << "SUCCESS: The 4 items that weren't removed are still in the table." << std::endl;
  } else {
    std::cout << "ERROR: One of the 4 keys that ought to still be in the table has been lost" << std::endl;
    return;
  }
}

void testGrow(){
  HashTable<std::string,int> testHash;
  testHash.add("0",0);
  unsigned long startingSize = testHash.backingArraySize;
  unsigned long i=0;
  while(testHash.backingArraySize == startingSize){
    i++;
    std::ostringstream ss;
    ss << i;
    testHash.add(ss.str(),i);
  }
  unsigned long endingSize = testHash.backingArraySize;
  if(i*2 > startingSize){
    std::cout << "ERROR: You didn't grown soon enough. Starting size was " << startingSize << ", didn't grow until " << i+1 << "adds done." << std::endl;
    return;
  } else {
    std::cout << "SUCCESS: Grow called at the right time. Starting size was " << startingSize << " and grow called on the " << i+1 << "th add call" << std::endl;
  }

  if(testHash.size() == i+1){
    std::cout << "SUCCESS: Size of hash table unchanged by the grow" << std::endl;
  } else {
    std::cout << "ERROR: Size of hash table should be " << i+1 << ", but got " << testHash.size() << std::endl;
    return;
  }

  if(testHash.numRemoved == 0){
    std::cout << "SUCCESS: After grow called, all removed items have been cleared out." << std::endl;
  } else {
    std::cout << "ERROR: When grow is called, you should clear out all the removed items." << std::endl;
    return;
  }

  for(int j=0; j<=i;j++){
    std::ostringstream ss;
    ss << j;
    if(!testHash.keyExists(ss.str())){
      std::cout << "ERROR: During grow the item with key '" << j << "' was lost" << std::endl;
      return;
    }
  }
  std::cout << "SUCCESS: After grow all items from the original table made it to the new one." << std::endl;
}

//A simple main function which creates a list, and tests it.
int main(){
 testCtor();
 testBasicMethods();
 testGrow();

  return 0;
}
