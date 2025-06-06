#pragma once

#ifdef BDIFF_STATIC
#define BDIFF_API

#else // !BDIFF_STATIC

#ifdef BDIFF_EXPORT
#define BDIFF_API extern "C" __declspec(dllexport)
#else // !BDIFF_EXPORT
#define BDIFF_API extern "C" __declspec(dllimport)
#endif // ifdef BDIFF_EXPORT

#endif // #ifdef BDIFF_STATIC
namespace bdiff
{
    struct VcdState
    {
        unsigned int next_slot;
        size_t anear[4];
        size_t asame[768];
        unsigned char *pAddr;
    };

    struct diffInfo
	{
		VcdState vcd;
		bool headerRead;
        void* state;
    };

    BDIFF_API bool bdiff_internal(diffInfo* s_diffInfo, 
        unsigned char* (__fastcall* loadSourceData)(void* s_diffInfo, size_t offset, size_t size),
        unsigned char* (__fastcall* loadPatchData)(void* s_diffInfo, size_t offset, size_t size, size_t* pOffset),
        unsigned char* (__fastcall* setupDestData)(void* s_diffInfo, size_t size));

    BDIFF_API bool bdiff(
        unsigned char *sourceBuffer, size_t sourceBufferSize,
        unsigned char *patchBuffer, size_t patchBufferSize,
        unsigned char *outBuffer, size_t outBufferSize);
}