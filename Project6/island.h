#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <string>
class MyNode{
private:
  int num;
  MyNode* next;
public:
  MyNode(){
    num=0;
    next=NULL;
  }

  void setNum(int n){
    num=n;
  }

  int getNum(){
    return num;
  }

  void setNext(MyNode* temp){
    next=temp;
  }

  MyNode* getNext(){
    return next;
  }
};

class MyList{
private:
  MyNode* head;

public:
  MyList(){
    head=NULL;
  }
  //~MyList();
  MyNode* gethead(){
    return head;
  }
  void sethead(MyNode* a){
    head = a;
  }

 
  
  bool pathexist(int a);
  void insertValue(int v1);
 int getNumberOfCurrentsValues();
 int getNthValue(int n);
 int getListLength();
  void deleteValue(int v1);
  void removeAll();
};

class Island{
private:
  bool visited;
  int preI;
  MyList *list;
public:

  Island(){
    visited=false;
    preI=-1;
    list=new MyList();
  }

  MyList* getList(){
    return list;
  }
  void setPre(int val){
    preI=val;
  }
  int getPre(){
    return preI;
  }
  void markV(){
    visited=true;
  }
  void markUV(){
    visited=false;
  }
  bool getV(){
    return visited;
  }

};
class files{
private:
  char* names;
  files* next;
public:
  files(){
    names=NULL;
    next=NULL;
  }

  char* getName(){
     return names;
  }
  void setName(char* fname){
    names=fname;
  }
  files* getNext(){
    return next;
  }
  void setNext(files* temp){
    next=temp;
  }
};

class Myfilelist{
private:
  files* head;

public:

  Myfilelist(){
    head=NULL;
    //getnext setnext
  }
  void removeAll()
{
  files* temp = head;
  while(temp!=NULL){
    files* temp1 = temp;
    temp=temp->getNext();
    delete temp1;
  }
  head=NULL;
}
  bool fexist(char* a);

  files* gethead(){
    return head;
  }
  void insertValue(char* v1){// change
    files*  temp= new files();
    temp->setName(v1);
    files*  cur = head;
    files*  pre = NULL;
    while (cur!= NULL)
    {
      pre = cur;
      cur = cur->getNext();
    }
    temp->setNext (cur);
    if (pre == NULL ){
      head = temp;
    }
    else{
      pre->setNext(temp);
    }
  }
  // char getNextName(){
  //   files*  temp= head;
  //   temp=temp->getNext();
  //   return temp->getName();
  // }
  // void setNextName(char* fname){
  //   temp=temp->getNext();
  //   temp->setName(fname);
  // }
};
// void MyList::insertValue(MyNode* head, int v1);
// void MyList::deleteValue(int v1);
// bool MyList::exist(int a);
// int MyList::getNthValue();
class queue: public MyList{
public:
 
  void delete_front(){
    MyNode* temp = gethead();
    MyNode* head = gethead();
    if(temp!=NULL){
       sethead(head->getNext());
      delete temp;
    }
  }

};
class stack: public MyList{

public:
  //stack breadthFirstSearch(int x, int y);
  void insert_front(int n){
    MyNode* temp=new MyNode();
    MyNode* temp1 = gethead(); // 
    temp->setNum(n);
    temp->setNext(temp1);
    sethead(temp);
    //printf("%d testing insert_front\n", head->getNum());
    //printList();
  }
  void delete_front(){
    MyNode* temp = gethead();
    MyNode* temp1 = gethead();
    if(temp!=NULL){
      sethead(temp1->getNext());
      delete temp;
    }
  }
  void printList(){
    MyNode* temp= gethead();
    if(temp==NULL){
      return;
    }
    printf("%d", temp->getNum());
    temp=temp->getNext();
    while (temp!= NULL){
      
      printf(" - %d", temp->getNum());
     
      temp = temp->getNext();
    }
    printf("\n");
  }

};