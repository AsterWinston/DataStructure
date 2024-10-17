
#include"graphic.h"
#include<queue>

template<class T>
bool graphic<T>::initGraphic() {
	this->capacity = 10;
	this->arr = new vertexNode<T>[capacity];
	if (this->arr == NULL) {
		this->capacity = 0;
		return false;
	}
	return true;
}

template<class T>
bool graphic<T>::insertVertexNode(vertexNode<T>v) {
	if (this->size >= capacity) {
		this->capacity += 10;
		vertexNode<T>* tempArr = new vertexNode<T>[capacity];
		if (tempArr == NULL)return 0;
		for (int i = 0; i < size; i++) {
			tempArr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = tempArr;
	}
	arr[size++] = v;
	return true;
}

template<class T>
bool graphic<T>::insertEdgeNode(edgeNode e) {
	if (e.head == e.tail)return false;
	if (e.head<0 || e.head>this->size - 1 || e.tail<0 || e.tail>this->size - 1)return false;
	edgeNode* temp = new edgeNode(e);
	if (temp == NULL)return false;

	edgeNode* outTemp = arr[e.head].firstOut;
	if (outTemp == NULL)arr[e.head].firstOut = temp;
	while (outTemp!= NULL) {
		if (outTemp->head == temp->head && outTemp->tail == temp->tail)return false;
		if (outTemp->nextOut == NULL) {
			outTemp->nextOut = temp;
			break;
		}
		outTemp = outTemp->nextOut;
	}
	edgeNode* inTemp = arr[e.tail].firstIn;
	if (inTemp == NULL)arr[e.tail].firstIn = temp;
	if (inTemp == NULL)arr[e.tail].firstIn = temp;
	while (inTemp != NULL) {
		if (inTemp->head == temp->head && inTemp->tail == temp->tail)return false;
		if (inTemp->nextIn == NULL) {
			inTemp->nextIn = temp;
			break;
		}
		inTemp = inTemp->nextIn;
	}
	temp->nextIn = NULL;
	temp->nextOut = NULL;
	return true;
}

template<class T>
void graphic<T>::traverseVertex() {
	for (int i = 0; i < this->size; i++) {
		cout << arr[i].data << endl;
	}
	cout << endl;
}

template<class T>
void graphic<T>::traverseEdge() {
	edgeNode* temp = NULL;
	for (int i = 0; i < this->size; i++) {
		temp = (this->arr)[i].firstOut;
		cout << "node" << i << ":" << endl;
		while (temp) {
			cout << temp->head << "->" << temp->tail << " " << "weight:" << temp->weight << endl;
			temp = temp->nextOut;
		}
		temp = (this->arr)[i].firstIn;
		while (temp) {
			cout << temp->head << "->" << temp->tail << " " << "weight:" << temp->weight << endl;
			temp = temp->nextIn;
		}
	}
	cout << endl;
}


template<class T>
bool graphic<T>::deleteVertex(vertexNode<T>v) {
	int nodePos = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i].data == v.data) {
			nodePos = i;
			break;
		}
	}
	if (nodePos == -1)return false;

	//删除与顶点有关的边
	edgeNode* in = arr[nodePos].firstIn;
	edgeNode* out = arr[nodePos].firstOut;
	edgeNode* t1 = NULL, * t2 = NULL, * t3 = NULL;
	while (in) {
		t1 = arr[in->head].firstOut;
		t3 = out->nextIn;
		if (t1 && t1->tail == nodePos) {
			arr[in->head].firstOut = t1->nextOut;
			delete t1;
			t1 = NULL;
		}
		while (t1 && t1->nextOut) {
			t2 = t1;
			t1 = t1->nextOut;
			if (t1->tail == nodePos) {
				t2->nextOut = t1->nextOut;
				delete t1;
				break;
			}
		}
		in = t3;
		
	}
	while (out) {
		t1 = arr[out->tail].firstIn;
		t3 = out->nextOut;
		if (t1 && t1->head == nodePos) {
			arr[out->tail].firstIn = t1->nextIn;
			delete t1;
			t1 = NULL;
		}
		while (t1 && t1->nextIn) {
			t2 = t1;
			t1 = t1->nextIn;
			if (t1->head == nodePos) {
				t2->nextIn = t1->nextIn;
				delete t1;
				break;
			}
		}
		out = t3;
		
	}

	//删除顶点并将顶点移动，对应边的head，tail移动
	edgeNode* temp = NULL;
	if (this->capacity - this->size == 9) {
		vertexNode<T>* tempArr = new vertexNode<T>[capacity - 10];
		if (tempArr == NULL)return false;
		for (int i = 0; i < nodePos; i++) {
			tempArr[i] = (this->arr)[i];
			temp = arr[i].firstIn;
			while (temp) {
				if (temp->head > nodePos) {
					temp->head--;
				}
				temp = temp->nextIn;
			}
			temp = arr[i].firstOut;
			while (temp) {
				if (temp->tail > nodePos) {
					temp->tail--;
				}
				temp = temp->nextOut;
			}
		}
		for (int i = nodePos + 1; i < size; i++) {
			tempArr[i - 1] = arr[i];
			temp = arr[i].firstIn;
			while (temp) {
				if (temp->head > nodePos) {
					temp->head--;
				}
				temp = temp->nextIn;
			}
			temp = arr[i].firstOut;
			while (temp) {
				if (temp->tail > nodePos) {
					temp->tail--;
				}
				temp = temp->nextOut;
			}
		}
		delete[]this->arr;
		this->arr = tempArr;
		this->capacity -= 10;
		this->size--;
		return true;
	}
	for (int i = 0; i < size; i++) {
		if (i != nodePos) {
			temp = arr[i].firstIn;
			while (temp) {
				if (temp->head > nodePos) {
					temp->head--;
				}
				temp = temp->nextIn;
			}
			temp = arr[i].firstOut;
			while (temp) {
				if (temp->tail > nodePos) {
					temp->tail--;
				}
				temp = temp->nextOut;
			}
		}
	}
	for (int i = nodePos; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	this->size--;
	return true;
}


//template<class T>
//bool graphic<T>::deleteVertex(vertexNode<T>v) {
//	int nodePos = -1;
//	for (int i = 0; i < size; i++) {
//		if (arr[i].data == v.data) {
//			nodePos = i;
//			break;
//		}
//	}
//	if (nodePos == -1)return false;
//	//删除包含v的edge，可优化
//	for (int i = 0; i < nodePos; i++) {
//		edgeNode* eTemp = arr[i].firstIn;
//		edgeNode* ePre = NULL;
//		if (eTemp != NULL && eTemp->head == nodePos) {
//			arr[i].firstIn = eTemp->nextIn;
//			delete eTemp;
//			eTemp = NULL;
//		}
//		while (eTemp != NULL && eTemp->nextIn != NULL) {
//			ePre = eTemp;
//			eTemp = eTemp->nextIn;
//			if (eTemp->head == nodePos) {
//				ePre->nextIn = eTemp->nextIn;
//				delete eTemp;
//				eTemp = ePre->nextIn;
//				break;
//			}
//		}
//
//		eTemp = arr[i].firstOut;
//		ePre = NULL;
//		if (eTemp != NULL && eTemp->tail == nodePos) {
//			arr[i].firstOut = eTemp->nextOut;
//			delete eTemp;
//			eTemp = NULL;
//		}
//		while (eTemp != NULL && eTemp->nextOut != NULL) {
//			ePre = eTemp;
//			eTemp = eTemp->nextOut;
//			if (eTemp->tail == nodePos) {
//				ePre->nextOut = eTemp->nextOut;
//				delete eTemp;
//				eTemp = ePre->nextOut;
//				break;
//			}
//		}
//	}
//	for (int i = nodePos + 1; i < this->size; i++) {
//		edgeNode* eTemp = arr[i].firstIn;
//		edgeNode* ePre = NULL;
//		if (eTemp != NULL && eTemp->head == nodePos) {
//			arr[i].firstIn = eTemp->nextIn;
//			delete eTemp;
//			eTemp = NULL;
//		}
//		while (eTemp != NULL && eTemp->nextIn != NULL) {
//			ePre = eTemp;
//			eTemp = eTemp->nextIn;
//			if (eTemp->head == nodePos) {
//				ePre->nextIn = eTemp->nextIn;
//				delete eTemp;
//				eTemp = ePre->nextIn;
//				break;
//			}
//		}
//
//		eTemp = arr[i].firstOut;
//		ePre = NULL;
//		if (eTemp != NULL && eTemp->tail == nodePos) {
//			arr[i].firstOut = eTemp->nextOut;
//			delete eTemp;
//			eTemp = NULL;
//		}
//		while (eTemp != NULL && eTemp->nextOut != NULL) {
//			ePre = eTemp;
//			eTemp = eTemp->nextOut;
//			if (eTemp->tail == nodePos) {
//				ePre->nextOut = eTemp->nextOut;
//				delete eTemp;
//				eTemp = ePre->nextOut;
//				break;
//			}
//		}
//	}
//
//	//移动edge的head和tail值
//	edgeNode* temp = NULL;
//	if (this->capacity - this->size == 9) {
//		vertexNode<T>* tempArr = new vertexNode<T>[capacity - 10];
//		if (tempArr == NULL)return false;
//		for (int i = 0; i < nodePos; i++) {
//			tempArr[i] = (this->arr)[i];
//			temp = arr[i].firstIn;
//			while (temp) {
//				if (temp->head > nodePos) {
//					temp->head--;
//				}
//				temp = temp->nextIn;
//			}
//			temp = arr[i].firstOut;
//			while (temp) {
//				if (temp->tail > nodePos) {
//					temp->tail--;
//				}
//				temp = temp->nextOut;
//			}
//		}
//		for (int i = nodePos + 1; i < size; i++) {
//			tempArr[i - 1] = arr[i];
//			temp = arr[i].firstIn;
//			while (temp) {
//				if (temp->head > nodePos) {
//					temp->head--;
//				}
//				temp = temp->nextIn;
//			}
//			temp = arr[i].firstOut;
//			while (temp) {
//				if (temp->tail > nodePos) {
//					temp->tail--;
//				}
//				temp = temp->nextOut;
//			}
//		}
//		this->capacity -= 10;
//		this->size--;
//		return true;
//	}
//	for (int i = 0; i < size; i++) {
//		if (i != nodePos) {
//			temp = arr[i].firstIn;
//			while (temp) {
//				if (temp->head > nodePos) {
//					temp->head--;
//				}
//				temp = temp->nextIn;
//			}
//			temp = arr[i].firstOut;
//			while (temp) {
//				if (temp->tail > nodePos) {
//					temp->tail--;
//				}
//				temp = temp->nextOut;
//			}
//		}
//	}
//	for (int i = nodePos; i < size - 1; i++) {
//		arr[i] = arr[i + 1];
//	}
//	this->size--;
//	return true;
//}//

template<class T>
int graphic<T>::searchVertex(vertexNode<T>& v) {
	for (int i = 0; i < this->size; i++) {
		if (v.data == arr[i].data) {
			v = arr[i];
			return i;
		}
	}
}

template<class T>
bool graphic<T>::deleteEdge(edgeNode e) {
	if (e.head<0 || e.head>size - 1 || e.tail<0 || e.tail>size - 1) {
		return false;
	}
	edgeNode* temp = NULL, *pre=NULL;
	if (arr[e.head].firstOut->tail == e.tail) {
		arr[e.head].firstOut = arr[e.head].firstOut->nextOut;
	}
	else {
		temp = arr[e.head].firstOut;
		while (temp) {
			pre = temp;
			temp = temp->nextOut;
			if (temp && temp->tail == e.tail) {
				pre->nextOut = temp->nextOut;
				break;
			}
		}
	}

	if (arr[e.tail].firstIn->head == e.head) {
		temp = arr[e.tail].firstIn;
		arr[e.tail].firstIn = temp->nextIn;
		delete temp;
		return true;
	}
	else {
		temp = arr[e.tail].firstIn;
		while (temp) {
			pre = temp;
			temp = temp->nextIn;
			if (temp && temp->head == e.head) {
				pre->nextIn = temp->nextIn;
				delete temp;
				return true;
			}
		}
	}
	
}

template<class T>
void graphic<T>::traverseBFS(bool (*visit)(vertexNode<T> n)) {
	if (this->size == 0)return;
	queue<vertexNode<T>>q;
	int* flag = new int[this->size];
	memset(flag, 0, this->size * sizeof(int));
	q.push(arr[0]);
	flag[searchVertex(arr[0])] = 1;
	vertexNode<T>temp;
	edgeNode* edgeIn = NULL, *edgeOut=NULL;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		visit(temp);
		edgeIn = temp.firstIn;
		edgeOut = temp.firstOut;
		while (edgeIn) {
			if (!flag[edgeIn->head]) {
				q.push(arr[edgeIn->head]);
				flag[searchVertex(arr[edgeIn->head])] = 1;
			}
			edgeIn = edgeIn->nextIn;
		}
		while (edgeOut) {
			if (!flag[edgeOut->tail]) {
				q.push(arr[edgeOut->tail]);
				flag[searchVertex(arr[edgeOut->tail])] = 1;
			}
			edgeOut = edgeOut->nextOut;
		}
	}
	cout << endl;
}

template<class T>
bool visit(vertexNode<T>n) {
	cout << n.data << endl;
	return true;
}

template<class T>
void graphic<T>::traverseDFS(bool (*visit)(vertexNode<T>n)) {
	if (this->size == 0)return;
	int* flag = new int[this->size];
	memset(flag, 0, this->size * sizeof(int));
	traverseCursion(0, visit,flag);
	cout << endl;
}

template<class T>
void graphic<T>::traverseCursion(int pos, bool (*visit)(vertexNode<T>n), int* flag) {
	visit(arr[pos]);
	flag[pos] = 1;
	edgeNode* edgeIn = NULL, * edgeOut = NULL;
	edgeIn = arr[pos].firstIn;
	edgeOut = arr[pos].firstOut;
	while (edgeIn) {
		if (flag[edgeIn->head] == 0) {
			traverseCursion(edgeIn->head, visit, flag);
		}
		edgeIn = edgeIn->nextIn;
	}
	while (edgeOut) {
		if (flag[edgeOut->tail] == 0) {
			traverseCursion(edgeOut->tail, visit, flag);
		}
		edgeOut = edgeOut->nextOut;
	}
}

