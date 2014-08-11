#ifndef boost_xml_xerces_dom_document_hpp_
#define boost_xml_xerces_dom_document_hpp_

#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <dom/DOM.hpp>
#include "dtd.hpp"
#include "element.hpp"
#include <framework/StdOutFormatTarget.hpp>

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
class document : public detail::wrapper<DOMDocument*>
{
	friend std::auto_ptr<document<S> > detail::factory<S>(DOMDocument*);
public:
	document()
	 : detail::wrapper<DOMDocument*>(_document)
	{
		_dom_impl = DOMImplementationRegistry::getDOMImplementation(
             XMLString::transcode("core") );
		// _document = _dom_impl->createDocument(0, XMLString::transcode("S_RPS"), 0 , XMLPlatformUtils::fgMemoryManager );
		// _document->setXmlEncoding(XMLString::transcode("UTF-8") );
		// _document->setXmlVersion(XMLString::transcode("1.0") );
		// std::cout<<"Saksham\n";
	}

	dtd_ptr<S> create_internal_subset(const char* name,
            const char* external_id,
			const char* system_id)
	{
		_doctype = _dom_impl->createDocumentType(XMLString::transcode(name),
  							XMLString::transcode(external_id),
  							XMLString::transcode(system_id));
		return dtd<S>(_doctype);
	}

	node_ptr<element<S> > create_root(const char* root_name)
	{
		_document = _dom_impl->createDocument(0, XMLString::transcode(root_name), _doctype , XMLPlatformUtils::fgMemoryManager );
		DOMElement* _element = _document->getDocumentElement();
		DOMNode* _node = dynamic_cast<DOMNode*>(_element);
		return element<S>(_node);
	}

	void set_version()
	{
		_document->setXmlVersion(XMLString::transcode("1.0") );
	}

	void write()
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

	/*DOMDocumentType* create_internal_subset(const char* nameId, const char* pubId, const char* sysId)
	{
		_doctype = _dom_impl->createDocumentType(XMLString::transcode("foo"),XMLString::transcode("bar"),XMLString::transcode("baz"));
		return _doctype;
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
	}	*/

	~document() { _document->release(); }

private:
	DOMImplementation* _dom_impl;
	document(DOMDocument *doc) : detail::wrapper<DOMDocument*>(doc) {}
	DOMDocumentType* _doctype;
	DOMDocument* _document;

};


// template <typename S>
// inline dtd_ptr<S>
// document<S>::create_internal_subset(std::string const &name,
// 			std::string const &external_id,
// 			std::string const &system_id)
// {
//   xmlDtd *d = _dom_impl->createDocumentType(XMLString::transcode("foo"),
//   							XMLString::transcode("bar"),
//   							XMLString::transcode("baz"));
//   return dtd<S>(d);
// }

}
}
}
}

#endif
