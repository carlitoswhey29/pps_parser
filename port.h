#ifndef __PORT_H__
#define __PORT_H__

#include <iostream>
#include <string>

class Port
{
private:
  std::string m_Address;
	std::string m_Protocol;
	int m_Number;

public:
	Port(const std::string& address ="", std::string protocol = "BLANK", int num = 0) : 
	m_Address(address), m_Protocol(protocol), m_Number(num)
	{
	}

	std::string Address() const
	{
		return m_Address;
	}

	void Address(const std::string& ip_add)
	{
		m_Address = ip_add;
	}


	std::string Protocol() const
	{
		return m_Protocol;
	}

	void Protocol(const std::string& p)
	{
		m_Protocol = p;
	}

	int Number() const
	{
		return m_Number;
	}

	void Number(int num)
	{
		m_Number = num;
	}


	friend std::ostream& operator<<(std::ostream& os, const Port& p);
	friend std::istream& operator>>(std::istream& is, Port& p);
};

#endif // __Port_H__

