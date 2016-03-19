#include <stdio.h>

#define Test
/*
 * 1)  __VA_ARGS__ 是一个可变参数的宏，很少人知道这个宏，这个可变参数的宏是新的C99规范中新增的，目前似乎只有gcc支持（VC6.0的编译器不支持）。宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错, 你可以试试。
 * 2) __FILE__ 宏在预编译时会替换成当前的源文件名
 * 3) __LINE__宏在预编译时会替换成当前的行号
 * 4) __FUNCTION__宏在预编译时会替换成当前的函数名称
 */
//DEBUG(info)这条宏定义只支持一个参数的替换，
//也就是说不能支持变量的打印,只能支持字符串的打印 
//#undef Test
/*
#ifdef Test

#define DEBUG(info)    printf(info)
#else 
#define DEBUG(info)    NULL

#endif
*/

//给printf用宏定义换个名字：
//#define DEBUG(...)  printf(__VA_ARGS__)

//' ## '的意思是，如果可变参数被忽略或为空，
//将使预处理器（ preprocessor ）去除掉它前面的那个逗号。
//这是Qt中的写法 
//以下是两种实现方式

//第一种先输出变量，再输出文件名、行号 
//#define DEBUG(format, ...) printf("[test] "format" File:%s, Line:%d, Function:%s", ##__VA_ARGS__, __FILE__, __LINE__ , __FUNCTION__)

//第二种先输出文件名、行号，然后再输出 变量值 
//#define DEBUG(format,...) printf("File: "__FILE__", Line: %05d: "format"", __FILE__ ,__LINE__, ##__VA_ARGS__)  

//第三种不加任何额外的参数 
//#define DEBUG(format,...) printf(format, ##__VA_ARGS__)

//另外一种写法，里面用一个逗号表达式来控制输出 
#define DEBUG(...) (printf("DEBUG: "), printf(__VA_ARGS__))

int main(void)
{
   int a=10;
   DEBUG("this is a testsdfsafsdfsdfsdfsdfasfsdfsf!!!,a= %d\n", a);
   //printf("[test] "form" file");
   return 0;
}
