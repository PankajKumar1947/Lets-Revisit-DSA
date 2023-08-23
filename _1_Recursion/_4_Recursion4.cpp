#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

// 7. Combination Sum-I:
// Given an array distinct integers candiates and target integer return all unique combination of candidates where the choosen numbers sum to target. return list in any order.
// Solution:
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    // pick up the element
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    // not pick the condition
    findCombination(ind + 1, target, arr, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

// 8. Combination Sum-II : Find unique combinations.
// Note that each number in candidates may be used only once in the combination.
// Also note that Solution set must not contain duplicate combinations
void findCombinationII(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombinationII(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinationII(0, target, candidates, ans, ds);
    return ans;
}

// 9. Subset Sum: return power set
// output should be printed in increasing order
void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    // element is picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    // element is not picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum);
}
vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}



//10. Subset Sum-II: Return all possible subsets(The Power Set)
//The solution set must not contain duplicate subsets.
//Return solution in any order.
void printAns(vector < vector < int >> & ans) {
  cout << "The unique subsets are " << endl;
  cout << "[ ";
  for (int i = 0; i < ans.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]";
  }
  cout << " ]";
}
void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
    if (index == nums.size()) {
    sort(ds.begin(), ds.end());
    res.insert(ds);
    return;
    }
    ds.push_back(nums[index]);
    fun(nums, index + 1, ds, res);
    ds.pop_back();
    fun(nums, index + 1, ds, res);
}
vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    fun(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
        ans.push_back( * it);
    }
    return ans;
}

int main()
{
    // 7.
    //  vector<int> v{2, 3, 6, 7};
    //  int target = 7;

    // vector<vector<int>> ans = combinationSum(v, target);
    // cout << "Combinations are: " << endl;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //         cout << ans[i][j] << " ";
    //     cout << endl;

    // }

    // 8.
    // vector<int> v{10, 1, 2, 7, 6, 1, 5};
    // vector<vector<int>> comb = combinationSum2(v, 8);
    // cout << "[ ";
    // for (int i = 0; i < comb.size(); i++)
    // {
    //     cout << "[ ";
    //     for (int j = 0; j < comb[i].size(); j++)
    //     {
    //         cout << comb[i][j] << " ";
    //     }
    //     cout << "]";
    // }
    // cout << " ]";

    // 9.
    // vector<int> arr{3, 1, 2};
    // vector<int> ans = subsetSums(arr, arr.size());
    // sort(ans.begin(), ans.end());
    // cout << "The sum of each subset is " << endl;
    // for (auto sum : ans)
    // {
    //     cout << sum << " ";
    // }
    // cout << endl;


    //10.
     vector < int > nums = {1, 2, 2};
    vector<vector<int>>ans=subsetsWithDup(nums);
    printAns(ans);

    return 0;
}