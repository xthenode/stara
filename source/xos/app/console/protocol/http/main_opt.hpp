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
///   Date: 6/12/2020, 5/4/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN_OPT_HPP

#include "xos/app/console/main.hpp"

#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPT "method"
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTARG "[{ GET | POST | ...}]"
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTUSE "Http request method"
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTVAL_S "m::"
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTVAL_C 'm'
#define XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTION \
   {XOS_PROTOCOL_HTTP_MAIN_METHOD_OPT, \
    XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPT "request"
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTARG ""
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTUSE "Send http request"
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTVAL_S "r"
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTVAL_C 'r'
#define XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTION \
   {XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPT, \
    XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPT "respond"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG ""
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTUSE "Send http response"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_S "s"
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C 's'
#define XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTION \
   {XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPT, \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTVAL_S \
    XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTVAL_S \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_S

#define XOS_PROTOCOL_HTTP_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTION \
    XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTION \
    XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTION 

#define XOS_PROTOCOL_HTTP_MAIN_OPTIONS_CHARS \
    XOS_PROTOCOL_HTTP_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_PROTOCOL_HTTP_MAIN_OPTIONS_OPTIONS \
    XOS_PROTOCOL_HTTP_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_CONSOLE_MAIN_OPTIONS_OPTIONS

#define XOS_PROTOCOL_HTTP_MAIN_ARUMENTS_CHARS 0
#define XOS_PROTOCOL_HTTP_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {

/// class main_optt
template 
<class TExtends = console::main, class TImplements = typename TExtends::implements>
class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy): run_(0) {
    }
public:

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
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

    /// ...respond_run
    virtual int respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_respond_run(argc, argv, env))) {
            int err2 = 0;
            err = respond_run(argc, argv, env);
            if ((err2 = after_respond_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...set_request_method_run
    virtual int set_request_method_run(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int before_set_request_method_run(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_request_method_run(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_request_method_run(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_request_method_run(method, argc, argv, env))) {
            int err2 = 0;
            err = set_request_method_run(method, argc, argv, env);
            if ((err2 = after_set_request_method_run(method, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_request_run
    virtual int set_request_run(int argc, char_t** argv, char** env) {
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
    /// ...set_respond_run
    virtual int set_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        run_ = &derives::all_respond_run;
        return err;
    }
    virtual int before_set_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_respond_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_respond_run(argc, argv, env))) {
            int err2 = 0;
            err = set_respond_run(argc, argv, env);
            if ((err2 = after_set_respond_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...options...
    virtual int on_method_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            err = all_set_request_run(argc, argv, env);
        } else  {
            err = all_set_request_method_run(arg,argc, argv, env);
        }
        return err;
    }
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = all_set_request_run(argc, argv, env);
        return err;
    }
    virtual int on_respond_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = all_set_respond_run(argc, argv, env);
        return err;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTVAL_C:
            err = this->on_method_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C:
            err = this->on_respond_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* method_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTUSE;
        return chars;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTUSE;
        return chars;
    }
    virtual const char_t* respond_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTUSE;
        return chars;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_PROTOCOL_HTTP_MAIN_METHOD_OPTVAL_C:
            chars = method_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_REQUEST_OPTVAL_C:
            chars = request_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_HTTP_MAIN_RESPOND_OPTVAL_C:
            chars = respond_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_PROTOCOL_HTTP_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_PROTOCOL_HTTP_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...arguments...
    virtual const char_t* arguments(const char_t**& args) {
        args = XOS_PROTOCOL_HTTP_MAIN_ARUMENTS_ARGS;
        return XOS_PROTOCOL_HTTP_MAIN_ARUMENTS_CHARS;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN_OPT_HPP 
