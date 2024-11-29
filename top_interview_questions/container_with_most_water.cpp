#include <vector>
#include <iostream>

class Solution {
public:
    static int maxArea(const std::vector<int>& height) {
        
        if(height.size() < 2) return 0;

        int left_id = 0;
        int right_id = height.size() - 1;

        long maxArea = getArea(left_id, right_id, height);
        long area;

        loop_1_entry:
        while(left_id < right_id){
            
            area = getArea(left_id, right_id, height);

            if(area > maxArea){
                maxArea = area;
            }
            
            if(height[left_id] > height[right_id]) goto loop_2_entry;

            left_id++;
        }       

        loop_2_entry:
        while(right_id > left_id){

            area = getArea(left_id, right_id, height);

            if(area > maxArea){
                maxArea = area;
            }
                        
            if(height[right_id] > height[left_id]) goto loop_1_entry;

            right_id--;
        }

        return maxArea;
        
    }

    static inline long getArea(const long &l, const long &r, const std::vector<int>& height){
        if(height[r] > height[l]) return (r-l)*height[l];
        return (r-l)*height[r];
    }
};

int main(int argc, char* argv[]){

    std::vector<int> height = {2,3,4,5,18,17,6};

    std::cout<<Solution::maxArea(height);

    return 0;
}