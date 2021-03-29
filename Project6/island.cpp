#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "island.h"
#include <string.h>
#include <string>



void MyList::insertValue( int v2){
  if(head==NULL){
    head=new MyNode();
    head->setNum(v2);
    return;
  }
  MyNode* temp = head;
  while(temp->getNext()!= NULL){
    temp=temp->getNext();
  }
  temp->setNext(new MyNode());
  temp->getNext()->setNum(v2);
}
bool MyList:: pathexist(int a){
    MyNode* temp =head;
  while(temp!=NULL){
    //printf("%d\n", temp->getNum());
    if(temp->getNum()==a){
      return true;
    }
    temp=temp->getNext();
  }
  return false;
}

void MyList::deleteValue(int v1){
  MyNode* cur = head;
  MyNode* pre = NULL;
  while ((cur != NULL)&& (cur->getNum() != v1))
  {
    pre = cur;
    cur= cur->getNext();
  }
  if(cur==NULL){
    return;
  }
  if(pre==NULL){
    head=cur->getNext();
    delete cur;
  }
  else{
    pre->setNext(cur->getNext());
    delete cur;
  } 
}
int MyList::getNthValue(int n){
  MyNode* temp = head;
  for (int i=0; i<n;i++){
    temp=temp->getNext();
  }
  return temp->getNum();
}
 int MyList::getListLength ()
 {
  MyNode* temp = head;
  int length = 0;
  while ( temp != NULL )
  {
    length ++;
    temp = temp->getNext();
  }
  return length;
  }

bool Myfilelist::fexist(char* a){
  files* temp =head;
  while(temp!=NULL){
    if(strcmp(temp->getName(), a)==0){
      return true;
    }
    else{
      return false;
    }
    temp=temp->getNext();
  }
}

void MyList::removeAll()
{
  MyNode* temp = head;
  while(temp!=NULL){
    MyNode* temp1 = temp;
    temp=temp->getNext();
    delete temp1;
  }
  head=NULL;
}