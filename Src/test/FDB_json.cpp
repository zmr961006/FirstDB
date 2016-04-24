#include<iostream>
#include"./FDB_server.h"
#include"./FDB_epoll.h"
#include"./FDB_Socket.h"
#include<thread>
#include"./FDB_buffer.h"
#include"../jsoncpp-src-0.5.0/include/json/json.h"

#include<stdlib.h>
#include<string.h>
/*Json 测试****************/

int main(){
    //基础测试，测试用例来自LVH 学长博客
    std::string test ="{\"id\":1,\"name\":\"kurama\"}";
    Json::Reader reader;
    Json::Value value ;

    if(reader.parse(test,value)){
        if(!value["id"].isNull()){

            std::cout << value["id"].asInt() << std::endl;
            std::cout << value["name"].asString() << std::endl;
        }

    }

    int mark = 1;
    std::string pwd("123456");

    //std::string test = "{\"id\":1,\"name\":\"kurama\"}";

    //Json::Reader reader;
    //Json::Value value;

    if(reader.parse(test,value)){
        
        if(!value["id"].isNull()){

            std::cout << value["id"].asInt() << std::endl;
            std::cout << value["name"].asString() << std::endl;

        }

    }

    Json::Value json;

    json["mark"] = Json::Value(mark);
    json["pass"] = Json::Value(pwd);

    std::cout << json["mark"].asInt() << json["pass"].asString() << std::endl;

    std::string s;
    s = json.toStyledString();

    std::cout << s << std::endl;

    Json::Value js;
    
    reader.parse(s,js);
    std::cout << js["pass"].asString() << std::endl;

    std::cout << " * "<<s << std::endl;
    

    
    std::cout << "ssssssssssssssss" << std::endl;
    Json::FastWriter writer;
    std::string out = writer.write(js);
    std::cout << out << std::endl;

    std::cout << "js" << out << sizeof(js) << std::endl;
    std::cout << "ss" << js  << std::endl;
    char buf[100];
    
    //memcpy(buf,js,sizeof(js));
    std::cout << buf << std::endl;
    return 0;

}

