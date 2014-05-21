#include <bits/stdc++.h>
#include <boost/xml/convert.hpp>

using namespace std;
using namespace boost::xml;

namespace boost
{
namespace xml
{
template <typename S> struct convert;
template<>
struct convert<string>
{
  static xmlChar const *in(string const &v)
  {
  	return (xmlChar *)v.c_str();
  }
  static string out(xmlChar const *v)
  {
  	return v ? string((char const *)v) : string("");
  }
};
}
}