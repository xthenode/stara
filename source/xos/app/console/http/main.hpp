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
///   Date: 6/12/2020, 5/20/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_HTTP_MAIN_HPP
#define XOS_APP_CONSOLE_HTTP_MAIN_HPP

#include "xos/app/console/http/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace http {

/// class maint
template 
<class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }
public:

protected:
    typedef typename extends::content_t content_t;
    typedef typename extends::message_t message_t;
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;

#if defined(XOS_APP_CONSOLE_HTTP_MAIN_OPT_EXTENDS_XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN)
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
        response_t &rs = this->response();
        char_t c = 0; ssize_t count = 0;
        int err = 0;
        if ((rq.read(count, c, reader))) {
            err = all_process_request(writer, rs, rq, reader, argc, argv, env);
        }
        return err;
    }

    virtual int process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        ssize_t amount = 0;
        int err = 0;
        err = this->all_write_response_to(amount, writer, rs, rq, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        if ((chars = rq.has_chars(length)) && (!chars[length])) {
            this->errlln(__LOCATION__, "...request = \"", chars, "\"", null);
            if ((length = rq.content_length())) {
                content_t& content = this->content();
                char_t c = 0;
                for (content.clear(); 0 < length; --length) {
                    if (0 <= (reader.read(&c, 1))) {
                        content.append(&c, 1);
                    }
                }
                this->errlln(__LOCATION__, "...content[", unsigned_to_string(length).chars(), "] = \"", content.chars(), "\"", null);
            }
        }
        return err;
    }
    virtual int after_process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_request(writer, rs, rq, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_request(writer, rs, rq, reader, argc, argv, env);
            if ((err2 = after_process_request(writer, rs, rq, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// send_response
    virtual int send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        message_t& message = this->message();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = message.has_chars(length))) {
            xos::network::sockets::writer writer(cn);
            writer.write(chars, length);
        }
        return err;
    }

    /// send_request
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        request_t &rq = this->request();
        int err = 0;
        err = this->send_request(rq, cn, argc, argv, env);
        return err;
    }
    virtual int send_request(request_t &rq, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        xos::network::sockets::writer writer(cn);
        int err = 0;
        err = this->send_request(reader, writer, rq, argc, argv, env);
        return err;
    }
    virtual int send_request
    (xos::network::sockets::reader& reader, 
     xos::network::sockets::writer& writer, request_t &rq, int argc, char_t** argv, char_t**env) {
        ssize_t amount = 0;
        int err = 0;
        err = this->all_write_request(amount, writer, rq, argc, argv, env);
        return err;
    }

    /// recv_response
    virtual int recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        response_t &rs = this->response();
        int err = 0;
        err = recv_response(rs, cn, argc, argv, env);
        return err;
    }
    virtual int recv_response(response_t &rs, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        int err = 0;
        err = recv_response(rs, reader, argc, argv, env);
        return err;
    }
    virtual int recv_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        char_t c = 0; ssize_t count = 0;
        int err = 0;
        if ((rs.read(count, c, reader))) {
            const char_t* chars = 0; size_t length = 0;
            if ((chars = rs.has_chars(length)) && (!chars[length])) {
                this->errlln(__LOCATION__, "...response = \"", chars, "\"", null);
            }
            err = process_response(rs, reader, argc, argv, env);
        }
        return err;
    }
    
    /// process_response
    virtual int process_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = rs.has_chars(length))) {
            this->out(chars, length);
            if ((chars = rs.headers().content_type().has_chars(length))) {
            }
        }
        return err;
    }
#else /// defined(XOS_APP_CONSOLE_HTTP_MAIN_OPT_EXTENDS_XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN)
#endif /// defined(XOS_APP_CONSOLE_HTTP_MAIN_OPT_EXTENDS_XOS_APP_CONSOLE_PROTOCOL_HTTP_MAIN)

}; /// class maint
typedef maint<> main;

} /// namespace http
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_HTTP_MAIN_HPP 
