#ifndef __GDL_MODELEXCEPTION__HH__
#define __GDL_MODELEXCEPTION__HH__

#include <exception>
#include <string>

namespace gdl
{
	///////////////////////////////
	/// Classe used to decribe error from Model Manipulation
	///////////////////////////////
	class ModelException : public std::exception
	{
	private:
		std::string		m_what;

	public:
		ModelException(const std::string&);
		virtual ~ModelException() throw() {}

		virtual const char* what() const throw();

	};

}
#endif /* __GDL_MODELEXCEPTION__HH__ */
