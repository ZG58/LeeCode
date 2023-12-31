﻿#include <iostream>
#include <unordered_map>
#include <string>

//class Solution {
//public:
//    bool canConstruct(std::string ransomNote, std::string magazine) {
//        for (int i = 0; i < magazine.length(); i++) {
//            for (int j = 0; j < ransomNote.length(); j++) {
//                // 在ransomNote中找到和magazine相同的字符
//                if (magazine[i] == ransomNote[j]) {
//                    ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
//                    break;
//                }
//            }
//        }
//        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
//        if (ransomNote.length() == 0) {
//            return true;
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int record[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // 测试示例
    std::string ransomNote = "aab";
    std::string magazine = "aab";

    bool result = solution.canConstruct(ransomNote, magazine);

    if (result) {
        std::cout << "Yes, you can construct ransomNote from magazine." << std::endl;
    }
    else {
        std::cout << "No, you cannot construct ransomNote from magazine." << std::endl;
    }

    return 0;
}

