#include "test.pb.h"
#include <iostream>
#include <string>

using namespace std;
using namespace fixbug;

int main() {
    // LoginResponse rsp;
    // ResultCode *rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登陆处理失败了");

    GetFriendListsResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);

    User *user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(18);
    user2->set_sex(User::WOMEN);

    cout << "friend num: " << rsp.friend_list_size() << endl;

    cout << rsp.friend_list(1).sex() << endl;

    return 0;
}

int example1() {
    // 封装了 Login 请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据序列化 -> char*
    string send_str;
    if (req.SerializeToString(&send_str)) {
        cout << send_str.c_str() << endl;
    }

    // 从send_str反序列化
    LoginRequest reqB;
    if (reqB.ParseFromString(send_str)) {
        cout << reqB.name() << endl;
        cout << reqB.pwd() << endl;
    }

    return 0;
}