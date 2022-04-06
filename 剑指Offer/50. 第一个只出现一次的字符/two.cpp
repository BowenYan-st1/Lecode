/*
 * @Author: your name
 * @Date: 2022-04-04 18:41:44
 * @LastEditTime: 2022-04-04 22:07:30
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/50. 第一个只出现一次的字符/two.cpp
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s
只包含小写字母。

示例 1:
输入：s = "abaccdeff"
输出：'b'
示例 2:

输入：s = ""
输出：' '
 
限制：
0 <= s 的长度 <= 50000
*/
using namespace std;

class Solution {
public:
    char firstUniqChar(string s)
    {
        if ("" == s) {
            return ' ';
        }
        vector<char>              keys;
        unordered_map<char, bool> map;
        for (int index = 0; index < s.size(); index++) {
            if (map.find(s[index]) == map.end()) {
                keys.push_back(s[index]);
            }
            map[s[index]] = (map.find(s[index]) == map.end());
        }
        for (int index = 0; index < keys.size(); index++) {
            if (map[keys[index]]) {
                return keys[index];
            }
        }
        return ' ';
    }
};

int main(int argc, char **argv)
{
    string    str("abaccdeff");
    Solution *Obj = new Solution;
    cout << "result=" << Obj->firstUniqChar(str) << endl;
    return 0;
}