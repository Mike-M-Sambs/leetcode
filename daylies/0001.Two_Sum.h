#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        vector<int> idxOne;
        vector<int> idxTwo;
        vector<int> idxSame;
        int negativeMin = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                if(negativeMin > nums[i])
                {negativeMin = nums[i];}
            }
        }

        int offset = target + (negativeMin*(-1));
        int targetHalf = target/2;
        bool isEqual = (target%2 == 0) ;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] <= targetHalf)
            {idxOne.push_back(i);}

            if(nums[i] >= targetHalf && nums[i] <= offset)
            {idxTwo.push_back(i);}

            if(nums[i] == targetHalf && isEqual)
            {
                idxSame.push_back(i);
                if(idxSame.size() > 1)
                {  return idxSame; }
            }
        }

        for(int i = 0; i<idxOne.size(); i++)
        {
            for(int j = 0; j<idxTwo.size(); j++)
            {
                if(nums[idxOne[i]] + nums[idxTwo[j]] == target && idxOne[i] != idxTwo[j])
                {
                    result.push_back(idxOne[i]);
                    result.push_back(idxTwo[j]);

                    // break;
                    return result;
                }
            }
        }
        
        // not found!
        return result;
    }
};
