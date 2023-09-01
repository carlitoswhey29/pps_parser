#include "node.h"


Port& Node::FindOrInsertPort(const std::string& ip)
{
	/// Search the m_Ports map to find the desired name
	/// If the Port is found, return a reference to the element
	/// If the Port is not found, create a new Port, 
  /// insert it into the map and return a reference to the
  /// newly inserted element.

    Port new_Port(ip);
    
    if(m_Ports.empty()) {                   
        m_Ports.emplace(ip, new_Port);
        return m_Ports.at(ip);
    }

    std::map <std::string, Port>::const_iterator found_Port;
    found_Port = m_Ports.find(ip);
    
   
    if (found_Port != m_Ports.end()) {       // if Port has been found return reference
            return m_Ports.at(ip);          // return reference to the element;
    }else {
        m_Ports.emplace(ip, new_Port);
        return m_Ports.at(ip);
    }
}


//all ports in that node
void Node::LoadPorts(std::istream& is)
{
    std::istream_iterator<Port> is_it(is);
    std::istream_iterator<Port> is_end; 
    
    std::transform(is_it, is_end, std::inserter(m_Ports, end(m_Ports)), 
    [](const Port& p) -> std::pair<std::string, Port>
    {
        return {p.Address(), p};
    });
}


void Node::LoadNodes(std::istream& is)
{
	/// Load the games and update the Port ratings as you go
    Port src, dest;
    std::string temp = "";
    std::string src_ip, dest_ip;
    int src_port, dest_port;

    // Use While loop, to identify Ports and read game results
    while (is >> src_ip >> src_port >> dest_ip >> dest_port) 
    {
        src = FindOrInsertPort(src_ip);
        dest = FindOrInsertPort(dest_ip);

    }
   
}

void Node::Report(std::ostream& os)
{
	/// Output the final Port ratings following all of the given games 
	/// without using a custom loop
    
    std::ostream_iterator<Port> os_it(os, "\n");

    std::transform(begin(m_Ports), end(m_Ports), os_it,
        [&](const std::pair<std::string, Port>& p)-> Port
        {
            return p.second;
        });

    
}
