#include "mprpcconfig.h"

#include <iostream>

// 负责解析加载配置文件
void MprpcConfig::LoadConfigFile(const char *config_file) 
{
    FILE *pf = fopen(config_file, "r");
    if (nullptr == pf) 
    {
        std::cout << config_file << "is not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
// 查询配置项信息
 std::string MprpcConfig::Load(std::string &key) 
 {

 }