#include <iostream>  
using namespace std;

/*提高代码适用性，参数传递函数的指针*/
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
int main() {
	bool answer = operation(1, isEven);
	cout << answer;
}