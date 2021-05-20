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
///   Date: 9/20/2020, 5/2/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HTTP_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HTTP_BASE_MAIN_HPP

#include "xos/app/console/protocol/http/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace http {
namespace base {

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
    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_type_which_t content_type_which_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;

    /// ...run
    virtual int content_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        content_t& content = this->content();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_content(amount, writer, content, argc, argv, env);
        return err;
    }
    virtual int content_type_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        content_type_t& content_type = this->content_type();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_content_type(amount, writer, content_type, argc, argv, env);
        return err;
    }

    /// ...write_content
    virtual int write_content(ssize_t& amount, writer_t& writer, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        content.write(amount, writer);
        return err;
    }
    virtual int before_write_content(ssize_t& amount, writer_t& writer, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_content(ssize_t& amount, writer_t& writer, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_content(ssize_t& amount, writer_t& writer, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_content(amount, writer, content, argc, argv, env))) {
            int err2 = 0;
            err = write_content(amount, writer, content, argc, argv, env);
            if ((err2 = after_write_content(amount, writer, content, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    
    /// ...write_content_type
    virtual int write_content_type(ssize_t& amount, writer_t& writer, content_type_t& content_type, int argc, char_t** argv, char** env) {
        int err = 0;
        content_type.write(amount, writer);
        return err;
    }
    virtual int before_write_content_type(ssize_t& amount, writer_t& writer, content_type_t& content_type, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_content_type(ssize_t& amount, writer_t& writer, content_type_t& content_type, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_content_type(ssize_t& amount, writer_t& writer, content_type_t& content_type, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_content_type(amount, writer, content_type, argc, argv, env))) {
            int err2 = 0;
            err = write_content_type(amount, writer, content_type, argc, argv, env);
            if ((err2 = after_write_content_type(amount, writer, content_type, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace http
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_PROTOCOL_HTTP_BASE_MAIN_HPP
