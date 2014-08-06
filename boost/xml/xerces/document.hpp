#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <dom/DOM.hpp>
// #include "iterator.hpp"
#include <framework/StdOutFormatTarget.hpp>
using namespace xercesc;

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
	 : _dom_impl(NULL), _document(NULL), _doctype(NULL)
	{
		_dom_impl = DOMImplementationRegistry::getDOMImplementation(
             XMLString::transcode("core") );
		// _document = _dom_impl->createDocument(0, XMLString::transcode("S_RPS"), 0 , XMLPlatformUtils::fgMemoryManager );
		// _document->setXmlEncoding(XMLString::transcode("UTF-8") );
		// _document->setXmlVersion(XMLString::transcode("1.0") );
		// std::cout<<"Saksham\n";
	}

	void create_root(const char* a)
	{
		_document = _dom_impl->createDocument(0, XMLString::transcode(a), _doctype , XMLPlatformUtils::fgMemoryManager );
	}

	void set_version()
	{
		_document->setXmlVersion(XMLString::transcode("1.0") );
	}

	void DoOutput2File()
	{
  		DOMImplementation *pImplement = NULL;
  		DOMLSSerializer *writer = NULL;
    	DOMLSOutput *output = NULL;
    	pImplement = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
  		writer = ((DOMImplementationLS*)pImplement)->createLSSerializer();
  		output = ((DOMImplementationLS*)pImplement)->createLSOutput();
    	DOMConfiguration* dc = writer->getDomConfig();
   		dc->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
    	output->setEncoding(XMLString::transcode("UTF-8"));
    	StdOutFormatTarget* target = new StdOutFormatTarget();
    	output->setByteStream(target);
    	writer->write(_document, output);
    	delete target;
    	output->release();
	}

	void create_internal_subset(const char* nameId, const char* pubId, const char* sysId)
	{
		_doctype = _dom_impl->createDocumentType(XMLString::transcode("foo"),XMLString::transcode("bar"),XMLString::transcode("baz"));
	// 	std::cout<<"hi1\n";
	// 	DOMDocumentType* dtd_node = _dom_impl->createDocumentType(XMLString::transcode("foo"),XMLString::transcode("bar"),XMLString::transcode("baz"));
	// 	std::cout<<"hi2\n";
	// 	DOMElement* rootElement = _document->getDocumentElement();
	// 	std::cout<<"hi3\n";
	// 	rootElement->appendChild(dtd_node);
	// 	std::cout<<"hi4\n";
	// 	DOMDocumentImpl* docImpl = (DOMDocumentImpl *) _document;
	// 	XMLCh* fPublicId = docImpl->cloneString(pubId);
	// 	XMLCh* fSystemId = docImpl->cloneString(sysId);
	// 	XMLCh* fName = ((DOMDocumentImpl *)_document)->getPooledString(nameId);
	}

	~document() { _document->release(); }

private:
	DOMImplementation* _dom_impl;
	DOMDocument* _document;
	DOMDocumentType* _doctype;
};

}
}
}
}