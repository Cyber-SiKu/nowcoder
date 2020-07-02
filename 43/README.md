
# 43

## 题目描述

幼儿园一个大班要分成两个小班，有些小朋友不希望自己和其他某几位小朋友同班。

园长向大家收集了不希望同班的要求，然后视情况将一个大班的小朋友分成两个班。

请你开发一个程序，帮助园长快速判断是否所有小朋友的不同班请求都可以被满足。

## 输入描述

输入分为三部分，第一个部分是一个 int，代表这个大班里小朋友的总数。

第二部分是一个 int，代表园长采集到的小朋友们的请求数。

第三部分是小朋友们的请求，每个请求由两个 int 组成，第一个 int 代表提请求的小朋友，第二个 int 代表他不希望同班的另一位小朋友。

## 输出描述

如果所有小朋友的请求都可以被满足，输出 1，否则输出 0。

## 示例1

### 输入

5

5

1 2

1 3

1 4

1 5

2 3

### 输出

0

### 说明

总共有 5 位小朋友，总共采集到了 5 个请求。

分别是：1 不希望和 2 同班。

1 不希望和 3 同班。

1 不希望和 4 同班。

1 不希望和 5 同班。

2 不希望和 3 同班。

不能满足所有人的请求，输出 0。

## 示例2

### 输入

5

4

1 2

1 3

1 4

1 5

### 输出

1

### 说明

总共有 5 位小朋友，总共采集到了 4 个请求。

分别是：1 不希望和 2 同班。

1 不希望和 3 同班。

1 不希望和 4 同班。

1 不希望和 5 同班。

可以满足所有人的请求，分班方式：1 一个人一班，2、3、4、5 另一班。

输出 1。