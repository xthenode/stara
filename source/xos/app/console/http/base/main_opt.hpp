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
///   Date: 10/29/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPT_HPP

#include "xos/app/console/xttp/base/main.hpp"
#include "xos/app/console/protocol/http/base/main.hpp"

#define XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPTIONS_CHARS \
   XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_XTTP_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_PROTOCOL_HTTP_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_XTTP_BASE_MAIN_OPTIONS_OPTIONS
   
#define XOS_APP_CONSOLE_HTTP_BASE_MAIN_ARUMENTS_CHARS 0
#define XOS_APP_CONSOLE_HTTP_BASE_MAIN_ARUMENTS_ARGS 0

namespace xos {
namespace app {
namespace console {
namespace http {
namespace base {

/// class main_optt
template 
<class TExtends = xttp::base::maint<xttp::base::main_optt
 <protocol::http::base::maint<protocol::http::base::main_optt
  <protocol::xttp::base::maint<protocol::xttp::base::main_optt<network::base::main> > > > > >, 
 class TImplements = typename TExtends::implements>
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
    typedef typename extends::content_type_type_which_t content_type_type_which_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;

    /// ...option...
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& args) {
        args = XOS_APP_CONSOLE_HTTP_BASE_MAIN_ARUMENTS_ARGS;
        return XOS_APP_CONSOLE_HTTP_BASE_MAIN_ARUMENTS_CHARS;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace http
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_HTTP_BASE_MAIN_OPT_HPP
