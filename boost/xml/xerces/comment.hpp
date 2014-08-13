#ifndef boost_xml_xerces_dom_comment_hpp_
#define boost_xml_xerces_dom_comment_hpp_

#include "node.hpp"

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{

template <typename S> class element;

template <typename S>
class comment : public node<S>
{
friend class element<S>;
public:
  S content() const;
  void set_content(S const &);

// private:
  comment(DOMNode *a) : node<S>(a) {}
};

template <typename S>
inline S comment<S>::content() const
{
	return converter<S>::out(this->impl()->getNodeValue());
  // XMLCh *content = this->impl()->getNodeValue();
  // S retn = converter<S>::out(content);
  // XMLString::release(&content);
  // return retn;
}

template <typename S>
inline void comment<S>::set_content(S const &content)
{
	this->impl()->setNodeValue(converter<S>::in(content));
}

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif