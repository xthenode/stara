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
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;
    typedef typename extends::message_t message_t;

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
            const char_t* chars = 0; size_t length = 0;
            if ((chars = rq.has_chars(length)) && (!chars[length])) {
                this->errlln(__LOCATION__, "...request = \"", chars, "\"", null);
            }
            err = process_request(writer, rs, rq, reader, argc, argv, env);
        }
        return err;
    }

    virtual int process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        ssize_t amount = 0;
        int err = 0;
        rs.write(amount, writer);
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
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = rq.has_chars(length))) {
            ssize_t amount = 0, count = 0;
            if (length <= (amount = writer.write(chars, length))) {
                count += amount;
                if ((chars = rq.content_chars(length))) {
                    if (length <= (amount = writer.write(chars, length))) {
                        count += amount;
                    }
                }
            }
        }
        return err;
    }

    /// recv_request / send_response
    virtual int recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        message_t& message = this->message();
        xos::network::sockets::reader reader(cn);
        int err = 0;
        if (!(err = this->recv(message, reader, argc, argv, env))) {
            xos::network::sockets::sockchar_t c = 0;
            ssize_t count = 0, amount = 0;
            while (0 < (amount = reader.read(&c, 1))) {
                this->out(&c, 1);
                ++count;
            }
        }
        return err;
    }
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

    /// recv 
    virtual int recv(message_t& message, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::sockchar_t c = 0;
        unsigned cr = 0, lf = 0;
        ssize_t count = 0, amount = 0;
        int err = 0;

        while (0 < (amount = reader.read(&c, 1))) {
            if (0 < (amount)) {
                count += amount;
                if (c == '\r') {
                    ++cr;
                } else {
                    if (c == '\n') {
                        if (cr) {
                            ++lf;
                        }
                    } else {
                        cr = lf = 0;
                    }
                }
                if ((err = this->recv(message, c, argc, argv, env))) {
                    break;
                }
                if (1 < lf) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int recv(message_t& message, const xos::network::sockets::sockchar_t& c, int argc, char_t** argv, char_t**env) {
        int err = 0;
        this->out(&c, 1);
        return err;
    }

}; /// class maint
typedef maint<> main;

} /// namespace http
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_HTTP_MAIN_HPP 
