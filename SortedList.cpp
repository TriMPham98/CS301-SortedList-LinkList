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
    if (IsFull()) {
        return;
    }

    NodeT *insertedNode = new NodeT;
    insertedNode->info = item;
    insertedNode->next = nullptr;
    length++;

    if (head == nullptr) {
        head = insertedNode;
        return;
    }

    NodeT *currPos = head;
    NodeT *prevPos = nullptr;

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

