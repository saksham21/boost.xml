#ifndef boost_xml_xerces_dom_parser_hpp_
#define boost_xml_xerces_dom_parser_hpp_

#include "document.hpp"
#include <parsers/XercesDOMParser.hpp>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>
#include <iostream>

XERCES_CPP_NAMESPACE_USE

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{

//. A catch-all error type for not-yet classified errors.
class internal_error : public std::runtime_error
{
public:
  internal_error(std::string const &msg) : std::runtime_error(msg) {}
};

//. An error indicating the input not containing well-formed XML.
class parse_error : public std::invalid_argument
{
public:
  parse_error(std::string const &msg) : std::invalid_argument(msg) {}
};

class validation_error : public std::runtime_error
{
public:
  validation_error(std::string const &msg) : std::runtime_error(msg) {}
};

//. A parser encapsulates parse-related parameters, such as non-fatal
//. errors encountered during the parse process. Other parameters might
//. be added, such as for catalog handling (See XML Catalog), or some
//. other form of caching, if possible.
class parser
{
public:
  parser();
  ~parser();
  template <typename S>
  std::auto_ptr<document<S> > parse_file(std::string const &filename);
private:
   // XercesDOMParser _parser;
   // ErrorHandler* _errHandler;

  // static void error_callback(void *closure, xmlError *error)
  // {
  //   parser *p = reinterpret_cast<parser *>(closure);
  //   p->error_callback(*error);
  // }
  // void error_callback(xmlError const &);

  // std::string error_msg_;
};

inline parser::parser()
{
  // _parser = new XercesDOMParser();
  // _parser.setValidationScheme(XercesDOMParser::Val_Always);
  // _parser.setDoNamespaces(true);
}

inline parser::~parser()
{
  // xmlSetStructuredErrorFunc(0, 0);
}

// inline void parser::error_callback(xmlError const &error)
// {
//   std::ostringstream oss;
//   oss << "error in " 
//       << error.file << ':' << error.line << ':' << error.int2 << ":\n";
//   oss << error.message << '\n';
//   this->error_msg_ += oss.str();
// }

template <typename S>
std::auto_ptr<document<S> > parser::parse_file(std::string const &filename)
{
  // try {
  //   ErrorHandler _errHandler = (ErrorHandler*) new HandlerBase();
  //   _parser->setErrorHandler(errHandler);
    XercesDOMParser* _parser = new XercesDOMParser();
    _parser->setValidationScheme(XercesDOMParser::Val_Always);
    _parser->setDoNamespaces(true);
    _parser->parse(filename.c_str());
    std::auto_ptr<document<S> > doc = detail::factory<S>(_parser->getDocument());
    // delete _parser;
    // delete _errHandler;
    return doc;
  // }
  // catch (const XMLException& toCatch) {
  //   char* message = XMLString::transcode(toCatch);
  //   std::cout << "XMLException message is: \n"
  //             << message << std::endl;  
  //   XMLString::release(&message);
  //   return -1;
  // }
  // catch (const DOMException& toCatch){
  //   char* message = XMLString::transcode(toCatch);
  //   std::cout << "XMLException message is: \n"
  //             << message << std::endl;  
  //   XMLString::release(&message);
  //   return -1;
  // }
  // catch (const OutofMemoryException& toCatch) {
  //   char* message = XMLString::transcode(toCatch);
  //   std::cout << "XMLException message is: \n"
  //             << message << std::endl;  
  //   XMLString::release(&message);
  //   return -1;
  // }
}

//. Parse the given file and create a document containing the new infoset.
//. For a richer interface to the parser, use the parser class directly.
template <typename S>
std::auto_ptr<document<S> > parse_file(std::string const &filename)
{
  std::cout<<"ggg\n";
  parser p;
  return p.parse_file<S>(filename);
}

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost
}

#endif
