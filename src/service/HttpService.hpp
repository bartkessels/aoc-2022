#include <cpr/cpr.h>
#include <string>

namespace AOC2022::service
{
    class HttpService
    {
        public:
            ~HttpService() = default;

            std::string getRawRequest(std::string uri);
    };
}