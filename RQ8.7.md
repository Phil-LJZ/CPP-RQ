# 8.7 复习题

1. 运行时间短

2. a.

   ```c++
   void song(const char * name, int times = 1);
   ```

   b.不需要做什么修改

   c.不能，函数原型默认值只能在所有变量之后

3. ```c++
   void iquote(int);
   void iquote(double);
   void iquote(string);
   ```

4. 下面是一个结构模板

   ```c++
   struct box 
   {
       char maker[40];
       float height;
       float width;
       float length;
       float volume;
   };
   ```

   a.

   ```c++
   #include <iostream>
   using namespace std;
   void show_box(box &); // c版本：void show_box(struct box *);
   void show_box(box & input_box)
   {
       cout << "maker:" << input_box.maker << endl;
       cout << "height:" << input_box.height << endl;
       cout << "width:" << input_box.width << endl;
       cout << "length:" << input_box.length << endl;
       cout << "volume:" << input_box.volume << endl;
   }
   ```

   b.

   ```c++
   void compute(box & input_box)
   {
       input_box.volume = input_box.height * input_box.length * input_box.width;
   }
   ```

5. ```c++
   //arrobj.cpp -- functions with array objects
   #include <iostream>
   #include <array>
   #include <string>
   const int Seasons = 4;
   const std::array<std::string, Seasons> Snames =
       {"Spring", "Summer", "Fall", "Winter"};
   
   void fill(std::array<double, Seasons> &);
   void show(std::array<double, Seasons> &);
   int main()
   {
       std::array<double, 4> expenses;
       fill(expenses);
       show(expenses);
       // std::cin.get();
       // std::cin.get();
       return 0;
   }
   
   void fill(std::array<double, Seasons> & pa)
   {
       for (int i = 0; i < Seasons; i++)
       {
           std::cout << "Enter " << Snames[i] << " expenses: ";
           std::cin >> (pa)[i];
       }
   }
   
   void show(std::array<double, Seasons> & da)
   {
       double total = 0.0;
       std::cout << "\nEXPENSES\n";
       for (int i = 0; i < Seasons; i++)
       {
           std::cout << Snames[i] << ": $" << da[i] << '\n';
           total += da[i];
       }
       std::cout << "Total: $" << total << '\n';
   }
   
   ```

6. a.用默认参数
   b.函数重载

   ```c++
   void repeat(int, string);
   void repeat(string);
   ```

   c.函数重载
   d. // 较难

   ```c++
   // 返回首字符的版本
   char mangle(char* str) {
       return *str;
   }
   
   // 返回字符串指针的版本
   const char* mangle(const char* str) {
       return str;
   }
   ```

7. ```c++
   template <typename T> T func(T & t1, T & t2)
   {
       return t1 > t2 ? t1 : t2;
   }
   ```

8. ```c++
   template <> box& func<box>(box& b1, box& b2)
   {
       return b1.volume > b2.volume ? b1 : b2;
   }
   ```

9. ```
   v1 float
   v2 float &
   v3 float
   v4 int
   v5 double
   ```

   