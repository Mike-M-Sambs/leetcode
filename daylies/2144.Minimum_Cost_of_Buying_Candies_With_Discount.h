#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int length = cost.size();
        int result = 0;
        int temp = -1;

        // trivial resolution
        if(length == 1)
        {return cost[0];}

        // Sort vector in ascending order
        sort(cost.begin(), cost.end());

        do
        {
            result += cost[length - 1];
            cost.pop_back(); length --;

            if(length > 0)
            {
                temp = cost[length - 1];
                result += temp;
                cost.pop_back(); length --;
            }

            if(length > 0 && cost[length - 1] <= temp)
            {cost.pop_back(); length --;} // don't add to cost

        } while (length > 0);
        
        return result;
    }
};

