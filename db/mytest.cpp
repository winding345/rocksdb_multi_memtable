//
// Created by hao on 2018/12/4.
//

#include <cstdio>
#include <string>

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"
#include <iostream>

using namespace std;
using namespace rocksdb;

const std::string PATH = "./myrocksdbkv";

int main(){
    DB* db;
    Options options;
    options.create_if_missing = true;
    Status status = DB::Open(options, PATH, &db);
    assert(status.ok());
    string key_,value_;
    while(1)
    {
        std::cin>>key_;
        if(key_=="-1")
            break;
        std::cin>>value_;
        Slice key(key_);
        Slice value(value_);

        std::string get_value;
        status = db->Put(WriteOptions(), key, value);
        if(status.ok()){
            status = db->Get(ReadOptions(), key, &get_value);
            if(status.ok()){
                printf("get %s\n", get_value.c_str());
            }else{
                printf("get failed\n");
            }
        }else{
            printf("put failed\n");
        }

    }

    delete db;
}
