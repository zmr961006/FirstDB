
#include"FDB_json.h"

void fdb_json::json_tostr(std::string buff)
{
    if(reader.parse(buff.c_str(), root) == 0){
        std::cout <<  __LINE__ << ":string to json error "  << std::endl;
	    exit(-1);
    }

    jflag = 1;
}

std::string fdb_json::input_str_tojson()
{
    char buff[MAXLINE];
    std::string sendline;

    std::cout <<  "请输入三个以空格隔开的字符串：" << std::endl;

    std::cin >> buff;
    sendline = "{";
    sendline = sendline  + "\"" + "comm_name" + "\"" + ":" + "\"" + buff + "\"" + ",";

    
    bzero(buff, sizeof(buff) );
    std::cin >> buff;
    sendline = sendline + "\"" + "jkey" + "\"" + ":" + "\"" + buff + "\"" + ",";

    bzero(buff, sizeof(buff) );
    std::cin >> buff;
    sendline = sendline + "\"" + "jvalue" + "\"" + ":" + "\"" + buff + "\"" + "}" + "\0";

    return sendline;
}

std::string fdb_json::get_comm_name()
{
    if(jflag == 0){
    
        return "\0";
    }

    return root["comm_name"].asString();
}

std::string fdb_json::get_key()
{
    if(jflag == 0){

        return "\0";
    }
    
    return root["jkey"].asString();
}

std::string fdb_json::get_value()
{
    if(jflag == 0){

        return "\0";
    }
    
    return root["jvalue"].asString();
}

void fdb_json::print_str()
{
    std::cout << get_comm_name() << " " << get_key() << " " << get_value() << std::endl;
}
