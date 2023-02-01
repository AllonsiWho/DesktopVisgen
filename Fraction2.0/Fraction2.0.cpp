//Fraction
#include<iostream>
using namespace std;

class Fraction
{
	int integer; //целоен число
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
		cout << "DefautConstrucor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstrucor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Construcor:\t\t" << this << endl;
	}


	Fraction(int integer , int numerator , int denominator )
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor" << endl;
	}
	Fraction(const Fraction& obj)
	{
		this->numerator = obj.numerator;
		this->integer = obj.integer;
		this->denominator = obj.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "\nDestructor:\t" << this << endl;
	}
	//			Method

	void Print()const
	{
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

	Fraction& to_improper()
	{
		int Boof = 0;
		Boof = (numerator / denominator);
		integer = integer + Boof;
		numerator = numerator % denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& to_proper()
	{
		if (integer == 0)
		{
			integer = 1;
		}
		numerator = (integer * denominator + numerator);
		integer = 0;
		return *this;
	}

	//			Operator

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;

	}





};

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int x, y, z;
	cout << "������� ����� ����� "; is >> x;
	cout << "������� ��������� "; is >> y;
	cout << "������� ����������� "; is >> z;

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
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction res;


	if (left.get_denominator() == right.get_denominator())
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
	}
	return res;
}
Fraction operator*(Fraction left, Fraction right)
{
	Fraction res;
	left.to_improper();
	right.to_improper();

	res.set_numerator(left.get_numerator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());

	
	return res;


}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*Fraction res;*/
	/*left.to_improper();
	right.to_improper();*/

	//res.set_numerator(left.get_numerator() * right.get_denominator());
	//res.set_denominator(left.get_denominator() * right.get_numerator());
	//
	//return Fraction
	//{
	//	/*left.get_numerator() * right.get_denominator(),
	//	left.get_denominator() * right.get_numerator()*/
	//}.to_proper();
	return left * right.inverted();

}

//#define constructor_chec
void main()
{
	setlocale(LC_ALL, "");
#ifdef constructor_chec



	Fraction A;
	A.Print();

	Fraction B = 5;
	B.Print();

	Fraction C(2, 3);
	C.Print();

	Fraction D(2, 3, 4);
	D.Print();

	Fraction E = D;
	E.Print();



#endif // constructor_chec

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);


}