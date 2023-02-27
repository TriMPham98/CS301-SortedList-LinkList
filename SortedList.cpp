#include "SortedList.h"

template<class T>
SortedList<T>::SortedList() {
    length = 0;
    head = nullptr;
    currentPos = nullptr;
}

template<class T>
void SortedList<T>::MakeEmpty() {
    while (head != nullptr) {
        NodeT *temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    try {
        NodeT *temp = new NodeT;
        delete temp;
    } catch (std::bad_alloc error) {
        return true;
    }
    return false;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    NodeT *currPos = head;
    while (currPos != nullptr) {
        if (currPos->info == someItem) {
            return true;
        }
        currPos = currPos->next;
    }
    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    // 1. Check if the list is full, if yes, return.
    if (IsFull()) {
        return;
    }
    // 2. Create a new node, set its info to the given item,
    // and set its next to nullptr.
    NodeT *insertedNode = new NodeT;
    insertedNode->info = item;
    insertedNode->next = nullptr;
    // 3. Increment the length of the list.
    length++;

    // 4. If the list is currently empty (head is nullptr),
    // set the head to the new node and return.
    if (head == nullptr) {
        head = insertedNode;
        return;
    }
    // 5. Otherwise, set current position to head and
    // previous position to nullptr.
    NodeT *currPos = head;
    NodeT *prevPos = nullptr;

    // 6. While current position is not nullptr:
    // a. Check if the info of the current node is greater than the given item.
    // b. If true:
    // i. Set the next of the new node to the current node.
    // ii. If the current node is the head, set the head to the new node,
    //     otherwise set the next of the previous node to the new node.
    // iii. Return.
    // c. If false, set previous position to current position
    // and current position to the next node.
    while (currPos != nullptr) {
        if (currPos->info > item) {
            insertedNode->next = currPos;
            if (currPos == head) {
                head = insertedNode;
            } else {
                prevPos->next = insertedNode;
            }
            return;
        }
        prevPos = currPos;
        currPos = currPos->next;
    }
    // 7. If the while loop completes without returning,
    // it means that the new node is the largest element in the list.
    // Set the next of the previous node to the new node.
    prevPos->next = insertedNode;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    NodeT *currN = head;
    NodeT *prevN = nullptr;

    while (currN != nullptr) {
        if (currN->info == item) {
            if (prevN != nullptr) {
                prevN->next = currN->next;
            } else {
                head = currN->next;
            }
            delete currN;
            --length;
            break;
        }
        prevN = currN;
        currN = currN->next;
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = head;
}

template<class T>
T SortedList<T>::GetNextItem() {
    if (currentPos == nullptr || currentPos->next == nullptr) {
        throw "Out of bounds";
    }

    T itemToReturn = currentPos->info;
    currentPos = currentPos->next;
    return itemToReturn;
}

