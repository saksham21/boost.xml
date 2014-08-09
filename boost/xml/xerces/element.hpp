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

template <typename S>
class element : public node<S>
{
  friend class document<S>;
  friend node_ptr<element<S> > detail::ptr_factory<element<S> >(DOMNode *);
public:

protected:
  element(DOMNode *e) : node<S>(e) {}
};

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost
