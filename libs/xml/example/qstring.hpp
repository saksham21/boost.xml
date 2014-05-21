#include <boost/xml/dom.hpp>
#include <QtCore/qstring.h>
#include <QtCore/qbytearray.h>

namespace boost
{
namespace xml
{
namespace dom
{
template <>
struct converter<QString>
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

typedef boost::xml::dom::node_ptr<boost::xml::dom::node<QString> > node_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::node<QString> const> const_node_ptr;
typedef boost::xml::dom::element<QString> element;
typedef boost::xml::dom::node_ptr<element> element_ptr;
typedef boost::xml::dom::node_ptr<element const> const_element_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<QString> > attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<QString> const> const_attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<QString> > text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<QString> const> const_text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<QString> > pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<QString> const> const_pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<QString> > comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<QString> const> const_comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<QString> > cdata_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<QString> const> const_cdata_ptr;
typedef std::auto_ptr<boost::xml::dom::document<QString> > document_ptr;
typedef boost::xml::dom::dtd_ptr<QString> dtd_ptr;
typedef boost::xml::dom::node_set<QString> node_set;
typedef boost::xml::dom::xpath<QString> xpath;
