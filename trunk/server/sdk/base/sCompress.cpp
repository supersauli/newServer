#include "sCompress.h"
bool sCompress::Init()
{
	return true;
}
bool sCompress::LoadConfig()
{
	return true;
}
int sCompress::Compress(const char* source, char* dest, int sourceSize, int maxDestSize)
{
		return LZ4_compress_default(source,dest,sourceSize,maxDestSize);
}

int sCompress::Decompress (const char* source, char* dest, int compressedSize, int maxDecompressedSize)
{
	return LZ4_decompress_safe(source,dest,compressedSize,maxDecompressedSize);

}
