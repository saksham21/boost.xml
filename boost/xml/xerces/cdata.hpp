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
class cdata : public text<S> 
{
  friend class element<S>;
public:
// private:
  cdata(DOMNode *a) : text<S>(a) {}
};

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost
