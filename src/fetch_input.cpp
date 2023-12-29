#include <string>
#include <curl/curl.h>
#include <sstream>
#include <tuple>
#include <vector>
#include <map>
#include <iostream>

#include "env.h"
#include "fetch_input.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string curl_get(std::string url, std::vector<std::tuple<CURLoption, std::string>> options = {}) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // Setting the URL to fetch from
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Adding the user set options to the get
        for (const auto& option : options) {
            curl_easy_setopt(curl, std::get<0>(option), std::get<1>(option).c_str());
        }

        // Running the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return readBuffer;
}

std::string fetch_input(int question_number) {
    std::map<std::string, std::string> env_vars = parse_env_file();
    
    std::ostringstream url;
    std::ostringstream cookies;
    url << "https://adventofcode.com/2023/day/" << question_number << "/input";
    cookies << "session=" << env_vars["session"] << ";";
    
    return curl_get(url.str(), {{CURLOPT_COOKIE, cookies.str()}});
}