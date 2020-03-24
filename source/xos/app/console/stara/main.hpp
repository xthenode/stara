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
///   Date: 3/11/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_STARA_MAIN_HPP
#define XOS_APP_CONSOLE_STARA_MAIN_HPP

#include "xos/app/console/stara/main_opt.hpp"

#include "xos/protocol/xttp/protocol/name.hpp"
#include "xos/protocol/xttp/protocol/version.hpp"
#include "xos/protocol/xttp/protocol/identifier.hpp"

#include "xos/protocol/xttp/message/part.hpp"
#include "xos/protocol/xttp/message/line.hpp"
#include "xos/protocol/xttp/message/header/field.hpp"
#include "xos/protocol/xttp/message/header/fields.hpp"
#include "xos/protocol/xttp/message/header/content/type.hpp"
#include "xos/protocol/xttp/message/header/content/length.hpp"
#include "xos/protocol/xttp/message/parts.hpp"

#include "xos/protocol/xttp/request/method.hpp"
#include "xos/protocol/xttp/request/parameters.hpp"
#include "xos/protocol/xttp/request/line.hpp"
#include "xos/protocol/xttp/request/message.hpp"

#include "xos/protocol/xttp/response/status.hpp"
#include "xos/protocol/xttp/response/reason.hpp"
#include "xos/protocol/xttp/response/line.hpp"
#include "xos/protocol/xttp/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace stara {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint()
    : protocol_(protocol_name_, protocol_version_),

      request_parameters_("/stara/"), 
      request_line_(request_method_, request_parameters_, protocol_),
      request_content_("Hello\r\n"), 
      request_content_length_(request_content_),
      request_content_type_("text/plain"),
      request_headers_(&request_content_type_, &request_content_length_, null),
      request_(request_line_, request_headers_, &request_content_),
    
      response_line_(protocol_, response_status_, response_reason_),
      response_content_(request_content_),
      response_content_length_(response_content_),
      response_content_type_(request_content_type_),
      response_headers_(&response_content_type_, &response_content_length_, null),
      response_(response_line_, response_headers_, &response_content_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): extends(copy) {
    }

protected:
    typedef derives main_t;
    typedef xos::protocol::xttp::message::part::reader_t reader_t;
    typedef xos::protocol::xttp::message::part::writer_t writer_t;

    /// class reader
    class exported reader: virtual public reader_t {
    public:
        reader(main_t& main): main_(main) {
        }
        virtual ssize_t read(what_t* what, size_t size) {
            sized_t* sized = 0; ssize_t count = 0;
            if ((sized = ((sized_t*)what)) && (size)) {
                count = main_.in(sized, size);
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
                count = main_.out(sized, size);
            }
            return count;
        }    
    protected:
        main_t& main_;
    }; /// class writer
    
protected:
    /// request_run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        derives::reader this_reader(*this);
        derives::writer this_writer(*this);
        err = request_run(this_writer, this_reader, argc, argv, env);
        return err;
    }
    virtual int request_run
    (writer_t& writer, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t count = 0;
        
        request_.write(count, writer);
        return err;
    }
    
    /// respond_run
    virtual int respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        derives::reader this_reader(*this);
        derives::writer this_writer(*this);
        err = respond_run(this_writer, this_reader, argc, argv, env);
        return err;
    }
    virtual int respond_run
    (writer_t& writer, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t count = 0;
        
        response_.write(count, writer);
        return err;
    }

protected:
    xos::protocol::xttp::protocol::name protocol_name_;
    xos::protocol::xttp::protocol::version protocol_version_;
    xos::protocol::xttp::protocol::identifier protocol_;

    xos::protocol::xttp::request::method request_method_;
    xos::protocol::xttp::request::parameters request_parameters_;
    xos::protocol::xttp::request::line request_line_;
    xos::protocol::xttp::message::body::content request_content_;
    xos::protocol::xttp::message::header::content::length request_content_length_;
    xos::protocol::xttp::message::header::content::type request_content_type_;
    xos::protocol::xttp::message::header::fields request_headers_;
    xos::protocol::xttp::request::message request_;
    
    xos::protocol::xttp::response::status response_status_;
    xos::protocol::xttp::response::reason response_reason_;
    xos::protocol::xttp::response::line response_line_;
    xos::protocol::xttp::message::body::content response_content_;
    xos::protocol::xttp::message::header::content::length response_content_length_;
    xos::protocol::xttp::message::header::content::type response_content_type_;
    xos::protocol::xttp::message::header::fields response_headers_;
    xos::protocol::xttp::response::message response_;
}; /// class maint
typedef maint<> main;

} /// namespace stara
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_STARA_MAIN_HPP 
