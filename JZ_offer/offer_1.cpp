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