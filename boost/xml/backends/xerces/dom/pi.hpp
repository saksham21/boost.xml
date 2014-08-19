#ifndef boost_xml_backends_xerces_dom_pi_hpp_
#define boost_xml_backends_xerces_dom_pi_hpp_

#include <boost/xml/backends/xerces/dom/node.hpp>

namespace boost
{
namespace xml
{
namespace dom
{

template <typename S> class element;

template <typename S>
class pi : public node<S>
{
friend class element<S>;
public:
  S content() const { return converter<S>::out(this->impl()->getNodeValue());}
  void set_content(S const &value) { this->impl()->setNodeValue(converter<S>::in(value));}

// private:
  pi(detail::DOMNode *a) : node<S>(a) {}
};

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
