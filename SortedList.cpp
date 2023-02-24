
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
    return false;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
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

}

template<class T>
void SortedList<T>::ResetIterator() {

}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }

    return T();
}

