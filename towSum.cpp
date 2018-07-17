#include <vector>
#include <map>
#import <stdexcept>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> v;
        int count = nums.size();
        if (count < 2) {
            throw new std::runtime_error("No two sum solution");
        }else {
            for (int i = 0; i < count - 1; i++) {
                for (int a = i+1; a < count; a++) {
                    int sum = nums[i] + nums[a];
                    if (sum == target) {
                        v.push_back(i);
                        v.push_back(a);
                        break;
                    }
                }
            }
        }
        if (v.size() != 2) {
            throw new std::runtime_error("No two sum solution");
        }
        return v;
    }

    std::vector<int> twoSum_2hashmap(std::vector<int>& nums, int target) {
        std::vector<int> v;
        std::map<int, int> *map = new std::map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            map->insert(std::pair<int ,int>(nums[i], i));
        }
        for (int j = 0; j < nums.size(); ++j) {
            int complement = target - nums[j];
            auto match = map->find(complement);
            // find a match and not himself;
            if (match != map->end() && match->second != j) {
                v.push_back(j);
                v.push_back(match->second);
                return v;
            }
        }
        throw new std::runtime_error("No two sum solution");
    }

    std::vector<int> twoSum_1hashmap(std::vector<int>& nums, int target) {
        std::vector<int> v;
        std::map<int, int> *map = new std::map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto match = map->find(complement);
            // find a match and not himself;
            if (match != map->end() && match->second != i) {
                v.push_back(match->second);
                v.push_back(i);
                return v;
            }
            map->insert(std::pair<int ,int>(nums[i], i));
        }
        throw new std::runtime_error("No two sum solution");
    }
};
