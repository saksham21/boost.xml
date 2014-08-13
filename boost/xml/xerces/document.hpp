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

	node_ptr<element<S> const> root() const
	{
		DOMElement* _element = _document->getDocumentElement();
		DOMNode* _node = dynamic_cast<DOMNode*>(_element);
  		return detail::ptr_factory<element<S> const>(_node);
	}

	node_ptr<element<S> > root()
	{
		std::cout<<"tttttsssssss\n";
		DOMElement* _element = NULL;
		_element = _document->getDocumentElement();
		if(_element!=NULL)
			std::cout<<"ttttt\n";
		DOMNode* _node = reinterpret_cast<DOMNode*>(_element);
		
		return element<S>(_node);
	}

	node_ptr<element<S> > create_root(const char* root_name)
	{
		_document = _dom_impl->createDocument(0, XMLString::transcode(root_name), _doctype , XMLPlatformUtils::fgMemoryManager );
		return root();
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

	~document() { _document->release(); }

private:
	DOMImplementation* _dom_impl;
	document(DOMDocument *doc) : detail::wrapper<DOMDocument*>(doc) {}
	DOMDocumentType* _doctype;
	DOMDocument* _document;

};

}
}
}
}

#endif
