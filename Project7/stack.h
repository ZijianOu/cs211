

class MyStack{
private:

	int* dArr;
	int size;
	int allocated;
public:
	MyStack(){
		size=0;
		allocated=2;
		dArr= new int[allocated];
	}

	bool isEmpty();
	void push(int a);
int* getArr();
	int top();
	void pop();
	void setEmpty();
};

class Operators{

private:

	char* dArr;
	int size;
	int allocated;
public:
	Operators(){
		size=0;
		allocated=2;
		dArr= new char[allocated];
	}

	bool isEmpty();
	void push(char a);

char* getArr();
	char top();
	void pop();
	void setEmpty();
};