#include <iostream> 
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

/*||提高代码适用性，参数传递函数的指针*/
int addition(int x, int y) {
	return x + y;
}
int subtraction(int x, int y) {
	return x - y;
}
bool isEven(int x) {
	return x % 2 == 0;
}
bool operation(int x, bool(*f)(int)) {//用指针将函数作为参数传参,函数指针
	//or another return way: return (*f)(x);
	return f(x);
}
void testisEven() {
	bool answer = operation(1, isEven);
	cout << answer;
}
/*提高代码适用性，参数传递函数的指针||*/

/*||知识点18051501：应用STL，务必养成良好习惯，遵照C++规范，使用无扩展名头文件，例如 #include<vector> 而不是 #include<vector.h>||*/

/*||仿函数的学习*/
template<typename T>
class print {
public:
	void operator()(const T& e) {//重载operator(),所以被称为仿函数。因为用法像函数
		cout << e << ' ';
	}
};
//template<typename T>
//class plus {//由于重载了operator(),所以plus被称为仿函数
//public:
//	T operator()(const T& x, const T& e) {//重载operator(),所以被称为仿函数。因为用法像函数
//		return x+e;
//	}
//};
void testPrint() {
	int ia[6] = { 0,1,2,3,4,5 };
	vector<int> iv(ia, ia + 6);
	//print<int>()是一个临时对象，不是仿函数
	for_each(iv.begin(), iv.end(), print<int>());
	cout << endl;
	plus<int> plusobj;
	//以下使用仿函数，就像使用函数一样
	cout << plusobj(3, 5) << endl;
	//以下是先产生临时对象（第一对小括号），并用之（第二对小括号）
	cout << plus<int>()(30, 50) << endl;
}

//for_each实现方法
//template <class InputIterator,class Fuction>
//Function for_each(InputIterator first, InputIterator last, Fuction f) {
//	for (; first != last; ++first)
//		f(*first);
//	return f;
//}

/*仿函数的学习||*/

/*||动态规划学习
https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
||*/

/*||switch用法*/
void testSwith(int a) {
	switch (a){
	case 1: {
		break;
	}
	default:
		break;
	}
}
/*switch用法||*/

/*|string to int/char to int*/
void teststoi() {
	string a("211");
	char b[10] = "211";
	int t;
	t = stoi(a);//在头文件string里面
	cout << t << endl;
	t = atoi(b);//在头文件stdlib.h里面
	cout << t << endl;
}
/*
1、itoa
功 能:把一整数转换为字符串
用 法:char *itoa(int value, char *string, int radix);
详细解释:itoa是英文integer to array(将int整型数转化为一个字符串,并将值保存在数组string中)的缩写.
参数:
value: 待转化的整数。
radix: 是基数的意思,即先将value转化为radix进制的数，范围介于2-36，比如10表示10进制，16表示16进制。
* string: 保存转换后得到的字符串。
返回值:
char * : 指向生成的字符串， 同*string。
备注:该函数的头文件是"stdlib.h"

2、ltoa
功 能:把一长整形转换为字符串
用 法:char *ltoa(long value, char *string, int radix);

3、ultoa
功 能:把一无符号长整形转换为字符串
用 法:char *ultoa(unsigned long value, char *string, int radix);

4、gcvt
功 能:把浮点型数转换为字符串，取四舍五入
用 法:char *gcvt(double value, int ndigit, char *buf);
详细解释:gcvt()用来将参数number转换成ASCII码字符串，参数ndigits表示显示的位数。
gcvt()与ecvt()和fcvt()不同的地方在于，gcvt()所转换后的字符串包含小数点或正负符号。若转换成功，转换后的字符串会放在参数buf指针所指的空间。
参 数:
value:待转化的浮点数。
ndigit:存储的有效数字位数。
*buf:结果的存储位置。

5、ecvt
功 能:将双精度浮点型数转换为字符串，转换结果中不包括十进制小数点
用 法:char *ecvt(double value, int ndigit, int *decpt, int *sign);
详细解释:ecvt函数把一个双精度浮点数转换成一个字符串。value参数是要转换的浮点数。
这个函数存储最多ndigit个数字值作为一个字符串,并添加一个空数字符('\0'),如果value中的数字个数超过ndigit,低位数字被舍入。
如果少于ndigit个数字,该字符串用0填充。《保留几位有效数字》

只有数字才存储在该字符串中,小数点位置和value符号在调用之后从decpt和sign获取。
decpt参数指出给出小数点位置的整数值,它是从该字符串的开头位置计算的。0或负数指出小数点在第一个数字的左边。
sign参数指出一个指出转换的数的符号的整数。如果该整数为0,这个数为正数,否则为负数。

参 数:
value:待转换的双精度浮点数。
ndigit:存储的有效数字位数。
*decpt:存储的小数点位置。
*sign:转换的数的符号。

6、fcvt
功 能:指定位数为转换精度，其余同ecvt
用 法:char *fcvt(double value, int ndigit, int *decpt, int *sign);
详细解释:参与转换的实际值保留的小数位数由ndigit决定。
如果少于ndigit个数字,不填充。《保留几位小数》。

*/
/*string to int/char to int|*/

/*||struct的默认构造函数与string的初始化*/
struct error {//struct里面默认是public，class默认是private
	string er;
	int rowNum;
	//error():er(""),rowNum(0){}//或者：error():rowNum(0){}
	/*
	  1、此处的string是默认为""的，但是我们不能用NULL来初始化他，会报错
	  2、默认构造函数只能有一个。所以下面的默认构造函数比较好
	*/
	error(string error = "", int n = 0) :er(error), rowNum(n) {}
};
void testStruct() {
	struct error e;
	cout << e.er << endl;
}
/*struct的默认构造函数与string的初始化||*/

int main() {
	//testisEven();/*提高代码适用性，参数传递函数的指针*/
	//testPrint();/*仿函数的学习*/
	testStruct();/*struct的默认构造函数与string的初始化*/

}
