 #include<iostream>
using namespace std;

int main()
{
	//string str;		//��������
	//const char* pStr = str.c_str();

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# # string( size_type length, char ch);
# # ��ֵlength��ch
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	string str1(5, 'a');
	cout << str1 << endl;
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# #  string( const char *str );
# #  �� str ��ֵ�� ����
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	string str2("yyyuuuasdasd");
	cout << str2 << endl;
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# #  string( const char *str, size_type length );
# #  ��str��ǰlength����ֵ�������Դ�'\0'
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	string str3("abcdefg", 3);
	cout << str3.c_str() << endl;
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# #  string( string &str, size_type index, size_type length );
# #  ��&str���±�Ϊindex���Ϊ��ֵ��ʼ�㣬��ֵ���󣨰�����㣩
# #  length���ַ����Դ�'\0'
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	string str4(str2, 2, 4);
	cout << str4.c_str() << endl;
/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# # ������str2�е��ַ���ֵ��str5������'\0'
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	string str5(str2);
	cout << str5.c_str() << endl;



/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# #�����������
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
	string str6("ancdefg");
	cout << str6 << endl;

	string str7("abc");
	cout << str7 << endl;
	cin >> str7;
	cout << str7 << endl;




	system("PAUSE");
	return 0;
}