//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/24

template <class Key, class T>
class USet {
 public:
  //Return the number of items currently in the USet
  virtual unsigned long size() = 0;

  //Add a new item, x, with Key k.
  // If an item with Key k already exists, overwrite it
  virtual void add(Key k, T x) = 0;

  //Remove the item with Key k. If there is no such item, do nothing.
  virtual void remove(Key k) = 0;

  //Return the item with Key k. 
  // If there is no such item, throw an exception.
  virtual T find(Key k) = 0;
  //Return true if there is an item with Key k in the table. If not,
  // return false
  virtual bool keyExists(Key k) = 0;

};
