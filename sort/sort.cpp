#include"sort.h"

void insertSort(int arr[], int n) {
	int temp, i, j;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && temp < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void selectSort(int arr[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (arr[k] > arr[j]) {
				k = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

void bubbleSort(int arr[], int n) {
	int i, j, flag;
	int temp;
	for (i = n - 1; i >= 1; --i) {
		flag = 0;
		for (j = 1; j <= i; j++) {
			if (arr[j - 1] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)return;
	}
}

void shellSort(int arr[], int n) {
	int temp;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void quickSort(int arr[], int low, int high) {
	int temp;
	int i = low, j = high;
	if (low < high) {
		temp = arr[low];
		while (i < j) {
			while (j > i && arr[j] >= temp)j--;
			if (i < j) {
				arr[i] = arr[j];
				//因为起始条件是i=low，low位置是唯一一个空闲位置，所以需要先从high端开始找一个比temp小的关键字，存到arr[i]（即arr[low]）中
				i++;
			}
			while (i < j && arr[i] < temp)i++;
			if (i < j) {
				arr[j] = arr[i];
				//当上面语句执行过后，显然j指向的是一个空闲位置，因为j位置的元素比temp小，已经存在了上一步的arr[i]中，所以下一步要从low端中找出比tmep小的一个关键字存到j位置
				j--;
			}

		}
		arr[i] = temp;//or arr[j] = tmep;
		quickSort(arr, low, i - 1);
		quickSort(arr, i + 1, high);
	}
}

void sift(int arr[], int low, int high) {
	int i = low, j = 2 * i + 1; // j 为 i 的左孩子。这里通过公式计算出当前节点 i 的左孩子节点的索引。
	int temp = arr[i];
	while (j <= high) {
		if (j < high && arr[j] < arr[j + 1])j++; // 如果右孩子存在且比左孩子大，就将 j 指向右孩子。
		if (temp < arr[j]) {
			arr[i] = arr[j]; // 将较大的子节点值赋给父节点。
			i = j;
			j = 2 * i + 1; // 更新 j 为新的 i 的左孩子。
		}
		else break; // 如果父节点不小于子节点，调整结束。
	}
	arr[i] = temp; // 将 temp（原始父节点值）赋给最终调整后的位置。
}
void heapSort(int arr[], int n) {
	int i;
	int temp;
	for (i = n / 2 - 1; i >= 0; i--) {
		sift(arr, i, n - 1); // 从最后一个非叶子节点开始，逐个调整为大顶堆。
	}
	for (i = n - 1; i > 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp; // 将堆顶元素与当前未排序部分的最后一个元素交换。
		sift(arr, 0, i - 1); // 对新的堆顶元素进行调整。
	}
}

void merge(int arr[], int low, int mid, int high) {
	//归并从low到mid和mid+1到high上的两个有序序列
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++) {
		L[i] = arr[low + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = low;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])arr[k] = L[i++];
		else arr[k] = R[j++];
		k++;
	}
	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}
}
void mergeSort(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void binaryInsertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int low = 0, high = i - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] < key) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		for (int j = i; j > low; j--) {//此时low==high
			arr[j] = arr[j - 1];
		}
		arr[low] = key;//or arr[high]=key
	}
}

// 获取数字的指定位数上的数字
int getDigit(int num, int digit) {
	int divisor = 1;
	for (int i = 0; i < digit - 1; i++) {
		divisor *= 10;
	}
	return (num / divisor) % 10;
}

// 基数排序函数
void radixSort(int arr[], int n) {
	int maxVal = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	int numDigits = 0;
	int temp = maxVal;
	while (temp > 0) {
		temp /= 10;
		numDigits++;
	}

	int* buckets[10];
	for (int i = 0; i < 10; i++) {
		buckets[i] = new int[n];
	}
	int bucketSizes[10] = { 0 };

	for (int digit = 1; digit <= numDigits; digit++) {
		for (int i = 0; i < n; i++) {
			int currentDigit = getDigit(arr[i], digit);
			buckets[currentDigit][bucketSizes[currentDigit]++] = arr[i];
		}

		int index = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < bucketSizes[i]; j++) {
				arr[index++] = buckets[i][j];
			}
			bucketSizes[i] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		delete[] buckets[i];
	}
}

//计数排序
void countingSort(int arr[], int n) {
	// 找出数组中的最大值和最小值
	int maxVal = arr[0];
	int minVal = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
	}

	// 创建计数数组并统计每个元素出现的次数
	int range = maxVal - minVal + 1;
	int* count = new int[range];
	for (int i = 0; i < range; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[arr[i] - minVal]++;
	}

	// 对计数数组进行累加，得到每个元素在排序后数组中的位置
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	// 创建临时数组，用于存储排序后的结果
	int* sortedArr = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		sortedArr[count[arr[i] - minVal] - 1] = arr[i];
		count[arr[i] - minVal]--;
	}

	// 将排序后的结果复制回原始数组
	for (int i = 0; i < n; i++) {
		arr[i] = sortedArr[i];
	}

	delete[] count;
	delete[] sortedArr;
}

#include <vector>
void bucketSort(int arr[], int n) {
	// 找出数组中的最大值和最小值
	int maxVal = arr[0];
	int minVal = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
	}

	// 确定桶的数量和范围
	int numBuckets = n;
	std::vector<std::vector<int>> buckets(numBuckets);
	int range = maxVal - minVal + 1;//防止出现maxVal==minVal的情况同时也为了防止bucketIndex=numBuckets的情况，就会造成访问溢出的情况
	for (int i = 0; i < n; i++) {
		int bucketIndex = (arr[i] - minVal) * numBuckets / range;
		buckets[bucketIndex].push_back(arr[i]);
	}

	// 对每个桶进行排序，可以使用插入排序等简单算法
	for (int i = 0; i < numBuckets; i++) {
		for (int j = 1; j < buckets[i].size(); j++) {
			int key = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > key) {
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = key;
		}
	}

	// 将排序后的桶中的元素复制回原始数组
	int index = 0;
	for (int i = 0; i < numBuckets; i++) {
		for (int j = 0; j < buckets[i].size(); j++) {
			arr[index++] = buckets[i][j];
		}
	}
}