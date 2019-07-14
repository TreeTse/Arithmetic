/*
题目描述：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c
所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

#include <stdio.h>

static int count = 0;

void swap(char* str,int a,int b)
{
    char tmp = str[a];
    str[a] = str[b];
    str[b] = tmp;
}


int is_swap(char *str, int begin, int k){   //判断从子串的第一个字符串开始，直到k-1位置，看是否有重复的字符
    int i, flag;

    for (i = begin, flag = 1; i < k; i ++) {
        if (str[i] == str[k]) {
            flag = 0;
            break;
        }
    }

    return flag;
}

void full_permutation(char* str,int begin,int end)
{
    if (begin == end)
    {
        count++;//此处可以输出字符串或者记录字符串
        return;
    }else{
        int i;
        for (i = begin; i <= end; i++)
        {
            if (is_swap(str,begin,i))
            {
                swap(str,begin,i);
                full_permutation(str,begin+1,end);
                swap(str,begin,i);
            }
        }
    }
}

int main()
{
    char str[7] = {'a','l','i','b','a','b','a'};
    full_permutation(str,0,6);
    printf("count=%d",count);
    return 0;
}