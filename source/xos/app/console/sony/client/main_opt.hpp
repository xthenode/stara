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
///   Date: 8/13/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SONY_CLIENT_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_SONY_CLIENT_MAIN_OPT_HPP

#include "xos/app/console/network/protocol/http/client/main.hpp"
#include "xos/protocol/xttp/content/json/node.hpp"
#include "xos/protocol/xttp/content/json/array.hpp"
#include "xos/protocol/xttp/content/json/object.hpp"

#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPT "previous"
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTARG "PLay previous"
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTUSE ""
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTVAL_S "e"
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPT "next"
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG ""
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTUSE "Play next"
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_S "x"
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C 'x'
#define XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPT "stop"
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTARG "Stop play"
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTUSE ""
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTVAL_S "s"
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTVAL_C 's'
#define XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_STOP_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPT "resume"
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTARG "Resume play"
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTUSE ""
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTVAL_S "u"
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTVAL_C 'u'
#define XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPT "volume"
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG "{ 0..n }"
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTUSE "Set Volume level"
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_S "v:"
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C 'v'
#define XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPT "power"
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTARG "{ on | off }"
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTUSE "Turn Power on/off"
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTVAL_S "w:"
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTVAL_C 'w'
#define XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTION \
   {XOS_APP_CONSOLE_SONY_MAIN_POWER_OPT, \
    XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTVAL_S \
   XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_S \
    XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTVAL_S \
    XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTVAL_S \
   XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_S \
   XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTVAL_S \

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTION \
   XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTION \
    XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTION \
    XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTION \
   XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTION \
   XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTION \

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_NETWORK_PROTOCOL_HTTP_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_SONY_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_NETWORK_PROTOCOL_HTTP_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_SONY_MAIN_ARUMENTS_CHARS 0
#define XOS_APP_CONSOLE_SONY_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace sony {
namespace client {

/// class main_optt
template <class TExtends = network::protocol::http::client::main, class TImplements = typename TExtends::implements>
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
    typedef xos::protocol::xttp::content::json::boolean json_boolean_t;
    typedef xos::protocol::xttp::content::json::number json_number_t;
    typedef xos::protocol::xttp::content::json::string json_string_t;
    typedef xos::protocol::xttp::content::json::node json_node_t;
    typedef xos::protocol::xttp::content::json::array json_array_t;
    typedef xos::protocol::xttp::content::json::object json_object_t;
    typedef typename extends::request_method_t request_method_t;
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;

    /// ...option...
    virtual int on_previous_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_next_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_stop_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_resume_option
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
    virtual int on_power_option
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
        case XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTVAL_C:
            err = this->on_previous_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C:
            err = this->on_next_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTVAL_C:
            err = this->on_stop_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTVAL_C:
            err = this->on_resume_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C:
            err = this->on_volume_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTVAL_C:
            err = this->on_power_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* previous_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTUSE;
        return chars;
    }
    virtual const char_t* next_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTUSE;
        return chars;
    }
    virtual const char_t* stop_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTUSE;
        return chars;
    }
    virtual const char_t* resume_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTUSE;
        return chars;
    }
    virtual const char_t* volume_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTUSE;
        return chars;
    }
    virtual const char_t* power_option_usage(const char_t*& optarg, const struct option* longopt) {
        optarg = XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTARG;
        const char_t* chars = XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTUSE;
        return chars;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_SONY_MAIN_PREVIOUS_OPTVAL_C:
            chars = previous_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_NEXT_OPTVAL_C:
            chars = next_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_STOP_OPTVAL_C:
            chars = stop_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_RESUME_OPTVAL_C:
            chars = resume_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_VOLUME_OPTVAL_C:
            chars = volume_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_SONY_MAIN_POWER_OPTVAL_C:
            chars = power_option_usage(optarg, longopt);
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

} /// namespace client
} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_SONY_CLIENT_MAIN_OPT_HPP
