/*
 * 斐波那契数列
 * 输入一个整数 n ，求斐波那契数列的第 n 项。
 * 假定从0开始，第0项为0。(n<=39)
 */
#include <iostream>

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        else{
            n--;
            return Fibonacci(n) + Fibonacci(n-1);
        }
    }
};