#include<bits/stdc++.h>
using namespace std;

//  must include all useful header files

namespace boost
{
	namespace xml
	{

		template< class string_type, class string_adaptor_type>
		class xmlReaderInterface
		{
		public:
			
			/* Interface for reading an XML document using callback. This interface allows an application
			to set and query features and properties in the parser, to register event handlers for document
			processing, and to initiate a document parse.	*/

			/* Various types of functions and features of the xml Document parser like errorHandling and 
			contentHandling will also be impleneted here */

			void parse(InputSource *abc)
			{
				/* here the document to be parsed will be finally called and from here wrapper function of the
				particular backend will handle the parsing calls. */

				/* InputSource tells us whether the input stream is byte-stream or character-stream or whether
				the entire document is given as query or it is a buffer stream. The "souce abc" will be decided
				correspondingly. */
			}

		private:

		};
	} // namespace xml
} // namespace boost
