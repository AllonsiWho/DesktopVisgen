
#include<iostream>
#include <conio.h>

#include<Windows.h>

using namespace std;

enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
class Fraction;
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(const Fraction& left, const Fraction& right);
class Fraction
{
	int integer; //целое число
	int numerator;//числитель
	int denominator;//знаминатель
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//			Constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DefautConstructor\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "1ArgConstructor\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);

	}
	Fraction(const Fraction& obj)
	{
		this->numerator = obj.numerator;
		this->integer = obj.integer;
		this->denominator = obj.denominator;
		//cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		//cout << "\nDestructor:\t" << this << endl;
	}
	// Type-cast-operators:
	explicit operator int()const
	{
		return Fraction(*this).to_proper().integer;
	}


	//			Method

	void Print()const
	{
		/*static int a = 0;
		if (integer)
		{
			SetCursor(1, 1+a);
			cout << integer;
		}
		if (numerator)
		{
			SetCursor(3, 0+a);
			cout << numerator;
			SetCursor(3, 1+a);
			cout << "-";
			SetCursor(3, 2+a);
			cout << denominator;
			SetCursor(0, 3+a);
		}

		a = a + 5;*/
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

	Fraction& to_proper()
	{
		int Boof = 0;
		Boof = (numerator / denominator);
		integer = integer + Boof;
		numerator = fabs(numerator % denominator);
		return *this;
	}
	Fraction& to_improper()
	{
		numerator = (integer * denominator + numerator);
		integer = 0;
		return *this;
	}
	Fraction indverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& reduse()
	{
		int more, less, rest = 0;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);

		int GCD = more;//GCD-Greates(Наибольший делитель)
		numerator /= GCD;
		denominator /= GCD;
		return*this;
	}


	//			Operator

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	Fraction& operator=(const Fraction obj)
	{
		this->integer = obj.integer;
		this->numerator = obj.numerator;
		this->denominator = obj.denominator;
		return *this;
	}
	Fraction& operator+=(Fraction obj)
	{
		return *this = *this + obj;
		/*this->integer = this->integer + obj.integer;
		if (this->denominator == obj.denominator)
		{
			this->numerator = this->numerator + obj.numerator;
		}
		else
		{
			this->numerator = (this->numerator * obj.denominator) + (obj.numerator * this->denominator);
			this->denominator = (this->denominator * obj.denominator);

		}

		return this->to_proper();*/
	}
	Fraction& operator -=(Fraction obj)
	{
		return *this = *this - obj;
		/*this->to_improper();
		obj.to_improper();
		if (this->denominator == obj.denominator)
		{
			this->numerator = (this->numerator - obj.numerator);
		}
		else
		{
			this->numerator = (this->numerator * obj.denominator) - (obj.numerator * this->denominator);
			this->denominator = this->denominator * obj.denominator;
		}
		this->to_proper();
		return *this;*/

	}
	Fraction& operator *=(Fraction obj)
	{
		return *this = *this * obj;

	}
	Fraction& operator /=(Fraction obj)
	{
		return *this = *this / obj;
		/**this *= obj.indverted();
		return this->to_proper();*/

	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

};

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int x, y, z;

	is >> x >> y >> z;
	obj(x, y, z);
	return is;
}
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_integer(left.get_integer() + right.get_integer());
	if (left.get_denominator() == right.get_denominator())
	{
		res.set_numerator(left.get_numerator() + right.get_numerator());
		res.set_denominator(left.get_denominator());
	}
	else
	{
		res.set_numerator((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()));
		res.set_denominator(left.get_denominator() * right.get_denominator());

	}
	return res;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;

	if (left.get_denominator() == right.get_denominator())
	{
		if (left.get_numerator() > right.get_numerator())
		{
			res.set_numerator(left.get_numerator() - right.get_numerator());

		}

		res.set_denominator(left.get_denominator());
	}
	else
	{
		res.set_numerator((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()));
		res.set_denominator(left.get_denominator() * right.get_denominator());
	}


	/*if (left.get_denominator() == right.get_denominator())
	{
		if (left.get_numerator() > right.get_numerator())
		{
			res.set_numerator(left.get_numerator() - right.get_numerator());

		}
		else
		{
			res.set_numerator(right.get_numerator() - left.get_numerator());
		}
		res.set_denominator(left.get_denominator());
	}
	else
	{
		if (left.get_numerator() > right.get_numerator())
		{
			res.set_numerator((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()));

		}
		else
		{
			res.set_numerator((right.get_numerator() * left.get_denominator()) - (left.get_numerator() * right.get_denominator()));
		}
		res.set_denominator(left.get_denominator() * right.get_denominator());
	}
	if (left.get_integer() > right.get_integer())
	{
		res.set_integer(left.get_integer() - right.get_integer());
	}
	else
	{
		res.set_integer(right.get_integer() - left.get_integer());
	}*/
	return res.to_proper();

}
Fraction operator*(Fraction left, Fraction right)
{

	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduse();


}
Fraction operator/(Fraction left, Fraction right)
{

	return left * right.indverted();

}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";

}
/////////////////////////////////////////////////////////////////////////////////////////
/////////                            comparision operators                      /////////
/////////////////////////////////////////////////////////////////////////////////////////
bool operator >(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	//if (left.get_integer() > right.get_integer())
	//{
	//	return true;
	//}
	//else return false;

	return left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();

}
bool operator <(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();



	return left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator ==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*if (left.get_integer() == right.get_integer())
	{
		return true;
	}
	else return false;*/


	return left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();


}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left == right);// Не равно
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);//Больше или равно это не меньше 
}
bool operator <=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
	//return!(left > right);
}
//#define ARIFMETICAL_OPERAND_CHEK
//#define COMPERESSON_OPERATOR
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS

void main()
{
	setlocale(LC_ALL, "");

	//Fraction A(2, 3, 4);
#ifdef ARIFMETICAL_OPERAND_CHEK



	A.Print();
	//cout << "Введите простую дробь ";cin >> obj;


	/*A.Print();
	cout << "------------" << endl;
	A.to_proper();
	A.Print();
	cout << "------------" << endl;
	A.to_improper();
	A.Print();
	cout << "------------" << endl;*/
	Fraction B(3, 4, 5);
	A *= B;
	A /= B;
	cout << "/" << endl;
	A.Print();
	B.Print();
	cout << A;
#endif // ARIFMETICAL_OPERAND_CHEK

#ifdef COMPERESSON_OPERATOR
cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
#endif // COMPERESSON_OPERATOR
#ifdef TYPE_CONVERSION_BASICS



int a = 2;//No conversion
double b = 3;//Conversion from less to more
int c = b;//Conversion from more to less with no date loss
int d = 4.5;//Conversion from more to less with data loss
#endif // TYPE_CONVERSION_BASICS
#ifdef CONVERSION_FROM_OTHER_TO_CLASS



Fraction A = (Fraction)5;//Conversin from other to cllass Конструктором с 1 аргументам 
A.Print();
Fraction B;
B = Fraction (8);//Conversion from other to class Оператором присваеванием 
//explicit
#endif // 

Fraction A(2, 3, 4);
A.Print();
int a = (int)A;
cout << a << endl;
}