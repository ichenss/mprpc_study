#include <iostream>
#include <string>

#include "user.pb.h"

using namespace std;

/*
UserService原来是一个本地服务，提供了两个进程内的本地方法，Login和GetFriendLists
*/
class UserService : public fixbug::UserServiceRpc // 使用在rpc服务发布端 (rpc服务提供者)
{
public:
    bool Login(string name, string pwd)
    {
        cout << "doing local service: Login " << endl;
        cout << "name: " << name << "pwd: " << pwd << endl;
    }

    // 重写基类UserServiceRpc的虚函数，下面这些方法都是框架直接调用的
    void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {

    }

};

int main() {

    return 0;
}