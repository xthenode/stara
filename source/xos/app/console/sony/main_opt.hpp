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
///   Date: 6/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SONY_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_SONY_MAIN_OPT_HPP

#include "xos/app/console/http/main.hpp"

#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPT "next"
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG ""
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTUSE ""
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_S "n"
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPT "volume"
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG ""
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTUSE ""
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_S "v:"
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C 'v'
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_S \
   XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_S \

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTION \
   XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTION \

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_HTTP_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_HTTP_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_SONY_MAIN_ARUMENTS_CHARS 0
#define XOS_APP_CONSOLE_SONY_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace sony {

/// class main_optt
template 
<class TExtends = xos::app::console::http::main, 
 class TImplements = typename TExtends::implements>

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
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef typename extends::json_number_t json_number_t;
    typedef typename extends::request_method_t request_method_t;
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;
    typedef typename extends::message_t message_t;

    /// ...option...
    virtual int on_next_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_volume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C:
            err = this->on_next_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C:
            err = this->on_volume_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* next_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTUSE;
        return chars;
    }
    virtual const char_t* volume_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTUSE;
        return chars;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C:
            chars = next_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C:
            chars = volume_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_SONY_MAIN_OPT_HPP
