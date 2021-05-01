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
///   Date: 9/16/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_HPP

#include "xos/app/console/xttp/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
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
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
    }

protected:
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;
    typedef typename extends::content_t content_t;
    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_type_type_which_t content_type_type_which_t;
    enum { content_type_type_text = extends::content_type_type_text };
    typedef typename extends::content_type_subtype_which_t content_type_subtype_which_t;
    enum { content_type_subtype_json = extends::content_type_subtype_json };

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

    /// ...process_response
    virtual int process_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        const char_t* chars = 0; size_t length = 0;
        int err = 0;

        if ((chars = rs.has_chars(length))) {
            this->out(chars, length);

            if ((chars = rs.headers().content_type().has_chars(length))) {
                content_type_t content_type(chars);

                if ((content_type_type_text == (content_type.type_name().which()))
                    || ((content_type_subtype_json == (content_type.subtype_name().which())))) {

                    if (0 < (length = rs.headers().content_length())) {
                        err = recv_response_content(reader, length, argc, argv, env);
                    } else {                    
                        err = recv_response_content(reader, argc, argv, env);
                    }
                }
            }
        }
        return err;
    }

    /// ...recv_response_content 
    virtual int recv_response_content(xos::network::sockets::reader& reader, size_t length, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::sockchar_t c = 0;
        ssize_t count = 0, amount = 0;
        int err = 0;
        while (0 < (length)) {
            if (0 < (amount = reader.read(&c, 1))) {
                ++count;
                --length;
                if ((err = this->recv_response_content(c, argc, argv, env))) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int recv_response_content(xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::sockchar_t c = 0;
        ssize_t count = 0, amount = 0;
        int err = 0;
        while (0 < (amount = reader.read(&c, 1))) {
            ++count;
            if ((err = this->recv_response_content(c, argc, argv, env))) {
                break;
            }
        }
        return err;
    }
    virtual int recv_response_content(const xos::network::sockets::sockchar_t& c, int argc, char_t** argv, char_t**env) {
        int err = 0;
        this->out(&c, 1);
        return err;
    }
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace xttp
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_HPP
