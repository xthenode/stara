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
///   Date: 8/13/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SONY_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_SONY_CLIENT_MAIN_HPP

#include "xos/app/console/sony/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace sony {
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
    : before_write_request_(0), port_(10000),
        
      previous_path_("/sony/avContent"),
      previous_begin_("{\"method\": \"setPlayPreviousContent\", \"id\": 73, \"params\": [{\"output\": \""),
      previous_end_("\"}], \"version\": \"1.0\"}"),
      previous_params_(""),
      
      next_path_("/sony/avContent"),
      next_begin_("{\"method\": \"setPlayNextContent\", \"id\": 73, \"params\": [{\"output\": \""),
      next_end_("\"}], \"version\": \"1.0\"}"),
      next_params_(""),
      
      stop_path_("/sony/avContent"),
      stop_begin_("{\"method\": \"stopPlayingContent\", \"id\": 73, \"params\": [{\"output\": \""),
      stop_end_("\"}], \"version\": \"1.1\"}"),
      stop_params_(""),
      
      resume_path_("/sony/avContent"),
      resume_begin_("{\"method\": \"setPlayContent\", \"id\": 73, \"params\": [{\"output\": \"\", \"resume\": "),
      resume_end_("}], \"version\": \"1.2\"}"),
      resume_params_("true"),
      
      replay_path_("/sony/avContent"),
      replay_begin_("{\"method\": \"setPlayContent\", \"id\": 73, \"params\": [{\"repeatType\": \""),
      replay_end_("\"}], \"version\": \"1.2\"}"),
      replay_params_("on"),
      
      volume_level_(10), volume_value_(volume_level_), volume_param_("volume", volume_value_), 
      volume_object_(&volume_param_, null), volume_params_(&volume_object_, null),
      volume_path_("/sony/audio"),
      volume_begin_("{\"method\": \"setAudioVolume\", \"id\": 73, \"params\": "),
      volume_end_(", \"version\": \"1.1\"}"),
        
      power_status_("on"), power_value_(power_status_), power_param_("status", power_value_), 
      power_object_(&power_param_, null), power_params_(&power_object_, null),
      power_path_("/sony/system"),
      power_begin_("{\"method\": \"setPowerStatus\", \"id\": 73, \"params\": "),
      power_end_(", \"version\": \"1.1\"}") {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }

protected:
    typedef typename extends::json_boolean_t json_boolean_t;
    typedef typename extends::json_number_t json_number_t;
    typedef typename extends::json_string_t json_string_t;
    typedef typename extends::json_node_t json_node_t;
    typedef typename extends::json_array_t json_array_t;
    typedef typename extends::json_object_t json_object_t;
    typedef typename extends::request_method_t request_method_t;
    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;

    /// ...run...
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
    virtual int before_write_previous_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        set_previous();
        request.set_method(this->request_method_post());
        request.set_path(previous_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(previous_.length());
        request.set_content(previous_);
        return err;
    }
    virtual int before_write_next_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        set_next();
        request.set_method(this->request_method_post());
        request.set_path(next_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(next_.length());
        request.set_content(next_);
        return err;
    }
    virtual int before_write_stop_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        set_stop();
        request.set_method(this->request_method_post());
        request.set_path(stop_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(stop_.length());
        request.set_content(stop_);
        return err;
    }
    virtual int before_write_resume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        set_resume();
        request.set_method(this->request_method_post());
        request.set_path(resume_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(resume_.length());
        request.set_content(resume_);
        return err;
    }
    virtual int before_write_volume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        set_volume();
        request.set_method(this->request_method_post());
        request.set_path(volume_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(volume_.length());
        request.set_content(volume_);
        return err;
    }
    virtual int before_write_power_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        set_power();
        request.set_method(this->request_method_post());
        request.set_path(power_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(power_.length());
        request.set_content(power_);
        return err;
    }

    /// on...option...
    virtual int on_previous_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        before_write_request_ = &derives::before_write_previous_request;
        return err;
    }
    virtual int on_next_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        before_write_request_ = &derives::before_write_next_request;
        return err;
    }
    virtual int on_stop_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        before_write_request_ = &derives::before_write_stop_request;
        return err;
    }
    virtual int on_resume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        before_write_request_ = &derives::before_write_resume_request;
        return err;
    }
    virtual int on_volume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            set_volume_level(string_t(arg).to_unsigned());
        }
        before_write_request_ = &derives::before_write_volume_request;
        return err;
    }
    virtual int on_power_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            set_power_status(arg);
        }
        before_write_request_ = &derives::before_write_power_request;
        return err;
    }

    /// ...next...
    virtual string_t& set_previous() {
        previous_.assign(previous_begin_);
        previous_.append(previous_params_);
        previous_.append(previous_end_);
        return previous_;
    }
    virtual string_t& set_next() {
        next_.assign(next_begin_);
        next_.append(next_params_);
        next_.append(next_end_);
        return next_;
    }
    virtual string_t& set_stop() {
        stop_.assign(stop_begin_);
        stop_.append(stop_params_);
        stop_.append(stop_end_);
        return stop_;
    }
    virtual string_t& set_resume() {
        resume_.assign(resume_begin_);
        resume_.append(resume_params_);
        resume_.append(resume_end_);
        return resume_;
    }

    /// ...volume...
    virtual string_t& set_volume_level(unsigned to) {
        volume_level_ = to;
        volume_value_.set(unsigned_to_string(volume_level_));
        volume_param_.set(volume_value_);
        volume_object_.set(&volume_param_, null);
        volume_params_.set(&volume_object_, null);
        return volume_;
    }
    virtual string_t& set_volume() {
        volume_.assign(volume_begin_);
        volume_.append(volume_params_);
        volume_.append(volume_end_);
        return volume_;
    }

    /// ...power...
    virtual string_t& set_power_status(const char_t* to) {
        power_status_.assign(to);
        power_value_.set(power_status_);
        power_param_.set(power_value_);
        power_object_.set(&power_param_, null);
        power_params_.set(&power_object_, null);
        return power_;
    }
    virtual string_t& set_power() {
        power_.assign(power_begin_);
        power_.append(power_params_);
        power_.append(power_end_);
        return power_;
    }

    /// ...port
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

protected:
    short port_;

    string_t previous_path_, previous_begin_, previous_end_, previous_params_, previous_;
    string_t next_path_, next_begin_, next_end_, next_params_, next_;
    string_t stop_path_, stop_begin_, stop_end_, stop_params_, stop_;
    string_t resume_path_, resume_begin_, resume_end_, resume_params_, resume_;
    string_t replay_path_, replay_begin_, replay_end_, replay_params_, replay_;

    unsigned volume_level_; json_node_t volume_value_, volume_param_;
    json_object_t volume_object_; json_array_t volume_params_;
    string_t volume_path_, volume_begin_, volume_end_, volume_;
    
    string_t power_status_; json_node_t power_value_, power_param_;
    json_object_t power_object_; json_array_t power_params_;
    string_t power_path_, power_begin_, power_end_, power_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_SONY_CLIENT_MAIN_HPP
