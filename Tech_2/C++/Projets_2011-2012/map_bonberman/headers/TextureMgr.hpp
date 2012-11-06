#ifndef __GDL_TEXTURE__HH__
#define __GDL_TEXTURE__HH__

#include "FBX.hpp"
#include "Texture.h"
#include "FBXModel.hpp"

namespace gdl
{
	typedef unsigned int uint;

	class TextureMgr
	{
	private:
		TextureMgr();
		TextureMgr(const TextureMgr&);

		~TextureMgr();

		TextureMgr&	operator=(const TextureMgr&);

	public:
		void	SetCurrent(FBXModel*);

		static TextureMgr&	GetInstance();

		int		GetId(KFbxTexture*, VSTexture**);
		void	RegisterId(VSTexture*, uint);

	private:
		static TextureMgr*	_instance;

		std::map<VSTexture*, uint> m_mappinTextures;

		FBXModel*		m_current;

		friend class FBXModel;
	};
}
#endif /* __GDL_TEXTURE__HH__ */
