#include <boost/xml/reader.hpp>
#include <bits/stdc++.h>
#include <glibmm/ustring.h>

using namespace std;
using namespace Glib;
using namespace boost::xml::reader;

namespace boost
{
namespace xml
{
namespace reader
{
template <typename S> struct convert;
template <>
struct convert<ustring>
{
  static xmlChar const *in(ustring const &v)
  {
    const char *str1=v.collate_key().c_str();
    return (xmlChar *)str1;
  }
  static ustring const out(xmlChar const *v)
  {
    if(v)
    {
      const char* str1=(const char*)v;
      ustring str2=ustring(str1);
      return str2;
    }
    else
    {
      ustring str2="";
      return str2;
    }
  }
};
}
}
}