#include <bits/stdc++.h>
#include <dom/DOM.hpp>
// #include "iterator.hpp"

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{

template <typename S>
class document
{
public:
	document()
	 : _dom_impl(NULL), _document(NULL)
	{
		_dom_impl = xercesc::DOMImplementationRegistry::getDOMImplementation(
             xercesc::XMLString::transcode("core"));
		std::cout<<"Saksham\n";
	}
	~document() {_document->release();}

private:
	xercesc::DOMImplementation* _dom_impl;
	xercesc::DOMDocument* _document;
};

}
}
}
}