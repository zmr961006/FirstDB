
#include"FDB_json.h"

std::string fdb_json::json_tostr(std::string buff)
{
    std::string str;

    if(reader.parse(buff.c_str(), root) == 0){
        std::cout <<  __LINE__ << ":string to json error "  << std::endl;
	    exit(-1);
    }
    str = str + root["comm_name"].asString() +" " + root["jkey"].asString() +" " + root["jvalue"].asString() + " " + root["jadd"].asString();
    jflag = 1;
    return str;

}

std::string fdb_json::str_tojson(int i, std::string buff[MAXLINE])
{
    std::string sendline;
    if(i <= 0){
        return "\0";
    }

    sendline = sendline + "{" + "\"" + "comm_name" + "\"" + ":" + "\"" + buff[0] + "\"" + ",";
    
    if(i == 1){
        sendline[strlen(sendline.c_str())-1] = '}';
        return sendline;
    }
    sendline = sendline + "\"" + "jkey" + "\"" + ":" + "\"" + buff[1] + "\"" + ",";
    if(i == 2){
        sendline[strlen(sendline.c_str())-1] = '}';
        return sendline;
    }
    sendline = sendline + "\"" + "jvalue" + "\"" + ":" + "\"" + buff[2] + "\""+",";
    if(i == 3){
        sendline[strlen(sendline.c_str())-1] = '}';
        return sendline;
     }
    sendline = sendline + "\"" + "jadd" + "\"" + ":" + "\"" + buff[3] + "\""+",";
    if(i == 4){
        sendline[strlen(sendline.c_str())-1] = '}';
        return sendline;
    }

    /*暂时定义为四个还可以加参数*/
    sendline[strlen(sendline.c_str())-1] = '}';
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

std::string fdb_json::get_jadd()
{
    if(jflag == 0){

        return "\0";
    }
    
    return root["jadd"].asString();
}

void fdb_json::print_str()
{
    std::cout << get_comm_name() << " " << get_key() << " " << get_value()  << " " << get_jadd() << std::endl;
}
