#include <iostream> 
#include <vector>
#include<algorithm>
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


int main() {
	//testisEven();/*提高代码适用性，参数传递函数的指针*/
	testPrint();/*仿函数的学习*/
}