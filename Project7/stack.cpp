	#include "stack.h"

	bool MyStack::isEmpty(){
		if(size==0){
			return true;
		}
		else{
			return false;
		}
	}
	bool Operators::isEmpty(){
		if(size==0){
			return true;
		}
		else{
			return false;
		}
	}

	void MyStack::push(int a){
		if(size==allocated){
			int *temp =dArr;
			dArr= new int[allocated+2];
			for(int i =0; i< allocated; ++i){
				dArr[i]=temp[i];

			}
			allocated+=2;
			delete[] temp;
		}
		dArr[size]=a;
		size++;
	}

	void Operators::push(char a){
		if(size==allocated){
			char *temp =dArr;
			dArr= new char[allocated+2];
			for(int i =0; i< allocated; ++i){
				dArr[i]=temp[i];

			}
			allocated+=2;
			delete[] temp;
		}
		dArr[size]=a;
		size++;
	}
	int* MyStack::getArr(){
		return dArr;
	}
	char* Operators::getArr(){
		return dArr;
	}
	int MyStack::top(){
		return dArr[size-1];
	}
	char Operators::top(){
		return dArr[size-1];
	}
	void MyStack::pop(){
		size--;

	}
	void Operators::pop(){
		size--;

	}
	void MyStack::setEmpty(){
		size=0;
	}
	void Operators::setEmpty(){
		size=0;
	}