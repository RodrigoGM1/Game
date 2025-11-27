#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, ""); 

    wchar_t mi_cadena[] = L"Hola mundo";
    wprintf(L"La cadena es: %ls\n", mi_cadena);
    return 0;
}