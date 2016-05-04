/*************************************************************************
	> File Name: FDB_json.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年05月04日 星期三 10时11分25秒
 ************************************************************************/

#include"./FDB_json.h"



JSon::JSon(std::string key,std::string operation,int type_data,int type_data2,std::string buf){

    json_obj["key"] = Json::Value(key);
    json_obj["operation"] = Json::Value(operation);
    json_obj["type_data"] = Json::Value(type_data);
    json_obj["type_data2"] = Json::Value(type_data2);
    json_obj["buf"]        = Json::Value(buf);

    message = json_obj.toStyledString();

    

}


int JSon::Json_get_size(){
    
    return message.length();

}

int JSon::Json_get_typedata(){

    return json_obj["type_data"].asInt();

}


int JSon::Json_get_typedata2(){
    
    return json_obj["type_data2"].asInt();

}


int JSon::Json_get_ack(){
    
    return json_obj["ack"].asInt();
    
}


std::string JSon::Json_get_key(){
    

    return json_obj["key"].asString();

}


std::string JSon::Json_get_operation(){
    
    return json_obj["operation"].asString();


}


std::string JSon::Json_get_buf(){
    
    return json_obj["buf"].asString();
    
}


