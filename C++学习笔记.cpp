#include <iostream>  
using namespace std;

/*��ߴ��������ԣ��������ݺ�����ָ��*/
int addition(int x, int y) {
	return x + y;
}
int subtraction(int x, int y) {
	return x - y;
}
bool isEven(int x) {
	return x % 2 == 0;
}
bool operation(int x, bool(*f)(int)) {//��ָ�뽫������Ϊ��������,����ָ��
	//or another return way: return (*f)(x);
	return f(x);
}
int main() {
	bool answer = operation(1, isEven);
	cout << answer;
}