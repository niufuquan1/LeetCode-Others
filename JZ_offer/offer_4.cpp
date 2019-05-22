/*
 *重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
  例子
    给定：
    前序遍历是：[3, 9, 20, 15, 7]
    中序遍历是：[9, 3, 15, 20, 7]
    返回：[3, 9, 20, null, null, 15, 7, null, null, null, null]
    返回的二叉树如下所示：
        3
       / \
      9  20
        /  \
       15   7
 * 前序遍历：根结点 ---> 左子树 ---> 右子树
 * 中序遍历：左子树 ---> 根结点 ---> 右子树
 * 后序遍历：左子树 ---> 右子树 ---> 根结点
 */
#include <cstdio>
#include <malloc.h>
#include<stdio.h>
#include<stdlib.h>

int flag = 1; 		//是否为二叉树的标志

typedef struct treeNode{
    int data;
    struct treeNode *lchild;
    struct treeNode *rchild;
}tree,*bTree;//节点结构体的两个别名，方便以两种方式使用（指针和非指针）

bTree buildTree(int *preOrder, int *inOrder, int length) {
    //首先判断长度是否是合理数值，不是则直接返回空
    if(length < 1){
        return NULL;
    }
    //思路是首先确定根节点，因此从先序排列的首元素中取出根节点,左右子树指向空
    bTree tRoot;
    tRoot = (bTree)malloc(sizeof(tree));
    tRoot->data = *preOrder;
    tRoot->lchild = NULL;
    tRoot->rchild = NULL;

    //在中序遍历中寻找根节点，记录左子树的长度，右子树的长度
    int i = 0,count = 0;
    while (*preOrder != *(inOrder + i)){
        count++;
        //如果超出寻找范围还没找到根节点，那就返回NULL吧，这个二叉树不对
        if(count >= length){
            //标志位置为0，不是一个二叉树
            flag = 0;
            return NULL;
        }else{
            i++;
        }
    }
    /*第三步是递归该函数（为什么可以开始递归了呢：观察本函数的三个参数，在完成前两步之后，
	都能确定左、右子树各自的前序遍历、中序遍历和长度，因此可以把一个大问题分解成一个个的小问题了） */
    tRoot->lchild = buildTree(preOrder+1,inOrder,count);
    tRoot->rchild = buildTree(preOrder+1+count,inOrder+count+1,length-count-1);
    return tRoot;
}

void TraverseBinaryPostOrder(bTree root)   //遍历函数的实现还是依靠递归,输出为后序遍历
{
    if(root == NULL){
        printf("null ");
        return;
    }
    TraverseBinaryPostOrder(root->lchild);
    TraverseBinaryPostOrder(root->rchild);
    printf("%d ",root->data);
}

int main(){
    int arrayPerOrder[5]={3,9,20,15,7};
    int arrayInOrder[5]={9,3,15,20,7};
    bTree root =buildTree(arrayPerOrder,arrayInOrder,5);
    if(flag == 1)
        TraverseBinaryPostOrder(root);
    else
        printf("No");
    printf("\n");
    return 0;
}