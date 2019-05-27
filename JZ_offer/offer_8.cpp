/*
 * 跳台阶
    一个楼梯共有n级台阶，每次可以走一级或者两级，问从第0级台阶走到第n级台阶一共有多少种方案。
 * 输入格式
    共一行，包含一个整数n。
 * 输出格式
    共一行，包含一个整数，表示方案数。
 * 数据范围
    1≤n≤15
 * 输入样例：
    5
 * 输出样例：
    8
 */
#include <iostream>

class Solution{
    //n台阶的方案数量 = n-1台阶方案数量 + n-2的方案数量
    int JumpingStairs(int n){
        if(n>15 || n<0) return -1;
        n--;
        if(n==1) return 1;
        if(n==2) return 2;
        return JumpingStairs(n)+JumpingStairs(n-1);
    }
};