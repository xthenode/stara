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
///   Date: 9/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_SERVER_MAIN_HPP

#include "xos/app/console/protocol/http/server/main_opt.hpp"
#include "xos/protocol/http/response/status/codeof.hpp"
#include "xos/protocol/http/response/status/reason.hpp"
#include "xos/protocol/http/response/line.hpp"
#include "xos/protocol/http/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {
namespace server {

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
    : status_(ok_), reason_(status_), response_line_(this->protocol_, status_, reason_),
      response_headers_(&this->content_type_header_, &this->content_length_header_, null),
      response_(response_line_, response_headers_, this->content_) {
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
    typedef xos::protocol::http::response::status::code response_status_t;
    typedef xos::protocol::http::response::status::reason response_reason_t;
    typedef xos::protocol::http::response::line response_line_t;
    typedef xos::protocol::http::response::message response_t;

    /*/// ...run
    virtual int respond_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        response_t& response = this->response();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }
    virtual int before_set_status_ok(int argc, char_t** argv, char** env) {
        int err = 0;
        set_response_status_ok();
        return err;
    }
    virtual int before_set_status_not_found(int argc, char_t** argv, char** env) {
        int err = 0;
        set_response_status_not_found();
        return err;
    }
    virtual int before_set_status(const char_t* status, int argc, char_t** argv, char** env) {
        int err = 0;
        set_response_status(status);
        return err;
    }

    /// ...write_response
    virtual int write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        response.write(amount, writer);
        return err;
    }
    virtual int before_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_response(amount, writer, response, argc, argv, env))) {
            int err2 = 0;
            err = write_response(amount, writer, response, argc, argv, env);
            if ((err2 = after_write_response(amount, writer, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }*/

    /// response...
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual headers_t& response_headers() const {
        return (headers_t&)response_headers_;
    }
    virtual response_line_t& response_line() const {
        return (response_line_t&)response_line_;
    }
    /*virtual response_status_t& set_response_status_ok() {
        return set_response_status(response_status_ok());
    }*/
    virtual response_status_t& response_status_ok() const {
        return (response_status_t&)ok_;
    }
    /*virtual response_status_t& set_response_status_not_found() {
        return set_response_status(response_status_not_found());
    }*/
    virtual response_status_t& response_status_not_found() const {
        return (response_status_t&)not_found_;
    }
    /*virtual response_status_t& set_response_status(const response_status_t& to) {
        return set_response_status(to.chars());
    }
    virtual response_status_t& set_response_status(const char_t* to) {
        status_.set(to);
        reason_.set(status_);
        response_.set_status(status_);
        response_.set_reason(reason_);
        return (response_status_t&)status_;
    }*/
    virtual response_status_t& response_status() const {
        return (response_status_t&)status_;
    }

protected:
    xos::protocol::http::response::status::codeof::OK ok_;
    xos::protocol::http::response::status::codeof::Not_Found not_found_;
    xos::protocol::http::response::status::code status_;
    xos::protocol::http::response::status::reason reason_;
    xos::protocol::http::response::line response_line_;
    xos::protocol::http::message::header::fields response_headers_;
    xos::protocol::http::response::message response_;
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_HTTP_SERVER_MAIN_HPP
