# 58

## 题目描述

在日常书面表达中，我们经常会碰到很长的单词，比如"localization"、"internationalization"等。

为了书写方便，我们会将太长的单词进行缩写。

这里进行如下定义：

如果一个单词包含的字符个数超过10则我们认为它是一个长单词。

所有的长单词都需要进行缩写，缩写的方法是先写下这个单词的首尾字符，然后再在首尾字符中间写上这个单词去掉首尾字符后所包含的字符个数。

比如"localization"缩写后得到的是"l10n"，"internationalization"缩写后得到的是"i18n"。

现给出n个单词，将其中的长单词进行缩写，其余的按原样输出。

## 输入描述

第一行包含要给整数n。1≤n≤100

接下来n行每行包含一个由小写英文字符构成的字符串，字符串长度不超过100。

## 输出描述

按顺序输出处理后的每个单词。

## 示例1

### 输入

4

word

localization

internationalization

pneumonoultramicroscopicsilicovolcanoconiosis

### 输出

word

l10n

i18n

p43s
