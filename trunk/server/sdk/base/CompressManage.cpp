#include "CompressManage.h"
using namespace sdk;
int CompressManage::Compress(const char* source, char* dest, int sourceSize, int maxDestSize)
{
		return LZ4_compress_default(source,dest,sourceSize,maxDestSize);
}

int CompressManage::Decompress (const char* source, char* dest, int compressedSize, int maxDecompressedSize)
{
	return LZ4_decompress_safe(source,dest,compressedSize,maxDecompressedSize);

}
