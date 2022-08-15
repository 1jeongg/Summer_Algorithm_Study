#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void quick_sort(vector<int>& arr, int start, int end);

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	random_shuffle(arr.begin(), arr.end()); // pivot을 랜덤으로 잡기 위해 배열을 섞는다.
	quick_sort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
void quick_sort(vector<int>& arr, int start, int end) {
	if (start >= end)
		return;
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int tmp;
	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}
		if (i > j) {
			tmp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = tmp;
		}
		else {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}
