#include "pipeline.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include "defines.h"

namespace engine
{
    Pipeline::Pipeline(const std::string& vertPath, const std::string& fragPath)
    {
        createGraphicsPipeline(vertPath, fragPath);
    }

    Pipeline::~Pipeline()
    {

    }

    void Pipeline::createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath)
    {
        auto vertShader = readFile(vertPath);
        auto fragShader = readFile(fragPath);

        std::cout << vertShader.size() << std::endl;
        std::cout << fragShader.size() << std::endl;
    }

    std::vector<char> Pipeline::readFile(const std::string& filePath)
    {
        std::string path = std::string(ENGINE_DIR) + filePath;
        std::ifstream in(path, std::ios::ate | std::ios::binary);

        if (!in.is_open())
        {
            throw std::runtime_error("open file error:" + path);
        }

        std::size_t fileSize = static_cast<std::size_t>(in.tellg());
        std::vector<char> buffer(fileSize);
        in.seekg(0);
        in.read(buffer.data(), fileSize);
        in.close();
        return buffer;
    }
}
