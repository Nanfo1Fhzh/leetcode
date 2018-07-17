#include <iostream>
#import <vector>
#include <map>
#import <stdexcept>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#pragma mark - impl
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *cl1 = l1;
    ListNode *cl2 = l2;
    ListNode *rlt = NULL;
    ListNode *crlt = rlt;
    if (cl1 && cl2) {
        int 
        while (cl1->next && cl2->next) {
            ListNode *tmp = new ListNode(0);
            tmp->val = (cl1->val + cl2->val > 9 ? (cl1->val + cl2->val - 10) : cl1->val + cl2->val);
            if (rlt) {
                crlt->next = tmp;
                crlt = tmp;
            }else {
                rlt = tmp;
                crlt = rlt;
            }
            cl1 = cl1->next;
            cl2 = cl2->next;
        }
        ListNode *last = new ListNode(cl1->val + cl2->val > 9 ? (cl1->val + cl2->val - 10) : cl1->val + cl2->val);
        crlt->next = last;
        return rlt;
    }else {
        throw new std::runtime_error("error with addTwoNumbers");
    }
}

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

#pragma mark - exec
void exec_twoSum() {
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    int target = 6;
    std::vector<int> rlt = twoSum(nums, target);
    std::vector<int> rlt1 = twoSum_2hashmap(nums, target);
    std::vector<int> rlt2 = twoSum_1hashmap(nums, target);

    if (rlt.size() > 1) {
        std::cout << "twoSum result indexes r " << rlt[0] << " and "<< rlt[1] << std::endl;
        std::cout << "twoSum_2hashmap result indexes r " << rlt1[0] << " and "<< rlt1[1] << std::endl;
        std::cout << "twoSum_1hashmap result indexes r " << rlt2[0] << " and "<< rlt2[1] << std::endl;
    }
}

void exec_addTwoNumbers() {
//    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//    输出：7 -> 0 -> 8
//    原因：342 + 465 = 807
    ListNode *l3 = new ListNode(3);
    ListNode *l2 = new ListNode(4);
    ListNode *l1 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;

    ListNode *r3 = new ListNode(4);
    ListNode *r2 = new ListNode(6);
    ListNode *r1 = new ListNode(5);
    r1->next = r2;
    r2->next = r3;
    auto rlt = addTwoNumbers(l1,r1);
    std::cout << rlt->val;
    while (rlt->next) {
        std::cout << " -> " << rlt->next->val;
        rlt = rlt->next;
    }
    std::cout << std::endl;
}

#pragma mark - main
int main(int argc, char const *argv[]) {
//    exec_twoSum();
    exec_addTwoNumbers();
    return 0;
}



