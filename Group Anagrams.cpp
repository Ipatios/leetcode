/*
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/ 
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::string key;
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, int> group;
        for (auto str: strs)
        {
            key = str;
            sort(key.begin(), key.end());
            if (group[key]>0)                      //anagram group of current string already exists in the array
            {
                result[group[key]-1].push_back(str);
            }
            else
            {
                result.push_back({str});
                group[key] = result.size();           //store index of new anagram group array in map
            }
            
        }
                
        return result;
    }
};
