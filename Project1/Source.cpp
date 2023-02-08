#include<iostream>
using namespace std;

class String
{
	int size;  ///размер строки
	char* str; // адрес строки в динамической памяти
public:
	int get_seise()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	//   Constuctors:
	 String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str);
		this->str = new char[size+1] {};
				
		strcpy_s(this->str, size+1, str);


	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//       Type-cast-operators:
	


	//  Methods:
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};
String operator +(const String& obj1, const String& obj2)
{
	int size = (strlen(obj1.get_str()) + strlen(obj2.get_str()));
	char* res = new char[size+1];
	strcpy_s(res, size, obj1.get_str());
	strcat_s(res, size+1, obj2.get_str());
	return res;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << "Obj-  " << obj.get_str();
}


void main()
{

	setlocale(LC_ALL, "");

	String str1 = "Hello";
	cout << str1 << endl;
	
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
}