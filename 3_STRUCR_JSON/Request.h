#pragma once
#ifndef REQUEST_H
#define REQUEST_H
#include"JSON_STRUCT.h"
#include <iostream>
#include <curl/curl.h>
#include <boost/json.hpp>
#include <boost/json/value.hpp>
#include <vector>
class Request
{
   private:

     static size_t got_data(char* buffer, size_t itemsize, size_t amount, std::string* userp);

     std::vector<st_json> all;
     std::string str_buffer;

     CURL* curl;
     CURLcode res;

   public:
    
        Request();
        void perform();
        void par();
        void show();
        ~Request();

        
    
};

#endif