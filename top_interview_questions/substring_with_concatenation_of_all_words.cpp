#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <iostream>

// for each word object check if its a valid word -> check if hashkey exists
//
// for each valid word check if its already in use ->
//
//   words is olny a <surjection> of natural numbers onto "word" objects
//   inverse words maps a word object onto a set of natural numbers, 
//   such that each element of the set is equal up to words aplictation
//
//   position in the original array is not needed, only whether its already
//   matched with any previous occurance in the input string 
//
//   when exeeding the word duplicate count limit, the earliest occurance must be popped
//   and so every other word occurance from the permutation start up to it

class Solution {
    public:
    struct boundedNaturalQueue{
        size_t bound;
        std::deque<int> q;
        
        boundedNaturalQueue(){
            bound = 0;
            q = std::deque<int>();
        };

        int push_back(const int &x){
            if(q.size() < bound) {
                q.push_back(x);
                return -1;
            }
            q.push_back(x);
            int first = q[0];
            q.pop_front();
            return first;
        }

        void pop_front(){
            q.pop_front();
        }
    };

    static std::vector<int> findSubstring(const std::string &s, std::vector<std::string> &words) {
        
        std::vector<int> output;

        if(words.size() == 0) return output;
        if(words[0].size() == 0) return output;

        const int word_length = words[0].size();
        const int word_count = words.size();

        if(s.size() < word_length) return output;
            
        std::unordered_map<std::string, boundedNaturalQueue> words_inverse;
        words_inverse.reserve(word_count);
        for(int id = 0; id < word_count; id++){
            words_inverse[words[id]].bound++;
        }
        auto notFound =  words_inverse.end();

        std::string temp = words[0];


        for(int char_offset = 0; char_offset < word_length; char_offset++){

            for(auto &que: words_inverse){
                que.second.q.clear();
            }

            int word_offset = char_offset;
            int popped_front;

            int currentPermutationOffset = char_offset;
            int currentPermutationLength = 0;

            while(word_offset <= s.size() - word_length){
                
                for(int charid = 0; charid < word_length; charid++){
                    temp[charid] = s[word_offset+charid];
                }

                if(words_inverse.find(temp) == notFound){

                    for(int deleterOffset = currentPermutationOffset; deleterOffset < word_offset; deleterOffset+=word_length){                    
                        for(int charid = 0; charid < word_length; charid++){
                            temp[charid] = s[deleterOffset+charid];
                        }
                        words_inverse.at(temp).pop_front();
                    }

                    currentPermutationLength = -1;
                    currentPermutationOffset = word_offset + word_length;
                }

                else {
                    popped_front = words_inverse.at(temp).push_back(word_offset);

                    if(popped_front != -1){

                        for(int deleterOffset = currentPermutationOffset; deleterOffset < popped_front; deleterOffset+=word_length){                    
                            for(int charid = 0; charid < word_length; charid++){
                                temp[charid] = s[deleterOffset+charid];
                            }
                            words_inverse.at(temp).pop_front();
                        }

                        currentPermutationLength = (word_offset - popped_front)/word_length - 1;
                        currentPermutationOffset = popped_front + word_length;
                        
                    }
                }

                currentPermutationLength++;

                if(currentPermutationLength == word_count){

                    output.push_back(currentPermutationOffset);

                    for(int charid = 0; charid < word_length; charid++){
                        temp[charid] = s[currentPermutationOffset+charid];
                    }
                    words_inverse.at(temp).pop_front();

                    currentPermutationOffset += word_length;
                    currentPermutationLength--;
                }
                
                word_offset += word_length;
            }

        }

        return output;
    }
};

int main(){

    {
        std::vector<std::string> words{"bar","foo"};
        auto sol = Solution::findSubstring("barfoothefoobarman",words);
        for(auto& id: sol){
            std::cout<<id<<", ";
        }
        std::cout<<std::endl;
    }
    {
        std::vector<std::string> words{"word","good","best","word"};
        auto sol = Solution::findSubstring("wordgoodgoodgoodbestword",words);
        for(auto& id: sol){
            std::cout<<id<<", ";
        }
        std::cout<<std::endl;
    }
    {
        std::vector<std::string> words{"bar","foo","the"};
        auto sol = Solution::findSubstring("barfoofoobarthefoobarman",words);
        for(auto& id: sol){
            std::cout<<id<<", ";
        }
        std::cout<<std::endl;
    }
    {
        std::vector<std::string> words{"aa","aa"};
        auto sol = Solution::findSubstring("aaaaaaaaaaaaaa",words);
        for(auto& id: sol){
            std::cout<<id<<", ";
        }
        std::cout<<std::endl;
    }
    {
        std::vector<std::string> words{"mississippis"};
        auto sol = Solution::findSubstring("mississippi",words);
        for(auto& id: sol){
            std::cout<<id<<", ";
        }
        std::cout<<std::endl;
    }
}


