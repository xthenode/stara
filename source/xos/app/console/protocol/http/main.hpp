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
///   Date: 6/12/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN_HPP

#include "xos/app/console/protocol/http/main_opt.hpp"

#include "xos/protocol/xttp/content/json/node.hpp"
#include "xos/protocol/xttp/content/json/array.hpp"
#include "xos/protocol/xttp/content/json/object.hpp"

#include "xos/protocol/http/protocol/name.hpp"
#include "xos/protocol/http/protocol/version.hpp"
#include "xos/protocol/http/protocol/identifier.hpp"
#include "xos/protocol/http/content/type/nameof.hpp"

#include "xos/protocol/http/message/body/content.hpp"
#include "xos/protocol/http/message/header/content/type.hpp"
#include "xos/protocol/http/message/header/content/length.hpp"
#include "xos/protocol/http/message/header/fields.hpp"

#include "xos/protocol/http/request/method/nameof.hpp"
#include "xos/protocol/http/request/resource/identifier.hpp"
#include "xos/protocol/http/request/line.hpp"
#include "xos/protocol/http/request/message.hpp"

#include "xos/protocol/http/response/status/codeof.hpp"
#include "xos/protocol/http/response/status/reason.hpp"
#include "xos/protocol/http/response/line.hpp"
#include "xos/protocol/http/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {

/// class maint
template 
<class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    /// constructor / destructor
    maint()
    : http_(http_name_, http_version_), protocol_(http_), 
      content_type_(text_), content_type_header_(content_type_),
      hello_("Hello\r\n"), bye_("Bye\r\n"), content_(hello_), content_length_header_(content_),

      method_(post_), resource_(path_), request_line_(method_, resource_, protocol_),
      request_headers_(&content_type_header_, &content_length_header_, null),
      request_(request_line_, request_headers_, content_),

      status_(ok_), reason_(status_), response_line_(protocol_, status_, reason_),
      response_headers_(&content_type_header_, &content_length_header_, null),
      response_(response_line_, response_headers_, content_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }
public:

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef xos::protocol::xttp::content::json::boolean json_boolean_t;
    typedef xos::protocol::xttp::content::json::number json_number_t;
    typedef xos::protocol::xttp::content::json::string json_string_t;
    typedef xos::protocol::xttp::content::json::node json_node_t;
    typedef xos::protocol::xttp::content::json::array json_array_t;
    typedef xos::protocol::xttp::content::json::object json_object_t;
    typedef xos::protocol::http::request::method::name request_method_t;
    typedef xos::protocol::http::request::message request_t;
    typedef xos::protocol::http::response::message response_t;
    typedef xos::protocol::http::message::part message_t;

    /// ...run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        request_t& request = this->request();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int respond_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        response_t& response = this->response();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }
    virtual int before_set_request_method_run(const char_t* method, int argc, char_t** argv, char** env) {
        int err = 0;
        set_request_method(method);
        return err;
    }

    /// ...process_response_to_CONNECT
    virtual int process_response_to_CONNECT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_CONNECT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_CONNECT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_CONNECT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_CONNECT(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_CONNECT(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_CONNECT(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_HEAD
    virtual int process_response_to_HEAD(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_HEAD(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_HEAD(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_HEAD(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_HEAD(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_HEAD(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_HEAD(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_GET
    virtual int process_response_to_GET(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_GET(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_GET(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_GET(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_GET(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_GET(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_GET(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_POST
    virtual int process_response_to_POST(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_POST(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_POST(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_POST(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_POST(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_POST(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_POST(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_PATCH
    virtual int process_response_to_PATCH(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_PATCH(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_PATCH(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_PATCH(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_PATCH(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_PATCH(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_PATCH(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_PUT
    virtual int process_response_to_PUT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_PUT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_PUT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_PUT(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_PUT(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_PUT(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_PUT(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_DELETE
    virtual int process_response_to_DELETE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_DELETE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_DELETE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_DELETE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_DELETE(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_DELETE(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_DELETE(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_OPTIONS
    virtual int process_response_to_OPTIONS(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_OPTIONS(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_OPTIONS(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_OPTIONS(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_OPTIONS(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_OPTIONS(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_OPTIONS(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_TRACE
    virtual int process_response_to_TRACE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_TRACE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_TRACE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_TRACE(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_TRACE(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_TRACE(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_TRACE(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_restart
    virtual int process_response_to_restart(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_restart(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_restart(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_restart(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_restart(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_restart(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_restart(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_stop
    virtual int process_response_to_stop(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_stop(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_stop(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_stop(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_stop(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_stop(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_stop(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_unknown
    virtual int process_response_to_unknown(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }
    virtual int before_process_response_to_unknown(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_unknown(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_unknown(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_response_to...
    virtual int write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        switch (request.line().method().which()) {
        case xos::protocol::http::request::method::CONNECT:
            err = this->all_process_response_to_CONNECT(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::DELETE:
            err = this->all_process_response_to_DELETE(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::GET:
            err = this->all_process_response_to_GET(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::HEAD:
            err = this->all_process_response_to_HEAD(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::OPTIONS:
            err = this->all_process_response_to_OPTIONS(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::PATCH:
            err = this->all_process_response_to_PATCH(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::POST:
            err = this->all_process_response_to_POST(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::PUT:
            err = this->all_process_response_to_PUT(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::TRACE:
            err = this->all_process_response_to_TRACE(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::restart:
            err = this->all_process_response_to_restart(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::stop:
            err = this->all_process_response_to_stop(amount, writer, response, request, reader, argc, argv, env);
            break;
        case xos::protocol::http::request::method::unknown:
        default:
            err = this->all_process_response_to_unknown(amount, writer, response, request, reader, argc, argv, env);
            break;
        }
        return err;
    }
    virtual int before_write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_response_to(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = write_response_to(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_write_response_to(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
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
    }

    /// request...
    virtual request_t& request() const {
        return (request_t&)request_;
    }
    virtual request_method_t& request_method_get() const {
        return (request_method_t&)get_;
    }
    virtual request_method_t& request_method_post() const {
        return (request_method_t&)post_;
    }
    virtual request_method_t& set_request_method(const char_t* to) {
        method_.set(to);
        request_.set_method(method_);
        return (request_method_t&)method_;
    }
    virtual request_method_t& request_method() const {
        return (request_method_t&)method_;
    }

    /// response... / message...
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual message_t& message() const {
        return (message_t&)message_;
    }

    /// content_type...
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
    virtual content_type_t& content_type_css() const {
        return (content_type_t&)css_;
    }
    virtual content_type_t& content_type_json() const {
        return (content_type_t&)json_;
    }
    virtual content_type_t& content_type_javasctipt() const {
        return (content_type_t&)javascript_;
    }
    virtual content_type_t& content_type_urlencoded_form_data() const {
        return (content_type_t&)urlencoded_form_data_;
    }
    virtual content_type_t& content_type_multipart_form_data() const {
        return (content_type_t&)multipart_form_data_;
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
    }
    
protected:
    xos::protocol::http::protocol::name http_name_;
    xos::protocol::http::protocol::version http_version_;
    xos::protocol::http::protocol::identifier http_, protocol_;

    xos::protocol::http::content::type::nameof::text text_;
    xos::protocol::http::content::type::nameof::html html_;
    xos::protocol::http::content::type::nameof::xml xml_;
    xos::protocol::http::content::type::nameof::css css_;
    xos::protocol::http::content::type::nameof::json json_;
    xos::protocol::http::content::type::nameof::javascript javascript_;
    xos::protocol::http::content::type::nameof::urlencoded_form_data urlencoded_form_data_;
    xos::protocol::http::content::type::nameof::multipart_form_data multipart_form_data_;
    xos::protocol::http::content::type::name content_type_;
    xos::protocol::http::message::header::content::type content_type_header_;

    xos::protocol::http::message::body::content hello_, bye_, content_;
    xos::protocol::http::message::header::content::length content_length_header_;
    xos::protocol::http::message::header::field connection_header_;

    xos::protocol::http::request::method::nameof::GET get_;
    xos::protocol::http::request::method::nameof::POST post_;
    xos::protocol::http::request::method::name method_;

    xos::protocol::http::request::resource::absolute::path path_;
    xos::protocol::http::request::resource::absolute::identifier identifier_;
    xos::protocol::http::request::resource::identifier asterisk_, resource_;
    xos::protocol::http::request::line request_line_;
    xos::protocol::http::message::header::fields request_headers_;
    xos::protocol::http::request::message request_;

    xos::protocol::http::response::status::codeof::OK ok_;
    xos::protocol::http::response::status::codeof::Not_Found not_found_;
    xos::protocol::http::response::status::code status_;
    xos::protocol::http::response::status::reason reason_;
    xos::protocol::http::response::line response_line_;
    xos::protocol::http::message::header::fields response_headers_;
    xos::protocol::http::response::message response_;
    
    xos::protocol::http::message::part message_;
}; /// class maint
typedef maint<> main;

} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN_HPP 
