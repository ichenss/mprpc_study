#include <iostream>
#include <string>

#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

/*
UserService原来是一个本地服务，提供了两个进程内的本地方法，Login和GetFriendLists
*/
class UserService : public fixbug::UserServiceRpc // 使用在rpc服务发布端 (rpc服务提供者)
{
public:
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "doing local service: Login " << std::endl;
        std::cout << "name: " << name << "pwd: " << pwd << std::endl;
        return true;
    }

    // 重写基类UserServiceRpc的虚函数，下面这些方法都是框架直接调用的
    void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 做本地业务
        bool login_result = Login(name, pwd);

        // 把响应写入, 包括错误码、错误消息以及返回值
        fixbug::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_success(login_result);

        // 执行回调操作, 执行响应对象数据的序列化和网络发送(都是由框架来完成的)
        done->Run();
    }
};

int main(int argc, char **argv) 
{
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    // 把UserService对象发布到rpc节点上
    RpcProvider provider;  // provider是一个rpc网络服务对象
    provider.NotifyService(new UserService());

    // 启动一个rpc服务发动节点，run以后，进程处于阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}