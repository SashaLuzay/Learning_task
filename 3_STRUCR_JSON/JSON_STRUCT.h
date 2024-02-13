#pragma once
#ifndef JSON_STRUCT_H
#define JSON_STRUCT_H
#include <iostream>
using namespace std;
struct st_json {
    int64_t id;
    string name;
    string username;
    string email;
    string street;
    string suite;
    string city;
    string zipcode;
    string geo_lat;
    string geo_lng;
    string phone;
    string website;
    string company_name;
    string company_catchPhrase;
    string company_bs;
};

#endif

