class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    string result = "";

    int minLength = word1.length()<word2.length() ? word1.length() : word2.length();

    for (int i = 0; i < minLength; i++) {
        result += word1[i];
        result += word2[i];
    }

    if(word1.length()<word2.length())
    {
        result += word2.substr(minLength);
    }
    else
    {
        result += word1.substr(minLength);
    }
        
    return result;
    }
};
