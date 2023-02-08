#ifndef SORTEDLIST_H
#define SORTEDLIST_H

const int MAX_ITEMS = 5;

template<class T>
class SortedList
{
public:
  SortedList();
  // Constructor
  
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  bool Contains(T someItem);
  // Function: Determines if someItem is in the list.
  // Pre:  List has been initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then the function returns true.
  // 	     otherwise it will return false. List is unchanged.

  void PutItem(T item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  // Post: item is in list if list is not full.  If list is full, no change occurs.

  void DeleteItem(T item);
  // Function: Deletes the first element whose key matches item's key.
  // Pre:  ???
  // Post: ???    

  void ResetIterator();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  int GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  struct NodeT {
      T info;
      NodeT* next;
  };

  int length;
  NodeT* head;
};

#include "SortedList.cpp"


#endif
