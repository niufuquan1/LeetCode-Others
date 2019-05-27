/*
 * 变态跳台阶
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 分析：用Fib(n)表示跳上n阶台阶的跳法数。如果按照定义，Fib(0)肯定需要为0，否则没有意义。但是我们设定Fib(0) = 1；n = 0是特殊情况，
 * 通过下面的分析就会知道，强制令Fib(0) = 1很有好处。ps. Fib(0)等于几都不影响我们解题，但是会影响我们下面的分析理解。
 * 当n = 1 时， 只有一种跳法，即1阶跳：Fib(1) = 1;
 * 当n = 2 时， 有两种跳的方式，一阶跳和二阶跳：Fib(2)  = 2;
 * 到这里为止，和普通跳台阶是一样的。
 * 当n = 3 时，有三种跳的方式，第一次跳出一阶后，对应Fib(3-1)种跳法； 第一次跳出二阶后，对应Fib(3-2)种跳法；
 * 第一次跳出三阶后，只有这一种跳法。Fib(3) = Fib(2) + Fib(1)+ 1 = Fib(2) + Fib(1) + Fib(0) = 4;
 * 当n = 4时，有四种方式：第一次跳出一阶，对应Fib(4-1)种跳法；第一次跳出二阶，对应Fib(4-2)种跳法；
 * 第一次跳出三阶，对应Fib(4-3)种跳法；第一次跳出四阶，只有这一种跳法。
 * 所以，Fib(4) = Fib(4-1) + Fib(4-2) + Fib(4-3) + 1 = Fib(4-1) + Fib(4-2) + Fib(4-3) + Fib(4-4) 种跳法。
 * 当n = n 时，共有n种跳的方式，第一次跳出一阶后，后面还有Fib(n-1)中跳法；
 * 第一次跳出二阶后，后面还有Fib(n-2)中跳法
 * 第一次跳出n阶后，后面还有 Fib(n-n)中跳法。
 * Fib(n) = Fib(n-1)+Fib(n-2)+Fib(n-3)+..........+Fib(n-n) = Fib(0)+Fib(1)+Fib(2)+.......+Fib(n-1)。
 * 通过上述分析，我们就得到了通项公式：
 * Fib(n) =  Fib(0)+Fib(1)+Fib(2)+.......+ Fib(n-2) + Fib(n-1)
 * 因此，有 Fib(n-1)=Fib(0)+Fib(1)+Fib(2)+.......+Fib(n-2)
 * 两式相减得：Fib(n)-Fib(n-1) = Fib(n-1)
 * 这就是我们需要的递推公式：Fib(n) = 2*Fib(n-1)(n >= 3)
 */
#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        number--;
        return 2*jumpFloorII(number);
    }
};