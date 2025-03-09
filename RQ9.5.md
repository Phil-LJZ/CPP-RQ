# 9.5 复习题

### 1.

```md
a. 用自动变量
b. 静态外部链接
c. 1.静态内部链接
   2.const变量(const限定的变量其链接性为内部的)
   3.namespace {类型名 变量名;};
```

### 2. 

```
using声明类似于在某特定位置例如main函数代码块中声明一个正常变量，此变量会和同作用域下的同名变量产生冲突，并且会隐藏同名的全局变量。

using编译指令类似于某特定位置例如main函数代码块中用using声明声明其名称空间内所有的声明，但是同名的所有声明将会隐藏此名称空间内的同名声明，例如全局变量和常规变量。
```

o3-mini补充：

下面给出一些关于 C++ 中 using 声明（using-declaration）和 using 指令（using directive）的补充说明，以及你描述中的一些不准确或遗漏之处：

---

### 1. using 声明 (using-declaration)

- **作用：**  
  using 声明用于将某个名称（函数、类、变量等）从一个命名空间“引入”到当前作用域，从而避免每次都写完整限定名。例如：
  ```cpp
  using std::cout;
  ```
  这样，在当前作用域中可以直接使用 `cout` 而不用写 `std::cout`。

- **作用域和冲突：**  
  当在某个作用域中引入一个名称时，如果该名称与当前作用域内已有其他实体冲突，就可能引起二义性或隐藏。  
  - 如果直接引入某个名称（例如函数），它会“合并”到当前作用域，也就是说如果当前作用域中已有同名的函数重载，则会与之产生函数重载集；  
  - 如果当前作用域中已经存在一个相同名称的实体（变量、类型等），通常编译器会产生错误或者出现二义性。  

- **使用限制：**  
  using 声明只能引入单个名称，而不是整个命名空间中的所有内容。

- **注意：**  
  using 声明出现的位置对其生效范围有影响，一般在块内、类内或命名空间内都是允许的，而且不同位置的 using 声明只在各自的作用域中有效。

---

### 2. using 指令 (using directive)

- **作用：**  
  using 指令用于将整个命名空间引入当前作用域。这意味着命名空间中的所有名称都变得可见。例如：
  ```cpp
  using namespace std;
  ```
  这样可以直接使用 `std` 中几乎所有名称，而无需写上 `std::` 前缀。

- **作用域：**  
  using 指令使得目标命名空间中所有名称在当前作用域（以及嵌套在该作用域内的子作用域）都可见。

- **名称冲突的问题：**  
  如果当前作用域中已经定义了同名实体，那么 using 指令引入的名称会与之产生冲突。  
  - 当出现同名时，编译器会依据查找规则进行名字解析（通常会优先考虑局部定义或者显示声明的名称）；  
  - 如果多个命名空间中有同名实体且未明确指定，可能会导致二义性错误，因此需要谨慎使用。

- **效果范围：**  
  using 指令不同于 using 声明，它没有“精细控制”，一旦引入整个命名空间，所有名称都被引入，不经过选择性过滤。

---

### 你描述中的几点需要注意的地方

1. **关于“类似正常变量”这个比喻：**  
   using 声明和变量声明机制完全不同，它只是引入名称到当前作用域。虽然在名字查找方面可能会产生冲突，但它不是一个变量。  
   - 更准确的说法是并不会“创建”一个独立的变量，而仅仅是为名称查找提供了一个别名。

2. **关于冲突遮蔽：**  
   - 使用 using 声明引入的名称会与当前作用域已有的同名实体产生冲突，这种冲突与变量类似，但它对函数（尤其是重载函数）常常有合并的行为。  
   - 而 using 指令是将命名空间中所有名称引入，如果和当前作用域已有的名称冲突，局部已有定义的名称会优先；而多个 using 指令引入的同名名称会导致二义性。

3. **遗漏的部分：**  
   - using 声明和 using 指令的安全性问题。特别是 using 指令常常被批评为会让代码的名称空间 “污染”，增加名字冲突的风险，尤其是在头文件中不建议使用 using 指令。  
   - using 指令对嵌套作用域的影响，比如当你在函数内部使用 using 指令，其有效范围仅限于该函数作用域。  
   - 对于类中成员隐藏和访问基类成员的问题，using 声明在类中也可以用作引入基类的重载函数到派生类中，这是一种常见的用法。

4. **举例说明：**

   - using 声明在局部作用域中的例子：
     ```cpp
     #include <iostream>
     using std::cout;  // 在全局作用域引入 std::cout
     
     int main() {
         int cout = 42;  // 局部变量 cout 隐藏了 using 声明引入的 std::cout
         std::cout << "Hello, world!" << std::endl;  // 这里必须写 std::cout，否则将用到局部变量
         return 0;
     }
     ```

   - using 指令在局部作用域中的例子：
     ```cpp
     #include <iostream>
     using namespace std;  // 全局引入会影响整个文件
     
     int main() {
         // 使用 namespace 指令可以直接访问 std 中的所有名称
         cout << "Hello, world!" << endl;
         return 0;
     }
     ```
     或者在局部作用域：
     ```cpp
     #include <iostream>
     int main() {
         using namespace std;  // 仅在 main 内有效
         cout << "Hello, world!" << endl;
         return 0;
     }
     ```

---

### 总结

- using 声明用于引入特定名称，不会引入整个命名空间；而 using 指令引入整个命名空间。
- 两者都会对名称查找产生影响，但冲突处理机制略有不同：using 声明的名称会与局部已有名称产生直接冲突，而 using 指令引入的名称在名字查找中处于备用地位（局部已有定义优先）。
- 使用 using 指令时需注意可能引起的名称污染和歧义问题，尤其是在头文件或较大范围作用域中使用时。
- 在类中 using 声明还有特殊用途，例如显式引入基类的重载函数，这也是比较重要但在你原先描述中没有提及的内容。

这样，希望能更全面准确地解释两者之间的区别和使用时应关注的细节。

### 3.

```c++
#include <iostream>

int main(void)
{
    double x;
    std::cout << "Enter value:";
    while (!(std::cin >> x))
    {
        std::cout << "Bad input. Please enter a number: ";
        std::cin.clear();
        while (std::cin.get() != '\n')
        {
            continue;
        }
    }
    std::cout << "Value = " << x << std::endl;
    return 0;
}
```

### 4.

```c++
#include <iostream>
int main()
{
	using std::cout;
	using std::cin, std::endl;
	
	double x;
	cout << "Enter value: ";
    while (!(cin >> x))
    {
        cout << "Bad input. Please enter a number:";
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }
    }
    cout << "Value = " << x << endl;
    return 0;
}
```

### 5.

使用一下文件组合编译的程序

main.c

```c++
#include <iostream>
#include "average.h"

int average(const int &, const int &);

int main(void)
{
    using std::cout, std::cin, std::endl;
    
    cout << "使用返回类型为int的函数：" << endl;
    cout << average(1, 2) << endl; // 注意，
                           // 特征标为const int &, const int &
                           // 所以参数可以为右值
    cout << "使用返回类型为double的函数：" << endl;
    cout << ae::average(1, 2) << endl;
    return 0;
}

int average(const int & n1, const int & n2)
{
    double temp;
    temp = (n1 + n2) / 2;
    return temp;
}
```

average.h

```c++
#ifndef __AVERAGE_H__
#define __AVERAGE_H__

namespace ae{
    double average(const int &, const int &);
}

#endif
```

average.c

```c++
namespace ae{
    double average(const int & n1, const int & n2)
    {
        double temp;
        temp = (double(n1) + double(n2)) / 2;
        return temp;
    }
}
```

### 6. 

```
10
4
0 // 因为静态变量自动初始化为0
Other: 10, 1
another(): 10, -4
```

### 7.

```
1
4, 1, 2
2
2
4, 1, 2
2
```

