#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
using namespace  std;

//#定义
void STLDefine()
{
	vector<int> vec;	//#定义vector对象

	struct STU
	{
		int age;
	};
	vector<struct STU> StuVec;
	vector<int *> vec1;
	vector<string> vec2;
}

//#构造函数
void STLConstructor()
{
	vector<int> vec;
	//cout << vec[0] << endl;	//#空容器，崩溃

	vector<int> vec1(5);	//#默认初始化为0；
	cout << vec1[1] << ' ' << vec1[4] << endl;	//#越界崩溃

	vector<char> vec2(5, 'a');	//#5个空间都初始化为’a‘
	cout << vec2[4] << endl;

	vector<int> vec3(5, 77);
	vector<int> vec4(vec3);		//#拷贝构造
	cout << vec4[1] << endl;

	vector<int>::iterator ite = vec3.begin();
	vector<int>::iterator ite1 = vec3.end();
	vector<int> vec5(ite, ite1);
	cout << vec5[1] << endl;
}

void STLCapacity()
{
	vector<int> vec;			//#无参构造初始化容量为0
	cout << vec.capacity() << endl;		///  5

	vector<int> vec1(5);	//#初始化多少个元素，初始容量就为多少个
	cout << vec1.capacity() << endl;	///  5
	/// void push_back( const TYPE &val );
	///push_back()添加值为val的元素到当前vector末尾
	vec1.push_back(1);
	cout << vec1.capacity() << endl;	///  7
	vec1.push_back(1);
	vec1.push_back(1);
	cout << vec1.capacity() << endl;	///  10
	/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	# # 容量增加规律为：已存在空间 + 已存在空间 / 2
	# #容量不够时，增加现有容量的一半，取整
	# # vs6.0容量不够时，增加现有容量的一倍（*2）
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	cout << "------------------------------------------------" << endl;

	vector<int> vec2(5);
	cout << vec2.size() << endl;		//#元素个数 5
	cout << vec2.capacity() << endl;	//#容量大小 5
	///resize() 函数改变当前vector的大小为size,且对新创建的元素赋值val
	//#若变小了则截断
	vec2.resize(4);
	vec2.reserve(7);	//#更改容量大小为7
	cout << vec2.size() << endl;		//#元素个数 5
	cout << vec2.capacity() << endl;	//#容量大小 7
	/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	# #元素个数和容器的容量大小不一样
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	
	cout << "------------------------------------------------" << endl;

	///如果当前vector没有容纳任何元素,则empty()函数返回true(1),否则返回false(0)
	vector<int> vec3;
	cout << vec3.empty() << endl;
}

void fun(int i)
{
	cout << i << ' ';
}
//#查
void StlVDo()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		/// void push_back( const TYPE &val );
		///push_back()添加值为val的元素到当前vector末尾
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
	///back() 返回当前容器末尾元素的引用
	cout << vec.back() << endl;

	cout << "------------------------------------------------" << endl;

	vector<int>::iterator ite = vec.begin();	//#输出全部
	for (ite; ite != vec.end(); ite++)
	{
		cout << *ite << ' ';
	}
	cout << endl;

	/*template<class InputIterator, class Function>
	Function for_each(
		InputIterator _First,	#容器头迭代器
		InputIterator _Last,	#容器尾迭代器
		Function _Func			#函数地址
	);*/

	for_each(vec.begin(), vec.end(), fun);
}

//#增
void StlVEnd()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	//#在一个元素前插入一个元素
	vec.insert(vec.begin() + 1, 11);
	///insert 5个
	vec.insert(vec.begin() + 1,5, 99);
	for_each(vec.begin(), vec.end(), fun);
	cout << endl;

	cout << "------------------------------------------------" << endl;

	vector<int> vec1(5, 1);
	vec.insert(vec.begin(), vec1.begin(), vec1.end());
	for_each(vec.begin(), vec.end(), fun);
}
//#删
void StlVDelete()
{
	vector<int> vec;
	for (int i = 0; i < 8; i++)
	{
		vec.push_back(i);
	}
	for_each(vec.begin(), vec.end(), fun);
	
	cout << endl;

	///pop_back() 删除末尾的一个元素
	vec.pop_back();
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;
	//#删除指定元素
	vec.erase(vec.begin() + 1);
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;
	//#删除一段
	vec.erase(vec.begin() + 2, vec.end() - 1);
	for_each(vec.begin(), vec.end(), fun);
	cout << endl;
	vec.clear();	//#clear（）删除所有元素
	for_each(vec.begin(), vec.end(), fun);
	///assign() 删除当前对象所有元素并重新赋值
	
}
//#改
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
//#交换swap（）详情查看String
///比较 > < >= <= == !=	返回false（0）和true（1）

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
	//#排序，默认从小到大
	//#greater（）从小到大  Header:<functional>	
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
	///  random_shuffle  随机打乱，只打乱一次
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
