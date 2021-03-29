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
  ~MyList();
  MyNode* gethead(){
    return head;
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
  MyList *list;
public:

  Island(){
    visited=false;

    list=new MyList();
  }

  MyList* getList(){
    return list;
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