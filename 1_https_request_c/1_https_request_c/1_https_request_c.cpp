#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

size_t got_data(char* buffer, size_t itemsize, size_t amount);

int main(void) {
	CURL* curl = curl_easy_init();
	CURLcode res;
    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            // curl_easy_strerror() will return a string with the error message
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            return -1;
        }
        curl_easy_cleanup(curl);
    }
	
	return 0;
 }

size_t got_data(char* buffer, size_t itemsize, size_t amount) {

    size_t bytes = itemsize * amount;

    for (int i = 0; i < bytes; i++) {
        printf("%c", buffer[i]);
    }
    return bytes;
}