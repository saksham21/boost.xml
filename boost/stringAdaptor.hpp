// this stringAdaptor class defines how our library is string-agnostic.
// the idea of implementation is taken from Arabica code

// include header files...

namespace boost
{

	template< class stringT>
	class default_string_adaptor_base
	{
	public:
		typedef stringT string_type;
		// some more will be inserted on the basis of implementation ...

	}; // class default_string_adaptor_base


	/* This template will be specialized for std::string and std::wstring */
	template< >
	class default_string_adapter<std::string> : public default_string_adaptor_tag, public default_string_adaptor_base<std::string>
	{

	public:

	static std::string construct_from_utf8(const char* str, int length)
	{

  		// some code here

  	  return std::string(str, length);

  	} // construct_from_utf8


  	static std::string construct_from_utf16(const char* str, int length)
  	{

	  	// some code here

 	   return std::string(str, length);

	} // construct_from_utf16

	// some more classes to be added depending upon more discussion...

	}: // class default_string_adapter

} // namespace boost
