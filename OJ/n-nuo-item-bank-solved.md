# N 诺题库刷题

> N 诺题库地址：[DreamJudge](http://noobdream.com/DreamJudge/Issue/page/0/)

## P1000 - A+B 问题

【题目描述】

```
Time Limit: 1000 ms
Memory Limit: 256 mb
输入A,B
输出A+B
-1,000,000,000<=A,B<=1,000,000,000
```

【输入描述】

```
输入包含两个整数A,B，用一个空格分隔。
```

【输出描述】

```
输出一个整数，表示A+B的值。
```

【输入样例】

```
5 8
```

【输出样例】

```
13
```

【代码实现】

```c
#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	return 0;
}
```

## P1001 - 01 序列

【题目描述】

```
Time Limit: 1000 ms
Memory Limit: 256 mb
对于长度为6位的一个01串，每一位都可能是0或1，一共有64种可能。它的前几个是：
000000
000001
000010
000011
000100
请按从小到大的顺序输出这64种01串。
```

【输入描述】

```
无
```

【输出描述】

```
输出64行，每行一个01串。
```

【代码实现】

* Example 01：

```c
#include <stdio.h>

int main(){
	int i,temp,j;
	int a[6];
	for(i=0;i<64;i++){
		temp = i;
		for(j=0;j<6;j++){
			a[j] = temp%2;
			temp /= 2;
		}
		for(j=5;j>=0;j--){
			printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
} 
```

* Example 02：

```c
#include <stdio.h>
void func(int n);
int main(){
	int i;
	for(i=0;i<64;i++){
		func(i);
		printf("\n");
	}
	return 0;
} 

void func(int n){
	int j;
	int a[6];
	for(j=0;j<6;j++){
		a[j] = n%2;
		n /= 2;
	}
	for(j=5;j>=0;j--){
		printf("%d",a[j]);
	}
}
```

* Example 03：栈+C++

```cpp
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	for (int num = 0; num < 64; num++) {
		stack<int> s;
		int tmp = num;
		for (int i = 1; i <= 6; i++) {
			s.push(tmp%2);
			tmp /= 2;
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
	return 0;
}
```

* Example 04：求和

```c
#include<stdio.h>
int main(){
    int i,j;     
    for(i=0;i<64;i++){
    	int res = 0;
        int temp = i;
		int cnt = 0;   
		int a[6]={0};
        while(temp>0){
            a[cnt] = temp % 2;
            temp /= 2;
            cnt++;
        }
        for(j = 5;j>=0;j--){
           res = res * 10 +a[j];
        }
        printf("%06d\n",res);
    }
    return 0;
}
```

* Example 05：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){

    int A[6]={0};
    int i,j;
    
    for(i=0;i<64;i++)
    {
        printf("%d%d%d%d%d%d\n",A[0],A[1],A[2],A[3],A[4],A[5]);
        A[5]++;
        for(j=5;j>0;j--)
        {
            if(A[j] == 2)
            {
                A[j]= 0;
                A[j-1]++;
            }
        }

    }
    
    return 0;
}
```

* Example 06：递归

```cpp
#include<bits/stdc++.h>
using namespace std;

void Badd(char *s,int i); 

int main(){
    char s[6]={'0','0','0','0','0','0'};
    for(int i=0;i<64;i++){
        cout<<s<<endl;
        Badd(s,5);      
    }
    return 0;
}

void Badd(char *s,int i){   //二进制加法器 
    if(i==-1)return;
    if(s[i]=='0')s[i]='1';
    else{
        s[i]='0';
        return Badd(s,i-1);
    }    
}
```

## P1002 - 数字统计

【题目描述】

```c
Time Limit: 1000 ms
Memory Limit: 256 mb
请统计某个给定范围[L, R]的所有整数中，数字 2 出现的次数。
比如给定范围[2, 22]，数字 2 在数 2 中出现了 1 次，在数 12 中出现 1 次，在数 20 中出现 1次，
在数 21 中出现 1次，在数 22 中出现 2 次，所以数字 2 在该范围内一共出现了 6次。
```

【输入描述】

```c
2个正整数 L 和 R，之间用一个空格隔开。
1≤L≤R≤100000
```

【输出描述】

```c
数字 2 出现的次数。
```

【代码实现】

```c
#include <stdio.h>

int main(){
	int i,j,temp,count=0;
	int l,r;
	scanf("%d %d",&l,&r);//输入l,r 
	for(i=l;i<=r;i++){
		temp = i;
		while(temp>0){
			if(temp%10==2){//取个位值是否和2相等，count++ 
				count++;
			}
			temp /= 10;  
		}
	}
	printf("%d\n",count);
	
	return 0;
}
```

## P1003 - 翻转数的和

【题目描述】

```c
Time Limit: 1000 ms
Memory Limit: 256 mb
喜欢数学的Lucy经常向哥哥LF请教一些题目，哥哥总能很快就帮她解决。这不，Lucy又有难题要请教哥哥了Lucy的难题。
Lucy的难题是有关翻转数的：

翻转数就是把一个数的所有数字以相反顺序写出来，即原来的第一个数字成为最后一个，而原来的最后一个则成为第一个。我们把未翻转的数称为翻转数的原数。

例 如：6789的翻转数是9876，而6789就是9876的原数。

你一定注意到了，一个翻转数的原数可以有很多个，例如18的原数可以是81、810、8100等等。因此我们假定：通过翻转数求原数时，所求得的原数的个 位不为零。即18的原数就是81。

Lucy现在给出2个翻转数A、B。

这两个翻转数各自对应的原数是C、D，C 与D的和为 S ，Lucy想知道 S是多少？
```

【输入描述】

```c
输入为多组测试数据，每行一组，包含两个整数A、B，两数中间以空格分隔，0<A<100 000 000，0<B<100 000 000。
```

【输出描述】

```c
输出只有一个整数，即为S。
注意：请不要输出翻转数前面无用的零。例：对于0056，只需输出56。
```

【代码实现】

* Example 01：C 语言实现

```c
#include <stdio.h>
int reverse(int x);//函数声明 

int main(){
	int a,b;
	while((scanf("%d %d",&a,&b))!=EOF){
		int s = reverse(a) + reverse(b); 
		printf("%d\n",s);
	} 
	return 0;
}

int reverse(int x){//实现翻转函数 
	int result = 0;
	while(x){
		result = result * 10 + x % 10; //x%10表示取个位 
		x /= 10;//表示舍去个位 
	}
	return result;
} 
```

* Example 02：

```c
#include <stdio.h>
int main() {
    int a, b;
    while(~scanf("%d %d", &a, &b)) {
        int ans1 = 0, ans2 = 0;
        while(a) {
            ans1 = ans1 * 10 + a % 10;
            a /= 10;
        }
        while(b) {
            ans2 = ans2 * 10 + b % 10;
            b /= 10;
        }
        printf("%d\n", ans1 + ans2);
    }
    return 0;
}
```

* Example 03：

```cpp
#include<iostream>
using namespace std;
int reverse(int num)
{
	int result = 0;//翻转结果 
	while (num > 0) {
		result = result * 10 + num % 10;
		num /= 10;
	}
	return result;
}
int main()
{
	int a, b;
	while (cin >> a >> b) {//EOF结束输入
		int c = reverse(a);
		int d = reverse(b);
		cout << c + d << endl;
	}
	return 0;
}
```

