### 1. 实验题目

Life Game : 利用面向对象程序设计思想，模拟 Life Game 的运行，输出迭代100代之后的结果。

### 2.实验目的

熟悉多种数据结构的使用，复习面向对象程序设计的知识。

### 3.程序设计

#### 题目分析：

Life Game 实质上是根据上一代地图上每一个细胞的状态，生成下一代细胞的状态的一个程序。

对于地图上的每一个坐标，只有 dead 和 alive 两种状态。

- 对于活细胞：


1. neighbor <= 2 : dead 
2. 3 <= neighbor <= 4 : alive
3. 5 <= neighbor : dead


- 对于死细胞：


1. neighbor <= 2 : dead 
2. neighbor == 3 : alive
3. 4 <= neighbor : dead

#### 软件设计：

由于地图的大小不确定，所以使用 `std::map` 来储存每个细胞的状态，key为坐标，value为细胞的状态，细胞状态用枚举类型记录。新建 `Coordinate` 类，重载`<`运算符使得可以作为 `std::map`的key。

每一次迭代，根据上一代每个细胞的状态，生成每个细胞 neighbor 的数量，再根据数量生成下一代细胞的状态。

记录边界，并根据活细胞的位置动态扩展。

由于测试数据和输出量大，使用文件读入测试数据。

### 4.程序运行与测试

代码在 `/src` 目录，已经为 OS X 系统和 Windows 系统编译好二进制文件，在 `/build`目录，若需再次编译，由于用到了 C++11 的特性，需要开启编译器 C++11 的支持。

测试样例在 `/test` 目录，以 Result 结尾的为输出结果。

使用方法

Please input test case address: 输入测试文件的地址

Please input output data address: 输入结果文件的输出地址

Please input times of generation: 迭代进行的次数

Enable debug mode? 是否输出运行过程所有数据，建议输入0 (false)。

### 5.实验总结与心得

在这次的 Project 中，我遇到了很多在日常在 soj 上做题不会遇到的问题，也学会了利用 Google 等搜索引擎，用关键字描述自己遇到的问题，找到解决方案。

例如在写 Project 时遇到一个问题，A类的声明里面用到了B类，B类的声明里面用到了A类，一开始的想法是互相 `#include "A/B.h”` 就可以了，编译器会自己解决，实际上不能。Google 之后知道了向前声明 / 向前引用  (Forward declaration / Reference)，解决这个问题。

``` c++
//    A.h

class B;

class A
{
    ...
};
```

``` c++
//   B.h

class A;

class B
{
    ...
};
```

完成这次 Project，我对 C++ 面向对象程序设计的理解更加深刻，更加熟练。

此外，通过设计地图的储存方式，对不同数据结构的判断、运用，运行效率的估计也有更有经验。

### 附录、提交文件清单

`/src/*` 

`/build/*` 

`/test/*`