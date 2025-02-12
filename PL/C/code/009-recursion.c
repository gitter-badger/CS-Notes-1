/*****************************
 File name:recursion
 Author:wugenqiang	Version:1.0		Date:2020/2/26
 Description:对一个数字n递归求n! 
 *****************************/
 
#include "stdio.h"
 
 /*****************************
 *函数名： recursion_fun
 *作用：求n! 
 *参数：n - 所求阶乘的值
 *返回值：n!的结果 
 *****************************/
int recursion_fun(int n){
    if(n == 0) return 0;
	if(n == 1) return 1;//递归结束条件
	else	return n * recursion_fun( n-1 );  //自己调用自己
}
 
//主函数 
 
int main(){
	int n,res;
	
	printf("请输入递归数字：");
	scanf("%d",&n);
	
	res = recursion_fun(n);			//n! 
	
	printf("\n %d! = %d",n,res);
	return 0;
}

