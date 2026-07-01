#include "include/MonoBridge.h"

namespace MB
{
	bool _bInitialized = false;

	MBG_STATUS Initialize(HMODULE hMono)
	{
		if (_bInitialized)
			return MBG_ALREADYINITIALIZED;

		_bInitialized = true;
		return MBG_OK;
	}

	const char* StatusToString(MBG_STATUS status)
	{
		switch (status)
		{
		case MBG_OK:
			return "OK";
		case MBG_NOTINITIALIZED:
			return "NOTINITIALIZED";
		case MBG_ALREADYINITIALIZED:
			return "ALREADYINITIALIZED";
		case MBG_MONONOTFOUND:
			return "MONONOTFOUND";
		case MBG_UNKNOWN:
			return "UNKNOWN";
		default:
			break;
		}

		return "";
	}
}