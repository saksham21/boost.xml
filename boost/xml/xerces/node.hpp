#ifndef boost_xml_xerces_dom_node_hpp_
#define boost_xml_xerces_dom_node_hpp_

#include "node_fwd.hpp"
#include "iterator.hpp"
#include <stdexcept>

XERCES_CPP_NAMESPACE_USE

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{

enum node_type
{
  INTERNAL = 0,
  ELEMENT,
  ATTRIBUTE,
  TEXT,
  CDATA,
  PI,
  COMMENT,
};

template <typename N>
class node_ptr
{
public:
  node_ptr() : impl_(0) {}
  node_ptr(N const &n) : impl_(n) {}
  //. downcasting copy-constructor (e.g. element_ptr -> node_ptr)
  template <typename N2>
  node_ptr(node_ptr<N2> n) : impl_(*n.get()) {}
  N &operator*() { return this->impl_;}
  N *operator->() { return &this->impl_;}
  N *get() { return &this->impl_;}
  operator bool() const { return this->impl_.impl();}

private:
  N impl_;
};

template <typename T, typename N>
inline T cast(node_ptr<N> n);

template <typename S>
class node : public detail::wrapper<DOMNode*>
{
  template <typename N> friend class iterator;
  friend class node_ptr<node<S> >;
  friend class node_ptr<node<S> const>;
  friend class element<S>;
  friend node_ptr<node<S> > detail::ptr_factory<node<S> >(DOMNode *);
  friend node_ptr<node<S> const> detail::ptr_factory<node<S> const>(DOMNode *);
  template <typename T, typename N> friend T cast(node_ptr<N>);

public:
  bool operator== (node<S> const &n) {return impl() == impl(n);}

  // node_type type() const { return types[this->impl()->getNodeType()];}
  //. Return the node's name.
 /* S name() const { return converter<S>::out(this->impl()->name);}
  //. Return the node's path within its document.
  S path() const;
  //. Return the node's active base (See XBase).
  S base() const;
  //. Return the node's active language.
  S lang() const;                                               */

  //. Return the parent node, if any.
  node_ptr<element<S> const> parent() const 
  { return detail::ptr_factory<element<S> >(this->impl()->getParentNode());}
  node_ptr<element<S> > parent() 
  { return detail::ptr_factory<element<S> >(this->impl()->getParentNode());}


protected:
  node(DOMNode *n) : detail::wrapper<DOMNode*>(n) {}
  node(node<S> const &n) : detail::wrapper<DOMNode*>(n) {}
  node<S> &operator=(node<S> const&n)
  {
    detail::wrapper<DOMNode*>::operator=(n);
    return *this;
  }

private:
  static node_type const types[22];
  static char const *names[7];

};


template <typename S>
node_type const node<S>::types[22] =
{
  INTERNAL,
  ELEMENT,   //XML_ELEMENT_NODE
  ATTRIBUTE, //XML_ATTRIBUTE_NODE
  TEXT,      //XML_TEXT_NODE
  CDATA,     //XML_CDATA_SECTION_NODE
  INTERNAL,  //XML_ENTITY_REF_NODE
  INTERNAL,  //XML_ENTITY_NODE
  PI,        //XML_PI_NODE
  COMMENT,   //XML_COMMENT_NODE
  INTERNAL,  //XML_DOCUMENT_NODE
  INTERNAL,  //XML_DOCUMENT_TYPE_NODE
  INTERNAL,  //XML_DOCUMENT_FRAG_NODE
  INTERNAL,  //XML_NOTATION_NODE
  INTERNAL,  //XML_HTML_DOCUMENT_NODE
  INTERNAL,  //XML_DTD_NODE
  INTERNAL,  //XML_ELEMENT_DECL
  INTERNAL,  //XML_ATTRIBUTE_DECL
  INTERNAL,  //XML_ENTITY_DECL
  INTERNAL,  //XML_NAMESPACE_DECL
  INTERNAL,  //XML_XINCLUDE_START
  INTERNAL,  //XML_XINCLUDE_END
  INTERNAL,  //XML_DOCB_DOCUMENT_NODE
};

template <typename S>
char const *node<S>::names[7] =
{
  "internal node",
  "element",
  "attribute",
  "text node",
  "cdata block",
  "processing instruction",
  "comment"
};

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif