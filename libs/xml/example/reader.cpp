// Copyright 2007 Stefan Seefeld.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xml/reader.hpp>
#include <bits/stdc++.h>

using namespace boost::xml::reader;
using namespace std;

int main(int, char **)
{
  try
  {
    parser<string> parser("article.xml");
    while (parser.next())
    {
      token_base<string> const &current = parser.get_token();
      cout << current.depth() << ' ' << current.name() << ' ' << current.value() << ' ' << '(' << current.type() << ')' << endl;
    }
  }
  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
