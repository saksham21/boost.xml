#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/XMLPScanToken.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include "convert.hpp"
#include "parser.hpp"

using namespace std;

int main(int argc, char **argv)
{
  bool doNamespaces = false;
  bool doSchema = false;
  bool schemaFullChecking = false;
  SAXParser::ValSchemes valScheme = SAXParser::Val_Auto;

  try
  {
    XMLPlatformUtils::Initialize();
  }
  catch (const XMLException& toCatch)
  {
    std::cerr << "Error during initialization! :\n" << StrX(toCatch.getMessage()) << std::endl;
    return 1;
  }

  // char *xmlFile = argv[2];
  std::string xmlFile="article.xml";

  SAXParser* parser = new SAXParser;
  handler h;
  parser->setDocumentHandler(&h);
  parser->setErrorHandler(&h);
  parser->setValidationScheme(valScheme);
  parser->setDoNamespaces(doNamespaces);
  parser->setDoSchema(doSchema);
  // parser->setHandleMultipleImports (true);
  parser->setValidationSchemaFullChecking(schemaFullChecking);

  try
  {
    XMLPScanToken token;

    if (!parser->parseFirst(xmlFile.c_str(), token))
    {
      std::cerr << "scanFirst() failed\n" << std::endl;
      XMLPlatformUtils::Terminate();
      return 1;
    }

    bool gotMore = true;
    while (gotMore && !parser->getErrorCount())
    {
      gotMore = parser->parseNext(token);
      std::cout << h.depth() << ' ' << StrX(h.name()) << ' ' << '(' << h.type() << ')' << ' ' << StrX(h.value()) << std::endl;
    }

    parser->parseReset(token);
  }
  catch (const OutOfMemoryException&)
  {
    std::cerr << "OutOfMemoryException" << std::endl;
  }
  catch (const XMLException& toCatch)
  {
    std::cerr << "\nAn error occurred: '" << xmlFile.c_str() << "'\n"
	      << "Exception message is: \n"
	      << StrX(toCatch.getMessage())
	      << "\n" << std::endl;
  }
  delete parser;

  XMLPlatformUtils::Terminate();
  return 0;
}
