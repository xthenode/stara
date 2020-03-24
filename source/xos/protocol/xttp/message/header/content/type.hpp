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
///   Date: 3/12/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_TYPE_HPP
#define XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_TYPE_HPP

#include "xos/protocol/xttp/message/header/field.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace message {
namespace header {
namespace content {

/// class typet
template <class TExtends = header::field, class TImplements = typename TExtends::implements>
class exported typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typet derives;

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    typet(const string_t& chars) {
        set_type(chars);
    }
    typet(const char_t* chars, size_t length) {
        set_type(chars, length);
    }
    typet(const char_t* chars) {
        set_type(chars);
    }
    typet(const typet& copy) {
        set_type(copy.value());
    }
    typet() {
        set_type();
    }
    virtual ~typet() {
    }

    /// set_type
    virtual derives& set_type(const string& s) {
        this->set_name(name_chars());
        this->set_value(s);
        return *this;
    }
    virtual derives& set_type(const char* chars, size_t length) {
        this->set_name(name_chars());
        this->set_value(chars, length);
        return *this;
    }
    virtual derives& set_type(const char* chars) {
        this->set_name(name_chars());
        this->set_value(chars);
        return *this;
    }
    virtual derives& set_type() {
        this->set_name(name_chars());
        this->set_value();
        return *this;
    }
    
    /// name_chars
    const char_t* name_chars() const {
        return "Content-Type";
    }
}; /// class typet
typedef typet<> type;

} /// namespace content
} /// namespace header
} /// namespace message
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_TYPE_HPP 
