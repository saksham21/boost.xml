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
class text : public node<S>
{
friend class element<S>;
public:
  S content() const;
  void set_content(S const &);

// private:
  text(DOMNode *a) : node<S>(a) {}
};

template <typename S>
S text<S>::content() const
{
  XMLCh *content = this->impl()->getNodeValue();
  S retn = converter<S>::out(content);
  XMLString::release(&content);
  return retn;
}

template <typename S>
void text<S>::set_content(S const &content)
{
	this->impl()->setNodeValue(converter<S>::in(content));
}
}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost
