#pragma once
#include <thread>
#include <future>

class CThread
{
public:
	template<typename Func, typename... Args>
	CThread(Func&& pFunc, Args&&... args)
	{
		m_Thread = std::jthread(std::forward<Func>(pFunc), std::forward<Args>(args)...);
		//TODO: 시간 계산 추가
	}

	~CThread()
	{
		// jthread의 경우 자동으로 join 실행합니다.
	}

public:
	std::thread::id GetThreadID() { return m_Thread.get_id(); }
	void Wait();

private:
	std::jthread m_Thread;
};

template<typename T>
class CAsync
{
public:
	template<typename Func, typename... Args>
	CAsync(Func&& pFunc, Args&&... args)
	{
		m_Future = std::async(std::launch::async, std::forward<Func>(pFunc), std::forward<Args>(args)...);
		
		//TODO: 로그 추가 후 시간 계산 추가
	}

	~CAsync()
	{
		// Asnyc는 자동으로 get을 통해 소멸자 호출합니다.
	}

public:
	T GetResult()
	{
		return m_Future.get();
	}

private:
	std::future<T> m_Future;
};