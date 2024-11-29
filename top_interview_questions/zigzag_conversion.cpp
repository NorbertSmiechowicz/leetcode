#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        
        
        if(numRows == 0) return "";
        if(numRows == 1) return s;

        std::string solution = "";
        solution.reserve(s.size());

        {
            int charId = 0;

            while(charId < s.size()){            
                solution.push_back(s[charId]);
                charId += 2*(numRows - 1);
            }
        }

        for(int row = 1; row < numRows - 1; row++){

            int charId = row;

            while(charId < s.size()){
                
                solution.push_back(s[charId]);
                if(charId + 2*(numRows - row - 1) < s.size()) solution.push_back(s[charId + 2*(numRows - row - 1)]);
                charId += 2*(numRows - 1);
            }
        }
        {
            int charId = numRows - 1;

            while(charId < s.size()){            
                solution.push_back(s[charId]);
                charId += 2*(numRows - 1);
            }
        }

        return solution;
    }   
};