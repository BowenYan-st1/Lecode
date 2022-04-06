/*
 * @Author: your name
 * @Date: 2022-04-04 18:29:30
 * @LastEditTime: 2022-04-05 20:23:23
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /剑指Offer/50. 第一个只出现一次的字符/one.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char firstUniqChar(char *s)
{
    if (NULL == s || "" == s) {
        return ' ';
    }
    char map[26] = {0};
    char key[26] = {0};
    char cnt_key = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (0 == map[s[i] - 'a']) {
            key[cnt_key] = s[i];
            cnt_key++;
        }
        map[s[i] - 'a']++;
    }

    for (int i = 0; i < cnt_key; i++) {
        if (1 == map[key[i] - 'a']) {
            return key[i];
        }
    }
    return ' ';
}

int main(int argc, char **argv)
{
    char str[] = "abaccdeff";
    printf("result = %c\n", firstUniqChar(str));
    return 0;
}