#include <bits/stdc++.h>
#include <xercesc/util/PlatformUtils.hpp>
//#include <boost/xml/backends/xerces/reader/parser.hpp> // just for now....later will be using some macro so that it can work with boot/xml/reader.hpp
#include "parser.hpp"
#include "convert.hpp"

using namespace std;
using namespace boost::xml::xerces::reader;

int main(int , char **)
{
	try
	{
		XMLPlatformUtils::Initialize();
  	}
  	catch (const XMLException& toCatch)
  	{
  	  std::cerr << "Error during initialization! :\n" << StrX(toCatch.getMessage()) << std::endl;
  	  return 1;
  	}

	try
	{
		parser<string> parser("article.xml");
		while(parser.next())
		{
			token_base<string> const &current = parser.get_token();
			std::cout << current.depth() << ' ' << StrX(current.name()) << ' ' << '(' << current.type() << ')' << ' ' << StrX(current.value()) << std::endl;
			if(std::cout.fail())
			{
				std::cout.clear();
				std::cout << std::endl;
			}
		}
	}
  	catch (const XMLException& toCatch)
  	{
  		std::cerr << "\nAn error occurred: '" << "article.xml" << "'\n"
	      << "Exception message is: \n"
	      << StrX(toCatch.getMessage())
	      << "\n" << std::endl;
	  }

	XMLPlatformUtils::Terminate();
	return 0;
}