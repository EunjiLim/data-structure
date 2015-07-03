// HW 1
// Name : Lim eunji
// Student ID : 20123407

enum DIR{ E, SE, NE, N, NW, W, SW, S };

struct offsets{
	int a, b;
};

offsets moveValue[8] = { { 0, 1 }, { 1, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 } };

class items{
public:
	int i,
		j,
		dir;
	items(){}
	items(int i, int j, int dir){
		this->i = i;
		this->j = j;
		this->dir = dir;
	}
	void change(int i, int j, int dir){
		this->i = i;
		this->j = j;
		this->dir = dir;
	}	
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity (stackCapacity)
{
// NEED TO IMPLEMENT 
	if(stackCapacity < 1) throw "Stack capacity must be > 0";
	stack = new T[stackCapacity];
	top = -1;
}

// If number of elements in the stack is 0, return true else return false
template <class T>
inline bool Stack<T>::IsEmpty() const
{

	// NEED TO IMPLEMENT
	return top == -1;
}

template <class T>
inline T & Stack<T>::Top () const
{
	// NEED TO IMPLEMENT
	if (IsEmpty()) throw "Stack is empty.";
	return stack[top];
}

template <class T>
void Stack<T>::Push (const T & item)
{ 
	// NEED TO IMPLEMENT
	/*if(top == capacity - 1){
		ChangeSize1D(stack, capacity, 2*capacity);
		capacity *= 2;
	}*/
	stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
	// NEED TO IMPLEMENT
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}

void Path(const int m, const int p)
{// Output a path (if any) in the maze; 

	// start at (1,1)
	mark[1][1] = 1; //start point

	// NEED TO IMPLEMENT
	Stack<items> mystack(1024);
	items ITEM(1,1,E);
	items tempItem;
	mystack.Push(ITEM); //push the start point
	int x, y;

	while(!mystack.IsEmpty()){
		ITEM=mystack.Top(); //put the mystack.Top's info into ITEM
		mystack.Pop();
		tempItem = ITEM; //keep the ITEM's members
		while(tempItem.dir<8){   
			//the next position which must be checked : x & y
			x = tempItem.i + moveValue[tempItem.dir].a;
			y = tempItem.j + moveValue[tempItem.dir].b;

			if( ( x == m ) &&  ( y == p )) {   //reach destination
				for(int c = 0 ; c <= mystack.top ; c++){
					cout << "(" << mystack.stack[c].i << "," << mystack.stack[c].j << ")" << endl;
				}
				cout << "(" << tempItem.i << "," << tempItem.j <<")"<<endl; 
				cout << "(" << x << "," << y << ")" << endl;
				return; //function end
			}

			if( (!maze[x][y]) && (!mark[x][y]) ) { //if the new position is available
				mark[x][y] = 1; 
				ITEM.change(tempItem.i, tempItem.j, tempItem.dir + 1);
				mystack.Push(ITEM);
				tempItem.i = x; 
				tempItem.j = y; 
				tempItem.dir = E;
			}
			else  tempItem.dir++;

		}
		if ( mystack.IsEmpty() ){
			cout << "No path in the maze." << endl;
			return;
		}
	}
}
