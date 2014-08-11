#include "node.hpp"
#include "attribute.hpp"
#include "text.hpp"
#include "comment.hpp"
#include "pi.hpp"
#include "cdata.hpp"

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
	typedef iterator<node<S> > child_iterator;
	typedef iterator<node<S> const> const_child_iterator;

	typedef iterator<dom::attribute<S> > attribute_iterator;
	typedef iterator<dom::attribute<S> const> const_attribute_iterator;

	node_ptr<dom::attribute<S> const> attribute(S const &name) const;

	node_ptr<dom::attribute<S> > attribute(S const &name);

	node_ptr<dom::attribute<S> > set_attribute(S const &name, S const &value);

	void unset_attribute(S const &name);

	attribute_iterator begin_attributes()
	{
		 DOMNamedNodeMap* attr = this->impl()->getAttributes();
		 return attribute_iterator(reinterpret_cast<DOMNode *>(attr));
	}
	const_attribute_iterator begin_attributes() const
	{
		DOMNamedNodeMap* attr = this->impl()->getAttributes();
		return const_attribute_iterator(reinterpret_cast<DOMNode *>(attr));
	}
	attribute_iterator end_attributes()
	{
		return attribute_iterator();
	}
	const_attribute_iterator end_attributes()
	{
		return const_attribute_iterator();
	}

	child_iterator begin_children()
	{ return child_iterator(this->impl()->getNextSibling());}
	const_child_iterator begin_children()
	{ return const_child_iterator(this->impl()->getNextSibling());}
	child_iterator end_children()
	{ return child_iterator();}
	const_child_iterator end_children()
	{ return const_child_iterator();}

protected:
  element(DOMNode *e) : node<S>(e) {}
};

/*
template <typename S>
inline node_ptr<dom::attribute<S> const> element<S>::attribute(S const &name) const
{
	XMLCh* n = converter<S>::in(name);
	for(DOMNamedNodeMap *attr = this->impl()->getAttributes(); attr; attr->getNextSibling())
	{
		DOMNode* _attr = reinterpret_cast<DOMNode *>(attr);
		if(XMLString::equals(_attr->getNodeName(), n))
			return dom::attribute<S>((DOMNode *)attr);
	}
	return dom::attribute<S>(0);
}

template <typename S>
inline node_ptr<dom::attribute<S> > element<S>::attribute(S const &name)
{
	XMLCh* n = converter<S>::in(name);
	for(DOMNamedNodeMap *attr = this->impl()->getAttributes(); attr; attr->getNextSibling())
	{
		DOMNode* _attr = reinterpret_cast<DOMNode *>(attr);
		if(XMLString::equals(_attr->getNodeName(), n))
			return dom::attribute<S>((DOMNode *)attr);
	}
	return dom::attribute<S>(0);
}			*/					//			working on this :-)

}
} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost
