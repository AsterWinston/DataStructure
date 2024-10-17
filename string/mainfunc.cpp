#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>
class str {
public:
	char* ch;
	int length;
	str() {
		this->ch = NULL;
		this->length = 0;
	}
	void initStr();

};

int* build_next(char*dest, int len) {
	int* arr = new int[len];
	arr[0] = 0;
	int prefix_len = 0;
	int i = 1;
	//int index = 1;
	while (i < len) {
		if (dest[prefix_len] == dest[i]) {
			prefix_len++;
			arr[i++] = prefix_len;

		}
		else {
			if (prefix_len == 0) {
				arr[i++] = 0;
			}
			else {
				prefix_len = arr[prefix_len - 1];
			}
		}
	}
	return arr;
}
int kmp_search(char* src, int len1, char* dest, int len2) {
	int* next = build_next(dest, len2);
	int i = 0, j = 0;
	while (i < len1) {
		if (src[i] == dest[j]) {
			i++;
			j++;
		}
		else if (j > 0) {
			j = next[j - 1];
		}
		else {
			i++;
		}
		if (j == len2) {
			return i - j;
		}
	}
	cout << "can not find string" << endl;
	return len1;
}

int main() {
	char str1[] = "ababdabcabd";
	char str2[] = "a";
	int pos = kmp_search(str1, strlen(str1), str2, strlen(str2));
	cout << "pos:" << pos << endl;
	char* str3 = new char[strlen(str2)+1];
	strncpy(str3, str1+pos, strlen(str2));
	str3[strlen(str2)] = '\0';
	cout << str3 << endl;
	system("pause");
	return 0;
}
