
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
    std::string buff[MAXLINE];
    std::string sendline;
    std::string lastsend;

    std::cout <<  "请输入字符串(ps:'$'为结束串，仅前四个以内有效)：" << std::endl;

    int i = 0;
    char c;

    std::cin >> buff[i];

    while( i < 5 ){
        i++;
        if(getchar() == '\n'){
            break;
        }
        std::cin >> buff[i];
    }
    
    if(i == 0){
        return "\0";
    }

    lastsend = lastsend +"{" + "\"" + "num" + "\"" + ":" + "\"" + "1" + "\"" + ",";
    sendline = sendline  + "\"" + "comm_name" + "\"" + ":" + "\"" + buff[0] + "\"" + ",";
    
    if(i == 1){
        sendline[strlen(sendline.c_str())-1] = '}';
        lastsend[8] = '1';
        return (lastsend + sendline);
    }
    sendline = sendline + "\"" + "jkey" + "\"" + ":" + "\"" + buff[1] + "\"" + ",";
    if(i == 2){
        sendline[strlen(sendline.c_str())-1] = '}';
        lastsend[8] = '2';
        return (lastsend + sendline);
    }
    sendline = sendline + "\"" + "jvalue" + "\"" + ":" + "\"" + buff[2] + "\""+",";
    if(i == 3){
        sendline[strlen(sendline.c_str())-1] = '}';
        lastsend[8] = '3';
        return (lastsend + sendline);
    }

    sendline = sendline + "\"" + "jadd" + "\"" + ":" + "\"" + buff[3] + "\""+",";
    if(i == 4){
        lastsend[8] = '4';
        sendline[strlen(sendline.c_str())-1] = '}';
        return (lastsend + sendline);
    }

    /*暂时定义为四个还可以加参数*/
    lastsend[8] = '4';
    sendline[strlen(sendline.c_str())-1] = '}';
    return (lastsend + sendline);
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
std::string fdb_json::get_num()
{
    if(jflag == 0){

        return "\0";
    }
    
    return root["num"].asString();
}

void fdb_json::print_str()
{
    std::cout << get_num() << " " << get_comm_name() << " " << get_key() << " " << get_value()  << " " << get_jadd() << std::endl;
}
