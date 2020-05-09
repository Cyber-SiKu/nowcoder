
# 刷算法(题目来源：牛客网)
---

# 12

## 题目描述
JSON是一种可以用来保存配置的数据格式，其结构为树状。

JSON中某个子节点的位置可以JSON路径的形式表示，JSON路径类似UNIX文件路径，以'/'分隔父子节点名。JSON路径中不会出现空格。

如下JSON值中

```others
mem -- daemons -- findme
    |          |- waccd
    |
    |- apps -- appd
```

findme子节点的JSON路径为： /mem/daemons/findme

appd子节点的JSON路径为：/mem/apps/appd

Swaccd子节点的JSON路径为：/mem/daemons/waccd

有一个列表用来描述各JSON子节点是否允许用户编辑。如下：

Y /mem/daemons/findme

N /mem/daemons

Y /mem

如果有设置用户对某个子节点的权限，则实际权限为该设定权限，否则继承其父节点的可访问性，对根节点的默认访问权限为N。

## 输入描述

第一行为一个正整数N，表示接下来有N行数据(0 < N < 100)
第2行到第N+1行，为字符串Path，表示待检查访问权限的JSON路径。
第N+2行为一个正整数T，表示接下来有T行数据（0 < T < 1000）

接下来会有T行数据，格式为"权限 JSON路径"。

权限有两种取值：Y和N
JSON路径最大长度为256

## 输出描述

输出“权限”，权限表示该节点的实际访问权限。

## 示例1

### 输入

```others
1
/mem/total
3
Y /mem/daemons/findme
N /mem/daemons
Y /mem
```

### 输出

```other
Y
```
