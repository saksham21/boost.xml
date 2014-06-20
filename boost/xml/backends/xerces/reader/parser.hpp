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

template <typename S> class parser;

template <typename S>
class token_base
{
	friend class parser<S>;
public:
	int depth() const { return h.depth(); }
	token_type type() const { return h.type(); }
	XMLCh const *name() const { return h.name(); }
	XMLCh const *value() const { return h.value(); }

private:
	handler h;
};

template <typename S>
class parser
{
public:

  	bool next() { status_ = parser->parseNext(token_); return status_ == 1;}
  	token_base<S> get_token()
  	{
  		token_base<S> token();
  		return token;
  	}

private:
	SAXParser* parser = new SAXParser;
	XMLPScanToken token_;
	int status_;
};
}
}
}
}