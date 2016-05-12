#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		unordered_map<int, int> idxmap;
		for(int i = 0; i < nums.size(); i++) {
			idxmap[nums[i]] = i;
		}
		for(int j = 0; j < nums.size(); j++) {
			int complement = target - nums[j];
			if(idxmap.count(complement) > 0 && idxmap[complement] != j) {
				res.push_back(j);
				res.push_back(idxmap[complement]);
				break;
			}
		}
		return res;
	}
};

int main() {
	int arr[] = {2, 7, 11, 15};
	int target = 9;

	int size = sizeof(arr)/sizeof(int);

	vector<int> nums(arr, arr + size);

	Solution sol;
	vector<int> res = sol.twoSum(nums, target);

	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}
