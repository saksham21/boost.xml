#ifndef boost_xml_xerces_dom_iterator_hpp_
#define boost_xml_xerces_dom_iterator_hpp_

#include <dom/DOM.hpp>
#include <memory>

XERCES_CPP_NAMESPACE_USE

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{
namespace detail
{

template <typename T> class wrapper;
template <typename T> T impl_cast(wrapper<T> *);
template <typename T> T impl_cast(wrapper<T> const *);

//. 
class accessor
{
protected:
  template <typename T>
  static T &impl(wrapper<T> &w) { return w.impl_;}
  template <typename T>
  static T impl(wrapper<T> const &w) { return w.impl_;}
};

//. wrapper helper class to encapsulate access to private
//. data among wrappers. This defines mutual access to the backend
//. data in an extensible way.
template <typename T>
class wrapper : public accessor
{
  friend class accessor;
  template <typename T1> friend T1 impl_cast(wrapper<T1> *);
  template <typename T1> friend T1 impl_cast(wrapper<T1> const *);
public:
  wrapper(T t) : impl_(t) {}

protected:
  using accessor::impl;
  T &impl() { return this->impl_;}
  T const impl() const { return this->impl_;}
  T release() 
  {
    T tmp = impl_; 
    impl_ = 0; 
    return tmp;
  }
private:
  T impl_;
};

template <typename T>
T impl_cast(wrapper<T> *w) { return w->impl();}
template <typename T>
T impl_cast(wrapper<T> const *w) { return w->impl();}

template <typename N>
node_ptr<N> ptr_factory(DOMNode *n) { return N(n);}

template <typename S>
std::auto_ptr<document<S> > factory(DOMDocument *d)
{
  return std::auto_ptr<document<S> >(new document<S>(d));
}

} // namespace boost::xml::dom::detail

template <typename N>
class iterator : public detail::wrapper<DOMNode*>
{
public:
  typedef iterator<N> self;
  typedef node_ptr<N> value_type;
  typedef value_type &reference;
  typedef value_type *pointer;

  iterator(DOMNode *current = 0) : detail::wrapper<DOMNode*>(current) {}
  bool operator == (self i) { return impl() == impl(i);}
  bool operator != (self i) { return !operator==(i);}
  value_type operator *() { return detail::ptr_factory<N>(impl());}
  pointer operator ->() { return &(operator *());}
  self operator ++(int) { increment(); return *this;}
  self operator ++() { /*std::cout<<"here\n";*/ self tmp = *this; increment(); return tmp;}
  self operator --(int) { decrement(); return *this;}
  self operator --() { self tmp = *this; decrement(); return tmp;}

private:
  void increment() { impl() = impl()->getNextSibling(); /*if(impl()==NULL)std::cout<<"sam: null\n";*/}
  void decrement() { impl() = impl()->getPreviousSibling();}
};

}
}
}
}

#endif