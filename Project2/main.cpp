#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

void display(char *ary, int size) {
	for (int i = 0; i < size; i++){
		cout << ary[i] << " ";
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

string generateTestingStr(){
	//generate 10 different characters from a~z, in sequence;
	const int MAX = 26, MAXREPEAT = 91;
	char txtChar;
	int typeLen = 10, tstPt;
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
		'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u',
		'v', 'w', 'x', 'y', 'z' };
	string res = "";
	srand(time(NULL));  //  using the time seed from srand explanation 
	for (int i = 0; i < typeLen; i++){
		res = res + alphabet[rand() % MAX];
	}
	sort(res.begin(), res.end()); // generate sorted string with 10 chars randomly
	for (int i = res.size() - 1; i >= 0; i--){
		tstPt = rand() % MAXREPEAT + 9; // generate random number 9~99
		res.insert( i, string(tstPt, res.at(i)) ); // repeat one char 10~100 times randomly
	}
	return res; // generate a sorted string with 10 (typeLen) chars, total length 100~1000 characters
}

int main() {
	int size, iptVal;
	string testStr = generateTestingStr();

	cout << "\nPlease make the selection below: \n";
	cout << "\nEnter 0 to use the quesion provided string. \nEnter anything else will use a random testing string: \n";
	char *ipt;
	cin >> iptVal;
	if (iptVal == 0){
		ipt = "abbbbbdhhhp";
	}
	else{
		
		ipt = &testStr[0];	
	}

	size = strlen(ipt);
	cout << endl;

	cout << "The initial array for counting is: \n";
	display(ipt, size);
	cout << endl;

	cout << "\nThe regular O(N) count reult is below , value -- frequency :";
	countProcess(ipt, size);
	cout << endl;

	cout << "\nThe fast O(logN) count reult is below, value -- frequency :";
	countFastProcess(ipt, size);
	cout << endl;

	cout << "\nPress enter key to exit this console application.";
	cin.ignore();
	cin.get();
	return 1; // An non-zero value indicates the app succeeds.
}
