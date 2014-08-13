#include "dom.hpp"
#include "string.hpp"
#include <iostream>
#include <util/PlatformUtils.hpp>
#include <parsers/XercesDOMParser.hpp>

namespace dom = boost::xml::xerces::dom;

class traversal
{
public:
  traversal() : indent_(0) {}
  void traverse(node_ptr node)
  {
    std::cout<<"saksham\n";
    if (!node) return;
    switch (node->type())
    {
      case dom::ELEMENT: traverse(dom::cast<element_ptr>(node)); break;
      case dom::ATTRIBUTE: traverse(dom::cast<attribute_ptr>(node)); break;
      case dom::TEXT: traverse(dom::cast<text_ptr>(node)); break;
      case dom::COMMENT: traverse(dom::cast<comment_ptr>(node)); break;
      case dom::PI: traverse(dom::cast<pi_ptr>(node)); break;
      case dom::CDATA: traverse(dom::cast<cdata_ptr>(node)); break;
      default: break; // all other node types are ignored
    }
  }
  void traverse(element_ptr node)
  {
    std::cout << indent() << "element: " << node->name() << std::endl;
    
    ++indent_;
    for (element::attribute_iterator i = node->begin_attributes();
	 i != node->end_attributes();
	 ++i)
      traverse(*i);
    for (element::child_iterator i = node->begin_children();
	 i != node->end_children();
	 ++i)
      traverse(*i);
    --indent_;
  }
  void traverse(attribute_ptr node)
  {
    std::cout << indent() << "attribute: " 
	      << node->name() << "=\"" << node->value() << '"' << std::endl;
  }
  void traverse(text_ptr node)
  {
    std::cout << indent() << "text: '" << node->content() << '\'' << std::endl;
  }
  void traverse(comment_ptr node)
  {
    std::cout << indent() << "comment: '" << node->content() << '\'' << std::endl;
  }
  void traverse(pi_ptr node)
  {
    std::cout << indent() << "processing instruction: '" 
	      << node->name() << ' ' << node->content() << '\'' << std::endl;
  }
  void traverse(cdata_ptr node)
  {
    std::cout << indent() << "cdata: '" << node->content() << '\'' << std::endl;
  }

private:
  std::string indent() { return std::string(indent_, ' ');}

  size_t indent_;
};


int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: example <xml-file>" << std::endl;
    return -1;
  }
  try
  {
    // create a document from a file
    XMLPlatformUtils::Initialize();
    std::string const &filename = argv[1];
    XercesDOMParser _parser;
    _parser.setValidationScheme(XercesDOMParser::Val_Always);
    _parser.setDoNamespaces(true);
    _parser.parse(filename.c_str());
    // document_ptr document = dom::parse_file<S>(argv[1]);
    document_ptr doc = boost::xml::xerces::dom::detail::factory<S>(_parser.getDocument());
    std::cout<<"askhaks\n";
    traversal t;
    t.traverse(doc->root());
  }
  catch (std::exception const &e)
  {
    std::cerr << "Error : " << e.what() << std::endl;
  }
}
