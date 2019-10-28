#include "data.h"

Data::Data()
: m_key(""), m_name(""), m_age(-1)
{

}

Data::Data(string key, string name, int age)
: m_key(key), m_name(name), m_age(age)
{

}

void Data::print(ostream& os) const
{
	os << m_key << " " << m_name << " " << m_age << endl;
}

// 与 1 搭配的第二种可行方式，首选方式
//ostream& operator<< (ostream& os, const Data& data)
//{
//	os << data.m_key << " " << data.m_name << " " << data.m_age << endl;
//	return os;
//}