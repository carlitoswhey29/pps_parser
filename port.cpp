#include "port.h"

std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.m_Address << "\t" << p.m_Protocol << "\t" << p.m_Number;
	return os;
}

std::istream& operator>>(std::istream& is, Port& p)
{
	is >>  p.m_Protocol >> p.m_Address >> p.m_Number;
	return is;
}
