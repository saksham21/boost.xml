#include <bits/stdc++.h>
#include <QtCore/qstring.h>
#include <QtCore/qbytearray.h>
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
template <>
struct convert<QString>
{
  static xmlChar const *in(QString const &v)
  {
    QByteArray arr1=v.toLocal8Bit();
    const char *arr2=arr1.data();
    return (xmlChar *)arr2;
  }
  static QString const out(xmlChar const *v)
  {
    const char *arr1=(char *)v;
    QString arr2 = QString::fromLocal8Bit(arr1);
    return arr2;
  }
};
}
}
}