#include "Request.h"

Request::Request()
{
    curl = curl_easy_init();
    
}

void Request::perform()
{
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_buffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            // curl_easy_strerror() will return a string with the error message
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            exit(-1);
        }
        std::cout << str_buffer;

    }
}

void Request::par()
{
    boost::json::value j = boost::json::parse(str_buffer);
    std::size_t n;
    n = j.as_array().size();
    st_json a;
    
    for (int g = 0; g < n; g++) {

        a.id = j.at(g).at("id").as_int64();
        a.name = j.at(g).at("name").as_string().c_str();
        a.username = j.at(g).at("username").as_string().c_str();
        a.email = j.at(g).at("email").as_string().c_str();
        a.street = j.at(g).at("address").at("street").as_string().c_str();
        a.suite = j.at(g).at("address").at("suite").as_string().c_str();
        a.city = j.at(g).at("address").at("city").as_string().c_str();
        a.zipcode = j.at(g).at("address").at("zipcode").as_string().c_str();
        a.geo_lat = j.at(g).at("address").at("geo").at("lat").as_string().c_str();
        a.geo_lng = j.at(g).at("address").at("geo").at("lng").as_string().c_str();
        a.phone = j.at(g).at("phone").as_string().c_str();
        a.website = j.at(g).at("website").as_string().c_str();
        a.company_name = j.at(g).at("company").at("name").as_string().c_str();
        a.company_catchPhrase = j.at(g).at("company").at("catchPhrase").as_string().c_str();
        a.company_bs = j.at(g).at("company").at("bs").as_string().c_str();

        all.push_back(a);

    }
}

void Request::show()
{
    for (int j = 0; j < all.size(); ++j) {
        std::cout <<"id:" << all[j].id << std::endl;
        std::cout << "name:" << all[j].name << std::endl;
        std::cout << "username:" << all[j].username << std::endl;
        std::cout << "email:" << all[j].email << std::endl;
        std::cout << "street:" << all[j].street << std::endl;
        std::cout << "suite:" << all[j].suite << std::endl;
        std::cout << "city:" << all[j].city << std::endl;
        std::cout << "zipcode:" << all[j].zipcode << std::endl;
        std::cout << "geo_lat:" << all[j].geo_lat << std::endl;
        std::cout << "geo_lng:" << all[j].geo_lng << std::endl;
        std::cout << "phone:" << all[j].phone << std::endl;
        std::cout << "website:" << all[j].website << std::endl;
        std::cout << "company_name:" << all[j].company_name << std::endl;
        std::cout << "company_catchPhrase:" << all[j].company_catchPhrase << std::endl;
        std::cout << "company_bs:" << all[j].company_bs << std::endl;
        std::cout << std::endl;
    }



}

Request::~Request()
{
    curl_easy_cleanup(curl);
    all.clear();
   
}

 size_t  Request:: got_data(char* buffer, size_t itemsize, size_t amount, std::string* userp) {

    size_t bytes = itemsize * amount;
    (*userp).append(buffer, bytes);
    return bytes;
}



