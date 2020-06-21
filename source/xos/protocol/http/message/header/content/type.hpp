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
///   File: type.hpp
///
/// Author: $author$
///   Date: 6/16/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_MESSAGE_HEADER_CONTENT_TYPE_HPP
#define XOS_PROTOCOL_HTTP_MESSAGE_HEADER_CONTENT_TYPE_HPP

#include "xos/protocol/xttp/message/header/content/type.hpp"
#include "xos/protocol/http/message/header/field.hpp"
#include "xos/protocol/http/content/type/name.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace message {
namespace header {
namespace content {

/// class typet
template 
<class TExtends = xttp::message::header::content::extended::typet
 <http::content::type::name, http::message::header::field>, 
 class TImplements = typename TExtends::implements>
class exported typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typet derives;

    typedef typename extends::type_t type_t;
    typedef typename extends::part_t part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    typet(const type_t& type) {
        this->set_type(type);
    }
    typet(const string_t& chars) {
        this->set_type(chars);
    }
    typet(const char_t* chars, size_t length) {
        this->set_type(chars, length);
    }
    typet(const char_t* chars) {
        this->set_type(chars);
    }
    typet(const typet& copy) {
        this->set_type(copy.value());
    }
    typet() {
        this->set_type();
    }
    virtual ~typet() {
    }
}; /// class typet
typedef typet<> type;

} /// namespace content
} /// namespace header
} /// namespace message
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_MESSAGE_HEADER_CONTENT_TYPE_HPP 
