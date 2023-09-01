#ifndef __NODE_H__
#define __NODE_H__

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include "port.h"

class Node
{
private:
	/// Find or Insert a Port by port_number and protocol
	/// @param name The ip_addtress of the port to find or insert
	/// @returns The reference to the port in the map

  std::string m_Name;
	std::map<std::string, Port> m_Ports;

  Port& FindOrInsertPort(const std::string& ip);
public:
	Node()
	{
	}


	void LoadPorts(std::istream& is);
	void LoadNodes(std::istream& is);
	void Report(std::ostream& os);


	friend std::ostream& operator<<(std::ostream& os, const Node& n);
	friend std::istream& operator>>(std::istream& is, Node& n);
};

#endif // __Node_H__

