#ifndef _URL_H_ 
#define _URL_H_ 


#include <string>


extern void UrlEncode(const std::string& src, std::string& dst);
extern int UrlDecode(const std::string& src, std::string& dst);

#endif //_URL_H_