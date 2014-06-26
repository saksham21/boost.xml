#ifndef boost_xml_unicode_qstring_hpp_
#define boost_xml_unicode_qstring_hpp_

#include <boost/xml/converter.hpp>
#include <QtCore/qstring.h>
#include <QtCore/qbytearray.h>
#include <ostream>

namespace boost
{
namespace xml
{
template <>
struct converter<QString>
{
#if USE_LIBXML2
  typedef xmlChar char_type;
#elif USE_XERCES
  typedef XMLCh char_type;
#endif

  static char_type const *in(QString const &buffer)
  {
  #if USE_LIBXML2
    QByteArray array=buffer.toLocal8Bit();
    return reinterpret_cast<char_type const *>(array.data());
  #elif USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    return buffer.utf16();
  #endif
  }
  static QString out(char_type const *buffer)
  {
  #if USE_LIBXML2
    return buffer ? QString::fromLocal8Bit(reinterpret_cast<char const*>(buffer)) : QString("");
  #elif USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    return QString::fromUtf16(buffer);
  #endif
  }
};

}
}

// Just a temporary helper to get examples working
std::ostream &operator<<(std::ostream &os, QString const &str)
{
  return os << str.toLocal8Bit().constData();
}

#endif
