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
				//��Ϊ��ʼ������i=low��lowλ����Ψһһ������λ�ã�������Ҫ�ȴ�high�˿�ʼ��һ����tempС�Ĺؼ��֣��浽arr[i]����arr[low]����
				i++;
			}
			while (i < j && arr[i] < temp)i++;
			if (i < j) {
				arr[j] = arr[i];
				//���������ִ�й�����Ȼjָ�����һ������λ�ã���Ϊjλ�õ�Ԫ�ر�tempС���Ѿ���������һ����arr[i]�У�������һ��Ҫ��low�����ҳ���tmepС��һ���ؼ��ִ浽jλ��
				j--;
			}

		}
		arr[i] = temp;//or arr[j] = tmep;
		quickSort(arr, low, i - 1);
		quickSort(arr, i + 1, high);
	}
}

void sift(int arr[], int low, int high) {
	int i = low, j = 2 * i + 1; // j Ϊ i �����ӡ�����ͨ����ʽ�������ǰ�ڵ� i �����ӽڵ��������
	int temp = arr[i];
	while (j <= high) {
		if (j < high && arr[j] < arr[j + 1])j++; // ����Һ��Ӵ����ұ����Ӵ󣬾ͽ� j ָ���Һ��ӡ�
		if (temp < arr[j]) {
			arr[i] = arr[j]; // ���ϴ���ӽڵ�ֵ�������ڵ㡣
			i = j;
			j = 2 * i + 1; // ���� j Ϊ�µ� i �����ӡ�
		}
		else break; // ������ڵ㲻С���ӽڵ㣬����������
	}
	arr[i] = temp; // �� temp��ԭʼ���ڵ�ֵ���������յ������λ�á�
}
void heapSort(int arr[], int n) {
	int i;
	int temp;
	for (i = n / 2 - 1; i >= 0; i--) {
		sift(arr, i, n - 1); // �����һ����Ҷ�ӽڵ㿪ʼ���������Ϊ�󶥶ѡ�
	}
	for (i = n - 1; i > 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp; // ���Ѷ�Ԫ���뵱ǰδ���򲿷ֵ����һ��Ԫ�ؽ�����
		sift(arr, 0, i - 1); // ���µĶѶ�Ԫ�ؽ��е�����
	}
}

void merge(int arr[], int low, int mid, int high) {
	//�鲢��low��mid��mid+1��high�ϵ�������������
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
		for (int j = i; j > low; j--) {//��ʱlow==high
			arr[j] = arr[j - 1];
		}
		arr[low] = key;//or arr[high]=key
	}
}

// ��ȡ���ֵ�ָ��λ���ϵ�����
int getDigit(int num, int digit) {
	int divisor = 1;
	for (int i = 0; i < digit - 1; i++) {
		divisor *= 10;
	}
	return (num / divisor) % 10;
}

// ����������
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

//��������
void countingSort(int arr[], int n) {
	// �ҳ������е����ֵ����Сֵ
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

	// �����������鲢ͳ��ÿ��Ԫ�س��ֵĴ���
	int range = maxVal - minVal + 1;
	int* count = new int[range];
	for (int i = 0; i < range; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[arr[i] - minVal]++;
	}

	// �Լ�����������ۼӣ��õ�ÿ��Ԫ��������������е�λ��
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	// ������ʱ���飬���ڴ洢�����Ľ��
	int* sortedArr = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		sortedArr[count[arr[i] - minVal] - 1] = arr[i];
		count[arr[i] - minVal]--;
	}

	// �������Ľ�����ƻ�ԭʼ����
	for (int i = 0; i < n; i++) {
		arr[i] = sortedArr[i];
	}

	delete[] count;
	delete[] sortedArr;
}

#include <vector>
void bucketSort(int arr[], int n) {
	// �ҳ������е����ֵ����Сֵ
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

	// ȷ��Ͱ�������ͷ�Χ
	int numBuckets = n;
	std::vector<std::vector<int>> buckets(numBuckets);
	int range = maxVal - minVal + 1;//��ֹ����maxVal==minVal�����ͬʱҲΪ�˷�ֹbucketIndex=numBuckets��������ͻ���ɷ�����������
	for (int i = 0; i < n; i++) {
		int bucketIndex = (arr[i] - minVal) * numBuckets / range;
		buckets[bucketIndex].push_back(arr[i]);
	}

	// ��ÿ��Ͱ�������򣬿���ʹ�ò�������ȼ��㷨
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

	// ��������Ͱ�е�Ԫ�ظ��ƻ�ԭʼ����
	int index = 0;
	for (int i = 0; i < numBuckets; i++) {
		for (int j = 0; j < buckets[i].size(); j++) {
			arr[index++] = buckets[i][j];
		}
	}
}