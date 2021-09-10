#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int l, int h,int &count)
{
    int x = arr[h];
	int i = (l - 1);
	for (int j = l; j <= h - 1; j++)
    {
		if (arr[j] <= x)
        {
			i++;
            count=count+1;
			swap(&arr[i], &arr[j]);
		}
	}
    count=count+1;
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}
void quickSortIterative(int arr[], int l, int h,int &count)
{
	int stack[h - l + 1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while (top >= 0) 
    {
		h = stack[top--];
		l = stack[top--];
		int p = partition(arr, l, h,count);
		if (p - 1 > l) 
        {
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < h) 
        {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << " ";
}
int main()
{
	int arr[] = { 23,65,21,76,46,89,45,32 };
	int count=0;
    int n = sizeof(arr) / sizeof(*arr);
	quickSortIterative(arr, 0, n - 1,count);
	printArr(arr, n);
    cout<<endl<<count;
	return 0;
}
