#include "HashTable.h"
#include <string>
#include <iostream>

//Check to make sure that numItems returns correct result on a fresh
// instance of the LinkedList class
void testCtor(){
  HashTable<std::string,int> testTable;
  if(testTable.size() == 0){
    std::cout << "SUCCESS: Fresh hash table has 0 items" << std::endl;
  } else {
    std::cout << "ERROR: Fresh hash table should have 0 items, but has " << testTable.size() << std::endl;
  }
}

//Add and remove some items, making sure they come back in the
// correct order
void testBasicMethods(){
  /*  HashTable<string,int> testList;
  testList.add(0,0);
  testList.add(0,1);
  testList.add(0,2);
  testList.add(3,3);
  testList.add(4,4);
  testList.add(5,5);

  if(testList.size() == 6){
    std::cout << "SUCCESS: 6 items added" << std::endl;
  } else {
    std::cout << "ERROR: Added 6 items, but size says " << testList.size() << std::endl;
    return;
  }

  int x0 = testList.get(0);
  int x1 = testList.get(1);
  int x2 = testList.get(2);
  int x3 = testList.get(3);
  int x4 = testList.get(4);
  int x5 = testList.get(5);

  if(x0 != 2 || x1 != 1 || x2 != 0 || x3 != 3 || x4 != 4 || x5 != 5){
    std::cout << "ERROR: Expected 2,1,0,3,4,5, but got " << x0 <<"," << x1 << "," << x2 << "," << x3 << "," << x4 << "," << x5 << std::endl;
  } else {
    std::cout << "SUCCESS: 6 added items came back out in the correct order" << std::endl;
  }

  testList.remove(5);
  testList.remove(0);

  if(testList.size() == 4){
    std::cout << "SUCCESS: 4 items after removing" << std::endl;
  } else {
    std::cout << "ERROR: After remove, expected 4 items, but size says " << testList.size() << std::endl;
    return;
  }

  x0 = testList.get(0);
  x1 = testList.get(1);
  x2 = testList.get(2);
  x3 = testList.get(3);

  if(x0 != 1 || x1 != 0 || x2 != 3 || x3 != 4){
    std::cout << "ERROR: After remove, expected 1,0,3,4, but got " << x0 <<"," << x1 << "," << x2 << "," << x3 << std::endl;
  } else {
    std::cout << "SUCCESS: After remove, 4 items came back out in the correct order" << std::endl;
  }

  testList.set(0,14);
  testList.set(1,13);
  testList.set(2,12);
  testList.set(3,11);
  if(testList.size() == 4){
    std::cout << "SUCCESS: List size not changed after set" << std::endl;
  } else {
    std::cout << "ERROR: After set, expected 4 items, but size says " << testList.size() << std::endl;
    return;
  }

  x0 = testList.get(0);
  x1 = testList.get(1);
  x2 = testList.get(2);
  x3 = testList.get(3);
  if(x0 != 14 || x1 != 13 || x2 != 12 || x3 != 11){
    std::cout << "ERROR: After set, expected 14,13,12,11, but got " << x0 <<"," << x1 << "," << x2 << "," << x3 << std::endl;
  } else {
    std::cout << "SUCCESS: After set, 4 items came back out in the correct order" << std::endl;
    }*/
}

void testExceptions(){
  /*  HashTable<string,int> testList;
  bool didException = false;
  try {
    testList.remove(0);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << s << std::endl;
    didException = true;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
    return;
  }

  if(!didException){
    std::cout << "ERROR: Tried to remove from an empty list, but did not get an exception" << std::endl;
  }

  testList.add(0,0);
  testList.add(0,1);
  testList.add(0,2);

  didException = false;
  try {
    testList.set(5,5);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << s << std::endl;
    didException = true;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
    return;
  }

  if(!didException){
    std::cout << "ERROR: Tried to set a non-existent item, but did not get an exception" << std::endl;
  }

  didException = false;
  try {
    int t = testList.get(5);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << s << std::endl;
    didException = true;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
    return;
  }

  if(!didException){
    std::cout << "ERROR: Tried to get a non-existent item, but did not get an exception" << std::endl;
  }

  didException = false;
  try {
    testList.add(5,5);
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << s << std::endl;
    didException = true;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
    return;
  }

  if(!didException){
    std::cout << "ERROR: Tried to add at invalid index, but did not get an exception" << std::endl;
  }
  */

}

//A simple main function which creates a list, and tests it.
int main(){
  testCtor();
  testBasicMethods();
  testExceptions();

  return 0;
}
