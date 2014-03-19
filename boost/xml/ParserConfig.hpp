// Class to select wrapper function based on which type of backend is used to compile .....

#ifdef BOOST_USE_LIBXML2
#include <backend/wrapper/libxml2.hpp>
#undef SELECT_WRAPPER
#define SELECT_WRAPPER libxml2_wrapper
#endif

#ifdef BOOST_USE_MSXML
#include <backend/wrapper/msxml2.hpp>
#undef SELECT_WRAPPER
#define SELECT_WRAPPER msxml2_wrapper
#endif 

#ifdef BOOST_USE_XERCES
#include <backend/wrapper/xerces.hpp>
#undef SELECT_WRAPPER
#define SELECT_WRAPPER xerces_wrapper
#endif

#ifdef BOOST_USE_EXPAT
#include <backend/wrapper/expat.hpp>
#undef SELECT_WRAPPER
#define SELECT_WRAPPER expat_wrapper
#endif

#ifdef BOOST_USE_LIBXML++
#include <backend/wrapper/libxml++.hpp>
#undef SELECT_WRAPPER
#define SELECT_WRAPPER libxml++_wrapper
#endif

// start defining the class boost::xml

#ifndef NO_DEFAULT_PARSER
#ifdef SELECT_WRAPPER

namespace boost
{
namespace xml
{
template<class string_type /* still figuring other callback parameters */>
  class XMLReader : public SELECT_WRAPPER<string_type> { };
} // namespace xml
} // namespace boost
#else
#error "No default parser defined."
#endif
#endif

#undef DEF_P

#endif 
