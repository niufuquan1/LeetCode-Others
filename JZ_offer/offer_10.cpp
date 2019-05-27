/*
 * 矩形覆盖
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 当n=1时,大矩形是2*1,只存在1种解法
 * 当n=2时,大矩形是2*2,仅存在2种解法
 * 当n=3时,大矩形是2*3,可以看做是前两种解法的解的合
 * 以此类推,该题实质是斐波那契数列.
 */
#include <iostream>

class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        return rectCover(number-1)+rectCover(number-2);
    }
};