#ifndef MonoBridge_h__
#define MonoBridge_h__

struct HINSTANCE__;
using HMODULE = HINSTANCE__*;

/**
 * @brief Namespace that contains all of MonoBridge's exposed functionality.
 */
namespace MB
{
	/**
	 * @brief Potential errors in initialization.
	 */
	enum MBG_STATUS
	{
		/** Completed successfully. */
		MBG_OK = 0,
		/** Already initialized. */
		MBG_ALREADYINITIALIZED,
		/** Failed to find mono runtime. */
		MBG_MONONOTFOUND,
		/** MonoBridge isn't initialized. */
		MBG_NOTINITIALIZED,
		/** Unknown error. */
		MBG_UNKNOWN
	};

	/**
	 * @brief Initializes MonoBridge.
	 *
	 * @param hMono Handle to the loaded mono module.
	 *
	 * @return A value from MBG_STATUS.
	 */
	MBG_STATUS Initialize(HMODULE hMono);

	/**
	 * @brief Converts MB_STATUS into C strings.
	 *
	 * @param status Status code.
	 *
	 * @return MBG_STATUS as a C string.
	 */
	const char* StatusToString(MBG_STATUS status);
}

#endif // MonoBridge_h__
