#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;
        int n = A.size();
        int count = 0;

        cout << "n: " << n; // test

        // first item
        if(A[0] == B[0]) {count = 1;}
        result.push_back(count);

        for(int i = 1; i < n - 1; i++)
        {
            if(A[i] == B[i]) count++;
            else
            {
                for(int j = i; j >= 0; j--)
                {
                    if(A[i] == B[j]) count++;
                    if(B[i] == A[j]) count++;
                }
            }

            result.push_back(count);
        }

        // last item
        if(n > 1) result.push_back(n);

        return result;
    }
};
