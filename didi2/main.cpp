//解题思路：
/**
 数字索引为begin，数字串长度n，数字最大和为maxsum
 临时数字索引tmp_begin，数字串长度tmp_n，临时数字最大个tmp_maxsum
按顺序读取每一个字符，如果遇到数字，如果前面为字母，tmp_begin跟新为当前索引，数字串长度tmp_n加1，tmp_maxsum+=当前数字，如果tmp_maxsum大于maxsum，则用临时的数字索引，字符串长度，最大数更新最大的值
 如果遇到字符，则tmp_begin，tmp_n，tmp_maxsum置为0
 遍历一遍，将下标为begin长为n的数字串打印出来
 **/


//
//  main.cpp
//  didi2
//
//  Created by LiLingyu on 15/10/15.
//  Copyright © 2015年 LiLingyu. All rights reserved.
//

#include <iostream>
#define MAXLEN 1000

void getmaxnum(char* a)
{
    int begin = 0;
    int n = 0;
    int maxsum = 0;
    
    int tmp_begin = -1;
    int tmp_n = 0;
    int tmp_maxsum = 0;
    
    for (int i=0; ; i++) {
        if (a[i]=='\0') {
            break;
        }
        else if(a[i]>='0'&&a[i]<='9')//num
        {
            if (tmp_begin == -1) {
                tmp_begin = i;
                
            }
            
            tmp_n++;
            tmp_maxsum += a[i]-'0';
            
            if (tmp_maxsum>maxsum) {
                begin = tmp_begin;
                n = tmp_n;
                maxsum = tmp_maxsum;
            }
        }
        else
        {
            tmp_begin = -1;
            tmp_n = 0;
            tmp_maxsum = 0;
        }
    
    }
    
    for (int i=begin; i<begin+n; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    char a[MAXLEN];
    
    while (scanf("%s", a)!=EOF) {
        getmaxnum(a);
    }
    
    
    
    return 0;
}
