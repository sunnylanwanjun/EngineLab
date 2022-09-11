#pragma once

#include <string>
#include <vector>

namespace engine
{
    class Pipeline
    {
    public:
        Pipeline(const std::string& vertPath, const std::string& fragPath);
        virtual ~Pipeline();
    private:
        static std::vector<char> readFile(const std::string& filePath);
        void createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath);
    };
}
