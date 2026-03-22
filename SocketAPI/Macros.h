#pragma once

#ifdef SOCKETAPI_EXPORTS
#define SOCKET_API __declspec(dllexport)
#else SOCKETAPI_EXPORTS
#define SOCKET_API __declspec(dllimport)
#endif