#ifndef GDL_ASSERTEXCEPTION__HPP
# define GDL_ASSERTEXCEPTION__HPP

# include <string>

namespace gdl
{
	////////////////////////////////////////////////////////////
	/// Send an assert.
	///
	/// \param condition Condition to test
	/// \param msg Message when the condition failed
	////////////////////////////////////////////////////////////
	void	Assert(bool condition, const std::string& msg);
}

// #include <exception>
// #include <string>

// class AssertException : public exception
// {
// private:
//	 const std::string& m_what;

//	 AssertException(const std::string& _error);

//	 virtual const char* what() const throw();

//	 static inline void Assert(bool expression, const std::string& msg) throw(AssertException);
// };

#endif /* !GDL_ASSERTEXCEPTION__HPP */
