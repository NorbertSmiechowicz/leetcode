#include <vector>
#include <iostream>

class Solution {
public:
    static int maxArea(const std::vector<int>& height) {
        
        if(height.size() < 2) return 0;

        int left_id = 0;
        int right_id = height.size() - 1;


        long maxArea;        
        if(height[right_id] > height[left_id]) maxArea = (right_id-left_id)*height[left_id];
        else maxArea = (right_id-left_id)*height[right_id];

        long area;

        // somehow this line increases leetcodes engine runtime from 0ms to 4 ms
        if(height[right_id] < height[left_id]) goto loop_2_entry;

        loop_1_entry:
        while(left_id < right_id){
            
            if(height[right_id] > height[left_id]) area = (right_id-left_id)*height[left_id];
            else area = (right_id-left_id)*height[right_id];


            if(area > maxArea){
                maxArea = area;
            }
            
            if(height[left_id] > height[right_id]) goto loop_2_entry;

            left_id++;
        }       

        loop_2_entry:
        while(right_id > left_id){


            if(height[right_id] > height[left_id]) area = (right_id-left_id)*height[left_id];
            else area = (right_id-left_id)*height[right_id];

            if(area > maxArea){
                maxArea = area;
            }
                        
            if(height[right_id] > height[left_id]) goto loop_1_entry;

            right_id--;
        }

        return maxArea;
        
    }
};

int main(int argc, char* argv[]){

    std::vector<int> height = {2,3,4,5,18,17,6};

    std::cout<<Solution::maxArea(height);

    return 0;
}