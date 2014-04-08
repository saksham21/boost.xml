#include <bits/stdc++.h>
#include <boost/xml/reader.hpp>

using namespace std;
using namespace boost::xml::reader;

namespace boost
{
namespace xml
{
namespace reader
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
}