// Copyright 2007 Stefan Seefeld.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "string.hpp"
#include <fstream>
// #include "io.hpp"
#include <util/PlatformUtils.hpp>

namespace dom = boost::xml::xerces::dom;
using namespace xercesc;

int main(int argc, char **argv)
{
  try
  {
    XERCES_CPP_NAMESPACE_USE
    XMLPlatformUtils::Initialize();
    document_ptr doc;
    // dom::document<S> doc;
    dtd_ptr doc_type=doc.create_internal_subset("foo", "bar", "baz");
    DOMElement* root=doc.create_root("config");
    doc.set_version();
    // document_ptr document(new dom::document<S>());
    // element_ptr root = document->create_root("config");
    // dtd_ptr doc_type = document->create_internal_subset("foo", "bar", "baz");
    // std::ofstream ofs("config.xml");
    doc.DoOutput2File();
    XMLPlatformUtils::Terminate();
  }
  catch (std::exception const &e)
  {
    std::cerr << "Error : " << e.what() << std::endl;
  }
}
