#include<iostream>
using namespace std;
class String;
String operator +(const String& left, const String& right);

class String
{
	int size;  ///размер строки В байтах
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
	char* get_str()
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
		this->size = strlen(str) + 1;//только так для работы с другими конструкторами
		this->str = new char[size] {};

		//strcpy_s(this->str, size+1, str);
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t";

	}
	String(String&& other)noexcept// гарантированна не бросает исключение
	{
		//Shallow copy поверхностное копирование
		this->size = other.size;
		this->str = other.str;//Shallow copy
		other.size = 0;
		other.str = nullptr;// nullptr -указатель на 0
		cout << "MoveConstructor:" << this << endl;
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
	//      operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;// защита от присваевания самого себя 
		delete[]this->str;

		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyASsssigment:\t" << this << endl;
		return *this;
	}
	const char& operator[](int i)const
	{

		return str[i];
	}
	char& operator[](int i)
	{

		return str[i];
	}
	String& operator+=(String obj)
	{
		return *this = *this + obj;


		/*String cat(this->get_seise() + obj.get_seise() - 1);
		for (int i = 0; i < this->get_seise(); i++)
		{
			cat[i] = this->get_str()[i];
		}
		for (int i = 0; i < obj.get_seise(); i++)
		{
			cat[i + this->get_seise() - 1] = obj[i];
		}

		return *this = cat;*/
	}
	String& operator =(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
};
String operator +(const String& left, const String& right)
{
	String cat(left.get_seise() + right.get_seise() - 1);
	/*int size = (strlen(left.get_str()) + strlen(right.get_str()));
	char* res = new char[size+1];
	strcpy_s(res, size, left.get_str());
	strcat_s(res, size+1, right.get_str());*/

	for (int i = 0; i < left.get_seise(); i++)
	{
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_seise(); i++)
	{
		cat[i + left.get_seise() - 1] = right[i];
	}

	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	static int a = 1;
	return os << "Obj-" << a++ << "\t" << obj.get_str();
}

//#define BASE_CHECK
void main()
{

	setlocale(LC_ALL, "");
#ifdef BASE_CHECK



	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;
	String str3;
	str3 = str1 + str2;//Move constructor
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
	

	String str4 = str3;//Copy constructor
#endif // BASE_CHECK

	String str4();//Здесь не вызываеться никакой конструктор, поотому что Не создаеться объект.
	// Здесь объявляеться функция str4(), которая не принимает никаких параметров,
	//и возвращает значение типа String.
	//str4- это Не объект, это функция а для функции нельзя вызвать метод
	//Если мы хотим явно вызвать конструктор по умолчанию, то это можно сделать так
	String str5{}; //Явный вызов конструктор по умолчанию.
	str5.print();
	String str6{22};
	str6.print();
	String str7{ "World" };
	str7.print();
	String str8{ str7 };


}