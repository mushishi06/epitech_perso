#ifndef GDL_ANIMSTATES__HPP
# define GDL_ANIMSTATES__HPP

namespace gdl
{
	namespace Anim
	{
		////////////////////////////////////////////////////////////
		/// Enum for the states of the animations
		////////////////////////////////////////////////////////////
		enum AnimStates
		{
			STOP = 0, // Stop the animation
			RUN = 1, // Run the animation
			LOOP = 2, // The animation is play in loop.
			REVERT = 4, // Revert the animation
			PAUSE = 8 // Pause the animation
		};
	}
}

# endif /* !GDL_ANIMSTATES__HPP */
