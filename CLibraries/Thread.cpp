#include "pch.h"
#include "Thread.h"

void CThread::Wait()
{

	
}

// ----------------------------------- ThreadManager --------------------------------------------

void CThreadManager::AddThreadToPool(const std::shared_ptr<CThread>& pThread)
{
	if (m_ThreadPool.contains(pThread))
		return;

	m_ThreadPool.insert(pThread);
}

void CThreadManager::RemoveThreadToPool(const std::shared_ptr<CThread>& pThread)
{
	if (m_ThreadPool.contains(pThread))
		m_ThreadPool.erase(pThread);
}

void CThreadManager::OnTick()
{
	
}

void CDeadlockDetection::OnDeadlockDetected()
{
}

void CDeadlockDetection::DetectDeadlock()
{

}
