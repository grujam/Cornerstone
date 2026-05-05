#pragma once
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <cassert>

enum class ELogCategories
{
	LOG_ThreadTime = 0,
	LOG_ENUMEND
};

const std::unordered_map<ELogCategories, std::string> LogCategoriesStringMap
{
    {ELogCategories::LOG_ThreadTime, "ThreadTime"},
    {ELogCategories::LOG_ENUMEND, "EnumEnd"}
};

//TODO: 이 line을 넣을만한 적당한 장소 필요
//assert((size_t)ELogCategories::LOG_ENUMEND == LogCategoriesStringMap.size() - 1);

//TODO: make it singleton
class CLog
{
public:
    CLog(std::string_view fileName, bool bWithTimeStamp)
    {
        std::filesystem::create_directories(LogPath);

        std::string fullPath = std::string(LogPath) + "\\" + std::string(fileName) + ".log";
        m_File.open(fullPath, std::ios::app);

        m_bTimeStamp = bWithTimeStamp;
    }

    ~CLog()
    {
        if (m_File.is_open())
            m_File.close();
    }

public:
    void Write(std::string_view message)
    {
        if (!m_File.is_open())
            return;

        if(m_bTimeStamp)
            m_File << GetTimestamp() << " " << message << "\n";
        else
            m_File << message << "\n";

        m_File.flush();
    }

private:
    std::string GetTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        return std::format("[{:%Y-%m-%d %H:%M:%S}]", now);
    }

private:
    std::ofstream m_File;
    bool m_bTimeStamp;

private:
    static const std::string LogPath;
};