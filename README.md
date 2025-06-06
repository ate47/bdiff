# MWBDiff
A modified implementation of VCDIFF (https://www.researchgate.net/publication/279639182_The_VCDIFF_Generic_Differencing_and_Compression_Data_Format) used by Modern Warfare 2019 and Modern Warfare 2 2022's FastFiles for data compression.

# Usage

Add `bdiff.hpp` to your program.

bdiff can be used using buffers or internal.

Two defines can be used:
- `BDIFF_STATIC` - Compile as a static lib
- `BDIFF_EXPORT` - Export part of the shared lib, when not set the functions are imported

## Using buffer

```cpp
bool bdiff(
    unsigned char* sourceBuffer, size_t sourceBufferSize, 
    unsigned char* patchBuffer, size_t patchBufferSize, 
    unsigned char* outBuffer, size_t outBufferSize);
```
    
where sourceBuffer and patchBuffer are pointers to the source and patch files, and outBuffer is a pointer to memory to be filled with the resulting patched FastFile.

outBufferSize must be the EXACT size of the resulting patched FastFile.

Will return false if any errors are encountered during diffing, true if was successful.

## Using internal

```cpp
bool bdiff_internal(diffInfo* s_diffInfo, 
    unsigned char* (__fastcall* loadSourceData)(void* s_diffInfo, size_t offset, size_t size),
    unsigned char* (__fastcall* loadPatchData)(void* s_diffInfo, size_t offset, size_t size, size_t* pOffset),
    unsigned char* (__fastcall* setupDestData)(void* s_diffInfo, size_t size));
```

Will return false if any errors are encountered during diffing, true if was successful.