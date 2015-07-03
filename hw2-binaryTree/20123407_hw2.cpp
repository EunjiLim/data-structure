// HW 2 : Binary Search Tree
// Name : LimEunji
// Student ID : 20123407


template <class T>
bool  BinaryST<T>::Insert(T item)  {
	BSTNode<T> * saveRoot = root;
	BSTNode<T> * nodePointer = new BSTNode<T>(item);

	Item rItem, nodePItem;
	nodePItem = item;
	if(root == NULL){
		root = nodePointer;
	}
	else{
		while(1){
			rItem = saveRoot->data;
			nodePItem = nodePointer->data;

			if( nodePItem.key > rItem.key ){
				if( saveRoot -> rC != NULL )
					saveRoot = saveRoot -> rC;
				else{
					saveRoot -> rC = nodePointer;
					break;
				}
			}
			else if( nodePItem.key < rItem.key ){
				if( saveRoot -> lC != NULL)
					saveRoot = saveRoot -> lC;
				else{
					saveRoot -> lC = nodePointer;
					break;
				}
			}
			else{// nodePItem.key == rItem.key
				saveRoot->data = nodePItem;
				return false;
			}
		}
	}
	return true;			
}

template <class T>
T BinaryST<T>::Get(T item)  {
BSTNode<T> * currentNode = root;
	Item cItem, itemItem;
	itemItem = item;
	while(currentNode) {
		cItem = currentNode->data;
		if( cItem.key > itemItem.key ){
			currentNode = currentNode -> lC;
		}
		else if( cItem.key < itemItem.key ){
			currentNode = currentNode -> rC;
		}
		else{
			return currentNode->data;
		}
	}
	return T(-1);
} 


template <class T>
bool  BinaryST<T>::Delete(T item)  {
if( root == NULL ){
		return false;
	}
	Item t = Get(item);
	if( t.key == -1 )
		return false;
	BSTNode<T> * currentNode = root;
	Item cItem, itemItem;
	itemItem = item;
	cItem = currentNode->data;
	if( cItem.key == itemItem.key ){ //when remove root
		if( currentNode ->rC == NULL && currentNode->lC ==NULL ){
			root = NULL;
			return true;
		}
		else if( currentNode -> rC == NULL && currentNode-> lC != NULL ){
			root = root->lC;
			return true;
		}
		else if ( currentNode -> rC != NULL && currentNode-> lC == NULL ){
			root = root -> rC;
			return true;
		}
		else{
			BSTNode<T> * saveRoot = root;
			BSTNode<T> * preCurrentNode = currentNode;
			currentNode = currentNode -> rC;
			int count = 0;
			while(currentNode -> lC != NULL){
					count++;
					preCurrentNode = currentNode;
					currentNode = currentNode -> lC;
			}
			if(count){
				root = currentNode;
				root->lC = saveRoot ->lC;
				root->rC = saveRoot ->rC;
				preCurrentNode -> lC = NULL;
				return true;
			}
			else{
				root = currentNode;
				root->lC = saveRoot ->lC;
				return true;
			}
		}

	}
	else{
		BSTNode<T> * preCurrentNode = currentNode;
		int rOrL = 0;
		while(1){
		cItem = currentNode->data;
		if( cItem.key > itemItem.key ){
			preCurrentNode = currentNode;
			currentNode = currentNode -> lC;
			rOrL = -1;
		}
		else if( cItem.key < itemItem.key ){
			preCurrentNode = currentNode;
			currentNode = currentNode -> rC;
			rOrL = 1;
		}
		else{//when finally find same key node
			if( currentNode ->rC == NULL && currentNode->lC ==NULL) { //leaf node
				if( rOrL == -1 ) {
					preCurrentNode -> lC = NULL;
				}
				else{
					preCurrentNode -> rC = NULL;
				}
				return true;
				}
			else if( currentNode -> rC == NULL && currentNode -> lC != NULL){//only have leftChild
				if( rOrL == -1 ){
					preCurrentNode -> lC = currentNode -> lC;
					return true;
				}
				if( rOrL == 1 ) {
					preCurrentNode -> rC = currentNode -> lC;
					return true;
				}
			}
			else if( currentNode -> rC != NULL && currentNode -> lC == NULL){//only have rightChild
				if( rOrL == -1 ){
					preCurrentNode -> lC = currentNode -> rC;
					return true;
				}
				else if( rOrL == 1 ){
					preCurrentNode -> rC = currentNode -> rC;
					return true;
				}
			}
			else{ //have both children
				BSTNode<T> * saveParent = preCurrentNode;
				preCurrentNode = currentNode;
				currentNode = currentNode -> rC;
				int count = 0;
				while(currentNode -> lC != NULL){
					count++;
					preCurrentNode = currentNode;
					currentNode = currentNode -> lC;
				}
				if(count){
					if( currentNode -> rC == NULL )
						preCurrentNode -> lC = NULL;
					else if( currentNode -> rC != NULL )
						preCurrentNode -> lC = currentNode -> rC;

					if( rOrL == -1 ){
						currentNode -> lC = saveParent->lC->lC;
						currentNode -> rC = saveParent->lC->rC;
						saveParent->lC = currentNode;
						return true;
					}
					else if( rOrL == 1 ){
						currentNode -> lC = saveParent ->rC->lC;
						currentNode -> rC = saveParent ->rC->rC;
						saveParent->rC = currentNode;
						return true;
					}
				}
				else{
					if(rOrL == -1){
						saveParent -> lC = currentNode;
						currentNode -> lC = preCurrentNode -> lC;
						return true;
					}
					else if(rOrL == 1){
						saveParent -> rC = currentNode;
						currentNode -> lC = preCurrentNode -> lC;
						return true;
					}
				}
			}

			}
		}
	}
	return false;
}

template <class T>
void  BinaryST<T>::PreOrder(BSTNode<T> *ptr)  {
	Item item;
	if(ptr == NULL)
		return;
	else{
		item = ptr->data;
		cout << item.key << "(" << item.val << ") ";
	}
	PreOrder(ptr->lC);
	PreOrder(ptr->rC);
}

template <class T>
void  BinaryST<T>::InOrder(BSTNode<T> *ptr)  {
	Item item;
	if(ptr == NULL)
		return;
	InOrder(ptr->lC);
	item = ptr->data;
	cout << item.key << "(" << item.val << ") ";
	InOrder(ptr->rC);
}

template <class T>
void  BinaryST<T>::PostOrder(BSTNode<T> *ptr)  {
	Item item;
	if(ptr == NULL)
		return;
	PostOrder(ptr->lC);
	PostOrder(ptr->rC);
	item = ptr->data;
	cout << item.key << "(" << item.val << ") ";
}

template <class T>
int  BinaryST<T>::Count(BSTNode<T> *ptr)  {
	if( ptr == NULL ) return 0;
	else return 1 + Count( ptr->lC ) + Count(ptr -> rC);
}

template <class T>
int  BinaryST<T>::Height(BSTNode<T> *ptr)  {
	if(ptr == NULL) return 0;
	int leftVal = Height(ptr->lC);
	int rightVal = Height(ptr->rC);
	if(leftVal > rightVal){
		return 1 + leftVal;
	}
	else
		return 1 + rightVal;
}


