
namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{

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

}
}
}
}