#define STATUS_NONE			0
#define STATUS_LOADING_MAP	1
#define STATUS_SAVING		2

#define DllExport	__declspec(dllexport)

#define MAX_PATH 260
typedef char16_t utf16_char;

typedef void *(__thiscall *t_LoadMap)(void*, const void*, void*, const void*, void*);

typedef void (__thiscall *t_SaveGame)(void*, int);

t_LoadMap					g_oLoadMap;
t_SaveGame					g_oSaveGame;

DllExport int			g_status = STATUS_NONE;
DllExport utf16_char	g_map[MAX_PATH];

DllExport
void set_map_ascii(const char *map)
{
	for (int i = 0; i < MAX_PATH; i++)
	{
		((char *)g_map)[i] = map[i];
		if (map[i] == '\0')
			break;
	}
}

DllExport
void set_map_utf16(const utf16_char *map)
{
	for (int i = 0; i < MAX_PATH; i++)
	{
		g_map[i] = map[i];
		if (map[i] == 0)
			break;
	}
}

DllExport
void* __fastcall Detour_LoadMap(void *This, void *edx, const void *URL, void *Pending, const void *TravelInfo, void *Error)
{
	utf16_char *map = *((utf16_char **)URL + 7);
	set_map_utf16(map);

	g_status = STATUS_LOADING_MAP;
	void *level = g_oLoadMap(This, URL, Pending, TravelInfo, Error);
	g_status = STATUS_NONE;

	return level;
}

DllExport
void __fastcall Detour_SaveGame(void *This, void *edx, int Position)
{
	g_status = STATUS_SAVING;
	g_oSaveGame(This, Position);
	g_status = STATUS_NONE;
}

int main()
{
	return 0;
}
