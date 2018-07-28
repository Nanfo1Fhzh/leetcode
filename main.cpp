#include <iostream>
#import <vector>
#include <map>
#import <stdexcept>
#import <string>
#import <unordered_map>

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
    int cflag = 0;
    if (cl1 && cl2) {
        while ((cl1 && cl1->next )|| (cl2 && cl2->next)) {
            ListNode *tmp = new ListNode(0);
            int val1 = cl1 ? cl1->val : 0;
            int val2 = cl2 ? cl2->val : 0;
            int diff = cflag + val1 + val2 - 10;
            if (diff >= 0) {
                tmp->val = diff;
                cflag = 1;
            }else {
                tmp->val = diff + 10;
                cflag = 0;
            }
            if (rlt) {
                crlt->next = tmp;
                crlt = tmp;
            }else {
                rlt = tmp;
                crlt = rlt;
            }
            if (cl1) {
                cl1 = cl1->next;
            }
            if (cl2) {
                cl2 = cl2->next;
            }
        }
        int val1 = cl1 ? cl1->val : 0;
        int val2 = cl2 ? cl2->val : 0;
        ListNode *last = new ListNode(0);
        int diff = cflag + val1 + val2 - 10;
        if (diff >= 0) {
            last->val = diff;
            cflag = 1;
        }else {
            last->val = diff + 10;
            cflag = 0;
        }
        if (crlt) {
            crlt->next = last;
            crlt = last;
        }else {
            rlt = last;
            crlt = rlt;
        }
        if (cflag > 0) {
            ListNode *lastCflag = new ListNode(cflag);
            crlt->next = lastCflag;
        }
        return rlt;
    }else {
        throw new std::runtime_error("error with addTwoNumbers");
    }
}

ListNode* addTwoNumbers_solution(ListNode* l1, ListNode* l2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *p = l1, *q = l2, *curr = dummyHead;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int val1 = p ? p->val : 0;
        int val2 = q ? q->val : 0;
        int sum = carry + val1 + val2;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return dummyHead->next;
}

int caculate(ListNode* l1,ListNode* l2){

    int add1 = 0,add2 = 0;
    if(l1!=nullptr)
        add1 = l1->val;
    if(l2!=nullptr)
        add2 = l2->val;

    return add1 + add2;

}

ListNode* addTwoNumbers_faster(ListNode* l1, ListNode* l2) {

    bool tCarry=0;//to store if current caculation results in carrying
    ListNode* tNode=nullptr,*ansNode=nullptr;
    while(l1!=nullptr||l2!=nullptr){
        if(tNode!=nullptr)
        {
            tNode->next = new ListNode((caculate(l1, l2)+static_cast<int>(tCarry))%10);
            tNode = tNode->next;
        }
        else
            tNode = new ListNode((caculate(l1, l2)+static_cast<int>(tCarry))%10);
        if(ansNode==nullptr)
            ansNode = tNode;
        tCarry=(caculate(l1, l2)+static_cast<int>(tCarry)>=10);
        if(l1!=nullptr)
            l1 = l1->next;
        if(l2!=nullptr)
            l2 = l2->next;
    }

    if(tCarry)
        tNode->next = new ListNode((1));

    return ansNode;
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

int lengthOfLongestSubstring(std::string s) {
    std::map<char, int> *map = new std::map<char, int>();
    for (int i = 0, j = 0; j < s.length(); j++) {
        if (map->find(s.at(j)) != map->end()) {
            i = 0;
        }
    }
    return 0;
}

int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() > 1) {
        int i = 0;
        while (i<nums.size()-1) {
            auto next = nums.at(i+1);
            if (next == nums.at(i)) {
                nums.erase(nums.begin()+i+1);
            }else {
                ++i;
            }
        }

    }
    return nums.size();
}

#pragma mark - exec
void exec_lengthOfLongestSubstring() {
    std::string *s = new std::string("dvdf");
    lengthOfLongestSubstring(*s);
}
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
//    ListNode *l3 = new ListNode(1);
//    ListNode *l2 = new ListNode(4);
    ListNode *l1 = new ListNode(5);
//    l1->next = l2;
//    l2->next = l3;

//    ListNode *r4 = new ListNode(9);
//    ListNode *r3 = new ListNode(9);
//    ListNode *r2 = new ListNode(5);
    ListNode *r1 = new ListNode(5);
//    r1->next = r2;
//    r2->next = r3;
//    r3->next = r4;
    auto rlt = addTwoNumbers(l1,r1);
//    auto rlt = addTwoNumbers(new ListNode(0),new ListNode(0));
        auto  rlt1 = addTwoNumbers_solution(l1,r1);

    std::cout << rlt->val;
    while (rlt->next) {
        std::cout << " -> " << rlt->next->val;
        rlt = rlt->next;
    }
    std::cout << std::endl;

    std::cout << rlt1->val;
    while (rlt1->next) {
        std::cout << " -> " << rlt1->next->val;
        rlt1 = rlt1->next;
    }
    std::cout << std::endl;
}

int maxProfit(std::vector<int>& prices) {
    int cnt = prices.size();
    int idx = 0;
    int benefit = 0;
    int curr_buy_price = 0;
    int curr_sale_price = 0;
    bool lock = false;
    if (cnt < 2) {
        return 0;
    }
    while (idx <= cnt - 1) {
        if (lock == false && idx < cnt - 1 && prices.at(idx) < prices.at(idx + 1)) {
            curr_buy_price = prices.at(idx);
            lock = true;
        }else if(lock == true && (idx == cnt - 1 || prices.at(idx) > prices.at(idx + 1))) {
            curr_sale_price = prices.at(idx);
            benefit += curr_sale_price - curr_buy_price;
            curr_sale_price = 0;
            curr_buy_price = 0;
            lock = false;
        }
        ++idx;
    }
    return benefit;
}

void rotate(std::vector<int>& nums, int k) {
    int cnt = nums.size();
    int real_k = k % nums.size();
    if (real_k == 0) {
        return;
    }
    int *buffers = new int[real_k]();
    for (int l = 0; l < real_k; l++) {
        buffers[l] = nums.at(cnt-1-(real_k-1-l));
    }
    for (int i=cnt-1; i>=0; i--) {
        if (i <= cnt-1 && i > real_k-1) {
            nums.at(i) = nums.at(i-real_k);
        }else{
            nums.at(i) = buffers[i];
        }
    }
}


bool containsDuplicate(std::vector<int>& nums) {
    if (nums.size()<2) {
        return false;
    }
    std::map<int, int> *v = new std::map<int,int>();
    for (int i=0;i<nums.size(); i++) {
        if (v->find(nums.at(i)) != v->end()) {
            return true;
        }else {
            v->insert(std::pair<int,int>(nums.at(i),i));
        }
    }
    return false;
}
/**-1 will be returned if not match any memeber*/
int indexOfnumInVector(int num, std::vector<int>& nums) {
    int idx = -1;
    for (int i=0;i<nums.size();i++) {
        if (nums.at(i) == num) {
            return i;
        }
    }
    return idx;
}

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> smallerNums = (nums1.size() > nums2.size()) ? nums2 : nums1;
    std::vector<int> biggerNums = (nums1 == smallerNums) ? nums2 : nums1;
    std::vector<int> intersectVector;
    for (int i=0;i<smallerNums.size();i++) {
        int idx = indexOfnumInVector(smallerNums.at(i),biggerNums);
        if (idx!=-1) {
            intersectVector.push_back(smallerNums.at(i));
            biggerNums.erase(biggerNums.begin()+idx);
            smallerNums.erase(smallerNums.begin()+i);
            --i;
        }
    }
    return intersectVector;
}

std::vector<int> intersect_use_map(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::map<int, int> *map = new std::map<int, int>();
    std::vector<int> smallerNums = (nums1.size() > nums2.size()) ? nums2 : nums1;
    std::vector<int> biggerNums = (nums1 == smallerNums) ? nums2 : nums1;
    std::vector<int> res;
    // 把biggerVector加入value和次数映射到map中
    for (int i = 0; i < biggerNums.size(); i++) {
        if (map->find(biggerNums.at(i)) != map->end()) {
            int newCnt = map->at(biggerNums.at(i)) + 1;
            map->erase(biggerNums.at(i));
            map->insert(std::pair<int, int>(biggerNums.at(i),newCnt));
        }else {
            map->insert(std::pair<int, int>(biggerNums.at(i),1));
        }
    }

    for (int j = 0; j < smallerNums.size(); j++) {
        auto t = map->find(smallerNums.at(j));
        if (t != map->end() && t->second > 0) {
            res.push_back(smallerNums.at(j));
            int newCnt = t->second - 1;
            map->erase(smallerNums.at(j));
            map->insert(std::pair<int, int>(t->first, newCnt));
        }
    }
    return res;
}

std::vector<int> intersect_use_unordered_map(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> *map = new std::unordered_map<int, int>();
    std::vector<int> smallerNums = (nums1.size() > nums2.size()) ? nums2 : nums1;
    std::vector<int> biggerNums = (nums1 == smallerNums) ? nums2 : nums1;
    std::vector<int> res;
    // 把biggerVector加入value和次数映射到map中
    for (int i = 0; i < biggerNums.size(); i++) {
        if (map->find(biggerNums.at(i)) != map->end()) {
            int newCnt = map->at(biggerNums.at(i)) + 1;
            map->erase(biggerNums.at(i));
            map->insert(std::pair<int, int>(biggerNums.at(i),newCnt));
        }else {
            map->insert(std::pair<int, int>(biggerNums.at(i),1));
        }
    }

    for (int j = 0; j < smallerNums.size(); j++) {
        auto t = map->find(smallerNums.at(j));
        if (t != map->end() && t->second > 0) {
            res.push_back(smallerNums.at(j));
            int newCnt = t->second - 1;
            map->erase(smallerNums.at(j));
            map->insert(std::pair<int, int>(t->first, newCnt));
        }
    }
    return res;
}

std::vector<int> intersect_use_unordered_map_plain(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int,int>map;
    std::vector<int>result;
    std::vector<int> *smallerNums = (nums1.size() > nums2.size()) ? &nums2 : &nums1;
    std::vector<int> *biggerNums = (nums1 == *smallerNums) ? &nums2 : &nums1;
    for(int i=0;i<smallerNums->size();i++)
    {
        map[(*smallerNums)[i]]++;
    }
    for(int i=0;i<biggerNums->size();i++ )
    {
        if(map[(*biggerNums)[i]]>0)
            result.push_back((*biggerNums)[i]);
        map[(*biggerNums)[i]]--;
    }
    return result;
}

int singleNumber(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return nums.at(0);
    }
    int len = nums.size();
    for (int i=0;i<len-1;i++) {
        for (int j=0;j<len-i-1;j++) {
            if (nums.at(j)>nums.at(j+1)) {
                int tmp = nums.at(j);
                nums.at(j) = nums.at(j+1);
                nums.at(j+1) = tmp;
            }
        }
    }

    for (int i=0;i<len;i++) {
        if (i > 0 && i < len-1) {
            if (((nums.at(i)^nums.at(i-1)) != 0 ) && ((nums.at(i)^nums.at(i+1)) !=0 )) {
                return nums.at(i);
            }
        }else if (i==0 && ((nums.at(0)^nums.at(1)) != 0) && ((nums.at(1)^nums.at(2)) == 0)){
            return nums.at(0);
        }else if (i==len-1 && ((nums.at(len-1)^nums.at(len-2)) != 0 ) && (nums.at(len-2)^nums.at(len-3)==0)){
            return nums.at(len-1);
        }
    }
}


int fast_singleNumber(std::vector<int>& nums) {
    int res = nums[0];
    for(int i=1; i<nums.size();i++)
    {
        res = res ^ nums[i];
    }
    return res;
}


#pragma mark - main
int main(int argc, char const *argv[]) {
//    exec_twoSum();
//    exec_addTwoNumbers();
    exec_lengthOfLongestSubstring();
    std::vector<int > *v = new std::vector<int >();
    v->push_back(2);
    v->push_back(1);
    v->push_back(4);
    v->push_back(5);
    v->push_back(2);
    v->push_back(6);
    v->push_back(7);
    int result = singleNumber(*v);
//    removeDuplicates(*v);
//    maxProfit(*v);
//    rotate(*v, 3);
    return 0;
}





