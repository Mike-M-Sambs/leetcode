#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> ans;
        int maxJumps = nums.size() > 100 ? nums.size() / 2 : nums.size() - 1;
        int maxValue = 0;
        int maxValueIdx = -1;
        int minValueAfterMax = -1;
        int minValueAfterMaxIdx = -1;
        int leftMax = nums[0];
        int leftMaxIdx = 0;
        vector<vector<int>> rightMin(2, vector<int>(nums.size(), 0));
        vector<int> vResults(nums.size(), -1); // for shortcuts

        // search vector for maxValue
        for(int i = 0; i <= nums.size() - 1; i++)
        {
            if(nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxValueIdx = i;    
            }
        }
        minValueAfterMax = maxValue;

        // search for min Value after Max to jump to
        for(int i = maxValueIdx; i <= nums.size() - 1; i++)
        {
            if(nums[i] < minValueAfterMax)
            {
                minValueAfterMax = nums[i];
                minValueAfterMaxIdx = i;    
            }
        }

        // search min val from right
        rightMin[0][nums.size()-1] = nums[nums.size()-1]; // val
        rightMin[1][nums.size()-1] = nums.size()-1;       // idx
        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(nums[i] > rightMin[0][i + 1])
            {
                rightMin[0][i] = rightMin[0][i+1]; // val
                rightMin[1][i] = rightMin[1][i+1]; // idx
            }
            else
            {
                rightMin[0][i] = nums[i]; // val
                rightMin[1][i] = i;       // idx
            }
        }

        // main check
        for(int i = 0; i <= nums.size() - 1; i++)
        {
            if(nums[i] > leftMax)
            {
                leftMax = nums[i];
                leftMaxIdx = i;
            }

            if(leftMax == maxValue || (minValueAfterMax != maxValue && i < minValueAfterMaxIdx && nums[i] > minValueAfterMax))
            {
                ans.push_back(maxValue);
                vResults[i] = maxValue;
            }
            else
            {
                ans.push_back(searchMaxVal(nums, i, leftMax, leftMaxIdx, maxValue, rightMin, vResults, maxJumps));
                vResults[i] = ans[i];
            }
        }

        return ans;
    }

private:
    int searchMaxVal(vector<int>& nums, int idx, int leftMax, int leftMaxIdx, int maxValue, vector<vector<int>>& rightMin, vector<int>& vResults, int maxJumpsRemaining)
    {
        // break conditions
        if(maxJumpsRemaining <= 0) // if max depth reached
        {return nums[idx];}
        if(vResults[idx] > 0) // if already executed, then shortcut!
        {return vResults[idx];}

        int result = nums[idx];

        // jump left
        if(nums[idx] < leftMax)
        {
            result = leftMax;
            if(result == maxValue)
            {
                return maxValue;
            }
            if(vResults[leftMaxIdx] > 0) // if already executed, then shortcut!
            {
                return vResults[leftMaxIdx];
            }
            return searchMaxVal(nums, leftMaxIdx, leftMax, leftMaxIdx, maxValue, rightMin, vResults, maxJumpsRemaining - 1);
        }

        // jump right
        int inbetweenMax = nums[idx];
        int inbetweenIdx = idx;
        if(nums[idx] > rightMin[0][idx])
        {
            int idxToCheck = rightMin[1][idx];
            if(idxToCheck <= idx + 1)
            {
                idxToCheck = getNextRightMinIndex(rightMin, idxToCheck);
            }
            do
            {
                if(nums[idx] <= rightMin[0][idxToCheck])
                {idxToCheck = -1;}

                for(int k = idxToCheck - 1; k > idx; k--)
                {
                    if(nums[k] > inbetweenMax)
                    {
                        inbetweenMax = nums[k];
                        inbetweenIdx = k;
                        idxToCheck = -1;
                        if(inbetweenMax == maxValue)
                        {
                            return maxValue;
                        }
                    }
                }
                if(idxToCheck != -1)
                {
                    idxToCheck = getNextRightMinIndex(rightMin, idxToCheck);
                }
            } while (idxToCheck != -1);
        
            if(inbetweenMax > result)
            {
                result = searchMaxVal(nums, inbetweenIdx, inbetweenMax, inbetweenIdx, maxValue, rightMin, vResults, maxJumpsRemaining - 1);
                vResults[inbetweenIdx] = result;
            }
        }

        return result;
    }

    int getNextRightMinIndex(vector<vector<int>>& rightMin, int idx)
    {
        int result = -1;

        for(int i = idx; i <= rightMin[0].size() - 2; i++)
        {
            if(rightMin[1][i] != rightMin[1][i+1])
            {
                result = rightMin[1][i+1];
                break;
            }
        }

        return result;
    }
};