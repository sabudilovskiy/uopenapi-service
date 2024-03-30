#pragma once
#include <string>
#include <uopenapi/enum/declare.hpp>

namespace models{
    UOPENAPI_DECLARE_ENUM(ErrorCode,
                          int,
                          invalid_token,
                          username_busy,
                          invalid_credentials
                          );
    struct ErrorResponseBody{
        std::string message;
        ErrorCode error_code;
    };

    struct ErrorResponse{
        ErrorResponseBody body;
    };
}
