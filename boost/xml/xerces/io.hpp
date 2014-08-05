#ifndef boost_xml_dom_write_hpp_
#define boost_xml_dom_write_hpp_

#include <streambuf>
#include <iostream>
// #include "document.hpp"
// #include <libxml/xmlsave.h>
#include <framework/StdOutFormatTarget.hpp>

namespace boost
{
namespace xml
{
namespace xerces
{
namespace dom
{
// namespace detail
// {
// inline int stream_write_callback(void *context, const char *buffer, int len)
// {
//   std::streambuf *sb = reinterpret_cast<std::streambuf *>(context);
//   int written = sb->sputn(buffer, len);
//   return written;
// }
// inline int stream_close_callback(void *context) { return 0;}
// }

template <typename S>
inline void write(document<S> const &document,
                  std::streambuf *sb,
                  std::string const &encoding = std::string())
  throw(std::runtime_error)
{
  // std::cout<<"hi\n";
  char const *enc = encoding.c_str();
  if (enc[0] == '\0') enc = 0;
  long bytes;
  int status;
  // xmlSaveCtxt *ctx = xmlSaveToIO(detail::stream_write_callback,
  //                                detail::stream_close_callback,
  //                                sb, enc,  XML_SAVE_FORMAT);
  // long bytes = xmlSaveDoc(ctx, detail::impl_cast(&document));
  // int status = xmlSaveClose(ctx);
  if(bytes == -1 || status == -1)
    throw std::runtime_error("Failed to stream document.");
  // std::cout<<"wassup\n";
}
/*template<typename S>
inline void DoOutput2File(document<S> &doc)
{
    DOMImplementation    *pImplement        = NULL;
    // DOMWriter            *pSerializer       = NULL;
    DOMLSSerializer      *writer            = NULL;
    // XMLFormatTarget      *pTarget           = NULL;
    DOMLSOutput          *output     = NULL;
    pImplement = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
    writer = ((DOMImplementationLS*)pImplement)->createLSSerializer();
    output = ((DOMImplementationLS*)pImplement)->createLSOutput();
    DOMConfiguration* dc = writer->getDomConfig();
    dc->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
    // doc->setXmlVersion(XMLString::transcode("1.0") );
    output->setEncoding(XMLString::transcode("UTF-8"));
    // dc->setParameter(XMLUni::fgDOMErrorHandler,errorHandler);
    // dc->setParameter(XMLUni::fgDOMWRTDiscardDefaultContent,true);
    // pSerializer = ((DOMImplementationLS*)pImplement)->createDOMWriter();
    // pSerializer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true);
    // pTarget = new LocalFileFormatTarget(FullFilePath);      ???????????????????????                                    
    // // pSerializer->writeNode(pTarget, pmyDOMDocument);
    // std::wstring widestr = std::wstring(str.begin(), str.end());
    // wchar_t* FullFilePath = widestr.c_str();
    // pTarget = new LocalFileFormatTarget(FullFilePath);
    StdOutFormatTarget* target = new StdOutFormatTarget();
    output->setByteStream(target);
    xercesc::DOMDocument* doc1;
    writer->write(doc1, output);
    delete target;
    output->release();
} */

// template <typename S>
// inline void write_to_file(document<S> const &document,
//                           std::string const &filename,
//                           std::string const &encoding = std::string())
//   throw(std::runtime_error)
// {
//   int result = 0;
//   if(!encoding.empty())
//     result = xmlSaveFormatFileEnc(filename.c_str(),
// 				  detail::impl_cast(&document), encoding.c_str(), 1);
//   else
//     result = xmlSaveFormatFile(filename.c_str(), detail::impl_cast(&document), 1);

//   if(result == -1)
//     throw std::runtime_error("Failed to write document.");
// }

} // namespace boost::xml::dom
} // namespace boost::xml
} // namespace boost
}

#endif
