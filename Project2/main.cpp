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
		cout << ((pairResult)->_Myfirst)[i].first << "  " << ((pairResult)->_Myfirst)[i].second;
		cout << endl;
	}
	cout << endl;	
}

void countProcess(char ary[], int size){
	vector<pair<char, int>> result;

	if (ary == nullptr || size == 0){
		return;
	}

	int cnt = 1, startIdx = 0;
	for (int i = startIdx+1; i < size; i++){
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


int main() {
	int size;
	char ipt[] = "abbdddffffffvvvx";
	cout << "Please enter the array. \n";
	//size = sizeof(ipt) / sizeof(*ipt)-1;
	size = strlen(ipt);

	cout << "The initial array is: \n";
	display(ipt, size);

	cout << "\n The count reult is below:";
	countProcess(ipt, size);

	cout << "Press any key to exit this console application.";
	cin.ignore();
	return 1; // An non-zero value indicates the app succeeds.
}
