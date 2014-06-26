#ifndef boost_xml_unicode_gstring_hpp_
#define boost_xml_unicode_gstring_hpp_

#include <boost/xml/converter.hpp>
#include <glibmm/ustring.h>

namespace boost
{
namespace xml
{
template <>
struct converter<Glib::ustring>
{
#if USE_LIBXML2
  typedef xmlChar char_type;
#elif USE_XERCES
  typedef XMLCh char_type;
#endif

  static char_type const *in(Glib::ustring const &buffer)
  {
  #if USE_LIBXML2
    return (char_type const *)buffer.collate_key().c_str();
  #elif USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    return XMLString::transcode(buffer.collate_key().c_str());
  #endif
  }
  static Glib::ustring out(char_type const *buffer)
  {
  #if USE_LIBXML2
    return buffer ? Glib::ustring((char const *)buffer) : Glib::ustring("");
  #elif USE_XERCES
    XERCES_CPP_NAMESPACE_USE
    char const *txt = XMLString::transcode(buffer);
    return txt ? Glib::ustring(txt) : Glib::ustring("");
  #endif
  }
};

}
}


#endif
