#include <iostream> 
#include <vector>
#include<algorithm>
using namespace std;

/*||��ߴ��������ԣ��������ݺ�����ָ��*/
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
void testisEven() {
	bool answer = operation(1, isEven);
	cout << answer;
}
/*��ߴ��������ԣ��������ݺ�����ָ��||*/

/*||֪ʶ��18051501��Ӧ��STL�������������ϰ�ߣ�����C++�淶��ʹ������չ��ͷ�ļ������� #include<vector> ������ #include<vector.h>||*/

/*||�º�����ѧϰ*/
template<typename T>
class print {
public:
	void operator()(const T& e) {//����operator(),���Ա���Ϊ�º�������Ϊ�÷�����
		cout << e << ' ';
	}
};
//template<typename T>
//class plus {//����������operator(),����plus����Ϊ�º���
//public:
//	T operator()(const T& x, const T& e) {//����operator(),���Ա���Ϊ�º�������Ϊ�÷�����
//		return x+e;
//	}
//};
void testPrint() {
	int ia[6] = { 0,1,2,3,4,5 };
	vector<int> iv(ia, ia + 6);
	//print<int>()��һ����ʱ���󣬲��Ƿº���
	for_each(iv.begin(), iv.end(), print<int>());
	cout << endl;
	plus<int> plusobj;
	//����ʹ�÷º���������ʹ�ú���һ��
	cout << plusobj(3, 5) << endl;
	//�������Ȳ�����ʱ���󣨵�һ��С���ţ�������֮���ڶ���С���ţ�
	cout << plus<int>()(30, 50) << endl;
}

//for_eachʵ�ַ���
//template <class InputIterator,class Fuction>
//Function for_each(InputIterator first, InputIterator last, Fuction f) {
//	for (; first != last; ++first)
//		f(*first);
//	return f;
//}

/*�º�����ѧϰ||*/

/*||��̬�滮ѧϰ
https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
||*/


int main() {
	//testisEven();/*��ߴ��������ԣ��������ݺ�����ָ��*/
	testPrint();/*�º�����ѧϰ*/
}