#include <bits/stdc++.h>
#include "handler.hpp"
#include "convert.hpp"
#include <xercesc/parsers/SAXParser.hpp>

using namespace std;

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

template <typename S> class parser;

template <typename S>
class token_base
{
	friend class parser<S>;
public:
	token_base()
		: h_() {}
	~token_base() {}

	int depth() const { return h_.depth(); }
	token_type type() const { return h_.type(); }
	XMLCh const *name() const { return h_.name(); }
	XMLCh const *value() const { return h_.value(); }

private:
	handler h_;			// how to use this handler with our token_base();
};

template <typename S>
class parser
{
public:
	parser(std::string const &filename)
		: token_(/* how to initialise this ?? */),
		  status_(0)
	{
		if(!parser->parseFirst(filename.c_str(), token_))
		{
			std::cerr << "scanFirst() failed\n" << std::endl;
			XMLPlatformUtils::Terminate();
			return 1;
		}
	}
	~parser() {}
  	bool next() { status_ = parser->parseNext(token_); return status_ == 1;}

  	token_base<S> get_token()
  	{
  		token_base<S> token(token_);
  		return token;
  	}

private:
	SAXParser* parser = new SAXParser; // how to implement this ???
	XMLPScanToken token_;
	int status_;
};
}
}
}
}