/***
 *	Name: LinkedList.h
 *	Author: Albert Lloveras Carbonell (alloveras@salleurl.edu)
 *	Last Revision: 18/07/2016
 *	Description: This class implements a generic dynamic list that
 *	can hold any type of data.
***/

#ifndef _LSMAKER_COLLECTIONS_LINKEDLIST_H_
#define _LSMAKER_COLLECTIONS_LINKEDLIST_H_

template <class T> class LinkedList{

  private:
    struct Node{
      T element;
      Node * next;
    };

  private:
    Node * current = NULL;
    Node * first = NULL;

  public:

    //Constructors & Destructors
    LinkedList(void);

    //Add, Get & Remove interface
    void addElement(T element);
    T getElement(void);
    bool removeElement(void);

    //Iteration interface
    void moveFirst(void);
    void moveNext(void);
    bool hasNext(void);


};

template <class T> LinkedList<T>::LinkedList(void){
  this->first = (Node *) malloc(sizeof(Node));
  this->current = this->first;
  this->first->next = NULL;
}

template <class T> void LinkedList<T>::addElement(T element){
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->element = element;
  newNode->next = this->current->next;
  this->current->next = newNode;
  this->current = newNode;
}

template <class T> bool LinkedList<T>::hasNext(void) {
  return this->current->next != NULL;
}

template <class T> void LinkedList<T>::moveNext(void){
  if(this->hasNext()){
    this->current = this->current->next;
  }
}

template <class T> void LinkedList<T>::moveFirst(void){
  this->current = this->first;
}

template <class T> T LinkedList<T>::getElement(void){
  if(this->hasNext()){
    return this->current->next->element;
  }
  return this->first->element;
}

template <class T> bool LinkedList<T>::removeElement(void){
  if(this->current->next != NULL){
    Node * aux = this->current->next->next;
    free(this->current->next);
    this->current->next = aux;
    return true;
  }
  return false;
}


#endif
