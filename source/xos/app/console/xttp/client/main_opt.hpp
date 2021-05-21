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
///   Date: 9/16/2020, 5/21/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPT_HPP

#include "xos/app/console/network/client/main.hpp"

#include "xos/app/console/protocol/xttp/base/main.hpp"
#include "xos/app/console/protocol/xttp/client/main.hpp"

#include "xos/protocol/http/response/status/codeof.hpp"
#include "xos/protocol/http/response/status/reason.hpp"
#include "xos/protocol/http/response/line.hpp"
#include "xos/protocol/http/response/message.hpp"

#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \

#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_PROTOCOL_XTTP_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_NETWORK_CLIENT_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_PROTOCOL_XTTP_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_NETWORK_CLIENT_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_ARGS 0
#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace xttp {
namespace client {

/// class main_optt
template 
<class TExtends = protocol::xttp::client::maint
 <protocol::xttp::client::main_optt<protocol::xttp::base::maint
 <protocol::xttp::base::main_optt<network::client::main> > > >, class TImplements = typename TExtends::implements>
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
    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_t content_t;
    typedef typename extends::request_method_t request_method_t;
    typedef typename extends::request_t request_t;
    typedef xos::protocol::http::response::message response_t;

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// response... / message...
    virtual response_t& response() const {
        return (response_t&)response_;
    }

protected:
    xos::protocol::http::response::message response_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace client
} /// namespace xttp
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_OPT_HPP
