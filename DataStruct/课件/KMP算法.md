# KMP算法

## 概念

KMP算法：在一个文本串 S 内查找一个模式串 P 的出现位置



首先理解一下普通字符串匹配算法。



假设S匹配到了i位置，P匹配到了j位置

原来的普通匹配算法是如果有不匹配的情况：j 回到第一个位置，i 倒退已经匹配过的字符数+1。

KMP算法的改进：j 回到了 next[j] 的位置，如果 j ==-1， i++，j++。



之所以KMP算法这样这样改进，是因为它考虑到了当模式串P匹配到了 j 的位置，之前的j-1位的已经匹配过的字符能否利用上，特别是有相同的情况  前缀和后缀

j 之前的 j-1 位都是已经和S的匹配过的，这是已知的信息，我们来考虑一下

1. j = 0，显然这时候你会 i++，j++

   ABCDOABCD				ABCDEABCD

   ABCDEE						    ABCDEE 

2. j 不等于 0，如果有相同的前缀和后缀，则模式串移动到相同的部分，如果没有，则同1一样

ABCDOABCD		ABCDEABCD	

ABCDEAB   D		   			 ABCDEABD

00000 12

AB   						AA

A    B 

从上面我们能发现这么几点规律：

1. KMP算法根据模式串P利用了已经匹配过的字符串内部的规律
2. j 每次回到的位置都是**最长的相同前缀后缀的长度的末尾**



## 算法流程

### 求text数组

求text数组就是一个小的kmp算法，用自己前面的字符串与后面的

```flow
st=>start:开始
io=>inputoutput:输入模式串P
op1=>operation:定义数组text，长度为p.len+1,text[0]=-1
op2=>
```



```flow
st=>start: 开始
io1=>inputoutput: 输入文本串S，模式串P
op1=>operation: 计算next数组（长度为P.length+1)
op2=>operation: 假设S匹配到了i位置，P匹配到了j位置,i=0,j=-1
cond1=>condition: i<S.len&&j<P.len
cond2=>condition: j==-1||S[i]==P[j]
op3=>operation: ++i,++j;
op4=>operation: j = next[j];
cond3=>condition: j==P.length
op5=>operation: return 0
op6=>operation: return j
e1=>end: 得到j的值
st->io1->op1->op2->cond1
cond1(yes)->cond2
cond2(yes)->op3->cond1
cond2(no)->op4(left)->cond1
cond1(no)->e1
```

KMP算法中的难点在于

1. next数组长度为什么是P.legth+1，怎么计算next数组
2. next数组有什么用，为什么这样来用



