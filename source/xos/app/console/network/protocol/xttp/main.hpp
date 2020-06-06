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
///   Date: 4/22/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_XTTP_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_XTTP_MAIN_HPP

#include "xos/app/console/network/protocol/xttp/main_opt.hpp"
#include "xos/protocol/xttp/request/message.hpp"
#include "xos/protocol/xttp/response/message.hpp"
#include "xos/protocol/xttp/content/reader.hpp"
#include "xos/protocol/xttp/message/writer.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace xttp {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef xos::protocol::xttp::request::message request_t;
    typedef xos::protocol::xttp::response::message response_t;
    typedef xos::protocol::xttp::message::body::content content_t;
    typedef xos::protocol::xttp::content::reader content_reader_t;
    typedef xos::protocol::xttp::message::writer message_writer_t;
    typedef xos::protocol::xttp::message::parts message_t;

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint()
    : request_("GET / HTTP/1.0\r\n\r\n"), response_("HTTP/1.0 200 Ok\r\n\r\nOk\r\n"),
      request_content_size_(2048), response_content_size_(request_content_size_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }
public:
    
protected:
    /// recv_request
    virtual int recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        request_t &rq = this->request();
        int err = 0;
        err = recv_request(rq, cn, argc, argv, env);
        return err;
    }
    virtual int recv_request(request_t &rq, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        xos::network::sockets::writer writer(cn);
        int err = 0;
        err = recv_request(writer, rq, reader, argc, argv, env);
        return err;
    }
    virtual int recv_request
    (xos::network::sockets::writer& writer, 
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        char_t c = 0; ssize_t count = 0;
        int err = 0;
        if ((rq.read(count, c, reader))) {
            size_t content_length = rq.content_length();
            response_t &rs = this->response();
            content_reader_t content(reader, content_length);
            const char_t* chars = 0; size_t length = 0;
            if ((chars = rq.has_chars(length)) && (!chars[length])) {
                this->errlln(__LOCATION__, "...request = \"", chars, "\"", null);
            }
            err = process_request(writer, rs, rq, content, argc, argv, env);
        }
        return err;
    }

    /// process_request
    virtual int process_request
    (xos::network::sockets::writer& writer, response_t& rs,
     request_t &rq, content_reader_t& reader, int argc, char_t** argv, char_t**env) {
        content_t &rc = request_content(), &sc = response_content();
        size_t content_length = 0;
        int err = 0;

        rc.clear();
        if ((0 < (content_length = reader.length())) && (request_content_size() >= content_length)) {
            const char_t* chars = 0; size_t length = 0;
            ssize_t amount = 0; char_t c = 0;
            while (0 < (amount = reader.read(&c, 1))) {
                rc.append(&c, 1);
            }
            if ((chars = rc.has_chars(length))) {
                this->errlln(__LOCATION__, "...content = \"", chars,"\"", null);
            }
        }
        err = process_request(writer, rs, sc, rq, rc, reader, argc, argv, env);
        return err;
    }
    virtual int process_request
    (xos::network::sockets::writer& writer, response_t& rs, content_t &sc,
     request_t &rq, content_t &rc, content_reader_t& reader, int argc, char_t** argv, char_t**env) {
        message_t &sm = response_message();
        message_writer_t sm_writer(sm);
        ssize_t count = 0;
        int err = 0;
        sm.clear();
        rs.write(count, sm_writer);
        return err;
    }

    /// send_response
    virtual int send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        message_t &sm = response_message();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = sm.has_chars(length))) {
            xos::network::sockets::writer writer(cn);
            writer.write(chars, length);
        }
        return err;
    }

    /// send_request
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        request_t &rq = this->request();
        int err = 0;
        err = send_request(rq, cn, argc, argv, env);
        return err;
    }
    virtual int send_request(request_t &rq, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        xos::network::sockets::writer writer(cn);
        int err = 0;
        err = send_request(reader, writer, rq, argc, argv, env);
        return err;
    }
    virtual int send_request
    (xos::network::sockets::reader& reader, 
     xos::network::sockets::writer& writer, request_t &rq, int argc, char_t** argv, char_t**env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = rq.has_chars(length))) {
            writer.write(chars, length);
        }
        return err;
    }

    /// request.. / response.. 
    virtual request_t& request() const {
        return (request_t&)request_;
    }
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual content_t& request_content() const {
        return (content_t&)request_content_;
    }
    virtual content_t& response_content() const {
        return (content_t&)response_content_;
    }
    virtual size_t& request_content_size() const {
        return (size_t&)request_content_size_;
    }
    virtual size_t& response_content_size() const {
        return (size_t&)response_content_size_;
    }
    virtual message_t& request_message() const {
        return (message_t&)request_message_;
    }
    virtual message_t& response_message() const {
        return (message_t&)response_message_;
    }

protected:
    typedef typename extends::out_writer_t out_writer_t;

protected:
    request_t request_; response_t response_;
    size_t request_content_size_, response_content_size_;
    content_t request_content_, response_content_;
    message_t request_message_, response_message_;
}; /// class maint
typedef maint<> main;

} /// namespace xttp
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_XTTP_MAIN_HPP 
