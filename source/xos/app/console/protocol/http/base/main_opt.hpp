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
///   Date: 9/20/2020, 5/20/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_BASE_MAIN_OPT_HPP

#include "xos/app/console/protocol/xttp/base/main.hpp"

#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPT "content"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTARG "[string]"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTUSE "Http message content"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTVAL_S "n::"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTVAL_C 'n'
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTION \
   {XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPT, \
    XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPT "content-type"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTARG_RESULT 0
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTARG "[string[/string]]"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTUSE "Http message content type"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTVAL_S "y::"
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTVAL_C 'y'
#define XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTION \
   {XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPT, \
    XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTARG_REQUIRED, \
    XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTARG_RESULT, \
    XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTVAL_C}, \

#define XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTVAL_S \
   XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTVAL_S \

#define XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTION \
   XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTION \

#define XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_CHARS \
   XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_CONSOLE_MAIN_OPTIONS_OPTIONS
   
#define XOS_PROTOCOL_HTTP_BASE_MAIN_ARUMENTS_CHARS 0
#define XOS_PROTOCOL_HTTP_BASE_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {
namespace base {

/// class main_optt
template <class TExtends = protocol::xttp::base::main, class TImplements = typename TExtends::implements>
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
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }

protected:
    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_type_which_t content_type_which_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;

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

    /// ...content_run
    virtual int content_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_content_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_content_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_content_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_content_run(argc, argv, env))) {
            int err2 = 0;
            err = content_run(argc, argv, env);
            if ((err2 = after_content_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_content_run
    virtual int set_content_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_content_run;
        return err;
    }
    virtual int before_set_content_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_content_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_content_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_content_run(argc, argv, env))) {
            int err2 = 0;
            err = set_content_run(argc, argv, env);
            if ((err2 = after_set_content_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...content_type_run
    virtual int content_type_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_content_type_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_content_type_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_content_type_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_content_type_run(argc, argv, env))) {
            int err2 = 0;
            err = content_type_run(argc, argv, env);
            if ((err2 = after_content_type_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...set_content_type_run
    virtual int set_content_type_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_content_type_run;
        return err;
    }
    virtual int before_set_content_type_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_content_type_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_content_type_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_content_type_run(argc, argv, env))) {
            int err2 = 0;
            err = set_content_type_run(argc, argv, env);
            if ((err2 = after_set_content_type_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...option...
    virtual int on_content_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            err = this->all_set_content(arg, argc, argv, env);
        } else {
            err = this->all_set_content_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_content_type_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            err = this->all_set_content_type(arg, argc, argv, env);
        } else {
            err = this->all_set_content_type_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTVAL_C:
            err = this->on_content_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTVAL_C:
            err = this->on_content_type_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* content_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTUSE;
        return chars;
    }
    virtual const char_t* content_type_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTARG;
        const char_t* chars = XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTUSE;
        return chars;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_OPTVAL_C:
            chars = content_option_usage(optarg, longopt);
            break;
        case XOS_PROTOCOL_HTTP_BASE_MAIN_CONTENT_TYPE_OPTVAL_C:
            chars = content_type_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& args) {
        args = XOS_PROTOCOL_HTTP_BASE_MAIN_ARUMENTS_ARGS;
        return XOS_PROTOCOL_HTTP_BASE_MAIN_ARUMENTS_CHARS;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_HTTP_BASE_MAIN_OPT_HPP
