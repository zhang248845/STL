#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
using namespace  std;

//#����
void STLDefine()
{
	vector<int> vec;	//#����vector����

	struct STU
	{
		int age;
	};
	vector<struct STU> StuVec;
	vector<int *> vec1;
	vector<string> vec2;
}

//#���캯��
void STLConstructor()
{
	vector<int> vec;
	//cout << vec[0] << endl;	//#������������

	vector<int> vec1(5);	//#Ĭ�ϳ�ʼ��Ϊ0��
	cout << vec1[1] << ' ' << vec1[4] << endl;	//#Խ�����

	vector<char> vec2(5, 'a');	//#5���ռ䶼��ʼ��Ϊ��a��
	cout << vec2[4] << endl;

	vector<int> vec3(5, 77);
	vector<int> vec4(vec3);		//#��������
	cout << vec4[1] << endl;

	vector<int>::iterator ite = vec3.begin();
	vector<int>::iterator ite1 = vec3.end();
	vector<int> vec5(ite, ite1);
	cout << vec5[1] << endl;
}

void STLCapacity()
{
	vector<int> vec;			//#�޲ι����ʼ������Ϊ0
	cout << vec.capacity() << endl;		///  5

	vector<int> vec1(5);	//#��ʼ�����ٸ�Ԫ�أ���ʼ������Ϊ���ٸ�
	cout << vec1.capacity() << endl;	///  5
	/// void push_back( const TYPE &val );
	///push_back()���ֵΪval��Ԫ�ص���ǰvectorĩβ
	vec1.push_back(1);
	cout << vec1.capacity() << endl;	///  7
	vec1.push_back(1);
	vec1.push_back(1);
	cout << vec1.capacity() << endl;	///  10
	/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	# # �������ӹ���Ϊ���Ѵ��ڿռ� + �Ѵ��ڿռ� / 2
	# #��������ʱ����������������һ�룬ȡ��
	# # vs6.0��������ʱ����������������һ����*2��
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	cout << "------------------------------------------------" << endl;

	vector<int> vec2(5);
	cout << vec2.size() << endl;		//#Ԫ�ظ��� 5
	cout << vec2.capacity() << endl;	//#������С 5
	///resize() �����ı䵱ǰvector�Ĵ�СΪsize,�Ҷ��´�����Ԫ�ظ�ֵval
	//#����С����ض�
	vec2.resize(4);
	vec2.reserve(7);	//#����������СΪ7
	cout << vec2.size() << endl;		//#Ԫ�ظ��� 5
	cout << vec2.capacity() << endl;	//#������С 7
	/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	# #Ԫ�ظ�����������������С��һ��
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	
	cout << "------------------------------------------------" << endl;

	///�����ǰvectorû�������κ�Ԫ��,��empty()��������true(1),���򷵻�false(0)
	vector<int> vec3;
	cout << vec3.empty() << endl;
}

void fun(int i)
{
	cout << i << ' ';
}
//#��
void StlVDo()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		/// void push_back( const TYPE &val );
		///push_back()���ֵΪval��Ԫ�ص���ǰvectorĩβ
		vec.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << vec.at(i) << ' ';
	}
	cout << endl;
	///back() ���ص�ǰ����ĩβԪ�ص�����
	cout << vec.back() << endl;

	cout << "------------------------------------------------" << endl;

	vector<int>::iterator ite = vec.begin();	//#���ȫ��
	for (ite; ite != vec.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;

	/*template<class InputIterator, class Function>
	Function for_each(
		InputIterator _First,	#����ͷ������
		InputIterator _Last,	#����β������
		Function _Func			#������ַ
	);*/

	for_each(vec.begin(), vec.end(), fun);
}

//#��
void StlVEnd()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	//#��һ��Ԫ��ǰ����һ��Ԫ��
	vec.insert(vec.begin() + 1, 11);
	///insert 5��
	vec.insert(vec.begin() + 1,5, 99);
	for_each(vec.begin(), vec.end(), fun);
	cout << endl;

	cout << "------------------------------------------------" << endl;

	vector<int> vec1(5, 1);
	vec.insert(vec.begin(), vec1.begin(), vec1.end());
	for_each(vec.begin(), vec.end(), fun);
}
//#ɾ
void StlVDelete()
{
	vector<int> vec;
	for (int i = 0; i < 8; i++)
	{
		vec.push_back(i);
	}
	for_each(vec.begin(), vec.end(), fun);
	
	cout << endl;

	///pop_back() ɾ��ĩβ��һ��Ԫ��
	vec.pop_back();
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;
	//#ɾ��ָ��Ԫ��
	vec.erase(vec.begin() + 1);
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;
	//#ɾ��һ��
	vec.erase(vec.begin() + 2, vec.end() - 1);
	for_each(vec.begin(), vec.end(), fun);
	cout << endl;
	vec.clear();	//#clear����ɾ������Ԫ��
	for_each(vec.begin(), vec.end(), fun);
	///assign() ɾ����ǰ��������Ԫ�ز����¸�ֵ
	
}
//#��
void StlVMod()
{
	vector<int> vec;
	for (int i = 0; i < 8; i++)
	{
		vec.push_back(i);
	}
	for_each(vec.begin(), vec.end(), fun);
	cout << endl;
	for (int i = 5, j = 0; i < 13; i++, j++)
	{
		*(vec.begin() + j) = i;
	}

	for_each(vec.begin(), vec.end(), fun);
}
//#����swap��������鿴String
///�Ƚ� > < >= <= == !=	����false��0����true��1��

void StlVAlgorithm()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(0);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(99);
	vec.push_back(12);
	vec.push_back(18);
	vec.push_back(1365);
	//#����Ĭ�ϴ�С����
	//#greater������С����  Header:<functional>	
	sort(vec.begin(), vec.end(),greater<int>());
	for_each(vec.begin(), vec.end(), fun);

	cout << "------------------------------------------------" << endl;
	cout << "------------------------------------------------" << endl;
	
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(6);
	vec1.push_back(7);
	vec1.push_back(8);
	for_each(vec1.begin(), vec1.end(), fun);
	cout << endl;
	///  random_shuffle  ������ң�ֻ����һ��
	srand((unsigned int)time(0));
	random_shuffle(vec1.begin(), vec1.end());
	for_each(vec1.begin(), vec1.end(), fun);

}


int main()
{
	//STLConstructor();

	//STLCapacity();
	
	//StlVDo();

	//StlVEnd();

	//StlVDelete();

	//StlVMod();

	StlVAlgorithm();



	system("PAUSE");
	return 0;
}
