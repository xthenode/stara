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
///   File: which.hpp
///
/// Author: $author$
///   Date: 5/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_REQUEST_METHOD_WHICH_HPP
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_WHICH_HPP

#include "xos/protocol/http/message/part.hpp"

#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_CONNECT "CONNECT"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_DELETE "DELETE"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_GET "GET"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_HEAD "HEAD"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_OPTIONS "OPTIONS"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PATCH "PATCH"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_POST "POST"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PUT "PUT"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_TRACE "TRACE"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_RESTART "restart"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_STOP "stop"
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_UNKNOWN "unknown"

#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAMES \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_CONNECT, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_DELETE, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_GET, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_HEAD, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_OPTIONS, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PATCH, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_POST, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_PUT, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_TRACE, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_RESTART, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_STOP, \
    XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_UNKNOWN, \

namespace xos {
namespace protocol {
namespace http {
namespace request {
namespace method {

/// enum which_t
typedef int which_t;
enum {
    none = 0,

    CONNECT, DELETE, GET, HEAD, OPTIONS, PATCH, POST, PUT, TRACE, 
    restart, stop, unknown, 

    next,
    first = (none + 1),
    last = (next - 1),
    count = ((last - first) + 1)
}; /// enum which_t

/// class whicht
template <class TExtends = message::part,  class TImplements = typename TExtends::implements>
class exported whicht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef whicht derives;

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    whicht(method::which_t of): of_(of), name_(name_of(of)) {
    }
    whicht(const whicht& copy): of_(copy.of_) {
    }
    whicht(): of_(method::none), name_(0) {
    }
    virtual ~whicht() {
    }

    /// name... / of...
    static const char_t** name_of() {
        static const char_t* name[method::count + 1] = {
            XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAMES
            0
        };
        return name;
    }
    static const char_t* name_of(method::which_t of) {
        const char_t** name = name_of();
        if ((name) && (of >= method::first) && (of <= method::last)) {
            return name[of - method::first];
        }
        return name_of_none();
    }
    static method::which_t of_name(const char_t* name) {
        if ((name)) {
            const char* to = 0;
            int unequal = 0;
            for (method::which_t of = method::first; of <= method::last; ++of) {
                if ((to = name_of(of))) {
                    if (!(unequal = chars_t::compare(name, to)))
                        return of;
                }
            }
        }
        return of_name_none();
    }
    static const char_t* name_of_none() {
        return XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAME_UNKNOWN;
    }
    static method::which_t of_name_none() {
        return method::none;
    }

    /// of / name
    virtual whicht& operator = (const char_t* name) {
        name_ = name_of(of_ = of_name(name));
        return *this;
    }
    virtual whicht& operator = (method::which_t of) {
        name_ = name_of(of_ = of);
        return *this;
    }
    virtual operator method::which_t() const {
        return of();
    }
    virtual method::which_t of() const {
        return of_;
    }
    virtual const char_t* name() const {
        return name_;
    }

protected:
    method::which_t of_;
    const char_t* name_;
}; /// class whicht
typedef whicht<> which;

} /// namespace method
} /// namespace request
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_REQUEST_METHOD_WHICH_HPP 
