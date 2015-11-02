### 1. 实验题目

Polynomial Arithmetic : 利用面向对象程序设计思想，设计程序进行多项式加法、减法和乘法三种运算。

### 2.实验目的

熟悉多种数据结构的使用，利用多种数据结构去解决实际问题，复习面向对象程序设计的知识。

### 3.程序设计

#### 题目分析：

对于多项式的每一项，系数和次数可以确定每一项，而对于一个多项式，每一项的次数是唯一且不重复的，所以对于一个多项式，可以使用`<key, value>`的形式储存。

- 对于加减法：

只需要对应项相加减即可。对于两个项数各为 m, n 项的多项式，需要运算`max(m, n)`次。

- 对于乘法：

对于一个多项式的一项，需要和另一多项式每一项相乘后相加。对于两个项数各为 m, n 项的多项式，需要运算`m*n`次。

#### 软件设计：

新建 `Polynomial` 类，重载`+ - *` 运算符进行多项式计算。

利用`std::map<int, double>`来储存一个多项式。

在`Polynomial` 类中记录最高次数和最小次数，每次修改多项式时调用更新函数实时更新。

增加 `iostream`的友元函数，使得可以使用`cout`输出多项式的值。

拓展`Polynomial` 类，使得其可以保存运算符，便于使用`std::stack<Polynomial>`和`stl::deque<Polynomial>`储存。

先将 infix expression 转换成 postfix expression，处理括号和运算优先级问题，最后通过计算 postfix expression 得出结果。

### 4.程序运行与测试

代码在 `/src` 目录，已经为 OS X 系统和 Windows 系统编译好二进制文件，在 `/build`目录，若需再次编译，由于用到了 C++11 的特性，需要开启编译器 C++11 的支持。

测试样例在 `/test` 目录，标准输入输出都重定向到了`test*.txt`文件。

- 若需要输入多项式，请以次数系数成对输入，以空格隔开，每个多项式一行。例如`3x^4-2x^-1`请输入`4 3 -1 -2`。
- 若输入运算符或括号` + - * ( )`，输入时每一个占一行。
- 结束输入请输入EOF。Windows 下是 `Ctrl + z`，Unix 下是 `Ctrl + d`。

case 0:

``` 
Please input degree and coefficient separate by a space in one line
Please input one operation (+ - *) in one line
Please end you input by EOF
(
1 9 4 5
+
1 8 7 4
)
*
(
1 9 4 5
-
1 8 7 4
)
The postfix expression is : 
(+5x^4+9x)(+4x^7+8x)(+)(+5x^4+9x)(+4x^7+8x)(-)(*)
The result is : 
+16x^14+39x^8-90x^5-17x^2
```

case 1:

``` 
Please input degree and coefficient separate by a space in one line
Please input one operation (+ - *) in one line
Please end you input by EOF
1 2 3 4
+
(
-1 -2 -3 -4
*
(
2 4 6 8
-
1 8 7 4
)
)
The postfix expression is : 
(+4x^3+2x)(-2x^-1-4x^-3)(+8x^6+4x^2)(+4x^7+8x)(-)(*)(+)
The result is : 
-8x^6+16x^5-16x^4+36x^3+10x-16
```

### 5.实验总结与心得

在这次的 Project 中，我遇到了很多在日常在 soj 上做题不会遇到的问题，也学会了利用 Google 等搜索引擎，用关键字描述自己遇到的问题，找到解决方案。

在重载`<<`运算符时，事先规划好的分类方式能让代码更加简洁，更少出错。

进行运算时，改用引用的方式而不使用按值传递，减少构造函数和析构函数不必要的重复调用，提高了效率。在能使用`const`的地方，尽量使用`const`，减少了很多 bug 出现的概率。

此外，通过设计多项式的储存方式，完成这份代码之后对不同数据结构的判断、运用，运行效率的估计也有更有经验。

### 附录、提交文件清单

`/src/*` 

