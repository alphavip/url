#include <memory.h>
#include "Url.h"

int UrlDecode(const std::string& src, std::string& out)
{
    int i, j, a, b;
#define HEXTOI(x) (isdigit(x) ? x - '0' : x - 'W')

    for (size_t i = 0; i < src.size(); ++i)
    {
        if (src[i] == '%') 
        {
            if (i < src.size() - 2 && isxdigit(src[i + 1]) && isxdigit(src[i + 2])) 
            {
                a = tolower(src[i + 1]);
                b = tolower(src[i + 2]);
                out += (char) ((HEXTOI(a) << 4) | HEXTOI(b));
                i += 2;
            }
            else
            {
                //illegal urlencode str
                return -1;
            }
            
        } 
        else if (src[i] == '+')
        {
            out += ' ';
        } 
        else 
        {
            out += src[i];
        }
    }

    return 0;
}


void UrlEncode(const std::string& src, std::string& out)
{
    const char *hex = "0123456789abcdef";
    const static std::string safe("._-$,;~()/");
    size_t i = 0;
    
    for (i = 0; i < src.length(); ++i)
    {
        const unsigned char c = src[i];
        if (isalnum(c) || (safe.find(c) != std::string::npos)) 
        {
            out += c;
        } 
        else if (c == ' ') 
        {
            out += "+";
        } 
        else 
        {
            out += "%";
            out += hex[c >> 4];
            out += hex[c & 15];
        }
    }
}