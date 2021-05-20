///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_SERVER_MAIN_OPT_HPP

#include "xos/app/console/protocol/xttp/server/main.hpp"
#include "xos/app/console/protocol/http/base/main.hpp"

#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPT "respond"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG "[{ filename | url }]"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTUSE "Send http response"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_S "s::"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C 's'
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTION \
   {XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPT, \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPT "ok"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTARG "[0..n]"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTUSE "OK http response status"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTVAL_S "k::"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTVAL_C 'k'
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTION \
   {XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPT, \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPT "not-found"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTARG "[0..n]"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTUSE "Not Found http response status"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTVAL_S "f::"
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTVAL_C 'f'
#define XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTION \
   {XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPT, \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_S \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTVAL_S \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTVAL_S \

#define XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTION \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTION \
    XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTION \

#define XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_CHARS \
    XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_CHARS

#define XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_OPTIONS \
    XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_PROTOCOL_HTTP_SERVER_MAIN_ARUMENTS_CHARS 0
#define XOS_PROTOCOL_HTTP_SERVER_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {
namespace server {

/// class main_optt
template <class TExtends = xttp::server::maint<xttp::server::main_optt<http::base::main> >, class TImplements = typename TExtends::implements>
class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives; 
    
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    /// constructors / destructor
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }

protected:
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;

    /// ...options...
    virtual const char_t* respond_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        optarg = XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG;
        chars = XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTUSE;
        return chars;
    }
    virtual const char_t* status_ok_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTUSE;
        return chars;
    }
    virtual const char_t* status_not_found_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTUSE;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C:
            err = this->on_respond_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTVAL_C:
            err = this->on_status_ok_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTVAL_C:
            err = this->on_status_not_found_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C:
            chars = respond_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_STATUS_OK_OPTVAL_C:
            chars = status_ok_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_STATUS_NOT_FOUND_OPTVAL_C:
            chars = status_not_found_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_PROTOCOL_HTTP_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...arguments...
    virtual const char_t* arguments(const char_t**& args) {
        args = XOS_PROTOCOL_HTTP_SERVER_MAIN_ARUMENTS_ARGS;
        return XOS_PROTOCOL_HTTP_SERVER_MAIN_ARUMENTS_CHARS;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server
} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_HTTP_SERVER_MAIN_OPT_HPP
