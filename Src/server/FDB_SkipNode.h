/*************************************************************************
	> File Name: SkipNode.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年04月16日 星期六 12时51分25秒
 ************************************************************************/

//
#ifndef _SKIPNODE_H
#define _SKIPNODE_H
#endif

//跳跃表结点类
template<class E>
class nodeStructure
{
public:
    E key;
    E value;
    nodeStructure<E>* forward[1];
};

