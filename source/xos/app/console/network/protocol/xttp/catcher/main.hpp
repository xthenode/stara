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
///   Date: 3/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_XTTP_CATCHER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_XTTP_CATCHER_MAIN_HPP

#include "xos/app/console/network/protocol/xttp/catcher/main_opt.hpp"
#include "xos/protocol/xttp/request/method.hpp"
#include "xos/protocol/xttp/request/parameters.hpp"
#include "xos/protocol/xttp/request/line.hpp"
#include "xos/protocol/xttp/request/message.hpp"
#include "xos/io/crt/file/writer.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace xttp {
namespace catcher {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef io::crt::file::char_writer writer_t;
    typedef io::crt::file::char_reader reader_t;
    typedef xos::network::sockets::sockstring_t response_t;
    typedef xos::protocol::xttp::request::message request_t;

    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint(): input_(0), output_(0), outname_("xttpcatch-request.txt"), response_("HTTP/1.0 200 Ok\r\n\r\nOk\r\n") {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }

protected:
    /// ...run
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->accept_run(argc, argv, env);
        return err;
    }

    /// ...accept / ...connect
    virtual int after_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        output_ = 0;
        writer_.closed();
        return err;
    }
    virtual int connect(int argc, char_t** argv, char_t**env) {
        xos::network::sockets::sockchar_t c = 0;
        ssize_t count = 0, amount = 0;
        int err = 0;

        while (0 < (amount = input(&c, 1))) {
            count += amount;
            this->out(&c, 1);
        }
        return err;
    }
    virtual int after_connect(int argc, char_t** argv, char_t**env) {
        int err = 0;
        reader_.closed();
        return err;
    }

    /// recv... / send...
    virtual int recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        request_t &rq = this->request();
        int err = 0;
        err = recv(rq, cn, argc, argv, env);
        return err;
    }
    virtual int recv(request_t &rq, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        int err = 0;
        err = recv(rq, reader, argc, argv, env);
        return err;
    }
    virtual int recv(request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        char_t c = 0;
        ssize_t count = 0;
        int err = 0;

        if ((rq.read(count, c, reader))) {
            const char_t* chars = 0;
            size_t length = 0;

            if ((chars = rq.has_chars(length))) {
                this->output(chars, length);
            }
            for (length = rq.content_length(); 0 < length; --length) {
                if (0 < (count = reader.read(&c, 1))) {
                    this->output(&c, 1);
                } else {
                    break;
                }
            }
        }
        return err;
    }
    virtual int send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        response_t &rs = this->response();
        int err = 0;
        err = send(rs, cn, argc, argv, env);
        return err;
    }
    virtual int send(response_t &rs, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::writer writer(cn);
        int err = 0;
        err = send(rs, writer, argc, argv, env);
        return err;
    }

    /// recv / send
    virtual int recv(string_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
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
                this->output(&c, 1);
                if (1 < lf) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int send(string_t &rs, xos::network::sockets::writer& writer, int argc, char_t** argv, char_t**env) {
        const xos::network::sockets::sockchar_t* chars = 0;
        size_t length = 0;
        ssize_t count = 0;
        int err = 0;
        
        if ((chars = rs.has_chars(length))) {
            count = writer.write(chars, length);
        }
        return err;
    }
    
    /// response / request
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual request_t& request() const {
        return (request_t&)request_;
    }

    /// ...output
    ssize_t (derives::*output_)(const char_t* chars, size_t length);
    virtual ssize_t output(const char_t* chars, size_t length) {
        ssize_t count = 0;
        if ((this->output_)) {
            count = (this->*output_)(chars, length);
        } else {
            count = begin_output(chars, length);
        }
        return count;
    }
    virtual ssize_t begin_output(const char_t* chars, size_t length) {
        const char_t* out_chars = 0;
        ssize_t count = 0;

        if ((out_chars = outname_.has_chars())) {
            const char_t* pattern_chars = 0;
            size_t pattern_length = 0;
            string_t pattern(out_chars);

            pattern.append("\r\n");
            if ((pattern_chars = pattern.has_chars(pattern_length))) {

                if ((writer_.open_safe(out_chars, pattern_chars))) {
                    
                    if (pattern_length <= (writer_.write(pattern_chars, pattern_length))) {
                        
                        if (length <= (count = write_output(chars, length))) {
                            output_ = &derives::write_output;
                            return count;
                        }
                    }
                    writer_.close();
                }
            }
        }
        count = out_output(chars, length);
        output_ = &derives::out_output;
        return count;
    }
    virtual ssize_t write_output(const char_t* chars, size_t length) {
        ssize_t count = 0;
        count = writer_.write(chars, length);
        return count;
    }
    virtual ssize_t out_output(const char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->out(chars, length);
        return count;
    }

    /// ...input
    ssize_t (derives::*input_)(char_t* chars, size_t length);
    virtual ssize_t input(char_t* chars, size_t length) {
        ssize_t count = 0;
        if ((this->input_)) {
            count = (this->*input_)(chars, length);
        } else {
            count = begin_input(chars, length);
        }
        return count;
    }
    virtual ssize_t begin_input(char_t* chars, size_t length) {
        const char_t* out_chars = 0;
        ssize_t count = 0;

        if ((out_chars = outname_.has_chars())) {
            const char_t* pattern_chars = 0;
            size_t pattern_length = 0;
            string_t pattern(out_chars);

            pattern.append("\r\n");
            if ((pattern_chars = pattern.has_chars(pattern_length))) {

                if ((reader_.open_safe(out_chars, pattern_chars))) {
                    
                    if (length <= (count = read_input(chars, length))) {
                        input_ = &derives::read_input;
                        return count;
                    }
                    writer_.close();
                }
            }
        }
        count = in_input(chars, length);
        input_ = &derives::in_input;
        return count;
    }
    virtual ssize_t read_input(char_t* chars, size_t length) {
        ssize_t count = 0;
        count = reader_.read(chars, length);
        return count;
    }
    virtual ssize_t in_input(char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->in(chars, length);
        return count;
    }

protected:
    string_t outname_;
    response_t response_;
    request_t request_;
    writer_t writer_;
    reader_t reader_;
}; /// class maint
typedef maint<> main;

} /// namespace catcher
} /// namespace xttp
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_XTTP_CATCHER_MAIN_HPP 
