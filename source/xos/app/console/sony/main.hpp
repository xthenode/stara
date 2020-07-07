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
///   Date: 6/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SONY_MAIN_HPP
#define XOS_APP_CONSOLE_SONY_MAIN_HPP

#include "xos/app/console/sony/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace sony {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

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
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint()
    : before_write_request_(0), port_(10000),

      next_path_("/sony/avContent"),
      next_begin_("{\"method\": \"setPlayNextContent\", \"id\": 73, \"params\": [{\"output\": \""),
      next_end_("\"}], \"version\": \"1.0\"}"),
      next_param_(""),

      volume_level_(10), volume_param_(volume_level_),
      volume_path_("/sony/audio"),
      volume_begin_("{\"method\": \"setAudioVolume\", \"id\": 73, \"params\": [{\"volume\": \""),
      volume_end_("\"}], \"version\": \"1.1\"}") {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::json_number_t json_number_t;
    typedef typename extends::err_writer_t err_writer_t;
    typedef typename extends::request_method_t request_method_t;
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;
    typedef typename extends::message_t message_t;

    int (derives::*before_write_request_)(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env);
    virtual int before_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        if ((before_write_request_)) {
            err = (this->*before_write_request_)(amount, writer, request, argc, argv, env);
        } else {
            err = extends::before_write_request(amount, writer, request, argc, argv, env);
        }
        return err;
    }
    virtual int before_write_next_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        next_.assign(next_begin_);
        next_.append(next_param_);
        next_.append(next_end_);
        request.set_method(this->request_method_post());
        request.set_path(next_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(next_.length());
        request.set_content(next_);
        return err;
    }
    virtual int before_write_volume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        volume_.assign(volume_begin_);
        volume_.append(volume_param_);
        volume_.append(volume_end_);
        request.set_method(this->request_method_post());
        request.set_path(volume_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(volume_.length());
        request.set_content(volume_);
        return err;
    }

    /// ...port
    virtual short& accept_port() const {
        return port();
    }
    virtual short& connect_port() const {
        return port();
    }
    virtual short& set_port(short to) {
        port_ = to;
        return port();
    }
    virtual short& port() const {
        return (short&)port_;
    }

    /// on...option...
    virtual int on_next_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_next_request;
        }
        return err;
    }
    virtual int on_volume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            volume_param_.set(volume_level_ = string_t(arg).to_unsigned());
        }
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_volume_request;
        }
        return err;
    }

protected:
    short port_;

    string_t next_path_, next_begin_, next_end_, next_param_, next_;

    unsigned volume_level_; json_number_t volume_param_;
    string_t volume_path_, volume_begin_, volume_end_, volume_;
}; /// class maint
typedef maint<> main;

} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_SONY_MAIN_HPP
