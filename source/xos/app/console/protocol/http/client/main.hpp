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
///   File: main.hpp
///
/// Author: $author$
///   Date: 8/18/2020, 5/4/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_CLIENT_MAIN_HPP

#include "xos/app/console/protocol/http/client/main_opt.hpp"
#include "xos/protocol/http/request/method/nameof.hpp"
#include "xos/protocol/http/request/resource/identifier.hpp"
#include "xos/protocol/http/request/line.hpp"
#include "xos/protocol/http/request/message.hpp"
#include "xos/protocol/http/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {
namespace client {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives; 
    
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    /// constructors / destructor
    maint()
    : method_(get_), resource_(path_), request_line_(method_, resource_, this->protocol_),
      request_headers_(&this->content_type_header_, &this->content_length_header_, null),
      request_(request_line_, request_headers_, this->content_),
      response_content_size_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }

protected:
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;
    typedef xos::protocol::http::message::header::fields headers_t;
    typedef xos::protocol::http::message::parts message_t;
    typedef xos::protocol::http::request::method::name request_method_t;
    typedef xos::protocol::http::request::resource::identifier request_resource_t;
    typedef xos::protocol::http::request::line request_line_t;
    typedef xos::protocol::http::request::message request_t;
    typedef xos::protocol::http::response::message response_t;

    /// request...
    virtual request_t& request() const {
        return (request_t&)request_;
    }
    virtual headers_t& request_headers() const {
        return (headers_t&)request_headers_;
    }
    virtual request_line_t& request_line() const {
        return (request_line_t&)request_line_;
    }
    virtual request_method_t& request_method_get() const {
        return (request_method_t&)get_;
    }
    virtual request_method_t& request_method_post() const {
        return (request_method_t&)post_;
    }
    virtual request_method_t& request_method() const {
        return (request_method_t&)method_;
    }
    virtual request_resource_t& request_resource() const {
        return (request_resource_t&)resource_;
    }

    /// response...
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual content_t& response_content() const {
        return (content_t&)response_content_;
    }
    virtual size_t& response_content_size() const {
        return (size_t&)response_content_size_;
    }

protected:
    xos::protocol::http::request::method::nameof::GET get_;
    xos::protocol::http::request::method::nameof::POST post_;
    xos::protocol::http::request::method::name method_;

    xos::protocol::http::request::resource::absolute::path path_;
    xos::protocol::http::request::resource::absolute::identifier identifier_;
    xos::protocol::http::request::resource::identifier asterisk_, resource_;
    xos::protocol::http::request::line request_line_;
    xos::protocol::http::message::header::fields request_headers_;
    xos::protocol::http::request::message request_;

    size_t response_content_size_; content_t response_content_;
    xos::protocol::http::response::message response_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_HTTP_CLIENT_MAIN_HPP
