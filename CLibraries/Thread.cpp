#include "pch.h"
#include "Thread.h"

#define CHECK_THREAD_VALID \
if(!m_Thread.joinable()) \
	return; \

void CThread::Wait()
{
	CHECK_THREAD_VALID;

	
}
