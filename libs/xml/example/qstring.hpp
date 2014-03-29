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
  static xmlChar *in(QString const &buffer)
  {
  	QByteArray arr1=buffer.toLocal8Bit();
  	// in place of toLocal8bit() we can also use Qstring::toUtf8()
  	const char *arr2=arr1.data();
  	return (xmlChar *)arr2;
  }
  static QString out(xmlChar const *buffer)
  {
  	const char *arr1=(char *)buffer;
  	QString arr2 = QString::fromLocal8Bit(arr1);
  	return arr2;
  	// in place of Qstring::fromLocal8Bit() we can also use Qstring::fromUtf8()  	 	  
  }
};
}
}
}



typedef boost::xml::dom::node_ptr<boost::xml::dom::node<qt::QString> > node_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::node<qt::QString> const> const_node_ptr;
typedef boost::xml::dom::element<qt::QString> element;
typedef boost::xml::dom::node_ptr<element> element_ptr;
typedef boost::xml::dom::node_ptr<element const> const_element_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<qt::QString> > attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::attribute<qt::QString> const> const_attribute_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<qt::QString> > text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::text<qt::QString> const> const_text_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<qt::QString> > pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::pi<qt::QString> const> const_pi_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<qt::QString> > comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::comment<qt::QString> const> const_comment_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<qt::QString> > cdata_ptr;
typedef boost::xml::dom::node_ptr<boost::xml::dom::cdata<qt::QString> const> const_cdata_ptr;
typedef std::auto_ptr<boost::xml::dom::document<qt::QString> > document_ptr;
typedef boost::xml::dom::dtd_ptr<qt::QString> dtd_ptr;
typedef boost::xml::dom::node_set<qt::QString> node_set;
typedef boost::xml::dom::xpath<qt::QString> xpath;