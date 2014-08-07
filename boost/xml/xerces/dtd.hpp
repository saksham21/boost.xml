#ifndef boost_xml_dom_dtd_hpp_
#define boost_xml_dom_dtd_hpp_

#include <dom/DOM.hpp>
#include <string>

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{

template <typename S> class document;
template <typename S> class dtd_ptr;

template <typename S>
class dtd
{
  friend class document<S>;
  friend class dtd_ptr<S>;
public:
  const char* name() const { return static_cast<char *>(impl_->getName());}
  const char* external_id() const { return static_cast<char *>(impl_->getPublicId());}    // DOMNotation.hpp
  const char* system_id() const { return static_cast<char *>(impl_->getSystemId());}
  
private:
  dtd(DOMDocumentType *dtd) : impl_(dtd) {}
  ~dtd() {}

  DOMDocumentType *impl_;
};

template <typename S>
class dtd_ptr
{
public:
  dtd_ptr() : dtd_(0) {}
  dtd_ptr(dtd<S> const &d) : dtd_(d) {}
  dtd<S> &operator*() { return this->dtd_;}
  dtd<S> *operator->() { return &this->dtd_;}
  dtd<S> *get() { return &this->dtd_;}
  operator bool() const { return this->dtd_.impl_;}

private:
  dtd<S> dtd_;
};

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost

#endif
