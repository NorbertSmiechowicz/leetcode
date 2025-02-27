#include <iostream>
#include <vector>
#include <tuple>

struct Solution {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
        ~ListNode() {
            if(next != nullptr) delete next;
            next = nullptr;
        }
        void print(){
            std::cout<<val<<", ";
            if(next==nullptr) return;
            next->print();
        }
    };

    static ListNode* reverseKGroup(ListNode* head, int k) {
        auto [begin, end, n] = reverse(nullptr, head, k);
        if(end == nullptr) return begin;
        ListNode* end_ = end;
        while(n == 1 and end_->next!=nullptr){
            auto [begin__, end__, m] = reverse(end_, end_->next, k);
            if(m > 1) reverse(end_, end_->next, k);
            n = m;
            end_ = end__;
        }
        return begin;
    };

    static std::tuple<ListNode*,ListNode*,int> reverse(ListNode* inPrevious, ListNode* head, int k) {
        
        if(head == nullptr) return std::tuple<ListNode*,ListNode*,int>(head,head,k);
        if(head->next == nullptr) return std::tuple<ListNode*,ListNode*,int>(head,head,k);
        if(k < 2) return std::tuple<ListNode*,ListNode*,int>(head,head,k);

        ListNode *previous = inPrevious;
        ListNode *current = head;
        ListNode *next;

        while(current->next != nullptr and k > 1){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            k--;
        }

        head->next = current->next;
        current->next = previous;
        if(inPrevious!=nullptr) inPrevious->next = current;
        return std::tuple<ListNode*,ListNode*,int>(current,head,k);
    }


};

int main(int argc, char* argv[]){


    {
        std::vector<int> testcase{1,2,3,4,5,6,7,8,9,10,11,12,13,14};

        Solution::ListNode* headptr = new Solution::ListNode(testcase[0]);
        auto headptrcpy = headptr;
        for(int elem = 1; elem < testcase.size(); elem++){
            headptr->next = new Solution::ListNode(testcase[elem]);
            headptr = headptr->next;
        }

        headptr = Solution::reverseKGroup(headptrcpy, 1);
        headptrcpy = nullptr;
        headptr->print();

        delete headptr;

        std::cout<<std::endl;
    }

    {
        std::vector<int> testcase{1,2,3,4,5,6,7,8,9,10,11,12,13,14};

        Solution::ListNode* headptr = new Solution::ListNode(testcase[0]);
        auto headptrcpy = headptr;
        for(int elem = 1; elem < testcase.size(); elem++){
            headptr->next = new Solution::ListNode(testcase[elem]);
            headptr = headptr->next;
        }


        headptr = Solution::reverseKGroup(headptrcpy, 4);
        headptrcpy = nullptr;
        headptr->print();

        delete headptr;

        std::cout<<std::endl;
    }

    return 0;
}