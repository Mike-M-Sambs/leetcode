#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int result = 0;
        auto count = 0;
        result = std::ranges::count(text, 'b');

        for (const char target : {'a', 'n'})
        {
            count = std::ranges::count(text, target);
            if(result > count)
            { result = count; }
        }
        for (const char target : {'l', 'o'})
        {
            count = std::ranges::count(text, target);
            if(result > count/2)
            { result = count/2; }
        }

        return result;
    }
};