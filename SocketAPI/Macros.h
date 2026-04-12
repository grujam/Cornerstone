#pragma once

#ifdef SOCKETAPI_EXPORTS
#define SOCKET_API __declspec(dllexport)
#else 
#define SOCKET_API __declspec(dllimport)
#endif