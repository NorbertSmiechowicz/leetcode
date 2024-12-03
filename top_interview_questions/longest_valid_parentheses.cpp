#include <iostream>
#include <unordered_map>
#include <vector>

// struct Solution {

//     //                     '('                       ')'
//     //  0  ->1, ->begin                         ->0
//     //  1  ->0, del begin, del end, calc max    ->2, ->end
//     //  2  ->1, ->begin                         ->2, ->end

//     struct parentheses_stack_frame{
//         // 0 - none found
//         // 1 - only begin found
//         // 2 - begin and end found
//         int code;
//         int begin;
//         int end;
//         parentheses_stack_frame(): code{0}, begin{0}, end{0} {};
//         parentheses_stack_frame(const char& code, const int& begin, const int& end):
//             code{code}, begin{begin}, end{end} {};
//         friend std::ostream& operator<<(std::ostream& os, const parentheses_stack_frame& obj){
//             os << "code: " << obj.code << "\t\tbegin: " << obj.begin << "  end: " << obj.end;
//             return os;
//         }
//     };

//     static int longestValidParentheses(const std::string &s) {

//         std::unordered_map<int, parentheses_stack_frame> stack_frame_map;

//         int firstopen = 0;
//         while(firstopen < s.size()){
//             if(s[firstopen] == '(') break;
//             firstopen++;
//         }

//         int max_length = 0;
//         int lenght = 0;
//         int parentheses_stack_height = 0;
//         stack_frame_map[firstopen] = parentheses_stack_frame(1,0,0);

//         for(int charId = firstopen; charId < s.size(); charId++){
//             if(s[charId] == '('){

//                 parentheses_stack_height++;

//                 if(stack_frame_map[parentheses_stack_height].code < 2){
//                     stack_frame_map[parentheses_stack_height].code = 1;
//                     stack_frame_map[parentheses_stack_height].begin = charId;
//                 }
//                 else{
//                     stack_frame_map[parentheses_stack_height].code = 0;
//                     lenght = stack_frame_map[parentheses_stack_height].end - stack_frame_map[parentheses_stack_height].begin;
//                     if(lenght > max_length) max_length = lenght;
//                 }

//             }
//             else {               

//                 parentheses_stack_height--;

//                 if(stack_frame_map[parentheses_stack_height].code > 0){
//                     stack_frame_map[parentheses_stack_height].code = 2;
//                     stack_frame_map[parentheses_stack_height].end = charId;
//                 }


//             }
//         }

//         for(auto& [key,val]: stack_frame_map){
//             std::cout<<"height: "<<key<<"\t"<<val<<"\n";
//         }


//         for(auto& [key,val]: stack_frame_map){
//             if(val.code == 2){
//                 lenght = val.end - val.begin;
//                 if(lenght > max_length) max_length = lenght;
//             }
//         }

//         if(max_length == 0) return 0;
//         return max_length+1;
//     }
// };

// struct Solution{

//     static int longestValidParentheses(const std::string &s) {

//         std::vector<char> stack;

//         int firstopen = 0;
//         while(firstopen < s.size()){
//             if(s[firstopen] == '(') break;
//             firstopen++;
//         }

//         int len = 0;
//         int max_len = 0;

//         for(int chrId = firstopen; chrId < s.size(); chrId++){

//             if(s[chrId]=='('){
//                 stack.push_back('0');
//                 len++;
//             }
//             else {
//                 if(stack.size() > 0) {
//                     stack.pop_back();
//                     len++;
//                 }
//                 else {
//                     if(len > max_len) max_len = len;
//                     len = 0;
//                 }
//             }
//         }

//         len = len - stack.size();
//         if(len > max_len) max_len = len;

//         return max_len;
//     }
// };

struct Solution{

    //  3:                  7
    //                     { }
    //  2:        2   4   6   8
    //           { } { } {     }
    //  1:      1   3   5       9       13
    //         {                 }     {
    //  0:    0                   10  12
    //                             } {
    // -1:                          11

    static int longestValidParentheses(const std::string &s) {

        std::unordered_map<int, std::pair<std::vector<int>, std::vector<int>>> height_graph;
        int height = 0;
        
        for(int chrid = 0; chrid < s.size(); chrid++){
            if(s[chrid]=='(') {
                height++;
                height_graph[height].first.push_back(chrid);
            }
        }

        return 0;
    }

};

int main(int argc, char* argv[]){



    std::cout<<Solution::longestValidParentheses("()()")<<"\n";

    std::cout<<Solution::longestValidParentheses("((()()))")<<"\n";

    std::cout<<Solution::longestValidParentheses(")()())")<<"\n";

    std::cout<<Solution::longestValidParentheses("()(()")<<"\n";
    

    return 0;
}