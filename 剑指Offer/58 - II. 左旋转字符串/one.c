/*
 * @Author: unkonw
 * @Date: 2022-03-31 11:39:56
 * @LastEditors: aydan.yan
 * @LastEditTime: 2022-03-31 12:54:04
 * @FilePath: /剑指Offer/58 - II. 左旋转字符串/one.c
 * @Description:
 *
 * Copyright (c) 2022 by XGIMI, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
记住：
    1. malloc后要用memset清零 
    2. malloc字符串时，长度strlen需要+1
*/
#if 1
char *reverseLeftWords(char *s, int n)
{
    int len = strlen(s);
    if (NULL == s) {
        return NULL;
    }
    if (n > len) {
        return s;
    }
    char *str = (char *)malloc(len + 1);
    memset(str, 0, len + 1);
    char *cur = str, *tmp = s + n;
    while (*tmp) {
        *cur = *tmp;
        tmp++;
        cur++;
    }
    tmp = s;
    while (tmp < s + n) {
        *cur = *tmp;
        cur++;
        tmp++;
    }
    return str;
}
#else
char *reverseLeftWords(char *s, int n)
{
    int len = strlen(s);
    if (NULL == s || n < 0) {
        return NULL;
    }
    if (n > len) {
        return s;
    }
    char *str = (char *)malloc(len + 1);
    memset(str, 0, len + 1);
    char *tmp = str;
    strncpy(tmp, s + n, len - n);
    tmp = str + len - n;
    strncpy(tmp, s, n);
    return str;
}
#endif

int main(int argc, char **argv[])
{
    char *str = "abcdefg";
    printf("%s\n", reverseLeftWords(str, 9));
    return 0;
}
