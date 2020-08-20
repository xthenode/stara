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
///   Date: 8/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPT_HPP

#include "xos/app/console/main.hpp"

#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPT "request"
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTARG ""
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTUSE "Send xttp request"
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTVAL_S "r"
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTVAL_C 'r'
#define XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTION \
   {XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPT, \
    XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPT "get"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTARG_RESULT 0
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTARG ""
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTUSE "GET xttp request method"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTVAL_S "g"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTVAL_C 'g'
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTION \
   {XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPT, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTARG_REQUIRED, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTARG_RESULT, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTVAL_C}, \

#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPT "post"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTARG_RESULT 0
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTARG ""
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTUSE "POST xttp request method"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTVAL_S "t"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTVAL_C 't'
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTION \
   {XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPT, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTARG_REQUIRED, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTARG_RESULT, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTVAL_C}, \

#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPT "method"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTARG_RESULT 0
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTARG "{ GET | POST | ...}"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTUSE "Xttp request method"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTVAL_S "m:"
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTVAL_C 'm'
#define XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTION \
   {XOS_PROTOCOL_XTTP_MAIN_METHOD_OPT, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTARG_REQUIRED, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTARG_RESULT, \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTVAL_C}, \

#define XOS_PROTOCOL_XTTP_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTVAL_S \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTVAL_S \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTVAL_S \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTVAL_S \

#define XOS_PROTOCOL_XTTP_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTION \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTION \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTION \
    XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTION \

#define XOS_PROTOCOL_XTTP_MAIN_OPTIONS_CHARS \
    XOS_PROTOCOL_XTTP_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_PROTOCOL_XTTP_MAIN_OPTIONS_OPTIONS \
    XOS_PROTOCOL_XTTP_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_CONSOLE_MAIN_OPTIONS_OPTIONS

#define XOS_PROTOCOL_XTTP_MAIN_ARUMENTS_CHARS 0
#define XOS_PROTOCOL_XTTP_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace client {

/// class main_optt
template <class TExtends = console::main, class TImplements = typename TExtends::implements>
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
    main_optt(const main_optt& copy): extends(copy) {
    }

protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = this->usage(argc, argv, env);
        }
        return err;
    }

    /// ...request_run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_request_run(argc, argv, env))) {
            int err2 = 0;
            err = request_run(argc, argv, env);
            if ((err2 = after_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_request_run;
        return err;
    }
    virtual int before_set_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_request_run(argc, argv, env))) {
            int err2 = 0;
            err = set_request_run(argc, argv, env);
            if ((err2 = after_set_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_method_get(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int before_set_method_get(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_method_get(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_method_get(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_method_get(argc, argv, env))) {
            int err2 = 0;
            err = set_method_get(argc, argv, env);
            if ((err2 = after_set_method_get(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_method_post(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int before_set_method_post(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_method_post(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_method_post(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_method_post(argc, argv, env))) {
            int err2 = 0;
            err = set_method_post(argc, argv, env);
            if ((err2 = after_set_method_post(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_method(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int before_set_method(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_method(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_method(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_method(method, argc, argv, env))) {
            int err2 = 0;
            err = set_method(method, argc, argv, env);
            if ((err2 = after_set_method(method, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...options...
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = all_set_request_run(argc, argv, env);
        return err;
    }
    virtual int on_method_get_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = all_set_method_get(argc, argv, env);
        return err;
    }
    virtual int on_method_post_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = all_set_method_post(argc, argv, env);
        return err;
    }
    virtual int on_method_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            err = all_set_method(arg, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        chars = XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTUSE;
        return chars;
    }
    virtual const char_t* method_get_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTARG;
        const char_t* chars = XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTUSE;
        return chars;
    }
    virtual const char_t* method_post_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTARG;
        const char_t* chars = XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTUSE;
        return chars;
    }
    virtual const char_t* method_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTARG;
        const char_t* chars = XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTUSE;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTVAL_C:
            err = this->on_method_get_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTVAL_C:
            err = this->on_method_post_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTVAL_C:
            err = this->on_method_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_PROTOCOL_XTTP_MAIN_REQUEST_OPTVAL_C:
            chars = request_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_XTTP_MAIN_METHOD_GET_OPTVAL_C:
            chars = method_get_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_XTTP_MAIN_METHOD_POST_OPTVAL_C:
            chars = method_post_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_XTTP_MAIN_METHOD_OPTVAL_C:
            chars = method_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_PROTOCOL_XTTP_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_PROTOCOL_XTTP_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...arguments...
    virtual const char_t* arguments(const char_t**& args) {
        args = XOS_PROTOCOL_XTTP_MAIN_ARUMENTS_ARGS;
        return XOS_PROTOCOL_XTTP_MAIN_ARUMENTS_CHARS;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace client
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPT_HPP
