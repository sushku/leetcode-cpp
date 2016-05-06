#include <iostream>

const int SUCCESS = 0;
const int FAILURE = 1;

using namespace std;

int problemSwitcher(int num) {
	cout << num << endl;
	return SUCCESS;
}

int main(int argc, char * argv[]) {
	int ret = SUCCESS;
	int pNum = 0;
	switch(argc) {
		case 1:
			cout << "Please specify the problem number to execute from https://leetcode.com" << endl;
			ret = FAILURE;
			break;
		case 2:
			pNum = atoi(argv[1]);
			if(pNum <= 0) {
				cout << "Argument must be a single valid problem number from https://leetcode.com" << endl;
				ret = FAILURE;
			}
			else {
				ret = problemSwitcher(pNum);
			}
			break;
		default:
			cout << "Expected 1 argument. Found " << argc - 1 << "." << endl;
			ret = FAILURE;
	}
	return ret;
}
