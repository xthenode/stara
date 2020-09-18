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
///   Date: 8/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_HPP

#include "xos/app/console/protocol/xttp/client/main_opt.hpp"
/*#include "xos/protocol/xttp/content/json/node.hpp"
#include "xos/protocol/xttp/content/json/array.hpp"
#include "xos/protocol/xttp/content/json/object.hpp"
#include "xos/protocol/http/content/type/nameof.hpp"
#include "xos/protocol/http/message/body/content.hpp"
#include "xos/protocol/http/message/header/content/type.hpp"
#include "xos/protocol/http/message/header/content/length.hpp"
#include "xos/protocol/http/message/header/fields.hpp"
#include "xos/protocol/http/protocol/name.hpp"
#include "xos/protocol/http/protocol/version.hpp"
#include "xos/protocol/http/protocol/identifier.hpp"*/
#include "xos/protocol/http/request/method/nameof.hpp"
#include "xos/protocol/http/request/resource/identifier.hpp"
#include "xos/protocol/http/request/line.hpp"
#include "xos/protocol/http/request/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
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
    : /*content_type_(text_), content_type_header_(content_type_),
      hello_("Hello\r\n"), bye_("Bye\r\n"), content_(hello_), content_length_header_(content_),
      http_(http_name_, http_version_), protocol_(http_),*/
      method_(get_), resource_(path_), request_line_(method_, resource_, this->protocol_),
      request_headers_(&this->content_type_header_, &this->content_length_header_, null),
      request_(request_line_, request_headers_, this->content_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }
    
protected:
    /*
    typedef xos::protocol::xttp::content::json::boolean json_boolean_t;
    typedef xos::protocol::xttp::content::json::number json_number_t;
    typedef xos::protocol::xttp::content::json::string json_string_t;
    typedef xos::protocol::xttp::content::json::node json_node_t;
    typedef xos::protocol::xttp::content::json::array json_array_t;
    typedef xos::protocol::xttp::content::json::object json_object_t;
    */
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;
    typedef xos::protocol::http::request::method::name request_method_t;
    typedef xos::protocol::http::request::resource::identifier request_resource_t;
    typedef xos::protocol::http::request::line request_line_t;
    typedef xos::protocol::http::message::header::fields request_headers_t;
    typedef xos::protocol::http::request::message request_t;

    /// ...run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        request_t& request = this->request();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_request(amount, writer, request, argc, argv, env);
        return err;
    }
    
    /// ...set_content...
    virtual int after_set_content(const char_t* content, int argc, char_t** argv, char** env) {
        content_type_header_t& content_type_header = this->content_type_header();
        content_length_header_t& content_length_header = this->content_length_header();
        request_line_t& request_line = this->request_line();
        request_headers_t& request_headers = this->request_headers();
        content_t& request_content = this->content();
        request_t& request = this->request();
        int err = 0;
        content_length_header.set_length(request_content.length());
        request_headers.is_setl(&content_type_header, &content_length_header, null);
        request.set(request_line, request_headers, request_content);
        return err;
    }

    /// ...set_method
    virtual int before_set_method_get(int argc, char_t** argv, char** env) {
        int err = 0;
        set_request_method_get();
        return err;
    }
    virtual int before_set_method_post(int argc, char_t** argv, char** env) {
        int err = 0;
        set_request_method_post();
        return err;
    }
    virtual int before_set_method(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        set_request_method(method);
        return err;
    }

    /// ...set_parameter
    virtual int before_set_parameter(const char_t* parameter, int argc, char_t** argv, char** env) {
        int err = 0;
        set_request_resource(parameter);
        return err;
    }

    /// ...write_request
    virtual int write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        request.write(amount, writer);
        return err;
    }
    virtual int before_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_request(amount, writer, request, argc, argv, env))) {
            int err2 = 0;
            err = write_request(amount, writer, request, argc, argv, env);
            if ((err2 = after_write_request(amount, writer, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// request...
    virtual request_t& request() const {
        return (request_t&)request_;
    }
    virtual request_headers_t& request_headers() const {
        return (request_headers_t&)request_headers_;
    }
    virtual request_line_t& request_line() const {
        return (request_line_t&)request_line_;
    }
    virtual request_method_t& set_request_method_get() {
        return set_request_method(request_method_get());
    }
    virtual request_method_t& request_method_get() const {
        return (request_method_t&)get_;
    }
    virtual request_method_t& set_request_method_post() {
        return set_request_method(request_method_post());
    }
    virtual request_method_t& request_method_post() const {
        return (request_method_t&)post_;
    }
    virtual request_method_t& set_request_method(const request_method_t& to) {
        return set_request_method(to.chars());
    }
    virtual request_method_t& set_request_method(const char_t* to) {
        method_.set(to);
        request_.set_method(method_);
        return (request_method_t&)method_;
    }
    virtual request_method_t& request_method() const {
        return (request_method_t&)method_;
    }
    virtual request_resource_t& set_request_resource(const char_t* to) {
        resource_.set(to);
        request_.set_resource(resource_);
        return (request_resource_t&)resource_;
    }
    virtual request_resource_t& request_resource() const {
        return (request_resource_t&)resource_;
    }

    /*/// content_type...
    typedef xos::protocol::http::content::type::name content_type_t;
    virtual content_type_t& content_type_text() const {
        return (content_type_t&)text_;
    }
    virtual content_type_t& content_type_html() const {
        return (content_type_t&)html_;
    }
    virtual content_type_t& content_type_xml() const {
        return (content_type_t&)xml_;
    }
    virtual content_type_t& content_type_json() const {
        return (content_type_t&)json_;
    }
    virtual content_type_t& content_type() const {
        return (content_type_t&)content_type_;
    }

    /// content_length...
    virtual size_t content_length() const {
        return content_.length();
    }
    
    /// content
    typedef xos::protocol::http::message::body::content content_t;
    virtual content_t& content() const {
        return (content_t&)content_;
    }*/

protected:
    /*
    xos::protocol::http::content::type::nameof::text text_;
    xos::protocol::http::content::type::nameof::html html_;
    xos::protocol::http::content::type::nameof::xml xml_;
    xos::protocol::http::content::type::nameof::json json_;
    xos::protocol::http::content::type::name content_type_;
    xos::protocol::http::message::header::content::type content_type_header_;

    xos::protocol::http::message::body::content hello_, bye_, content_;
    xos::protocol::http::message::header::content::length content_length_header_;
    xos::protocol::http::message::header::field connection_header_;

    xos::protocol::http::protocol::name http_name_;
    xos::protocol::http::protocol::version http_version_;
    xos::protocol::http::protocol::identifier http_, protocol_;
    */
    xos::protocol::http::request::method::nameof::GET get_;
    xos::protocol::http::request::method::nameof::POST post_;
    xos::protocol::http::request::method::name method_;

    xos::protocol::http::request::resource::absolute::path path_;
    xos::protocol::http::request::resource::absolute::identifier identifier_;
    xos::protocol::http::request::resource::identifier asterisk_, resource_;
    xos::protocol::http::request::line request_line_;
    xos::protocol::http::message::header::fields request_headers_;
    xos::protocol::http::request::message request_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_HPP
