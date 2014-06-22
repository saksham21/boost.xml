#include <bits/stdc++.h>
#include "handler.hpp"
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>

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
	token_base()
		: h_(depth(0) , type(none), name(0), value(0)) {}
	~token_base() {}

	int depth() const { return h_.depth(); }
	token_type type() const { return h_.type(); }
	XMLCh const *name() const { return h_.name(); }
	XMLCh const *value() const { return h_.value(); }

protected:
	token_base(handler &h) : h_(h) {}

	handler &h_;

// private:
// 	handler& h_;
};

template <typename S>
class parser
{
public:
	parser(string const &filename)
		: token_(),
		  status_(0),
		  parser_(),
		  h_()
	{
		if(!parser_.parseFirst(filename.c_str(), token_))
		{
			XMLPlatformUtils::Terminate();
			throw std::runtime_error("unable to open file");
		}
		parser_.setDocumentHandler(&h_);
	}
	~parser() {}
  	bool next() { status_ = parser_.parseNext(token_); return status_ == 1;}

  	token_base<S> get_token()
  	{
  		token_base<S> token(h_);
  		return token;
  	}

private:
	SAXParser parser_;
	handler h_;
	XMLPScanToken token_;
	int status_;
};
}
}
}
}
