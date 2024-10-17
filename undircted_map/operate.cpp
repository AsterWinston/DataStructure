#include"graphic.h"
#define INT_MAX 5201314
#include<queue>

template<class T>
void visit(vertexNode<T> v) {
	cout << v.data << endl;
}

template<class T>
void graphic<T>::initGraphic() {
	this->capacity = 10;
	this->arr = new vertexNode<T>[10];
	this->size = 0;
}

template<class T>
void graphic<T>::insertVertexNode(vertexNode<T>v) {
	if (this->size >= capacity) {
		this->capacity += 10;
		vertexNode<T>* tempArr = new vertexNode<T>[capacity];
		if (tempArr == NULL)return;
		for (int i = 0; i < size; i++) {
			tempArr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = tempArr;
	}
	arr[size++] = v;
}

template<class T>
void graphic<T>::insertEdgeNode(edgeNode e) {
	if (e.t1<0 || e.t2>this->size - 1 || e.t2<0 || e.t2>this->size - 1 || e.t1 == e.t2) {
		return;
	}
	edgeNode* p1 = NULL, * p2 = NULL;
	p1 = this->arr[e.t1].firstEdge;
	p2 = this->arr[e.t2].firstEdge;
	//判断是否已经存在了传入的边
	while (p1) {
		if (p1->t1 == e.t1 && p1->t2 == e.t2 || p1->t1 == e.t2 && p1->t1 == e.t1)return;
		p1 = p1->t1 == e.t1 ? p1->t1_next : p1->t2_next;
	}
	while (p2) {
		if (p2->t1 == e.t1 && p2->t2 == e.t2 || p2->t1 == e.t2 && p2->t1 == e.t1)return;
		p2 = p2->t1 == e.t1 ? p2->t1_next : p2->t2_next;
	}
	edgeNode* temp = new edgeNode(e);
	temp->t1_next = arr[e.t1].firstEdge;
	temp->t2_next = arr[e.t2].firstEdge;
	arr[e.t1].firstEdge = temp;
	arr[e.t2].firstEdge = temp;
}

template<class T>
void graphic<T>::traverseEdgeNode(void (*visit)(edgeNode e)) {
	edgeNode* temp = NULL;
	for (int i = 0; i < this->size; i++) {
		temp = this->arr[i].firstEdge;
		cout << "node" << i << ':' << endl;
		while (temp) {
			visit(*temp);
			temp = temp->t1 == i ? temp->t1_next : temp->t2_next;
		}
	}
	cout << endl;
}

template<class T>
void graphic<T>::traverseVertexNode(void (*visit)(vertexNode<T> v)) {
	for (int i = 0; i < this->size; i++) {
		cout << "node" << i <<':';
		visit(this->arr[i]);
	}
	cout << endl;
}

template<class T>
int graphic<T>::getIndex(vertexNode<T> v) {
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] == v)return i;
	}
	return -1;
}

template<class T>
void BFS(graphic<T> g,int index) {
	if (index<0 || index>g.size - 1)return;
	int *distance = new int[g.size], *path = new int[g.size], *visit = new int[g.size];
	for (int i = 0; i < g.size; i++) {
		distance[i] = INT_MAX;
		path[i] = -1;
		visit[i] = 0;
	}

	queue<vertexNode<T>>q;
	q.push(g.arr[index]);
	edgeNode* etemp;
	vertexNode<T>vtemp;
	int preIndex, nowIndex;
	distance[index] = 0;
	visit[index] = 1;
	while (!q.empty()) {
		vtemp = q.front();
		q.pop();
		preIndex = g.getIndex(vtemp);
		etemp = vtemp.firstEdge;
		while (etemp) {
			if (etemp->t1 == preIndex) {
				nowIndex = etemp->t2;
				vtemp = g.arr[etemp->t2];
				etemp = etemp->t1_next;
			}
			else {
				nowIndex = etemp->t1;
				vtemp = g.arr[etemp->t1];
				etemp = etemp->t2_next;
			}
			if (!visit[nowIndex]) {
				distance[nowIndex] = distance[preIndex] + 1;
				path[nowIndex] = preIndex;
				visit[nowIndex] = 1;
				q.push(vtemp);
			}
		}
	}
	cout << "distance:" << endl;
	for (int i = 0; i < g.size; i++) {
		cout << distance[i] << ' ';
	}
	cout << endl;

	cout << "path:" << endl;
	for (int i = 0; i < g.size; i++) {
		cout << path[i] << ' ';
	}
	cout << endl;
	
	cout << "visit:" << endl;
	for (int i = 0; i < g.size; i++) {
		cout << visit[i] << ' ';
	}
	cout << endl;
}

template<class T>
void Dijkstra(graphic<T> g, int index) {
	if (index > g.size - 1 || index < 0)return;
	int* distance = new int[g.size], * path = new int[g.size], * set = new int[g.size];
	for (int i = 0; i < g.size; i++) {
		distance[i] = INT_MAX;
		path[i] = -1;
		set[i] = 0;
	}
	
	int index_mindis = index;
	distance[index] = 0;
	set[index] = 1;
	edgeNode* etemp;
	vertexNode<T>vtemp;
	for (int i = 0; i < g.size; i++) {
		cout << "index:" << index_mindis << endl;
		set[index_mindis] = 1;
		etemp = g.arr[index_mindis].firstEdge;
		while (etemp) {
			if (!set[etemp->t1 == index_mindis ? etemp->t2 : etemp->t1] && etemp->weight + distance[index_mindis] < distance[etemp->t1 == index_mindis ? etemp->t2 : etemp->t1]) {
				distance[etemp->t1 == index_mindis ? etemp->t2 : etemp->t1] = etemp->weight + distance[index_mindis];
				path[etemp->t1 == index_mindis ? etemp->t2 : etemp->t1] = index_mindis;
			}
			etemp = etemp->t1 == index_mindis ? etemp->t1_next : etemp->t2_next;
		}
		int j = 0;
		while (j < g.size) {
			if (!set[j]) {
				index_mindis = j;
				break;
			}
			j++;
		}
		for (int i = 0; i < g.size; i++) {
			if (!set[i]) {
				if (distance[i] < distance[index_mindis])index_mindis = i;
			}
		}
		
	}

	cout << "distance:" << endl;
	for (int i = 0; i < g.size; i++) {
		cout << distance[i] << ' ';
	}
	cout << endl;
	
	cout << "path:" << endl;
	for (int i = 0; i < g.size; i++) {
		cout << path[i] << ' ';
	}
	cout << endl;

	cout << "set:" << endl;
	for (int i = 0; i < g.size; i++) {
		cout << set[i] << ' ';
	}
	cout << endl;
}

template<class T>
int** Floyd(graphic<T> g) {
	int i, j, v;
	int** A = new int* [g.size];
	int** path = new int* [g.size];
	for (int i = 0; i < g.size; i++) {
		A[i] = new int[g.size];
		path[i] = new int[g.size];
	}
	for (int i = 0; i < g.size; i++) {
		for (int j = 0; j < g.size; j++) {
			A[i][j] = INT_MAX;
			path[i][j] = -1;
		}
	}
	edgeNode* etemp = NULL;
	for (i = 0; i < g.size; i++) {
		etemp = g.arr[i].firstEdge;
		while (etemp) {
			A[etemp->t1][etemp->t2] = etemp->weight;
			A[etemp->t2][etemp->t1] = etemp->weight;
			etemp = etemp->t1 == i ? etemp->t1_next : etemp->t2_next;
		}
	}
	for (v = 0; v < g.size; v++) {
		for (i = 0; i < g.size; i++) {
			for (j = 0; j < g.size; j++) {
				if (i == j || j == v || i == v)continue;
				if (A[i][j] > A[i][v] + A[v][j]) {
					A[i][j] = A[i][v] + A[v][j];
					path[i][j] = v;
				}
			}
		}
	}
	cout << "A:" << endl;
	for (i = 0; i < g.size; i++) {
		for (j = 0; j < g.size; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "path:" << endl;
	for (i = 0; i < g.size; i++) {
		for (j = 0; j < g.size; j++) {
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
	
	return path;
}

template<class T>
graphic<T> prim(graphic<T> g, int index) {
	int* distance = new int[g.size];
	int* flag = new int[g.size];
	for (int i = 0; i < g.size; i++) {
		distance[i] = INT_MAX;
		flag[i] = 0;
	}
	graphic<T> g_result;
	g_result.initGraphic();
	edgeNode* etemp = NULL;
	edgeNode edgePicked;
	vertexNode<T> vertexPicked;
	while (g_result.size < g.size) {
		vertexPicked.data = g.arr[index].data;
		vertexPicked.firstEdge = NULL;
		g_result.insertVertexNode(vertexNode<T>(vertexPicked));
		etemp = g.arr[index].firstEdge;
		edgePicked.weight = INT_MAX;
		while (etemp) {
			if (!flag[etemp->t1 == index ? etemp->t2 : etemp->t1] && etemp->weight < distance[etemp->t1 == index ? etemp->t2 : etemp->t1]) {
				distance[etemp->t1 == index ? etemp->t2 : etemp->t1] = etemp->weight;
			}
			else if (flag[etemp->t1 == index ? etemp->t2 : etemp->t1]) {
				if (etemp->weight < edgePicked.weight) {
					edgePicked = *etemp;
				}
			}
			etemp = etemp->t1 == index ? etemp->t1_next : etemp->t2_next;
		}
		
		if (g_result.size != 1) {
			edgePicked.t1 = g_result.size - 2;
			edgePicked.t2 = g_result.size - 1;
			g_result.insertEdgeNode(edgePicked);
		}//第一次插入顶点不需要插入边
		flag[index] = 1;
		int j = 0;
		while (j < g.size) {
			if (!flag[j]) {
				index = j;
				break;
			}
			j++;
		}
		for (int i = 0; i < g.size; i++) {
			if (!flag[i] && distance[i] < distance[index])index = i;
		}
	}
	return g_result;
}

template<class T>
int graphic<T>::getEdgeCount() {
	int result = 0;
	edgeNode* etemp = NULL;
	for (int i = 0; i < this->size; i++) {
		etemp = this->arr[i].firstEdge;
		while (etemp) {
			if (etemp->t1 == i)result++;
			etemp = etemp->t1 == i ? etemp->t1_next : etemp->t2_next;
		}
	}
	return result;
}

template<class T>
graphic<T> kruskal(graphic<T> g) {
	int edgeCount = g.getEdgeCount();
	graphic<T>g_result;
	edgeNode* edgeArr = new edgeNode[edgeCount];
	edgeNode* etemp = NULL;
	
	int j = 0;
	for (int i = 0; i < g.size; i++) {
		etemp = g.arr[i].firstEdge;
		while (etemp) {
			if (etemp->t1 == i)edgeArr[j++] = *etemp;
			etemp = etemp->t1 == i ? etemp->t1_next : etemp->t2_next;
		}
	}

	shellSort(edgeArr, edgeCount);

	int *union_find=new int[g.size];
	vertexNode<T>temp;
	for (int i = 0; i < g.size; i++) {
		temp = g.arr[i];
		temp.firstEdge = NULL;
		g_result.insertVertexNode(temp);
		union_find[i] = -1;
	}
	j = 0;
	for (int i = 0; i < edgeCount; i++) {
		if (Find(union_find, edgeArr[i].t1) != Find(union_find, edgeArr[i].t2)) {
			Union(union_find, edgeArr[i].t1, edgeArr[i].t2);
			g_result.insertEdgeNode(edgeArr[i]);
			j++;
			if (j == g.size - 1)break;
		}
	}

	return g_result;
}