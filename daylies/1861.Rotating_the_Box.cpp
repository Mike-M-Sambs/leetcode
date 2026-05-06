class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int verLength = boxGrid.size();
        int horLength = boxGrid[0].size();

        // gravity effect
        vector<vector<char>> gravitatedBox;
        for (vector<char> boxGridLine : boxGrid)
        {
            for (int idx = horLength - 1; idx > 0; --idx)
            {
                if(boxGridLine[idx] == '.')
                {
                    for (int j = idx - 1; j >= 0; --j)
                    {
                        if(boxGridLine[j] == '*') {break;}
                        if(boxGridLine[j] == '#')
                        {
                            boxGridLine[idx] = '#';
                            boxGridLine[j] = '.';
                            break;
                        }
                    }
                }
            }

            gravitatedBox.push_back(boxGridLine);
        }

        // rotate Box
        vector<vector<char>> rotatedBox;
        for (int row = 0; row < horLength; ++row)
        {
            vector<char> rotatedLine;

            for (int line = verLength - 1; line >= 0; --line) // backward
            {
                rotatedLine.push_back(gravitatedBox[line][row]);
            }
            rotatedBox.push_back(rotatedLine);
        }

        return rotatedBox;
    }
};
