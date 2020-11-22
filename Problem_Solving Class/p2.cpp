#include <iostream>
#include <stdio.h>

using namespace std;

void swap(long long a[2], long long b[2]){
	long long temp[2];
	
	temp[0] = a[0];
	temp[1] = a[1];
	a[0] = b[0];
	a[1] = b[1];
	b[0] = temp[0];
	b[1] = temp[1];
	
	return;
}
void quicksort(int start, int end, long long arr[][2]){
	if(start>=end)
		return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;

	while(i<=j){
		while(arr[j][1] > arr[pivot][1])
			j--;
		while(arr[i][1] < arr[pivot][1])
			i++;
		if(i>j)
			swap(arr[pivot], arr[j]);
		else
			swap(arr[j], arr[i]);
	}	
	
	quicksort(start, j-1, arr);
	quicksort(j+1, end, arr);

	return;
}

int main(){
	int n, k;
	cin >> n >> k;

	long long input[n][2];
	for(int i=0;i<n;i++){
		cin >> input[i][0] >> input[i][1];
	}

	long long n_ppl = 0;
	long long max = 0; 

	quicksort(0, n-1, input);
	
	int begin = 0;
	int start_index = 0;
	while(input[start_index][1] <= input[0][1]+2*k){
		n_ppl += input[start_index][0];
		start_index++;
	}
	
	max = n_ppl;
	for(int i=start_index;i<n;i++){
		n_ppl += input[i][0];
		while(input[begin][1] < input[i][1]-2*k){
			n_ppl -= input[begin][0];
			begin++;
		}
		if(n_ppl > max)
			max = n_ppl;
	}

	cout << max;
	exit(0);
}
