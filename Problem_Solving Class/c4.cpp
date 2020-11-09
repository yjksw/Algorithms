#include <stdio.h>
#include <iostream>
using namespace std;

void heapify (int heap[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left<n && heap[left]>heap[largest])
        largest = left;
    if (right<n && heap[right]>heap[largest])
        largest = right;
    if (largest != root) {
        swap(heap[root], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapSort(int heap[], int n) {
    for (int i=n/2-1 ; i>=0 ; i--) {
        heapify(heap, n, i);
    }
    for (int i=n-1 ; i>=0 ; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int main() {
	int nPoles, nAmp;
	cin >> nPoles >> nAmp;

	int poles[nPoles];
	fill_n(poles, nPoles, 0);

	for(int i=0;i<nPoles;i++){	
		cin >> poles[i];
	}
	
	heapSort(poles, nPoles);

	int maxDist = poles[nPoles-1] - poles[0];
	int binLeft = 1;
	int binRight = maxDist;
	int mid = 0;
	
	while(binLeft<=binRight) {
		mid = (binLeft+binRight)/2;
		int countAmp = 1;
		int posAmp = poles[0];
		for(int i=1 ; i<nPoles ; i++){
			if(poles[i]-posAmp >= mid){
				posAmp = poles[i];
				countAmp++;
			}
		}
		if(countAmp >= nAmp)
			binLeft = mid+1;
		else
			binRight = mid-1;
	}

	cout << binRight;
	exit(0);
}
