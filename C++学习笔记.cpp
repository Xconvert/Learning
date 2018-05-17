#include <iostream> 
#include <vector>
#include<algorithm>
#include<string>
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

/*||switch�÷�*/
void testSwith(int a) {
	switch (a){
	case 1: {
		break;
	}
	default:
		break;
	}
}
/*switch�÷�||*/

/*|string to int/char to int*/
void teststoi() {
	string a("211");
	char b[10] = "211";
	int t;
	t = stoi(a);//��ͷ�ļ�string����
	cout << t << endl;
	t = atoi(b);//��ͷ�ļ�stdlib.h����
	cout << t << endl;
}
/*
1��itoa
�� ��:��һ����ת��Ϊ�ַ���
�� ��:char *itoa(int value, char *string, int radix);
��ϸ����:itoa��Ӣ��integer to array(��int������ת��Ϊһ���ַ���,����ֵ����������string��)����д.
����:
value: ��ת����������
radix: �ǻ�������˼,���Ƚ�valueת��Ϊradix���Ƶ�������Χ����2-36������10��ʾ10���ƣ�16��ʾ16���ơ�
* string: ����ת����õ����ַ�����
����ֵ:
char * : ָ�����ɵ��ַ����� ͬ*string��
��ע:�ú�����ͷ�ļ���"stdlib.h"

2��ltoa
�� ��:��һ������ת��Ϊ�ַ���
�� ��:char *ltoa(long value, char *string, int radix);

3��ultoa
�� ��:��һ�޷��ų�����ת��Ϊ�ַ���
�� ��:char *ultoa(unsigned long value, char *string, int radix);

4��gcvt
�� ��:�Ѹ�������ת��Ϊ�ַ�����ȡ��������
�� ��:char *gcvt(double value, int ndigit, char *buf);
��ϸ����:gcvt()����������numberת����ASCII���ַ���������ndigits��ʾ��ʾ��λ����
gcvt()��ecvt()��fcvt()��ͬ�ĵط����ڣ�gcvt()��ת������ַ�������С������������š���ת���ɹ���ת������ַ�������ڲ���bufָ����ָ�Ŀռ䡣
�� ��:
value:��ת���ĸ�������
ndigit:�洢����Ч����λ����
*buf:����Ĵ洢λ�á�

5��ecvt
�� ��:��˫���ȸ�������ת��Ϊ�ַ�����ת������в�����ʮ����С����
�� ��:char *ecvt(double value, int ndigit, int *decpt, int *sign);
��ϸ����:ecvt������һ��˫���ȸ�����ת����һ���ַ�����value������Ҫת���ĸ�������
��������洢���ndigit������ֵ��Ϊһ���ַ���,�����һ�������ַ�('\0'),���value�е����ָ�������ndigit,��λ���ֱ����롣
�������ndigit������,���ַ�����0��䡣��������λ��Ч���֡�

ֻ�����ֲŴ洢�ڸ��ַ�����,С����λ�ú�value�����ڵ���֮���decpt��sign��ȡ��
decpt����ָ������С����λ�õ�����ֵ,���ǴӸ��ַ����Ŀ�ͷλ�ü���ġ�0����ָ��С�����ڵ�һ�����ֵ���ߡ�
sign����ָ��һ��ָ��ת�������ķ��ŵ����������������Ϊ0,�����Ϊ����,����Ϊ������

�� ��:
value:��ת����˫���ȸ�������
ndigit:�洢����Ч����λ����
*decpt:�洢��С����λ�á�
*sign:ת�������ķ��š�

6��fcvt
�� ��:ָ��λ��Ϊת�����ȣ�����ͬecvt
�� ��:char *fcvt(double value, int ndigit, int *decpt, int *sign);
��ϸ����:����ת����ʵ��ֵ������С��λ����ndigit������
�������ndigit������,����䡣��������λС������

*/
/*string to int/char to int|*/

/*||struct��Ĭ�Ϲ��캯����string�ĳ�ʼ��*/
struct error {//struct����Ĭ����public��classĬ����private
	string er;
	int rowNum;
	//error():er(""),rowNum(0){}//���ߣ�error():rowNum(0){}
	/*
	  1���˴���string��Ĭ��Ϊ""�ģ��������ǲ�����NULL����ʼ�������ᱨ��
	  2��Ĭ�Ϲ��캯��ֻ����һ�������������Ĭ�Ϲ��캯���ȽϺ�
	*/
	error(string error = "", int n = 0) :er(error), rowNum(n) {}
};
void testStruct() {
	struct error e;
	cout << e.er << endl;
}
/*struct��Ĭ�Ϲ��캯����string�ĳ�ʼ��||*/

int main() {
	//testisEven();/*��ߴ��������ԣ��������ݺ�����ָ��*/
	//testPrint();/*�º�����ѧϰ*/
	testStruct();/*struct��Ĭ�Ϲ��캯����string�ĳ�ʼ��*/

}
