#ifndef boost_xml_xerces_dom_attribute_hpp_
#define boost_xml_xerces_dom_attribute_hpp_

#include "node.hpp"

XERCES_CPP_NAMESPACE_USE

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
class attribute : public node<S>
{
  friend node_ptr<attribute<S> > detail::ptr_factory<attribute<S> >(DOMNode *);
  friend class element<S>;
public:
  S name() const ;
  S value() const;
  void set_value(S const &);

private:
  attribute(DOMNode *a) : node<S>(a) {}
};

template <typename S>
inline S attribute<S>::name() const
{
  XMLCh *value = this->impl()->getNodeName();
  S retn = converter<S>::out(value);
  XMLString::release(&value);
  return retn;
}

template <typename S>
inline S attribute<S>::value() const
{
  XMLCh *value = this->impl()->getNodeValue();
  S retn = converter<S>::out(value);
  XMLString::release(&value);
  return retn;
}

template <typename S>
inline void attribute<S>::set_value(S const &value)
{
  this->impl()->setNodeValue(converter<S>::in(value));
}

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
