#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(char *ary, int size) {
	for (int i = 0; i < size; i++){
		cout << ary[i] << "  ";
	}
	cout << endl;
}

void displayPair(vector<pair<char, int>> *pairResult, int size) {
	cout << endl;
	for (int i = 0; i < size; i++){
		cout << ((pairResult)->_Myfirst)[i].first << " --- " << ((pairResult)->_Myfirst)[i].second;
		cout << endl;
	}
	cout << endl;	
}

void countProcess(char ary[], int size){
	vector<pair<char, int>> result;

	if (ary == nullptr || size == 0){
		return;
	}

	int cnt = 0, startIdx = 0;
	for (int i = 0; i < size; i++){
		if (ary[startIdx] == ary[i]){
			cnt++;
		}
		else{
			result.push_back(make_pair(ary[startIdx], cnt));
			cnt = 1;
			startIdx = i;
		}
		if (i == (size - 1)){
			result.push_back(make_pair(ary[startIdx], cnt));
		}
	}
	displayPair(&result, result.size());
}

// to return the first different item index, using "binary search". O(N)
int findNextDiffItemIdx(char ary[], int size, int startIdx){
	int endIdx = size - 1;
	while (startIdx < endIdx){
		if (ary[startIdx] == ary[endIdx]){
			startIdx = endIdx;
			endIdx = size - 1;
		}
		else{
			endIdx = (startIdx + endIdx) / 2; // binary search idea applied here
		}
	}
	return endIdx;
}

void countFastProcess(char ary[], int size){
	vector<pair<char, int>> result;

	if (ary == nullptr || size == 0){
		return;
	}

	int cnt, endIdx, startIdx = 0;

	while (startIdx < size){
		endIdx = findNextDiffItemIdx(ary, size, startIdx); 
		cnt = endIdx - startIdx + 1;
		result.push_back(make_pair(ary[startIdx], cnt));
		startIdx = endIdx+1;
	}

	displayPair(&result, result.size());
}

int main() {
	int size;
	char ipt[] = "abbbbbdhhhp";
	cout << "Please enter the array. \n";
	size = strlen(ipt);
	cout << endl;

	cout << "The initial array is: \n";
	display(ipt, size);
	cout << endl;

	cout << "\nThe count reult is below, value -- frequency :";
	countProcess(ipt, size);
	cout << endl;

	cout << "\nThe fast count reult is below, value -- frequency :";
	countFastProcess(ipt, size);
	cout << endl;

	cout << "\nPress any key to exit this console application.";
	cin.ignore();
	return 1; // An non-zero value indicates the app succeeds.
}
