#include <iostream>
#include <curl/curl.h>
class Request {
private:
    static  size_t  got_data(char* buffer, size_t itemsize, size_t amount, std::string* userp) {

        size_t bytes = itemsize * amount;
        (*userp).append(buffer, bytes);
        return bytes;
    }
    CURL* curl = curl_easy_init();
    CURLcode res;

    std::string str_buffer;
public:
    void perform() {


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

            curl_easy_cleanup(curl);
        }
    }

};