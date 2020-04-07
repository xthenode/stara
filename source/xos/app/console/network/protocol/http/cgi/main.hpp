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
///   Date: 4/2/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_MAIN_HPP

#include "xos/app/console/network/protocol/http/cgi/main_opt.hpp"
#include "xos/protocol/xttp/message/header/content/type.hpp"
#include "xos/protocol/http/cgi/identifier.hpp"
#include "xos/protocol/http/cgi/environment/variable/values.hpp"
#include "xos/protocol/http/cgi/environment/variable/setting.hpp"
#include "xos/io/crt/file/attached.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace http {
namespace cgi {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint()
    : run_(0), in_std_in_(0), out_std_out_(0),
      out_content_type_(0), content_type_(0), 
      content_type_text_("text/plain"), content_type_html_("text/html"), 
      content_type_xml_("text/html"), content_type_parameter_name_("content_type"),
      environment_file_name_("cgicatch-env.txt"), environment_file_pattern_("environment\r\n"),
      input_file_name_("cgicatch-stdin.txt"), input_file_pattern_("stdin\r\n") {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }

protected:
    typedef derives main_t;
    typedef xos::protocol::xttp::message::header::content::type content_type_header_t;
    typedef xos::protocol::xttp::message::part::reader_t reader_t;
    typedef xos::protocol::xttp::message::part::writer_t writer_t;
    typedef xos::protocol::http::cgi::identifier gateway_interface_t;
    typedef xos::protocol::http::cgi::environment::variable::which_t environment_which_t;
    typedef xos::protocol::http::cgi::environment::variable::name environment_name_t;
    typedef xos::protocol::http::cgi::environment::variable::value environment_value_t;
    typedef xos::protocol::http::cgi::environment::variable::values environment_values_t;
    typedef xos::protocol::http::cgi::environment::variable::setting environment_variable_t;
    enum {
        GATEWAY_INTERFACE = xos::protocol::http::cgi::environment::variable::GATEWAY_INTERFACE,
        environment_first = xos::protocol::http::cgi::environment::variable::first,
        environment_last = xos::protocol::http::cgi::environment::variable::last,
        environment_count = xos::protocol::http::cgi::environment::variable::count
    };

    /// class reader
    class exported reader: virtual public reader_t {
    public:
        reader(main_t& main): main_(main) {
        }
        virtual ssize_t read(what_t* what, size_t size) {
            sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((sized_t*)what)) && (size)) {
                count = main_.input(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class reader

    /// class writer
    class exported writer: virtual public writer_t {
    public:
        writer(main_t& main): main_(main) {
        }
        virtual ssize_t write(const what_t* what, size_t size) {
            const sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((const sized_t*)what)) && (size)) {
                count = main_.output(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class writer

protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = default_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_gateway_console_run(argc, argv, env);
        return err;
    }

    /// ...gateway_console_run
    virtual int gateway_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((get_gateway_interface(argc, argv, env))) {
            err = all_gateway_run(argc, argv, env);
        } else {
            err = all_console_run(argc, argv, env);
        }
        return err;
    }
    virtual int before_gateway_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gateway_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gateway_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_gateway_console_run(argc, argv, env))) {
            err = gateway_console_run(argc, argv, env);
            if ((err2 = after_gateway_console_run(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }
    virtual gateway_interface_t* get_gateway_interface(int argc, char_t** argv, char_t** env) {
        if ((gateway_interface_.get(argc, argv, env))) {
            return &gateway_interface_;
        }
        return 0;
    }
    
    /// ...gateway_run
    virtual int gateway_run(int argc, char_t** argv, char_t** env) {
        int err = all_console_gateway_run(argc, argv, env);
        return err;
    }
    virtual int before_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /*set_gateway_in_std_in();
        set_gateway_out_std_out();*/
        if (!(err = all_get_environment_values(argc, argv, env))) {
            //err = all_get_form_fields(argc, argv, env);
        }
        return err;
    }
    virtual int after_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /*unset_in_std_in();
        unset_out_std_out();*/
        return err;
    }
    virtual int all_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_gateway_run(argc, argv, env))) {
            err = gateway_run(argc, argv, env);
            if ((err2 = after_gateway_run(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...console_run
    virtual int console_run(int argc, char_t** argv, char_t** env) {
        int err = all_console_gateway_run(argc, argv, env);
        return err;
    }
    virtual int before_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /*set_console_in_std_in();
        set_console_out_std_out();
        err = all_read_environment_values(argc, argv, env);*/
        return err;
    }
    virtual int after_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /*unset_in_std_in();
        unset_out_std_out();*/
        return err;
    }
    virtual int all_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_console_run(argc, argv, env))) {
            err = console_run(argc, argv, env);
            if ((err2 = after_console_run(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...console_gateway_run
    virtual int console_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /*if ((content_type_is_html()) || (content_type_is_xml())) {
            this->outlln("<html><body><pre>", NULL);
        }*/

        all_out_environment_values(argc, argv, env);
        /*out_form_fields(argc, argv, env);

        if ((content_type_is_html()) || (content_type_is_xml())) {
            this->outlln("</pre></body></html>", NULL);
        }*/
        return err;
    }
    virtual int before_console_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /*set_content_type_from_parameter();*/
        return err;
    }
    virtual int after_console_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_console_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_console_gateway_run(argc, argv, env))) {
            err = console_gateway_run(argc, argv, env);
            if ((err2 = after_console_gateway_run(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...get_environment_values
    virtual int get_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        environment_.get(argc, argv, env);
        return err;
    }
    virtual int before_get_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_get_environment_values(argc, argv, env))) {
            err = get_environment_values(argc, argv, env);
            if ((err2 = after_get_environment_values(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...out_environment_values
    virtual int out_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        
        if (0 < (environment_.size())) {

            this->outlln("environment = \"", environment_file_name_.chars(), "\"", null);
            this->outln();

            for (environment_which_t which = environment_first; which <= environment_last; ++which) {
                environment_value_t *value = 0;
                const char_t *name = 0;
    
                if ((value = environment_.value_of(which)) && (name = value->of())) {
                    const char_t *setting = value->setting();

                    this->outlln(name, " = ", (setting?"\"":""), (setting?setting:"0"), (setting?"\"":""), null);
                }
            }
        }
        return err;
    }
    virtual int before_out_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_out_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_out_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_out_environment_values(argc, argv, env))) {
            err = out_environment_values(argc, argv, env);
            if ((err2 = after_out_environment_values(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// input / output
    virtual ssize_t input(char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->in_input(chars, length);
        return count;
    }
    virtual ssize_t output(const char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->out_output(chars, length);
        return count;
    }

    /// ...input / ...output
    virtual ssize_t in_input(char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->in(chars, length);
        return count;
    }
    virtual ssize_t out_output(const char_t* chars, size_t length) {
        ssize_t count = 0;
        count = this->out(chars, length);
        return count;
    }

    /// ...in_std_in
    typedef file_t (derives::*in_std_in_t)();
    file_t (derives::*in_std_in_)();
    virtual file_t in_std_in() {
        if (in_std_in_) {
            return (this->*in_std_in_)();
        }
        return default_in_std_in();
    }
    virtual file_t default_in_std_in() {
        return gateway_in_std_in();
    }
    virtual file_t gateway_in_std_in() {
        file_t in = this->std_in();
        io::crt::file::attached input(in);
        input.set_mode_is_binary();
        in_std_in_ = &derives::console_in_std_in;
        return in;
    }
    virtual file_t console_in_std_in() {
        file_t in = this->std_in();
        return in;
    }
    virtual in_std_in_t set_gateway_in_std_in() {
        in_std_in_ = &derives::gateway_in_std_in;
        return in_std_in_;
    }
    virtual in_std_in_t set_console_in_std_in() {
        in_std_in_ = &derives::console_in_std_in;
        return in_std_in_;
    }
    virtual in_std_in_t unset_in_std_in() {
        in_std_in_ = 0;
        return in_std_in_;
    }

    /// ...out_std_out
    typedef file_t (derives::*out_std_out_t)();
    file_t (derives::*out_std_out_)();
    virtual file_t out_std_out() {
        if (out_std_out_) {
            return (this->*out_std_out_)();
        }
        return default_out_std_out();
    }
    virtual file_t default_out_std_out() {
        return gateway_out_std_out();
    }
    virtual file_t gateway_out_std_out() {
        file_t out = this->std_out();
        all_out_content_type();
        out_std_out_ = &derives::console_out_std_out;
        return out;
    }
    virtual file_t console_out_std_out() {
        file_t out = this->std_out();
        return out;
    }
    virtual out_std_out_t set_gateway_out_std_out() {
        out_std_out_ = &derives::gateway_out_std_out;
        return out_std_out_;
    }
    virtual out_std_out_t set_console_out_std_out() {
        out_std_out_ = &derives::console_out_std_out;
        return out_std_out_;
    }
    virtual out_std_out_t unset_out_std_out() {
        out_std_out_ = 0;
        return out_std_out_;
    }

    /// ...out_content_type
    virtual ssize_t out_content_type() {
        if (!(out_content_type_)) {
            content_type_header_t* content_type = 0;

            if ((content_type = this->output_content_type())) {
                const char* chars = 0; size_t length = 0;                

                out_content_type_ = content_type;
                if ((chars = content_type->has_chars(length))) {
                    ssize_t count = 0, amount = 0;

                    if (0 < (amount = this->out(chars, length))) {
                        count += amount;
                        if (0 < (amount = this->out("\r\n\r\n"))) {
                            count += amount;
                        }
                    }
                    return count;
                }
            }
        }
        return 0;
    }
    virtual ssize_t before_out_content_type() {
        return 0;
    }
    virtual ssize_t after_out_content_type() {
        return 0;
    }
    virtual ssize_t all_out_content_type() {
        ssize_t count = 0, amount = 0;
        if (0 <= (amount = before_out_content_type())) {
            count += amount;
            if (0 < (amount = out_content_type())) {
                count += amount;
                if (0 <= (amount = after_out_content_type())) {
                    count += amount;
                } else {
                    count = amount;
                }
            } else {
                count = amount;
            }
        } else {
            count = amount;
        }
        return count;
    }

    /// ...content_type
    virtual content_type_header_t* output_content_type() {
        content_type_header_t* content_type = 0;
        if (!(content_type = this->content_type())) {
            content_type = set_content_type(this->default_content_type());
        }
        return content_type;
    }
    virtual content_type_header_t* set_content_type(content_type_header_t* to) {
        content_type_ = to;
        return content_type_;
    }
    virtual content_type_header_t* content_type() const {
        return content_type_;
    }
    virtual content_type_header_t* default_content_type() const {
        return this->content_type_text();
    }
    virtual content_type_header_t* content_type_text() const {
        return (content_type_header_t*)&content_type_text_;
    }
    virtual content_type_header_t* content_type_html() const {
        return (content_type_header_t*)&content_type_html_;
    }
    virtual content_type_header_t* content_type_xml() const {
        return (content_type_header_t*)&content_type_xml_;
    }

protected:
    content_type_header_t *out_content_type_, *content_type_,
                          content_type_text_, content_type_html_, content_type_xml_;

    string_t content_type_parameter_name_,
             environment_file_name_, environment_file_pattern_,
             input_file_name_, input_file_pattern_;
    
    gateway_interface_t gateway_interface_;
    environment_values_t environment_;
}; /// class maint
typedef maint<> main;

} /// namespace cgi
} /// namespace http
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_MAIN_HPP 
