# 70

## 题目描述

牛牛现在有n张扑克牌，每张扑克牌都有点数和花色两部分组成。点数为‘1’-‘9’的正整数，花色为'C','D','H','S''其中的一个，分别表示梅花、方块、红桃、黑桃。现在牛牛想按一定的顺序把这n张牌扔掉。扔牌顺序的规则如下：

1. 如果现在还剩素数张牌，则将牌顶的牌扔掉
2. 如果现在还剩非素数张牌，则将牌底的牌扔掉

牛牛想知道他的扔牌顺序是什么，请返回扔牌顺序的字符串

## 示例1

### 输入

"3C8D6H3D"

### 输出

"3D3C8D6H"

### 说明

开始n=4，为非素数，扔掉牌底的牌3D

n=3，为素数，扔掉牌顶的牌3C

n=2，为素数，扔掉牌顶的牌8D

n=1，为非素数，扔掉牌底的牌6H

## 示例2

### 输入

"8S8S8S8S8S8S8S"

### 输出

"8S8S8S8S8S8S8S"

### 说明

因为全是8S，所以扔牌顺序的每一张牌也都是8S

## 说明

对于100%的数据，1≤n≤10
