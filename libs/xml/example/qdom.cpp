// Copyright 2007 Stefan Seefeld.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/xml/dom.hpp>
#include "qstring.hpp"
#include <iostream>
#include <QtCore/qtextstream.h>

namespace dom = boost::xml::dom;
using namespace std;

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    std::cerr << "Usage: example <xml-input> <xml-output>" << std::endl;
    return -1;
  }
  try
  {
  	QTextStream out1(stdout);
    // create a document from a file
    document_ptr document = dom::parse_file<QString>(argv[1], false);
    element_ptr root = document->root();
   out1 << "the root node " << root->name() << " has the following child nodes:\n";
    for (element::child_iterator i = root->begin_children();
	 i != root->end_children();
	 ++i)
    {
      out1 << " " << (*i)->name() << "\n";
    }
    // find all sections, no matter where...
    {
      xpath path("//section");
      out1 << "searching with xpath '" << path.string() << "' in root node: ";
      node_set set = path.find(root);
      out1 << set.size() << " nodes have been found:\n";
      for (node_set::iterator i = set.begin(); i != set.end(); ++i)
      {
	//...and print their structural path
 	out1 << " " << (*i)->path() << "\n";
      }
    }
    // find the title node (if there is one)
    xpath path("title");
    node_set set = path.find(root);
    node_ptr title;
    if (set.size()) title = set[0];
    else { std::cout << "no title found !" << std::endl;}
    // now insert an 'articleinfo' node
    std::cout << "inserting 'articleinfo' element..." << std::endl;
    element_ptr info = root->insert_element(root->begin_children(), "articleinfo");
    if (title)
    {
      info->insert(info->begin_children(), title);
      info->insert_comment(info->begin_children(), "This title was moved");
    }
    element_ptr author = info->append_element("author");
    element_ptr firstname = author->append_element("firstname");
    firstname->set_content("Joe");
    element_ptr surname = author->append_element("surname");
    surname->set_content("Random");
    // and finally test whether intra-document links are well-formed
    {
      // to be well-formed, the 'linkend' attribute has to refer to
      // an element in terms of its 'id'.
      // find out whether there are linkend attributes that don't have
      // corresponding 'id's
      std::cout << "searching for unresolved internal references "
		<< "(see docbook manual):" << std::endl;
      xpath linkend("//xref/@linkend");
      node_set xrefs = linkend.find(root);
      for (node_set::iterator i = xrefs.begin(); i != xrefs.end(); ++i)
      {
	attribute_ptr attribute = dom::cast<attribute_ptr>(*i);
	xpath id("//*[@id=\"" + attribute->value() + "\"]");
	node_set target = id.find(root);
	if (!target.size())
	{
    out1 << " document has reference to non-existing id '"
		    << attribute->value() << '\'' << "\n";
	  std::cout << "removing invalid reference..." << std::endl;
	  // We are looking at a 'linkend' attribute, and we want to remove
	  // the 'xref' parent element from its parent, so we need to go two 
	  // levels up.
	  element_ptr xref = (*i)->parent();
	  element_ptr parent = xref->parent();
	  // For simplicity's sake, assume the content is text only.
	  QString content = xref->content();
	  element::child_iterator j = parent->find(xref);
	  if (j != parent->end_children())
	  {
	    parent->insert_text(j, content);
	    parent->remove(j);
	  }
	}
      }
    }
    write_to_file(*document, argv[2]);
  }
  catch (std::exception const &e)
  {
    std::cerr << "Error : " << e.what() << std::endl;
  }
}
