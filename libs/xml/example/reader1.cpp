// Copyright 2007 Stefan Seefeld.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xml/reader.hpp>

using namespace boost::xml::reader;
using namespace std;

int main(int, char **)
{
  try
  {
    parser<QString> parser("article.xml");
    while (parser.next())
    {
      token_base<QString> const &current = parser.get_token();
      std::cout << current.depth() << ' ' << current.name() << ' ' << current.value() << ' '
                << '(' << current.type() << ')' << std::endl;
    }
  }
  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
