#pragma once
#include<iostream>
using namespace std;

void insertSort(int arr[], int n);
void selectSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void shellSort(int arr[], int n);
void quickSort(int arr[], int low, int high);

void sift(int arr[], int low, int high);
void heapSort(int arr[], int n);

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int getDigit(int num, int digit);
void radixSort(int arr[], int n);//»ùÊýÅÅÐò

void binaryInsertionSort(int arr[], int n);
void countingSort(int arr[], int n);
void bucketSort(int arr[], int n);