# 机试指南

## 从零开始

### OJ 网站

* [OJ-Websites](OJ/OJ-websites.md)

### 做题结果反馈

* Accepted
  * 答案正确
* Wrong Answer
  * 答案错误：程序实现或者思路出现问题，也可能是数据范围边界没有考虑到
* Runtime Error
  * 运行时错误：数组越界或者递归过深导致栈溢出
* Presentation Error
  * 输出格式错误：一般是末尾多了或少了空格或少了换行
* Time Limit Exceeded
  * 程序运行超时：算法不够优秀，程序运行时间过长
* Memory Limit Exceeded
  * 运行内存超限：程序申请太大了空间，超过了题目规定的空间大小

* Compile Error
  * 编译错误：代码存在语法错误，检查是不是选择错误的语言提交了
* Output Limit Exceeded
  * 输出超限：程序输出过多的内容，一般是循环出了问题导致多次输出或者调试信息忘记删除了
* Submitting
  * 提交中，等待题目结果的返回，由于判题机有性能差异所以返回结果也不一样

### 输入输出技巧

```c
//输入int型变量
scanf("%d",&x);
//输入double型变量
scanf("%lf",&x);//不用float直接double
//输入char类型变量
scanf("%c",&x);
//输入字符串数组
scanf("%s",s);
//输出与输入表示方式一致
printf("%s\n",s);
```

* scanf 输入解析

  * 输入日期 2020 - 03 - 21

  * ```c
    int year,month,day;
    scanf("%d-%d-%d",&year,&month,&day);
    printf("%d %d %d\n",year,month,day);
    ```

  * 输入时间 18 : 21 : 30

  * ```c
    int hour,minute,second;
    scanf("%d:%d:%d",&hour,&minute,&second);
    printf("%d %d %d\n",hour,minute,second);
    ```

* scanf 和 gets

输入一行字符串带空格的话，使用 gets，scanf 遇到空格会自动结束

```c
char s[105];
gets(s);
printf("%s\n",s);
```

* getchar 和 putchar

读入单个字符和输出单个字符，一般在 scanf 和 gets 中间使用 getchar 用于消除回车 '\n' 的影响

* 输出进制转换

```c
int a = 10;
printf("%x\n",a);//小写十六进制输出a
printf("%X\n",a);//大写十六进制输出A
printf("%o\n",a);//八进制输出答案12
```

* 输出增加前置0

```c
int a = 5;
printf("%02d\n",a);//2代表宽度，不足的地方用0补充
输出结果 05
printf("%04d\n",a);
输出结果 0005
```

* 输出保留小数

```c
double a = 3.6;
printf("%.2lf\n",a);//2表示保留两位小数
输出结果 3.60
```

注：有小数输出小数，没小数输出整数，前提是输入的类型浮点类型

```c
%g
```

Example：

```c
#include <stdio.h>
int main(){
	
	double a = 2;
	double b = 2.5467;
	printf("a = %g\n",a);
	printf("b = %g\n",b);
	
	return 0;
} 
```

Test Result：

![image-20200321110921091](../images/image-20200321110921091.png)

* long long 的使用

很多情况下的计算会超过 int，比如求 N!，N 比较大的时候 int 就存不下了，这个时候我们就要使用 long long。

注：int 取值范围：-1e9 到 1e9，long long 取值范围：-1e18 到 1e18

```c
long long x;
scanf("%11d",&x);
printf("%lld\n",x);
```

* 字符的 ASCII 码

```c
printf("%d\n",'a');
```

注：若遇到需要 ASCII 码的题目，记住 char 字符和 int 值是可以相互转化的。

* cin 和 cout

很多时候使用 c++ 的输入输出更简单，在应对输入输出量不是很大的题目的时候，我们会采用 cin 和 cout 来提高我们的解题速度。

Example：求两个数之和

 ```cpp
#include <iostream>//输入输出函数的头文件 
using namespace std;

int main(){
	
	int a,b;
	cin >> a >> b;
	cout << a + b;
	
	return 0;
} 
 ```

> 注：平时练习的时候不要排斥混合编程，即 C 与 C++ 混用，然后用 C++ 提交。但是注意：printf 尽量不要和 cout 同时使用，会发生一些不可控的意外。

### 头文件技巧

cpp 文件中推荐一个万能头文件：

```cpp
#include <bits/stdc++.h>
using namespace std;
```

注：要看考试的评测机型支不支持，绝大部分都是支持的，当然准备一个完整的头文件还是有必要的，作为备用。

```cpp
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(){
	
	return 0;
} 
```

注：头文件可以多，但是不能少

### 数组使用技巧

> 数组除了可以存储数据以外，还可以用来进行标记

例题 01：

![image-20200321120529994](../images/image-20200321120529994.png)

【代码实现】

```cpp
#include <bits/stdc++.h>//万能头文件 
using namespace std;

int f[105]={0};//注意：尽量将数组开在全局 
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		f[x]++;
	} 
	for(int i=1;i<=100;i++){
		if(f[i]>0){
			printf("%d %d\n",i,f[i]);
		}
	}
	return 0;
} 
```

例题 02：

![image-20200321134145614](../images/image-20200321134145614.png)

【代码实现】

```cpp
#include <bits/stdc++.h>//万能头文件 
using namespace std;

int f[105] = {0};//注意：尽量将数组开在全局 
int p[105] = {0};//p[i]表示有 i个这样的数的最大值是多少 
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		f[x]++;
	} 
	for(int i=0;i<100;i++){
		p[f[i]] = i;
	} 
	for(int i=1;i<=100;i++){
		if(p[i]>0){
			printf("%d %d\n",p[i],i);
		}
	}
	return 0;
} 
```



例题 03：

【题目】二维数组实现存储地图

```
####
#.##
##@#
####
```

【代码实现】

```cpp
#include <bits/stdc++.h>//万能头文件 
using namespace std;

char mpt[10][10];
int main(){
	for(int i=0;i<4;i++){
		scanf("%s",mpt[i]);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%c",mpt[i][j]);
		}
		printf("\n");
	}

	return 0;
} 
```

### 复杂度与是否可做

> 做好审时度势

|   算法   |   循环嵌套    | 时间复杂度 | 空间复杂度 |
| :------: | :-----------: | :--------: | ---------- |
| 冒泡排序 | 两个 for 循环 |   O(N^2​)   |            |

注：空间复杂度一般不会限制，如果遇到了再想办法优化空间。

> 时限 1 s 情况下的复杂度：

| 时间复杂度 | N 取值（时限 1 s） |
| ---------- | ------------------ |
| O(N)       | N 最大在 500w 左右 |
| O(NlogN​)   | N 最大在 20w 左右  |
| O(N^2​)     | N 最大在 2000 左右 |
| O(N^2logN​) | N 最大在 700 左右  |
| O(N^3​)     | N 最大在 200 左右  |
| O(N^4​)     | N 最大在 50 左右   |
| O(2^N​)     | N 最大在 24 左右   |
| O(N!)​      | N 最大在 10 左右   |

注：如果是 2S、3S 对应的乘以 2 和 3 就可以。

### C++ STL 的使用

?> C++ 的算法头文件里有很多实用的函数，我们可以直接拿来用。

```cpp
#include <algorithm>
```

* （1）排序函数 sort()

  * 依次传入三个参数，要排序区间的起点，要排序区间的终点+1，比较函数。比较函数可以不填，则默认为从小到大排序

  * 示例：

  * ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    int a[105];
    int main(){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
        	scanf("%d",&a[i]);
    	}
    	sort(a,a+n);
    	for(int i=0;i<n;i++){
    		printf("%d ",a[i]);
    	}
        return 0;
    }
    ```



* （2）查找函数

  * lower_bound() 函数

  * upper_bound() 函数

  * lower_bound() 和 upper_bound() 都是利用二分查找的方法在一个排好序的数组中进行查找的。

  * 在从小到大的排序数组中：

  * lower_bound(begin,end,num)：从数组的 begin 位置到 end-1 位置二分查找第一个大于或等于 num 的数字，找到返回该数字的地址，不存在则返回 end。通过返回的地址减去起始地址 begin,得到找到数字在数组中的下标

  * upper_bound(begin,end,num)：从数组的 begin 位置到 end-1 位置二分查找第一个大于 num 的数字，找到返回该数字的地址，不存在则返回 end。通过返回的地址减去起始地址 begin,得到找到数字在数组中的下标

  * 重载 lower_bound() 和 upper_bound() 

  * lower_bound(begin,end,num,greater< type >()):

  * 从数组的 begin 位置到 end-1 位置二分查找第一个小于或等于 num 的数字，找到返回该数字的地址，不存在则返回 end。通过返回的地址减去起始地址 begin,得到找到数字在数组中的下标

  * upper_bound(begin,end,num,greater< type >()):

  * 从数组的 begin 位置到 end-1 位置二分查找第一个小于 num 的数字，找到返回该数字的地址，不存在则返回 end。通过返回的地址减去起始地址 begin,得到找到数字在数组中的下标

  * 示例：

  * ```cpp
    //查找函数
    #include <bits/stdc++.h>
    using namespace std;
    
    int cmp(int a,int b);
    int main(){
        int num[6]={1,2,4,7,15,34};
        sort(num,num+6);//按从小到大排序
        //返回数组中第一个大于或等于被查数的值
    	int pos1 = lower_bound(num,num+6,7)-num;
    	//返回数组中第一个大于被查数的值
    	int pos2 = upper_bound(num,num+6,7)-num;
    	cout<<pos1<<" "<<num[pos1]<<endl;
    	cout<<pos2<<" "<<num[pos2]<<endl;
    	sort(num,num+6,cmp);//按从大到小排序
    	//返回数组中第一个小于或等于被查数的值
    	int pos3 = lower_bound(num,num+6,7,greater<int>())-num;
    	//返回数组中第一个小于被查数的值
    	int pos4 = upper_bound(num,num+6,7,greater<int>())-num;
    	cout<<pos3<<" "<<num[pos3]<<endl;
    	cout<<pos4<<" "<<num[pos4]<<endl;
    	 
        return 0;
    }
    
    int cmp(int a,int b){
    	return a>b;
    }
    ```



* （3）优先队列

  * 通过 priority_queue< int >q 来定义一个储存整数的空的 priority_queue。当然 priority_queue 可以存任何类型的数据，比如 priority_queue< string >q 等等。

  * 示例：

  * ```cpp
    //#include <bits/stdc++.h>
    #include <iostream>
    #include <queue>
    using namespace std;
    
    int main(){
        priority_queue<int> q;//定义一个优先队列
    	q.push(1);//入队 
    	q.push(2);
    	q.push(3);
    	while(!q.empty()){//判读队列不为空 
    		cout << q.top() << endl; //队首元素 
    		q.pop();//出队 
    	} 
        return 0;
    }
    ```

> C++ 的 STL (标准模板库)是一个非常重要的东西，可以极大的帮助更快速的解决题目

* vector
  * 通过 vector< int >v 来定义一个储存整数的空的 vector。当然 vector 可以存任何类型的数据，比如 vector< string >v 等等
  
  * 示例：
  
  * ```cpp
    //#include <bits/stdc++.h>
    #include <iostream>
    #include <vector>
    using namespace std;
    
    int main(){
        vector<int> v;//定义一个空的 vector
    	for(int i=1;i<=10;i++){
    		v.push_back(i*i);//加入到 vector 中 
    	} 
    	for(int i=0;i<v.size();i++){
    		cout<<v[i]<<" ";//访问 vector 元素 
    	} 
    	cout << endl; 
        return 0;
    }
    ```
  
  * Result：

![image-20200322201845985](../images/image-20200322201845985.png)



## 暴力求解



## 排序与查找



## 字符串



## 数据结构一



## 数学问题



## 贪心策略



## 递归与分治



## 搜索



## 数据结构二



## 图论



## 动态规划





