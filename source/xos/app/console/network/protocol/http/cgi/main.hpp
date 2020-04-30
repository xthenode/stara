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
#include "xos/protocol/xttp/content/reader.hpp"
#include "xos/protocol/http/form/content.hpp"
#include "xos/protocol/http/form/field.hpp"
#include "xos/protocol/http/form/fields.hpp"
#include "xos/protocol/http/url/encoded/reader.hpp"
#include "xos/protocol/http/url/encoded/form/content/type.hpp"
#include "xos/protocol/http/cgi/identifier.hpp"
#include "xos/protocol/http/cgi/configure/values.hpp"
#include "xos/protocol/http/cgi/environment/variable/values.hpp"
#include "xos/protocol/http/cgi/environment/variable/setting.hpp"
#include "xos/io/crt/file/attached.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/io/crt/file/writer.hpp"
#include "xos/io/string/reader.hpp"

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
      content_type_xml_("text/xml"), content_type_css_("text/css"), 
      content_type_js_("application/javascript"), content_type_json_("application/json"), content_type_parameter_name_("content_type"),
      configure_name_("configure"), configure_file_name_("cgicatch-conf.txt"), configure_file_pattern_("configure\r\n"),
      environment_name_("environment"), environment_file_name_("cgicatch-env.txt"), environment_file_pattern_("environment\r\n"),
      input_name_("stdin"), input_file_name_("cgicatch-stdin.txt"), input_file_pattern_("stdin\r\n"),
      form_name_("form"), form_file_name_("cgicatch-form.txt"), form_file_pattern_("form\r\n"),
      query_name_("query"), query_file_name_("cgicatch-query.txt"), query_file_pattern_("query\r\n") {
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
    typedef xos::protocol::xttp::content::readert<reader_t> content_reader_t;
    typedef xos::io::crt::file::readert<reader_t> file_reader_t;
    typedef xos::io::crt::file::writert<writer_t> file_writer_t;
    typedef xos::io::string::readert<reader_t> string_reader_t;
    typedef string_reader_t::string_t query_string_t;
    typedef xos::protocol::http::form::content form_content_t;
    typedef xos::protocol::http::form::field form_field_t;
    typedef xos::protocol::http::form::fields form_fields_t;
    typedef xos::protocol::http::url::encoded::readert<reader_t> url_encoded_reader_t;
    typedef xos::protocol::http::url::encoded::form::content::type url_encoded_form_content_type_t;
    typedef xos::protocol::http::cgi::identifier gateway_interface_t;
    typedef xos::protocol::http::cgi::configure::which_t configure_which_t;
    typedef xos::protocol::http::cgi::configure::name configure_name_t;
    typedef xos::protocol::http::cgi::configure::value configure_value_t;
    typedef xos::protocol::http::cgi::configure::values configure_values_t;
    enum {
        configure_content_type = xos::protocol::http::cgi::configure::content_type,
        configure_first = xos::protocol::http::cgi::configure::first,
        configure_last = xos::protocol::http::cgi::configure::last,
        configure_count = xos::protocol::http::cgi::configure::count
    };
    typedef xos::protocol::http::cgi::environment::variable::which_t environment_which_t;
    typedef xos::protocol::http::cgi::environment::variable::name environment_name_t;
    typedef xos::protocol::http::cgi::environment::variable::value environment_value_t;
    typedef xos::protocol::http::cgi::environment::variable::values environment_values_t;
    typedef xos::protocol::http::cgi::environment::variable::setting environment_variable_t;
    enum {
        CONTENT_LENGTH = xos::protocol::http::cgi::environment::variable::CONTENT_LENGTH,
        CONTENT_TYPE = xos::protocol::http::cgi::environment::variable::CONTENT_TYPE,
        GATEWAY_INTERFACE = xos::protocol::http::cgi::environment::variable::GATEWAY_INTERFACE,
        PATH_TRANSLATED = xos::protocol::http::cgi::environment::variable::PATH_TRANSLATED,
        QUERY_STRING = xos::protocol::http::cgi::environment::variable::QUERY_STRING,
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
        set_gateway_in_std_in();
        set_gateway_out_std_out();
        if (!(err = all_read_configure_values(argc, argv, env))) {
            if (!(err = all_get_environment_values(argc, argv, env))) {
                err = all_get_form_fields(argc, argv, env);
            }
        }
        return err;
    }
    virtual int after_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unset_in_std_in();
        unset_out_std_out();
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
        set_console_in_std_in();
        set_console_out_std_out();
        if (!(err = all_read_configure_values(argc, argv, env))) {
            if (!(err = all_read_environment_values(argc, argv, env))) {
                err = all_read_form_fields(argc, argv, env);
            }
        }
        return err;
    }
    virtual int after_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unset_in_std_in();
        unset_out_std_out();
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
        err = all_console_gateway_out_run(argc, argv, env);
        return err;
    }
    virtual int before_console_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        set_content_type_from_parameter();
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

    /// ...console_gateway_out_run
    virtual int console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        all_out_environment_values(argc, argv, env);
        all_out_form_content(argc, argv, env);
        all_out_form(argc, argv, env);
        all_out_query(argc, argv, env);
        return err;
    }
    virtual int before_console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((content_type_is_html()) || (content_type_is_xml())) {
            this->outln("<html><body><pre>");
        }
        return err;
    }
    virtual int after_console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((content_type_is_html()) || (content_type_is_xml())) {
            this->outln("</pre></body></html>");
        }
        return err;
    }
    virtual int all_console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_console_gateway_out_run(argc, argv, env))) {
            err = console_gateway_out_run(argc, argv, env);
            if ((err2 = after_console_gateway_out_run(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...get_environment_values
    virtual int get_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        environment_.get();
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

    /// ...get_form_fields
    virtual int get_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t content_length = 0;
        const char_t *setting = 0;
        environment_value_t *value = 0;

        form_content_.clear();
        if ((setting = (environment_.setting_of(value, QUERY_STRING))) && (setting[0])) {
            query_string_t query_string(setting);
            string_reader_t string_reader(query_string);
            url_encoded_reader_t url_encoded_reader(string_reader);

            all_read_query_fields(url_encoded_reader, argc, argv, env);
        }
        if ((setting = (environment_.setting_of(value, CONTENT_LENGTH))) && (setting[0])) {
            content_length = value->to_unsigned();
        }
        if ((setting = (environment_.setting_of(value, CONTENT_TYPE))) && (setting[0])) {
            url_encoded_form_content_type_t url_encoded_form_content_type;

            if ((url_encoded_form_content_type.is_equal(setting))) {
                derives::reader this_reader(*this);
                content_reader_t content_reader(this_reader, content_length);
                url_encoded_reader_t url_encoded_reader(content_reader);
                
                all_read_form_content(url_encoded_reader, argc, argv, env);
            }
        }
        return err;
    }
    virtual int before_get_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_get_form_fields(argc, argv, env))) {
            err = get_form_fields(argc, argv, env);
            if ((err2 = after_get_form_fields(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_configure_values
    virtual int read_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        configure_.read(configure_file_name_, configure_file_pattern_);
        return err;
    }
    virtual int before_read_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_configure_values(argc, argv, env))) {
            err = read_configure_values(argc, argv, env);
            if ((err2 = after_read_configure_values(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_environment_values
    virtual int read_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        environment_.read(environment_file_name_, environment_file_pattern_);
        return err;
    }
    virtual int before_read_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_environment_values(argc, argv, env))) {
            err = read_environment_values(argc, argv, env);
            if ((err2 = after_read_environment_values(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_form_fields
    virtual int read_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t content_length = 0;
        const char_t *setting = 0;
        environment_value_t *value = 0;

        form_content_.clear();
        if ((setting = (environment_.setting_of(value, QUERY_STRING))) && (setting[0])) {
            query_string_t query_string(setting);
            string_reader_t string_reader(query_string);
            url_encoded_reader_t url_encoded_reader(string_reader);

            all_read_query_fields(url_encoded_reader, argc, argv, env);
        }
        if ((setting = (environment_.setting_of(value, CONTENT_LENGTH))) && (setting[0])) {
            content_length = value->to_unsigned();
        }
        if ((setting = (environment_.setting_of(value, CONTENT_TYPE))) && (setting[0])) {
            url_encoded_form_content_type_t url_encoded_form_content_type;

            if ((url_encoded_form_content_type.is_equal(setting))) {
                const char_t *name = 0, *pattern = 0;
                
                if ((name = input_file_name_.has_chars()) && (pattern = input_file_pattern_.has_chars())) {
                    file_reader_t file;
                    
                    if ((file.open_safe(name, pattern))) {
                        content_reader_t content_reader(file, content_length);
                        url_encoded_reader_t url_encoded_reader(content_reader);
                        
                        all_read_form_content(url_encoded_reader, argc, argv, env);
                        file.close();
                    }
                }
            }
        }
        return err;
    }
    virtual int before_read_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_form_fields(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_form_fields(argc, argv, env))) {
            err = read_form_fields(argc, argv, env);
            if ((err2 = after_read_form_fields(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_form_content
    virtual int read_form_content(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;

        all_read_form_fields(reader, argc, argv, env);
        /*if (0 < (form_content_.read(reader))) {
            string_reader_t string_reader(form_content_);

            all_read_form_fields(string_reader, argc, argv, env);
        }*/
        return err;
    }
    virtual int before_read_form_content(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_form_content(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_form_content(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_form_content(reader, argc, argv, env))) {
            err = read_form_content(reader, argc, argv, env);
            if ((err2 = after_read_form_content(reader, argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_form_fields
    virtual int read_form_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t count = 0;
        char_t c = 0;
        form_.read(count, c, reader);
        return err;
    }
    virtual int before_read_form_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        form_.start_read();
        return err;
    }
    virtual int after_read_form_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        form_.finish_read();
        return err;
    }
    virtual int all_read_form_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_form_fields(reader, argc, argv, env))) {
            err = read_form_fields(reader, argc, argv, env);
            if ((err2 = after_read_form_fields(reader, argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...read_query_fields
    virtual int read_query_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t count = 0;
        char_t c = 0;
        query_.read(count, c, reader);
        return err;
    }
    virtual int before_read_query_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        query_.start_read();
        return err;
    }
    virtual int after_read_query_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        query_.finish_read();
        return err;
    }
    virtual int all_read_query_fields(reader_t &reader, int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_read_query_fields(reader, argc, argv, env))) {
            err = read_query_fields(reader, argc, argv, env);
            if ((err2 = after_read_query_fields(reader, argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_configure_values
    virtual int write_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t *name = 0, *pattern = 0;
        
        if ((name = configure_file_name_.has_chars()) && (pattern = configure_file_pattern_.has_chars())) {
            file_writer_t file;
            
            if ((file.open_safe(name, pattern))) {
                all_write_configure_values(file, argc, argv, env);
                file.close();
            }
        }
        return err;
    }
    virtual int before_write_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_configure_values(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_write_configure_values(argc, argv, env))) {
            err = write_configure_values(argc, argv, env);
            if ((err2 = after_write_configure_values(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_configure_values
    virtual int write_configure_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t *pattern = 0;
        size_t length = 0;
        
        if ((pattern = configure_file_pattern_.has_chars(length))) {
            if (0 < (writer.write(pattern, length))) {
                configure_.write(writer);
            }
        }
        return err;
    }
    virtual int before_write_configure_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_configure_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_configure_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_write_configure_values(writer, argc, argv, env))) {
            err = write_configure_values(writer, argc, argv, env);
            if ((err2 = after_write_configure_values(writer, argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_environment_values
    virtual int write_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t *name = 0, *pattern = 0;
        
        if ((name = environment_file_name_.has_chars()) && (pattern = environment_file_pattern_.has_chars())) {
            file_writer_t file;
            
            if ((file.open_safe(name, pattern))) {
                all_write_environment_values(file, argc, argv, env);
                file.close();
            }
        }
        return err;
    }
    virtual int before_write_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_write_environment_values(argc, argv, env))) {
            err = write_environment_values(argc, argv, env);
            if ((err2 = after_write_environment_values(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_environment_values
    virtual int write_environment_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t *pattern = 0;
        size_t length = 0;
        
        if ((pattern = environment_file_pattern_.has_chars(length))) {
            if (0 < (writer.write(pattern, length))) {
                environment_.write(writer);
            }
        }
        return err;
    }
    virtual int before_write_environment_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_environment_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_environment_values(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_write_environment_values(writer, argc, argv, env))) {
            err = write_environment_values(writer, argc, argv, env);
            if ((err2 = after_write_environment_values(writer, argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_form_content
    virtual int write_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t *name = 0, *pattern = 0;
        
        if ((name = input_file_name_.has_chars()) && (pattern = input_file_pattern_.has_chars())) {
            file_writer_t file;
            
            if ((file.open_safe(name, pattern))) {
                all_write_form_content(file, argc, argv, env);
                file.close();
            }
        }
        return err;
    }
    virtual int before_write_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_write_form_content(argc, argv, env))) {
            err = write_form_content(argc, argv, env);
            if ((err2 = after_write_form_content(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_form_content
    virtual int write_form_content(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t *pattern = 0;
        size_t length = 0;
        
        if ((pattern = input_file_pattern_.has_chars(length))) {
            if (0 < (writer.write(pattern, length))) {
                const char_t *setting = 0;
                environment_value_t *value = 0;

                if ((setting = (environment_.setting_of(value, CONTENT_LENGTH))) && (setting[0])) {
                    size_t content_length = 0;

                    if (0 < (content_length = value->to_unsigned())) {
                        ssize_t amount = 0;
                        char_t c = 0;
                        
                        for (; 0 < content_length; --content_length) {
                            if (0 < (amount = input(&c, 1))) {
                                if (0 < (amount = writer.write(&c, 1))) {
                                    continue;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int before_write_form_content(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_form_content(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_form_content(writer_t& writer, int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_write_form_content(writer, argc, argv, env))) {
            err = write_form_content(writer, argc, argv, env);
            if ((err2 = after_write_form_content(writer, argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...out_environment_values
    virtual int out_environment_values(int argc, char_t** argv, char_t** env) {
        int err = 0;
        
        if (0 < (environment_.size())) {

            this->outln();
            this->outlln(environment_name_.chars(), " = \"", environment_file_name_.chars(), "\"", null);
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

    /// ...out_form_content
    virtual int out_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        
        if ((chars = form_content_.has_chars(length))) {

            this->outln();
            this->outlln(input_name_.chars(), " = \"", input_file_name_.chars(), "\"", null);
            this->outln();
            this->out(chars, length);
            this->outln();
        }
        return err;
    }
    virtual int before_out_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_out_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_out_form_content(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_out_form_content(argc, argv, env))) {
            err = out_form_content(argc, argv, env);
            if ((err2 = after_out_form_content(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...out_form
    virtual int out_form(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        
        if (0 < (length = form_.length())) {
            const form_field_t* field = 0;
            form_fields_t::const_iterator_t i;

            this->outln();
            if (!(form_content_.has_chars(length))) {
                this->outlln(input_name_.chars(), " = \"", input_file_name_.chars(), "\"", null);
                this->outln();
            }
            this->outlln(form_name_.chars(), " = \"", form_file_name_.chars(), "\"", null);
            this->outln();
            for (field = form_.first(i); field; field = form_.next(i)) {
                this->outlln(field->name().chars(), " = \"", field->value().chars(), "\"", NULL);
            }
        }
        return err;
    }
    virtual int before_out_form(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_out_form(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_out_form(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_out_form(argc, argv, env))) {
            err = out_form(argc, argv, env);
            if ((err2 = after_out_form(argc, argv, env))) {
                if ((!err)) err = err2;
            }
        }
        return err;
    }

    /// ...out_query
    virtual int out_query(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        
        if (0 < (length = query_.length())) {
            const form_field_t* field = 0;
            form_fields_t::const_iterator_t i;

            this->outln();
            this->outlln(query_name_.chars(), " = \"", query_file_name_.chars(), "\"", null);
            this->outln();
            for (field = query_.first(i); field; field = query_.next(i)) {
                this->outlln(field->name().chars(), " = \"", field->value().chars(), "\"", NULL);
            }
        }
        return err;
    }
    virtual int before_out_query(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_out_query(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_out_query(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;
        if (!(err = before_out_query(argc, argv, env))) {
            err = out_query(argc, argv, env);
            if ((err2 = after_out_query(argc, argv, env))) {
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

    /// ...parameter
    const char_t* get_parameter(const string_t& name) const {
        const char_t* chars = 0;
        if (!(chars = query_.has_value_of(name))) {
            chars = form_.has_value_of(name);
        }
        return chars;
    }

    /// set_content_type...
    virtual content_type_header_t* set_content_type_from_configure() {
        const char_t* chars = 0;
        if ((chars = configure_setting_content_type()) && (chars[0])) {
            set_content_type(chars);
        }
        return content_type_;
    }
    virtual content_type_header_t* set_content_type_from_parameter() {
        return set_content_type_from_parameter(content_type_parameter_name_);
    }
    virtual content_type_header_t* set_content_type_from_parameter(const string_t& parameter_name) {
        const char_t* chars = 0;
        if ((chars = get_parameter(parameter_name))) {
            set_content_type(chars);
        } else {
            set_content_type_from_configure();
        }
        return content_type_;
    }
    virtual content_type_header_t* set_content_type(const char_t* chars) {
        if ((chars) && (chars[0])) {
            if (!(content_type_text_.value().compare(chars))) {
                content_type_ = content_type_text();
            } else {
                if (!(content_type_html_.value().compare(chars))) {
                    content_type_ = content_type_html();
                } else {
                    if (!(content_type_xml_.value().compare(chars))) {
                        content_type_ = content_type_xml();
                    } else {
                        if (!(content_type_css_.value().compare(chars))) {
                            content_type_ = content_type_css();
                        } else {
                            if (!(content_type_js_.value().compare(chars))) {
                                content_type_ = content_type_js();
                            } else {
                                if (!(content_type_json_.value().compare(chars))) {
                                    content_type_ = content_type_json();
                                } else {
                                    if ((content_type_ = content_type_other())) {
                                        content_type_->set_value(chars);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return content_type_;
    }

    /// set_content_type...
    virtual content_type_header_t* set_content_type_text() {
        set_content_type(content_type_text());
        return content_type_;
    }
    virtual content_type_header_t* set_content_type_html() {
        set_content_type(content_type_html());
        return content_type_;
    }
    virtual content_type_header_t* set_content_type_xml() {
        set_content_type(content_type_xml());
        return content_type_;
    }
    virtual content_type_header_t* set_content_type_css() {
        set_content_type(content_type_css());
        return content_type_;
    }
    virtual content_type_header_t* set_content_type_js() {
        set_content_type(content_type_js());
        return content_type_;
    }
    virtual content_type_header_t* set_content_type_json() {
        set_content_type(content_type_json());
        return content_type_;
    }

    /// content_type_is...
    virtual content_type_header_t* content_type_is_text() const {
        return content_type_is(content_type_text());
    }
    virtual content_type_header_t* content_type_is_html() const {
        return content_type_is(content_type_html());
    }
    virtual content_type_header_t* content_type_is_xml() const {
        return content_type_is(content_type_xml());
    }
    virtual content_type_header_t* content_type_is_css() const {
        return content_type_is(content_type_css());
    }
    virtual content_type_header_t* content_type_is_js() const {
        return content_type_is(content_type_js());
    }
    virtual content_type_header_t* content_type_is_json() const {
        return content_type_is(content_type_json());
    }
    virtual content_type_header_t* content_type_is(content_type_header_t* content_type) const {
        if ((content_type_) && (content_type)) {
            int unequal = 0;
            if ((content_type_ != content_type)) {
                unequal = content_type_->compare(*content_type);
            }
            if (!(unequal)) {
                return content_type_;
            }
        }
        return 0;
    }

    /// ...content_type
    virtual const char_t* output_content_type_value_chars() {
        content_type_header_t* content_type = 0;
        if ((content_type = output_content_type())) {
            return content_type->value().chars();
        }
        return 0;
    }
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
    virtual content_type_header_t* content_type_css() const {
        return (content_type_header_t*)&content_type_css_;
    }
    virtual content_type_header_t* content_type_js() const {
        return (content_type_header_t*)&content_type_js_;
    }
    virtual content_type_header_t* content_type_json() const {
        return (content_type_header_t*)&content_type_json_;
    }
    virtual content_type_header_t* content_type_other() const {
        return (content_type_header_t*)&content_type_other_;
    }
    
    /// ...configure_setting...
    virtual const char_t *set_configure_setting_content_type(const char_t *to) {
        const char_t *setting = 0;
        setting = configure_.set_setting_of(configure_content_type, to);
        return setting;
    }
    virtual const char_t *configure_setting_content_type() const {
        const char_t *setting = 0;
        setting = configure_.setting_of(configure_content_type);
        return setting;
    }
    virtual const char_t *set_configure_setting(configure_which_t of, const char_t *to) {
        const char_t *setting = 0;
        setting = configure_.set_setting_of(of, to);
        return setting;
    }
    virtual const char_t *configure_setting(configure_which_t of) const {
        const char_t *setting = 0;
        setting = configure_.setting_of(of);
        return setting;
    }

    /// environment_setting...
    virtual const char_t *environment_setting_PATH_TRANSLATED() const {
        const char_t *setting = environment_setting(PATH_TRANSLATED);
        return setting;
    }
    virtual const char_t *environment_setting(environment_which_t of) const {
        const char_t *setting = 0;
        setting = environment_.setting_of(of);
        return setting;
    }
    
    /// ...form_field
    const form_field_t* first_form_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = form_.first(i);
        return field;
    }
    const form_field_t* next_form_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = form_.next(i);
        return field;
    }
    const form_field_t* last_form_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = form_.last(i);
        return field;
    }
    const form_field_t* prev_form_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = form_.prev(i);
        return field;
    }

    /// ...query_field
    const form_field_t* first_query_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = query_.first(i);
        return field;
    }
    const form_field_t* next_query_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = query_.next(i);
        return field;
    }
    const form_field_t* last_query_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = query_.last(i);
        return field;
    }
    const form_field_t* prev_query_field(form_fields_t::const_iterator_t& i) const {    
        const form_field_t* field = 0;
        field = query_.prev(i);
        return field;
    }

protected:
    content_type_header_t *out_content_type_, *content_type_,
                          content_type_text_, content_type_html_, content_type_xml_,
                          content_type_css_, content_type_js_, content_type_json_,
                          content_type_other_;

    string_t content_type_parameter_name_,
             configure_name_, configure_file_name_, configure_file_pattern_,
             environment_name_, environment_file_name_, environment_file_pattern_,
             input_name_, input_file_name_, input_file_pattern_,
             form_name_, form_file_name_, form_file_pattern_,
             query_name_, query_file_name_, query_file_pattern_;
    
    gateway_interface_t gateway_interface_;
    configure_values_t configure_;
    environment_values_t environment_;

    form_content_t form_content_;
    form_fields_t form_, query_;
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
