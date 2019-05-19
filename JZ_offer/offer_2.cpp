/*
 * 请实现一个函数，把字符串中的每个空格替换成"%20"
 * 你可以假定输入字符串的长度最大是1000
 * 注意输出字符串的长度可能大于1000
 * Note:最后的字符串长度可能大于1000
 */
#include <cstdio>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

char* replaceSpaces(char *str){
    int spaceNum = 0;
    for (int i = 0;i < strlen(str); ++i) {
        if(str[i] == ' '){
            spaceNum++;
        }else{
            continue;
        }
    }
    char* strNoSpace = (char*)malloc(sizeof(char)*strlen(str) + sizeof(char)*strlen("%20")*spaceNum);
    for (int i = 0,j = 0;i<strlen(str);) {
        if(str[i] != ' '){
            strNoSpace[j] = str[i];
            i++;
            j++;
        }else{
            strNoSpace = strncat(strNoSpace,"%20",strlen("%20"));
            j = j+strlen("%20");
            i++;
        }
    }
    return strNoSpace;
}

int main(){
    char* str;
    char* str_;
    str = (char*)malloc(sizeof(char)*1000);

    printf("请输入带空格的字符串，默认字符串的大小在1000以内\n");
    fgets(str,1000,stdin);//代替gets，在gcc编译器中无法使用gets（）函数

    str_ = replaceSpaces(str);
    printf("替换后的字符串为：%s",str_);

    free(str);
    free(str_);
    return 0;
}