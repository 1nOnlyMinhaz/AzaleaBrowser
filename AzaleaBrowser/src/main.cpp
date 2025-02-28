#include <iostream>
#include <string>
#include <string_view>
#include "network/url/url.h"
#include "network/protocols.h"


int main(int, char *[]) {
    const std::string_view validProtocols[]{ "http", "https" };
    std::string urlstr{ "://google.com" };
    URLParser::URL testURL{ urlstr };
    std::cout << testURL.getURL();
    return 0;
}