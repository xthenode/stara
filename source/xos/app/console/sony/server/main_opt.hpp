///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
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
///   Date: 4/28/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SONY_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_SONY_SERVER_MAIN_OPT_HPP

#include "xos/app/console/http/server/main.hpp"

#define XOS_APP_CONSOLE_SONY_ACCEPT_PORT 10000
#define XOS_APP_CONSOLE_SONY_CONNECT_PORT 10000

namespace xos {
namespace app {
namespace console {
namespace sony {
namespace server {

/// class main_optt
template 
<class TExtends = http::server::maint<>, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): port_(XOS_APP_CONSOLE_SONY_ACCEPT_PORT) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...port
    virtual short& accept_port() const {
        return port();
    }
    virtual short& set_port(short to) {
        port_ = to;
        return port();
    }
    virtual short& port() const {
        return (short&)port_;
    }

protected:
    short port_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server
} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_SONY_SERVER_MAIN_OPT_HPP
