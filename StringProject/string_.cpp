#include "string_.h"




string_::string_()
{
	this->str = nullptr;
	this->length = 0;
}

string_::string_(int length)
{
	this->str = new char[length + 1];
	str[length] = '\0';
	this->length = length;
}
//конструктор, создающий строку на основе str
string_::string_(const char * str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
	this->length = strlen(str);
}


string_::string_(const string_ & obj)
{
	this->length = obj.length;

	if (obj.length == 0) {
		this->str = nullptr;
		return;
	}

	this->str = new char[obj.length + 1];
	strcpy_s(this->str, obj.length + 1, obj.str);

}

string_ & string_::operator=(const string_ & obj)
{
	if (this == &obj) return *this;
	if (obj.length == 0)
	{
		this->~string_();
		return *this;
	}
	if (obj.length != this->length)
	{
		this->~string_();
		this->str = new char[obj.length+1];
		this->length = obj.length;
	}
	strcpy_s(this->str, obj.length + 1, obj.str);
	return *this;

}

void string_::print()
{
	cout << this->str;
}

void string_::input()
{
	char tmp[1200];
	cin.getline(tmp, 1200);
	this->~string_();
	this->str = new char[strlen(tmp) + 1];
	strcpy_s(this->str, strlen(tmp) + 1, tmp);
	this->length = strlen(tmp);
}

void string_::insert(int position, const char * str)
{
	char *tmp;
	int k = position;

	if (str == nullptr || position < 0 || position > this->length) return;

	if (this->str == nullptr && position == 0) {
		this->setString(str);
		return;
	}

	tmp = new char[this->length + strlen(str) + 1];
	int newLength = length + strlen(str);
	for (int i = 0, j = 0; i < newLength + 1; i++)
	{
		if (i < position) tmp[i] = this->str[i];
		else
			if (i >= position && j < strlen(str))
			{
				tmp[i] = str[j];
				j++;
			}
			else
			{
				tmp[i] = this->str[k];
				k++;
			}

	}
	this->~string_();

	this->str = tmp;

	this->length = newLength;

	this->str[length] = '\0';


}



int string_::getLength()
{
	return this->length;
}

const char * string_::getString()
{
	return this->str;
}


void string_::setString(const char * str)
{
	this->~string_();
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
	this->length = strlen(str);
}

string_::~string_()
{
	if (this->str != nullptr)
		delete[] str;
	this->str = nullptr;
	this->length = 0;
}

void string_::clear()
{
	this->~string_();
}

ostream & operator<<(ostream & os, string_ &s)
{
	os << s.getString();
	return os;
}

istream & operator>>(istream & is, string_ & s)
{
	/*char *str;
	is >> str;
	s.setString(str);*/
	s.input();	
	return is;
}
