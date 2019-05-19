/**
 * 在一个二维数组中（每个一维数组的长度相同），
 * 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * **/
#include <cstdio>

bool searchArray(int** array, int arrayRowSize, int arrayColSize, int target);

int main(){
    int arrayRowSize;
    int arrayColSize;
    int target;
    bool result;
    printf("请输入行数\n");
    scanf("%d",&arrayRowSize);
    printf("请输入列数\n");
    scanf("%d",&arrayColSize);
    printf("请输入目标数字\n");
    scanf("%d",&target);

    //此处初始化二维数组
    int array[arrayRowSize][arrayColSize];
    for(int i = 0 ;i < arrayRowSize;++i){
        for (int j = 0; j < arrayColSize; ++j) {
            int temp;
            printf("请输入第%d行数组元素\n",i+1);
            scanf("%d",&temp);
            array[i][j] = temp;
            printf("该行目前有%d个元素了\n",j+1);
        }
    }
    int* p = &array[0][0];
    int** pp = &p;
    result = searchArray(pp,arrayRowSize,arrayColSize,target);
    if(result == true){
        printf("找到该数字！");
    }else{
        printf("找不到该数字！");
    }
    return 0;
}

bool searchArray(int** array, int arrayRowSize, int arrayColSize, int target) {
    int i = 0;
    int j = arrayColSize - 1;
    while(i < arrayRowSize && j >= 0)
    {
        if(array[i][j] == target)
            return true;
        else if(array[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}