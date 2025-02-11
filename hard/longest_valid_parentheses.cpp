#include <iostream>
#include <unordered_map>
#include <vector>

struct Solution{

    static int longestValidParentheses(const std::string &s) {

        std::vector<int> stack;
        stack.reserve(4);

        std::vector<int> stack_frame_begin{0};

        for(int chrId = 0; chrId < s.size(); chrId++){

            if(s[chrId]=='(') stack.push_back(chrId);

            else if(stack.size() > 0) stack.pop_back();

            else stack_frame_begin.push_back(chrId+1);
        }

        int max_len = 0;
        int len = 0;

        // check last frame
        if(stack.size() == 0){
            len = s.size() - *stack_frame_begin.rbegin();
            if(len > max_len) max_len = len;            
        }
        else {
            
            len = s.size() - 1 - *stack.rbegin();
            if(len > max_len) max_len = len;

            for(int elem = stack.size() - 2; elem >= 0; elem--){
                len = stack[elem+1] - stack[elem] - 1;
                if(len > max_len) max_len = len;
            }

            len = stack[0] - *stack_frame_begin.rbegin();
            if(len > max_len) max_len = len;
        }
        
        // check for all resolved frames before the last one
        for(int frame_offset_id = 1; frame_offset_id < stack_frame_begin.size(); frame_offset_id++){
            len = stack_frame_begin[frame_offset_id] - stack_frame_begin[frame_offset_id - 1] - 1;
            if(len > max_len) max_len = len;
        }

        return max_len;
    }
};

int main(int argc, char* argv[]){



    std::cout<<Solution::longestValidParentheses(")())")<<"\t| 2\n";

    std::cout<<Solution::longestValidParentheses(")((()()))")<<"\t| 8\n";

    std::cout<<Solution::longestValidParentheses("()()")<<"\t| 4\n";

    std::cout<<Solution::longestValidParentheses("(())(")<<"\t| 4\n";

    std::cout<<Solution::longestValidParentheses(")(((((()())()()))()(()))(")<<"\t| 22\n";

    std::cout<<Solution::longestValidParentheses(")()())")<<"\t| 4\n";

    std::cout<<Solution::longestValidParentheses(")()())()()(")<<"\t| 4\n";

    std::cout<<Solution::longestValidParentheses("()()()()(())))()")<<"\t| 12\n";
    

    return 0;
}