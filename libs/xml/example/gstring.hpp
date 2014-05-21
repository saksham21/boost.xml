#include <boost/xml/dom.hpp>
#include <glibmm/ustring.h>

using namespace Glib;

namespace boost
{
namespace xml
{
namespace dom
{
template <>
struct converter<ustring>
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

typedef boost::xml::dom::node_ptr<boost::xml::dom::node<ustring> > node_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::node<ustring> const> const_node_ptr;
typedef boost::xml::dom::element<ustring> element;
typedef boost::xml::dom::node_ptr<element> element_ptr;
typedef boost::xml::dom::node_ptr<element const> const_element_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<ustring> > attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<ustring> const> const_attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<ustring> > text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<ustring> const> const_text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<ustring> > pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<ustring> const> const_pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<ustring> > comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<ustring> const> const_comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<ustring> > cdata_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<ustring> const> const_cdata_ptr;
typedef std::auto_ptr<boost::xml::dom::document<ustring> > document_ptr;
typedef boost::xml::dom::dtd_ptr<ustring> dtd_ptr;
typedef boost::xml::dom::node_set<ustring> node_set;
typedef boost::xml::dom::xpath<ustring> xpath;
