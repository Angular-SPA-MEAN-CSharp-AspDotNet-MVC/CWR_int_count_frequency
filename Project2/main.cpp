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

void displayPair(vector<pair<int, int>> *pairResult, int size) {
	for (int i = 0; i < size; i++){
		cout << (((pairResult[0])._Myfirst)[0]).first << "  " << (((pairResult[0])._Myfirst)[0]).second;
	}
	cout << endl;	
}

void countProcess(char *ary = nullptr, int size = 0){
	vector<pair<int, int>> result;
	result.push_back(make_pair(3, 5));

	displayPair(&result, 1);
}

int main() {
	int size;
	char ipt[] = { 'a', 'b', 'b', 'v', 'v', 'v' };
	cout << "Please enter the array. \n";
	size = sizeof(ipt) / sizeof(*ipt);

	cout << "The initial array is: \n";
	display(ipt, size);

	cout << "\n Input the array to process";
	countProcess(ipt, size);

	cout << "Press any key to exit this console application.";
	cin.ignore();
	return 1; // An non-zero value indicates the app succeeds.
}
