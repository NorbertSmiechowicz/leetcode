/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

 

Constraints:

    1 <= s.length <= 20
    1 <= p.length <= 20
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

*/


/*
    1. when * check if previous ptrn_char is 0 or more
    2. when .* take all characters until end
        3. if pattern continues return

    -> recurrence ??

*/

#include<string>
#include<iostream>
#include<vector>

struct Solution {

    struct token{
        char chr;
        bool star;

        token(char const & c): chr{c}, star{false}{};
        token(char const & c, bool const & b): chr{c}, star{b}{};

        bool operator ==(std::string const & s){
            if(this->star){
                if(this->chr == '.') return true;

                for(auto& s_chr : s){
                    if(s_chr != this->chr) return false;
                }
                return true;
            }

            if(s.size() != 1) return false;

            if(this->chr == '.') return true;
            if(this->chr == s[0]) return true;
            return false;
        }

        std::string popFront(std::string const & s){
            
            if(this->star){
                if(this->chr == '.') return "";

                int offset = 0;
                for(auto& s_chr : s){
                    if(s_chr != this->chr) goto escape;
                    offset++;
                }
                escape:
                std::string out = "";
                for(int cid = offset; cid < s.size(); cid++){
                    out.push_back(s[cid]);
                }
                return out;
            }
            
            if(s.size() == 0) return "";


            if(this->chr == '.') goto escape1;
            if(this->chr != s[0]) return s;

            escape1:
            std::string out = "";
            out.reserve(s.size()+1);

            for(int cid = 1; cid < s.size(); cid++){
                out.push_back(s[cid]);
            }
            
            return out;
        }

        bool operator ==(char const & s){
            if(this->chr == '.') return true;
            if(this->chr == s) return true;
            return false;
        }
    };

    static bool isMatch(std::string const & s, std::string const & p) {

        std::vector<token> tokens;

        int tkn_id = 0;
        for(auto& s_chr : s){

            if(s[tkn_id] == '*') {
                tokens[tkn_id].star = true;
            }

            else{
                tokens.push_back(token{s_chr});
                tkn_id++;
            }
        }

        return true;
    }

};

int main(){


    // std::cout<<(Solution::token{'a',0}=="a")<<"\t"<<(Solution::token{'a',0}.popFront("a"))<<"\n";
    // std::cout<<(Solution::token{'a',0}=="aa")<<"\t"<<(Solution::token{'a',0}.popFront("aa"))<<"\n";
    // std::cout<<(Solution::token{'a',1}=="aa")<<"\t"<<(Solution::token{'a',1}.popFront("aa"))<<"\n";
    // std::cout<<(Solution::token{'a',1}=="ab")<<"\t"<<(Solution::token{'a',1}.popFront("ab"))<<"\n";
    // std::cout<<(Solution::token{'.',1}=="ab")<<"\t"<<(Solution::token{'.',1}.popFront("ab"))<<"\n";
    // std::cout<<(Solution::token{'.',1}=="")<<"\t"<<(Solution::token{'.',1}.popFront(""))<<"\n";
    // std::cout<<(Solution::token{'.',0}=="")<<"\t"<<(Solution::token{'.',0}.popFront(""))<<"\n";
    // std::cout<<(Solution::token{'a',0}=="")<<"\t"<<(Solution::token{'a',0}.popFront(""))<<"\n";

    // std::cout<<Solution::isMatch("aa","a")<<"\n";

    // std::cout<<Solution::isMatch("aa","a*")<<"\n";

    // std::cout<<Solution::isMatch("ab",".*")<<"\n";

    return 0;
}