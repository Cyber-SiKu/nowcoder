# 19

## 题目描述

给定一个由正整数组成的集合S，找出一个最大的子集合S·，使得S·中任意两个数字的和都不能被K整除。

例如S=「10，10，12，19，22，24，25」，K=4。

S·的可能取值为「10，12，25」或者「19，22，25」等，S·最多只能取3个数。

## 输入描述

输入为两行，第一行两个数字，分别表示集合S的元素数量N和K。

第二行为N个数字，分别是S的各个元素值。

1<N<1e5

1<K<100

1<S[i]<1e9

## 输出描述

输出为一个数字，集合S·的最大长度。

## 示例1

### 输入

4 3

1 7 2 4

### 输出

3
