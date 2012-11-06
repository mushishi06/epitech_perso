#ifndef _GDL_GL_ERROR_HPP_
#define _GDL_GL_ERROR_HPP_

#include <GL/gl.h>

inline char const *			glGetStrError(size_t glError)
{
	static struct {
		size_t				e;
		char const * const	str;
	} errs[] = {
		{GL_NO_ERROR, "GL_NO_ERROR"},
		{GL_INVALID_ENUM, "GL_INVALID_ENUM"},
		{GL_INVALID_VALUE, "GL_INVALID_VALUE"},
		{GL_INVALID_OPERATION, "GL_INVALID_OPERATION"},
		{GL_STACK_OVERFLOW, "GL_STACK_OVERFLOW"},
		{GL_STACK_UNDERFLOW, "GL_STACK_UNDERFLOW"},
		{GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY"},
		{GL_TABLE_TOO_LARGE, "GL_TABLE_TOO_LARGE"}
	};

	if (glError == 0)
		return "";
	for (size_t i = 0; i < sizeof(errs) / sizeof(*errs); ++i)
	{
		if (errs[i].e == glError)
			return errs[i].str;
	}
	return "GL ERROR UNKNOWN ??";
}

inline char const *			glGetStrError()
{
	return glGetStrError(glGetError());
}

#endif // _GDL_GL_ERROR_HPP_

