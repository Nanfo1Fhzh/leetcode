#include <iostream>
#import <vector>
#import "towSum.cpp"

void twoSum() {
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    int target = 6;
    Solution *s = new Solution();
    std::vector<int> rlt = s->twoSum(nums, target);
    std::vector<int> rlt1 = s->twoSum_2hashmap(nums, target);
    std::vector<int> rlt2 = s->twoSum_1hashmap(nums, target);

    if (rlt.size() > 1) {
        std::cout << "twoSum result indexes r " << rlt[0] << " and "<< rlt[1] << std::endl;
        std::cout << "twoSum_2hashmap result indexes r " << rlt1[0] << " and "<< rlt1[1] << std::endl;
        std::cout << "twoSum_1hashmap result indexes r " << rlt2[0] << " and "<< rlt2[1] << std::endl;


    }
}

int main(int argc, char const *argv[]) {
    twoSum();
    return 0;
}

