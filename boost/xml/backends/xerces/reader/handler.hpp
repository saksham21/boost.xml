#ifndef handler_hpp_
#define handler_hpp_

#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/sax/AttributeList.hpp>
#include "convert.hpp"

XERCES_CPP_NAMESPACE_USE

namespace boost
{
namespace xml
{
namespace xerces
{
namespace reader
{
enum token_type
{
  none,
  element,
  attribute,
  text,
  cdata,
  entity_reference,
  type_entity,
  processing_instruction,
  comment,
  document,
  document_type,
  document_fragment,
  notation,
  whitespace,
  significant_whitespace,
  end_element,
  end_entity,
  xml_declaration,
};

class handler : public HandlerBase
{
public:
  handler() : type_(none), depth_(0), name_(0), value_(0) {}
  ~handler() {}

  int depth() const { return depth_;}
  token_type type() const { return type_;}
  XMLCh const *name() const { return name_;}
  XMLCh const *value() const { return value_;}

  void startElement(const XMLCh* const name, AttributeList& attributes)
  {
    type_ = element;
    ++depth_;
    name_ = name;
  }
  void endElement(const XMLCh* const name)
  { 
    --depth_;
  }
  void characters(const XMLCh* const chars, const XMLSize_t length)
  {
    type_ = text;
    value_ = chars;
    length_ = length;
  }
  void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length)
  {
    type_ = whitespace;
    value_ = chars;
    length_ = length;
  }
  void processingInstruction(const XMLCh *target, const XMLCh *data)
  {
    type_ = processing_instruction;
    name_ = target;
    value_ = data;
  }
  
private:
  token_type type_;
  int depth_;
  XMLCh const *name_;
  XMLCh const *value_;
  XMLSize_t length_;
};
}
}
}
}

#endif
