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
///   Date: 9/10/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_HPP

#include "xos/app/console/protocol/xttp/base/main_opt.hpp"
#include "xos/protocol/xttp/content/json/node.hpp"
#include "xos/protocol/xttp/content/json/array.hpp"
#include "xos/protocol/xttp/content/json/object.hpp"
#include "xos/protocol/http/content/type/nameof.hpp"
#include "xos/protocol/http/message/body/content.hpp"
#include "xos/protocol/http/message/header/content/type.hpp"
#include "xos/protocol/http/message/header/content/length.hpp"
#include "xos/protocol/http/message/header/fields.hpp"
#include "xos/protocol/http/protocol/name.hpp"
#include "xos/protocol/http/protocol/version.hpp"
#include "xos/protocol/http/protocol/identifier.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace base {

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
    : content_type_(text_), content_type_header_(content_type_),
      hello_("Hello\r\n"), bye_("Bye\r\n"), content_(hello_), content_length_header_(content_),
      http_(http_name_, http_version_), protocol_(http_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }

protected:
    typedef xos::protocol::xttp::content::json::boolean json_boolean_t;
    typedef xos::protocol::xttp::content::json::number json_number_t;
    typedef xos::protocol::xttp::content::json::string json_string_t;
    typedef xos::protocol::xttp::content::json::node json_node_t;
    typedef xos::protocol::xttp::content::json::array json_array_t;
    typedef xos::protocol::xttp::content::json::object json_object_t;

    /// ...content_type_run
    typedef xos::protocol::http::content::type::name content_type_t;
    virtual int content_type_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        content_type_t& content_type = this->content_type();
        
        if ((chars = content_type.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...content_run
    typedef xos::protocol::http::message::body::content content_t;
    virtual int content_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        content_t& content = this->content();
        
        if ((chars = content.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...set_content_type
    virtual int before_set_content_type(const char_t* content_type, int argc, char_t** argv, char** env) {
        int err = 0;
        set_content_type(content_type);
        return err;
    }

    /// ...set_content
    virtual int before_set_content(const char_t* content, int argc, char_t** argv, char** env) {
        int err = 0;
        set_content(content);
        return err;
    }

    /// content_type...
    typedef xos::protocol::http::message::header::fields headers_t;
    typedef xos::protocol::http::message::header::content::type content_type_header_t;
    virtual content_type_header_t& content_type_header() const {
        return (content_type_header_t&)content_type_header_;
    }
    enum { content_type_subtype_json = xos::protocol::http::content::media::subtype::json };
    typedef xos::protocol::http::content::media::subtype::which_t content_type_subtype_which_t;
    typedef xos::protocol::http::content::media::subtype::name content_type_subtype_t;
    enum { content_type_type_text = xos::protocol::http::content::media::type::text };
    typedef xos::protocol::http::content::media::type::which_t content_type_type_which_t;
    typedef xos::protocol::http::content::media::type::name content_type_type_t;
    typedef xos::protocol::http::content::type::which_t content_type_which_t;
    virtual content_type_t& content_type_text() const {
        return (content_type_t&)text_;
    }
    virtual content_type_t& content_type_html() const {
        return (content_type_t&)html_;
    }
    virtual content_type_t& content_type_xml() const {
        return (content_type_t&)xml_;
    }
    virtual content_type_t& content_type_css() const {
        return (content_type_t&)css_;
    }
    virtual content_type_t& content_type_json() const {
        return (content_type_t&)json_;
    }
    virtual content_type_t& content_type_javascript() const {
        return (content_type_t&)javascript_;
    }
    virtual content_type_t& set_content_type(const char_t* to) {
        content_type_t& content_type = this->content_type();
        content_type_header_t& content_type_header = this->content_type_header();
        content_type.set(to);
        content_type_header.set_type(content_type);
        return (content_type_t&)content_type;
    }
    virtual content_type_t& content_type() const {
        return (content_type_t&)content_type_;
    }

    /// content_length...
    typedef xos::protocol::http::message::header::content::length content_length_header_t;
    virtual content_length_header_t& content_length_header() const {
        return (content_length_header_t&)content_length_header_;
    }
    virtual size_t content_length() const {
        return content_.length();
    }
    
    /// content
    virtual content_t& set_content(const char_t* to) {
        content_length_header_t& content_length_header = this->content_length_header();
        content_t& content = this->content();
        content.set(to);
        content_length_header.set_length(this->content_length());
        return content;
    }
    virtual content_t& content() const {
        return (content_t&)content_;
    }

    /// protocol
    typedef xos::protocol::http::protocol::identifier protocol_t;
    virtual protocol_t& protocol() const {
        return (protocol_t&)protocol_;
    }

protected:
    xos::protocol::http::content::type::nameof::text text_;
    xos::protocol::http::content::type::nameof::html html_;
    xos::protocol::http::content::type::nameof::xml xml_;
    xos::protocol::http::content::type::nameof::css css_;
    xos::protocol::http::content::type::nameof::json json_;
    xos::protocol::http::content::type::nameof::javascript javascript_;
    xos::protocol::http::content::type::name content_type_;
    xos::protocol::http::message::header::content::type content_type_header_;

    xos::protocol::http::message::body::content hello_, bye_, content_;
    xos::protocol::http::message::header::content::length content_length_header_;

    xos::protocol::http::protocol::name http_name_;
    xos::protocol::http::protocol::version http_version_;
    xos::protocol::http::protocol::identifier http_, protocol_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_HPP
